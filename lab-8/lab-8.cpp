#include <iostream>
#include <cstdlib>
#define MAX 8
using namespace std;

int a1[]={1,3,6,7,9,11,13,22};
int a2[]={2,8,10,15,19,26,44,55};
int a3[]={23,24,36,39,41,46,48,49};
int a4[]={14,17,18,21,26,66,77,87};
int a5[]={4,5,16,25,43,59,62,68};
int a6[]={31,33,35,37,40,63,64,70};
int a7[]={61,71,72,81,83,89,90,101};
int a8[]={92,94,95,97,102,120,122,130};


struct QNode
{
	QNode *next;
	int data;
};

struct LinkQueue
{
	QNode *front;
	QNode *rear;
};


LinkQueue Q1;
LinkQueue Q2;
LinkQueue Q3;
LinkQueue Q4;
LinkQueue Q5;
LinkQueue Q6;
LinkQueue Q7;
LinkQueue Q8;

void initQueue(LinkQueue& Q)
{
	QNode *q;
	q=new QNode;
	q->next=NULL;
	
	Q.front=q;
	Q.rear=q;
}

bool isEmpty(LinkQueue& Q)
{
	if(Q.front==Q.rear)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void enqueue(LinkQueue& Q, int num)
{
	QNode* p;
	p=new QNode;
	p->next=NULL;
	p->data=num;
	
	Q.rear->next=p;
	Q.rear=p;
	
}

int dequeue(LinkQueue& Q)
{
	if(isEmpty(Q))
	{
		return -1;
	}
	QNode* p;
	p=Q.front->next;
	
	int tmp=p->data;
	
	Q.front->next=p->next;
	
	if(Q.rear==p)
	{
		Q.front=Q.rear;
	}
	delete p;
	
	return tmp;
}

void destroyQueue(LinkQueue& Q)
{
	while(Q.front)
	{
		Q.rear=Q.front;
		delete Q.front;
		Q.front=Q.rear;
	}
}

int top(LinkQueue& Q)
{
	return Q.front->next->data;
}



class MinHeap
{
	public:
		MinHeap();
		bool isEmpty();
		void push(int num);
		int pop();
		void print();
		int tail();
		void heap();
		
	private:
		int heapArr[MAX];
		int len;
		
};

void MinHeap::heap()
{  
    int tmp; 
	int head=0;
	int tail=len-1; 
    tmp=heapArr[head]; 
    int j;  
    for(j=2*head;j<=tail;j*=2)
    {  
        if(j<tail && heapArr[j]>heapArr[j+1])
            ++j;  
        if(tmp<=heapArr[j])  
            break;  
        heapArr[head]=heapArr[j];
        head=j;  
    }  
    heapArr[head]=tmp;
}  

int MinHeap::tail()
{
	len--;
	heapArr[len-1]=0;
	return heapArr[len-1];
}

MinHeap::MinHeap()
{
	len=0;
}

bool MinHeap::isEmpty()
{
	if(len==0)
	{
		return true;
	}
	
	return false;
}

void MinHeap::push(int n)
{
	int i=len;
	len++;
	
	while(i)
	{
		int j=(i-1)/2;
		
		if(heapArr[j]<=n)
		{
			break;
		}
		
		heapArr[i]=heapArr[j];
		
		i=j;
	}
	
	heapArr[i]=n;
}

int MinHeap::pop()
{
	len--;
	int i=0;
	int tmp1=heapArr[0];
	int tmp2=heapArr[len];
	
	while(len>i*2+1)
	{
		int leftChild=i*2+1;
		int rightChild=i*2+2;
		
		if(rightChild<len && heapArr[leftChild]>heapArr[rightChild])
		{
			leftChild=rightChild;
		}
		
		if(heapArr[leftChild]>tmp2)
		{
			break;
		}
		
		heapArr[i]=heapArr[leftChild];
		i=leftChild;
	}
	
	heapArr[i]=tmp2;
	return tmp1;
}

void MinHeap::print()
{
	int i;
	for(i=0;i<len-1;i++)
	{
		cout<<heapArr[i]<<" ";
	}
	cout<<heapArr[i]<<endl;
}

int search(int x)
{
	int tmp;
	for(int i=0;i<8;i++)
	{
		if(x==a1[i])
		{
			tmp=1;
			break;
		}
		
		if(x==a2[i])
		{
			tmp=2;
			break;
		}
		
		if(x==a3[i])
		{
			tmp=3;
			break;
		}
		
		if(x==a4[i])
		{
			tmp=4;
			break;
		}
		
		if(x==a5[i])
		{
			tmp=5;
			break;
		}
		
		if(x==a6[i])
		{
			tmp=6;
			break;
		}
		
		if(x==a7[i])
		{
			tmp=7;
			break;
		}
		
		if(x==a8[i])
		{
			tmp=8;
			break;
		}
	}
	
	return tmp;
}

void mergeSort(MinHeap m)
{
	int x=m.pop();
	int tmp=search(x);
	int y;
	
	switch(tmp)
	{
		case 1:
			y=dequeue(Q1);
			break;
			
		case 2:
			y=dequeue(Q2);
			break;
			
		case 3:
			y=dequeue(Q3);
			break;
			
		case 4:
			y=dequeue(Q4);
			break;
			
		case 5:
			y=dequeue(Q5);
			break;
			
		case 6:
			y=dequeue(Q6);
			break;
			
		case 7:
			y=dequeue(Q7);
			break;
			
		case 8:
			y=dequeue(Q8);
			break;
	}
	
	if(y==-1)
	{
		int temp=m.tail();
		m.push(temp);
		m.heap();
		return;
	}
	
	m.push(y);
	m.heap();
}

int main()
{
	initQueue(Q1);
	initQueue(Q2);
	initQueue(Q3);
	initQueue(Q4);
	initQueue(Q5);
	initQueue(Q6);
	initQueue(Q7);
	initQueue(Q8);
	
	for(int i=0;i<8;i++)
	{
		enqueue(Q1,a1[i]); 
		enqueue(Q2,a2[i]); 
		enqueue(Q3,a3[i]); 
		enqueue(Q4,a4[i]); 
		enqueue(Q5,a5[i]); 
		enqueue(Q6,a6[i]); 
		enqueue(Q7,a7[i]); 
		enqueue(Q8,a8[i]); 
	}
	
	MinHeap m;
	
	m.push(top(Q1));
	m.push(top(Q2));
	m.push(top(Q3));
	m.push(top(Q4));
	m.push(top(Q5));
	m.push(top(Q6));
	m.push(top(Q7));
	m.push(top(Q8));
	
	mergeSort(m);
	m.print();
}
 
