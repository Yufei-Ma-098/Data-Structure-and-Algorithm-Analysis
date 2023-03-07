

/*  TA抱歉，我来不及改完了…… */ 


#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define max 30

typedef struct
{
	int unused[max];
	int top;
}S;

typedef struct
{
	float coef;
	int exp;
	int cur;
}component; 



void init(S& s);

void push(S &s, int n);

void pop(S &s);

bool isEmpty(S &s);

bool isFull(S &s);

int getTop(S &s);

void reserveArr(component* arr,int n, S seq);

int mallocArr(component* arr); 

int initArr(component* arr, S seq, float coef, int exp);

void insertArr(component* arr, int body, int pos, float coef, int exp);

void deleteArr(component* arr, int body, float coef, int exp);

int select(component* arr, int body, float coef, int exp);

void changeElement(component* arr, int body, float oldCoef, float newCoef, int oldExp, int newExp);

void displayArr(component* arr);

void freeArr(component* arr, int k);

void add(component* a, component* b);

void polyPlus(component *a, component *b, int body1, int body2);


int main()
{
	cout<<"请依次输入LP和LQ的项数"<<endl;
	int m,n;
	cin>>m>>n;
	
	int cnt=m>=n?m:n;
	
	component LP[max];
	component LQ[max];
	S s1;
	S s2;
	
	init(s1);
	init(s2);
	
	int body1=0, body2=0;
	
	float coef;
	int exp;
	
	cout<<"请依次输入LP的系数和指数，常数项指数请输入0"<<endl;
	
	
	reserveArr(LP,m,s1);
	for(int i=0;i<m;i++)
	{
		cin>>coef>>exp;
		LP[body1].coef=coef;
		LP[body1].exp=exp;
		body1=LP[body1].cur;
	}
	
	cout<<"LP:"<<endl;
	displayArr(LP);
	
	cout<<"请依次输入LQ的系数和指数，常数项指数请输入0"<<endl;
	
	reserveArr(LQ,n,s2);
	for(int i=0;i<m;i++)
	{
		cin>>coef>>exp;
		LQ[body2].coef=coef;
		LQ[body2].exp=exp;
		body2=LQ[body2].cur;
	}
	
	cout<<"LQ:"<<endl; 
	displayArr(LQ);
	
	polyPlus(LP, LQ, body1, body2);
	
	cout<<"LP+LQ:"<<endl;
	displayArr(LP);
}

void polyPlus(component *a, component *b, int body1, int body2)
{
	int p=a[body1].cur;
	int q=b[body2].cur;
	int t=body1;
	int temp;
	
	while(p!=-1&&q!=-1)
	{
		if(a[p].exp<b[q].exp)
		{
			a[t].cur=p;
			t=a[t].cur;
			p=a[p].cur;
		}
		
		else if(a[p].exp>b[q].exp)
		{
			a[t].cur=q;
			t=a[t].coef;
			q=b[q].cur;
		}
		
		else if(a[p].exp==b[q].exp)
		{
			if(a[p].coef+b[q].coef!=0)
			{
				a[p].coef=a[p].coef+b[q].coef;
				a[t].cur=p;
				t=a[t].cur;
				freeArr(b, q);
			}
			
			else
			{
				int tmp1=a[p].cur;
				int tmp2=b[q].cur;
				
				freeArr(a, p);
				freeArr(b, q);
				
				p=tmp1;
				q=tmp2;
			}
		}
	}
	
	
	
	
	
	
//	int tmp=body;
//	
//	while(arr[tmp].cur)
//	{
//		cout<<arr[tmp].coef<<"x^"<<arr[tmp].exp<<"+";
//		tmp=arr[tmp].cur;
//	}
//	
//	cout<<arr[tmp].coef<<"x^"<<arr[tmp].exp<<endl;
//	
	
	
}


void push(S &s, int n)
{
//	if(s.top==max-1)
//	{
//		cout<<"Error!"<<endl;
//		return;
//	}
	
	s.unused[s.top]=n;
	s.top++;
}

void init(S &s)
{
	int num[max], cnt=0, n;
    srand(clock());
    while(cnt<max)
    {
        n=rand()%max;
        for (int i=0;i<cnt;i++)
            if (num[i]==n)
                continue;
        num[cnt++]=n;
    }
    
    s.top=0;
    
	for(int i=0;i<max;i++)
	{
		push(s,num[i]);
	}
	
	
}

