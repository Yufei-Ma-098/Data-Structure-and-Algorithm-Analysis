#include <iostream>
#define MAX 20
using namespace std;

class MinHeap
{
	public:
		MinHeap();
		bool isEmpty();
		void push(int num);
		int pop();
		void print();
		
	private:
		int heapArr[MAX];
		int len;
		
};

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

void test1()
{
	int arr[MAX]={7,6,10,99,182,1,3,45,76,33,100,15,67,11,500,88,222,56,2,70};
	MinHeap* obj=new MinHeap();
	
	cout<<"The array to store:"<<endl;
	
	for(int i=0;i<MAX;i++)
	{
		cout<<arr[i]<<" ";
	} 
	cout<<endl<<endl<<"**************************************";
	
	for(int i=0;i<MAX;i++)
	{
		cout<<"Push "<<arr[i]<<endl;
		obj->push(arr[i]);
		obj->print();
		cout<<endl;
	}
	
	cout<<endl<<endl<< "**************************************";
	
	while(!(obj->isEmpty()))
	{
		cout<<"Pop "<<obj->pop()<<endl;
		obj->print();
		cout<<endl; 
	}
	
	delete obj;
	 
}

void test2()
{
	int arr[MAX]={3,7,24,15,13,28,55,92,99,81,77,61,74,35,1,6,5,9,101,88};
	MinHeap* obj=new MinHeap();
	
	cout<<"The array to store:"<<endl;
	
	for(int i=0;i<MAX;i++)
	{
		cout<<arr[i]<<" ";
	} 
	cout<<endl<<endl<<"**************************************";
	
	for(int i=0;i<MAX;i++)
	{
		cout<<"Push "<<arr[i]<<endl;
		obj->push(arr[i]);
		obj->print();
		cout<<endl;
	}
	
	cout<<endl<<endl<< "**************************************";
	
	while(!(obj->isEmpty()))
	{
		cout<<"Pop "<<obj->pop()<<endl;
		obj->print();
		cout<<endl; 
	}
	
	delete obj;
	 
}

void test3()
{
	int arr[MAX]={48,52,70,95,34,63,17,3,66,2,4,9,0,99,27,13,26,77,99,101};
	MinHeap* obj=new MinHeap();
	
	cout<<"The array to store:"<<endl;
	
	for(int i=0;i<MAX;i++)
	{
		cout<<arr[i]<<" ";
	} 
	cout<<endl<<endl<<"**************************************";
	
	for(int i=0;i<MAX;i++)
	{
		cout<<"Push "<<arr[i]<<endl;
		obj->push(arr[i]);
		obj->print();
		cout<<endl;
	}
	
	cout<<endl<<endl<< "**************************************";
	
	while(!(obj->isEmpty()))
	{
		cout<<"Pop "<<obj->pop()<<endl;
		obj->print();
		cout<<endl; 
	}
	
	delete obj;
	 
}

void test4()
{
	int arr[MAX]={3,24,18,2,12,13,16,88,67,54,39,101,245,787,11,0,-4,999,26,1};
	MinHeap* obj=new MinHeap();
	
	cout<<"The array to store:"<<endl;
	
	for(int i=0;i<MAX;i++)
	{
		cout<<arr[i]<<" ";
	} 
	cout<<endl<<endl<<"**************************************";
	
	for(int i=0;i<MAX;i++)
	{
		cout<<"Push "<<arr[i]<<endl;
		obj->push(arr[i]);
		obj->print();
		cout<<endl;
	}
	
	cout<<endl<<endl<< "**************************************";
	
	while(!(obj->isEmpty()))
	{
		cout<<"Pop "<<obj->pop()<<endl;
		obj->print();
		cout<<endl; 
	}
	
	delete obj;
	 
}

void test5()
{
	int arr[MAX]={232,565,4,5888,5654,1,3,4,0,2,5,-9,-44,-6,333,13,25,67,34,52};
	MinHeap* obj=new MinHeap();
	
	cout<<"The array to store:"<<endl;
	
	for(int i=0;i<MAX;i++)
	{
		cout<<arr[i]<<" ";
	} 
	cout<<endl<<endl<<"**************************************";
	
	for(int i=0;i<MAX;i++)
	{
		cout<<"Push "<<arr[i]<<endl;
		obj->push(arr[i]);
		obj->print();
		cout<<endl;
	}
	
	cout<<endl<<endl<< "**************************************";
	
	while(!(obj->isEmpty()))
	{
		cout<<"Pop "<<obj->pop()<<endl;
		obj->print();
		cout<<endl; 
	}
	
	delete obj;
	 
}

int main()
{
	int i;
	cout<<"Enter 1,2,3,4 or 5 to call test cases. Enter -1 to exit."<<endl;
	cin>>i;
	
	while(i!=-1)
	{
		switch(i)
		{
			case 1:
				test1();
				break;
				
			case 2:
				test2();
				break;
				
			case 3:
				test3();
				break;
				
			case 4:
				test4();
				break;
				
			case 5:
				test5();
				break;
		}
		
		cout<<"Enter 1,2,3,4 or 5 to call test cases. Enter -1 to exit."<<endl;
		cin>>i;
	}
}

