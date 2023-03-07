#include <iostream>
#include <cstring>
#define MAX 12
using namespace std;

class AdjList
{
	private:
		class ENode
		{
			int ivex;
			ENode *nextEdge;
			friend class AdjList;
		};
		
		class VNode
		{
			char data;
			ENode *firstEdge;
			friend class AdjList;
		};
		
	private:
		int mVexNum;
		int mEdgNum;
		VNode *mVexs;
			
	public:
		AdjList();
		AdjList(char vexs[], int vlen, char edges[][2], int elen);
		~AdjList();
		
		void print();
		int topologicalSort();
		
	private:
		char readChar();
		int getPosition(char ch);
		void linkLast(ENode* list, ENode *node);
};

AdjList::AdjList(char vexs[], int vlen, char edges[][2], int elen)
{
	char c1, c2;
	int i, p1, p2;
	ENode *node1, *node2;
	
	mVexNum=vlen;
	mEdgNum=elen;
	
	mVexs=new VNode[mVexNum];
	
	for(i=0;i<mVexNum;i++)
	{
		mVexs[i].data=vexs[i];
		mVexs[i].firstEdge=NULL;
	}
	
	for(i=0;i<mEdgNum;i++)
	{
		c1=edges[i][0];
		c2=edges[i][1];
		
		p1=getPosition(c1);
		p2=getPosition(c2);
		
		node1=new ENode();
		node1->ivex=p2;
		
		if(mVexs[p1].firstEdge==NULL)
		{
			mVexs[p1].firstEdge=node1;
		}
		
		else
		{
			linkLast(mVexs[p1].firstEdge, node1);
		}
	}
}

AdjList::~AdjList()
{
	ENode *node;
	
	for(int i=0;i<mEdgNum;i++)
	{
		node=mVexs[i].firstEdge;
		
		while(node!=NULL)
		{
			delete node;
			node=node->nextEdge;
		}
	}
	
	delete[] mVexs;
}

void AdjList::linkLast(ENode *list, ENode *node)
{
	ENode *p=list;
	
	while(p->nextEdge)
	{
		p=p->nextEdge;
	}
	
	p->nextEdge=node;
} 

int AdjList::getPosition(char ch)
{
	int i;
	for(i=0;i<mVexNum;i++)
	{
		if(mVexs[i].data==ch)
		{
			return i;
		}
	}
	
	return -1;
}

char AdjList::readChar()
{
	char ch;
	
	do
	{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	
	return ch;
}

void AdjList::print()
{
	int i, j;
	ENode* node;
	
	cout<<"AdjList Graph:"<<endl;
	
	for(i=0;i<mVexNum;i++)
	{
		cout<<i<<"("<<mVexs[i].data<<"):";
		node=mVexs[i].firstEdge;
		
		while(node!=NULL)
		{
			cout<<node->ivex<<"("<<mVexs[node->ivex].data<<")";
			node=node->nextEdge;
		} 
		
		cout<<endl;
	}
}

int AdjList::topologicalSort()
{
	int i,j;
	int index=0, head=0, rear=0;
	int *queue, *ins;
	char *tops;
	ENode *node;
	
	ins=new int[mVexNum];
	queue=new int[mVexNum];
	tops=new char[mVexNum];
	
	memset(ins, 0, mVexNum*sizeof(int));
	memset(queue, 0, mVexNum*sizeof(int));
	memset(tops, 0, mVexNum*sizeof(char));
	
	for(i=0;i<mVexNum;i++)
	{
		node=mVexs[i].firstEdge;
		while(node!=NULL)
		{
			ins[node->ivex]++;
			node=node->nextEdge;
		}
	}
	
	for(i=0;i<mVexNum;i++)
	{
		if(ins[i]==0)
		{
			queue[rear]=i;
			rear++;
		}
	}
	
	while(rear!=head)
	{
		j=queue[head++];
		tops[index++]=mVexs[j].data;
		node=mVexs[j].firstEdge;
		
		while(node!=NULL)
		{
			ins[node->ivex]--;
			
			if(ins[node->ivex]==0)
			{
				queue[rear++]=node->ivex;
			}
			
			node=node->nextEdge;
			

			
			cout<<"The queue:"<<endl;
			for(int i=head;i<rear;i++)
			{
				cout<<char(queue[i]+'A')<<" ";
			}
			cout<<endl;
			
			cout<<"The pocess of topological sort:"<<endl;
			for(int i=0;i<mVexNum;i++)
			{
				cout<<tops[i]<<" ";
			}
			cout<<endl<<endl<<"----------------------------"<<endl;
		}
		
	}
	
		if(index!=mVexNum)
		{
			cout<<"Graph has a cycle"<<endl;
			delete queue;
			delete ins;
			delete tops;
			return 1;
		}
		
		cout<<endl<<endl<<"Topological Sorting Result:"<<endl;
		for(i=0;i<mVexNum;i++)
		{
			cout<<tops[i]<<" ";
		}
		cout<<endl;
		
		delete queue;
		delete ins;
		delete tops;
		
		return 0;
}

int main()
{
	char vexs[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
	char edges[][2]=
	{
		{'C', 'D'},
		{'D', 'A'},
		{'A', 'B'},
		{'B', 'E'},
		{'D', 'E'},
		{'D', 'F'},
		{'F', 'G'},
		{'F', 'E'},
		{'G', 'E'},
		{'F', 'K'},
		{'K', 'L'},
		{'G', 'L'},
		{'H', 'D'},
		{'H', 'I'},
		{'I', 'J'},
		{'J', 'F'}	
	};
	
	int vlen=sizeof(vexs)/sizeof(vexs[0]);
	int elen=sizeof(edges)/sizeof(edges[0]);
	AdjList* adjlist;
	adjlist=new AdjList(vexs,vlen,edges,elen);
	
	adjlist->print();
	cout<<endl;
	
	adjlist->topologicalSort();
	
	return 0;
}
