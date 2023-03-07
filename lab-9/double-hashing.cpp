#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstdio>
#define M 64
#define N 24
using namespace std;

class DoubleHash
{
	public:
		DoubleHash();
		bool isFull();
		int hash1(int key);
		int hash2(int key);
		void insert(int key);
		int probes(int key);
		void display();
		
	private:
		int *hashTable;
		int curSize;
};

int DoubleHash::probes(int key)
{
	return (hash1(key)+hash2(key)&(M-1));
}

DoubleHash::DoubleHash()
{
	hashTable=new int[M];
	curSize=0;
	for(int i=0;i<M;i++)
	{
		hashTable[i]=-1;
	} 
}

void DoubleHash::insert(int key)
{
	if(isFull())
	{
		return;
	}
	
	int tmp1=hash1(key);
	
	if(hashTable[tmp1]==-1)
	{
		hashTable[tmp1]=key;
	}
	
	else
	{
		int i=1;
		int tmp2=hash2(key);
		
		while(1)
		{
			int newIndex=(tmp1+i*tmp2)%M;
			
			if(hashTable[newIndex]==-1)
			{
				hashTable[newIndex]=key;
				break;
			}
			
			i++;
		}
	}
	
	curSize++;
}

int DoubleHash::hash1(int key)
{
	return key%M;
}

int DoubleHash::hash2(int key)
{
	return key/M;
}

void DoubleHash::display()
{
	for(int i=0;i<M;i++)
	{
		if(hashTable[i]!=-1)
		{
			cout<<i<<"-->"<<hashTable[i]<<endl;
		}
		
		else
		{
			cout<<i<<endl;
		}
	}
}


bool DoubleHash::isFull()
{
	return (curSize==M);
}

int trans(int *arr)
{
	int exp=0,sum=0;
	for(int i=23;i>=0;i--)
	{
		if(arr[i]==1)
		{
			sum+=exp*2;
		}
		
		exp++;
	}
	return sum;
}

int main()
{
	int arr[32][24];
	int arr1[32];
	int i;
	
	cout<<"The 32 random 24-bit number:"<<endl;
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<24;j++)
		{
			arr[i][j]=rand()&1;
			cout<<arr[i][j];
		}
		
		cout<<endl;
	}
	cout<<endl<<endl;
	
	cout<<"After transformation"<<endl;
	for(int i=0;i<32;i++)
	{
		int tmp=trans(arr[i]);
		arr1[i]=tmp;
		cout<<arr1[i]<<endl;
	}
	cout<<endl<<endl;
	
	DoubleHash d;
	double sum=0;
	
	for(int i=0;i<32;i++)
	{
		d.insert(arr1[i]);
		sum+=d.probes(arr1[i]);
	}
	double tmp=sum/32;
	
	cout<<"Hashing"<<endl;
	d.display();
	cout<<endl<<"Average probes:"<<tmp<<endl;
}

 