bool isEmpty(S &s)
{
	if(s.top==-1)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool isFull(S &s)
{
	if(s.top==max-1)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void pop(S &s)
{
	if(!isEmpty(s))
	{
		s.top--;
	}
	
	else
	{
		cout<<"The stack is empty."<<endl;
	}
}

int getTop(S &s)
{
	if(!isEmpty(s))
	{
		return s.unused[s.top];
	}
	
	else
	{
		cout<<"The stack is empty."<<endl;
	}
}

void reserveArr(component* arr, int m, S seq)
{
	for(int i=0;i<max;i++)
	{
		arr[i].cur=-1;
	}
	
	int cnt=m;
	int tmp=0;
	while(cnt)
	{
		arr[tmp].cur=getTop(seq);
		pop(seq);
		tmp=arr[tmp].cur;
		cnt--;
	}

}

int mallocArr(component* arr)
{
	int i=arr[0].cur;
	
	if(arr[0].cur)
	{
		arr[0].cur=arr[i].cur;
	}
	
	return i;
}

//int initArr(component* arr, S seq, float coef, int exp)
//{
//	reserveArr(array);
//	int body=mallocArr(arr);
//	int tmp=body;
//	
//	
//	int j=mallocArr(arr);
//	arr[tmp].cur=j;
//	arr[j].coef=coef;
//	arr[j].exp=exp;
//	tmp=j;
//	
//	arr[tmp].cur=0;
//	
//	return body;
//} 

void insertArr(component* arr, int body, int pos, float coef, int exp)
{
	int tmp=body;
	
	for(int i=1;i<pos;i++)
	{
		tmp=arr[tmp].cur;
	}
	
	int ins=mallocArr(arr);
	arr[ins].cur=arr[tmp].cur;
	arr[ins].coef=coef;
	arr[ins].exp=exp;
	arr[tmp].cur=ins;
}

void deleteArr(component* arr, int body, float coef, int exp)
{
	int tmp=body;
	
	while(arr[tmp].coef!=coef||arr[tmp].exp!=exp)
	{
		tmp=arr[tmp].cur;
		
		if(tmp==0)
		{
			cout<<"Error!"<<endl;
			return;
		}
	}
	
	int del=tmp;
	tmp=body;
	
	while(arr[tmp].cur!=del)
	{
		tmp=arr[tmp].cur;
	}
	
	arr[tmp].cur=arr[del].cur;
	
	freeArr(arr,del);
}

int select(component* arr, int body, float coef, int exp)
{
	int tmp=body;
	
	while(arr[tmp].cur!=0)
	{
		if(arr[tmp].coef==coef&&arr[tmp].exp==exp)
		{
			return tmp;
		}
	}
	
	return -1;
}

void changeElement(component* arr, int body, float oldCoef, float newCoef, int oldExp, int newExp)
{
	int tmp=select(arr, body, oldCoef, oldExp);
	
	if(tmp==-1)
	{
		cout<<"Error!"<<endl;
		return;
	}
	
	arr[tmp].exp=newExp;
	arr[tmp].coef=newCoef;
}

void displayArr(component* arr)
{
	int tmp=0;
	
	while(arr[tmp].cur!=-1)
	{
		int m=arr[tmp].cur;
		
		if(arr[tmp].coef==0)
		{
			continue;
		}
		
		else if(arr[m].cur!=-1)
		{
			cout<<arr[tmp].coef<<"x^"<<arr[tmp].exp<<"+";
		}
		
		else
		{
			cout<<arr[tmp].coef<<"x^"<<arr[tmp].exp;
		}
		
		tmp=arr[tmp].cur;
	}
	
	cout<<endl;
	
	//cout<<arr[tmp].coef<<"x^"<<arr[tmp].exp<<endl;
}

void freeArr(component* arr, int pos)
{
	arr[pos].cur=arr[0].cur;
	arr[0].cur=pos;
}

//float getRandFloat(int min, int max)
//{
//	float m1=(float)(rand()%101)/101; 
//	min++; 
//	float m2=(float)((rand()%(max-min+1))+min); 
//	m2=m2-1;
//	return m1+m2; 
//}

//void test1()
//{
//	int m=3, n=3;
//	S s1, s2;
//	init(s1);
//	init(s2);
//	component poly1[max];
//	component poly2[max];
//	int body1=initArr(poly1, m, s1);
//	int body2=initArr(poly2, n, s2);
//	
//	poly1[0].coef=1;
//	poly1[1].coef=2.1;
//	poly1[2].coef=0.2;
//	poly1[0].exp=2;
//	poly1[1].exp=1;
//	poly1[2].exp=0;
//	
//	poly2[0].coef=2;
//	poly2[1].coef=1.2;
//	poly2[2].coef=3.3;
//	poly2[0].exp=2;
//	poly2[1].exp=1;
//	poly2[2].exp=0;
//	
//	displayArr(poly1, 0);
//	displayArr(poly2, 0);
//	
//	for(int i=0;i<m;i++)
//	{
//		if(poly1[i].exp==poly2[i].exp)
//		{
//			poly2[i].coef=poly1[i].coef+poly2[i].coef;
//		}
//	}
//	
//	displayArr(poly2, 0);
//	
//
//}

