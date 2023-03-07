#include <iostream>

using namespace std;

//边的结构体 
class EData
{
	public:
		char start;
		char end;
		int weight;
		
	public:
		EData(){}
		EData(char s, char e, int w):start(s),end(e),weight(w){}
};

//邻接表 
class AdjList
{
#define MAX 100
#define INF (~(0x1<<31))
	private:
		//链表顶点 
		class ENode
		{
			int ivex; //该边所指向的点的位置 
			int weight; //该边的权 
			ENode *nextEdge; //指向下一条边 
			friend class AdjList;
		};
		
		//表的顶点 
		class VNode
		{
			char data; //顶点名称 
			ENode *firstEdge; //指向第一条连接该点的边的指针 
			friend class AdjList;
		};
		
	private:
		int mVexNum;//图的顶点数目 
		int mEdgNum;//图的边数目 
		VNode mVexs[MAX];
		
	public:
		AdjList(){}
		AdjList(char vexs[], int vlen, EData *edges[], int elen);
		~AdjList(){}
		
		void print();
		void kruskal();
		
	private:
		char readChar();
		int getPosition(char ch);
		void linkLast(ENode* list, ENode *node);
		int getWeight(int start, int end);
		EData* getEdges();
		void sortEdges(EData* edges, int start, int last);
		int getEnd(int vends[], int i);
};


AdjList::AdjList(char vexs[], int vlen, EData *edges[], int elen)
{
	char c1, c2;
	int i, p1, p2, weight;
	ENode *node1, *node2;
	
	mVexNum=vlen;
	mEdgNum=elen;
	
	for(i=0;i<mVexNum;i++)
	{
		mVexs[i].data=vexs[i];
		mVexs[i].firstEdge=NULL;
	}
	
	for(i=0;i<mEdgNum;i++)
	{
		c1=edges[i]->start;
		c2=edges[i]->end;
		weight=edges[i]->weight;
		
		p1=getPosition(c1);
		p2=getPosition(c2);
		
		node1=new ENode();
		node1->ivex=p2;
		node1->weight=weight;
		
		if(mVexs[p1].firstEdge==NULL)
		{
			mVexs[p1].firstEdge=node1;
		}
		else
		{
			linkLast(mVexs[p1].firstEdge, node1);
		}
		
		node2=new ENode();
		node2->ivex=p1;
		node2->weight=weight;
		
		if(mVexs[p2].firstEdge==NULL)
		{
			mVexs[p2].firstEdge=node2;
		}
		else
		{
			linkLast(mVexs[p2].firstEdge, node2);
		}
	}
}


void AdjList::print()
{
	int i, j;
	ENode* node;
	
	cout<<"Adjacency List:"<<endl;
	
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

void AdjList::kruskal()
{
	int i,j,m,n,p1,p2;
	int length;
	int index=0;
	int vends[MAX]={0};
	EData rets[MAX];
	EData *edges;
	
	edges=getEdges();
	sortEdges(edges, 0, mEdgNum-1);
	
	for(i=0;i<mEdgNum;i++)
	{
		p1=getPosition(edges[i].start);
		p2=getPosition(edges[i].end);
		
		m=getEnd(vends,p1);
		n=getEnd(vends,p2);
		
		if(m!=n)
		{
			vends[m]=n;
			rets[index]=edges[i];
			index++;
		}
				
		
		for(j=0;j<index;j++)
		{
			cout<<"("<<rets[j].start<<","<<rets[j].end<<")";
		}
		
		cout<<endl;
		
	}
	cout<<endl<<"********************"<<endl;
	delete []edges;
	
	length=0;
	for(i=0;i<index;i++)
	{
		length+=rets[i].weight;
	}
	cout<<"Kruscal Result:"<<endl;
	cout<<"length:"<<length<<endl;
	for(i=0;i<index;i++)
	{
		cout<<"("<<rets[i].start<<","<<rets[i].end<<")";
	}
	cout<<endl;
}

char AdjList::readChar()
{
	char ch;
	
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	
	return ch;
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

void AdjList::linkLast(ENode* list, ENode *node)
{
	ENode* p=list;
	
	while(p->nextEdge)
	{
		p=p->nextEdge;
	}
	
	p->nextEdge=node;
}

int AdjList::getWeight(int start, int end)
{
	ENode* node;
	
	if(start==end)
	{
		return 0;
	}
	
	node=mVexs[start].firstEdge;
	
	while(node!=NULL)
	{
		if(node->ivex==end)
		{
			return node->weight;
		}
		node=node->nextEdge;
	}
	
	return INF;
}

EData* AdjList::getEdges()
{
	int i,j;
	int index=0;
	ENode *node;
	EData *edges;
	
	edges=new EData[mEdgNum];
	for(i=0;i<mVexNum;i++)
	{
		node=mVexs[i].firstEdge;
		
		while(node!=NULL)
		{
			if(node->ivex>i)
			{
				edges[index].start=mVexs[i].data;
				edges[index].end=mVexs[node->ivex].data;
				edges[index].weight=node->weight;
				index++;
			}
			
			node=node->nextEdge;
		}
		
		
	}
	
	return edges;
}

void AdjList::sortEdges(EData* edges, int start, int last)
{
	int i=start;
	int j=last;
	EData tmp=edges[i];
	
	if(i<j)
	{
		while(i<j)
		{
			while(i<j && edges[j].weight>=tmp.weight)
			{
				j--;
			}
			
			if(i<j)
			{
				edges[i]=edges[j];
				i++;
			}
			
			while(i<j && tmp.weight>=edges[i].weight)
			{
				i++;
			}
			
			if(i<j)
			{
				edges[j]=edges[i];
				j--;
			}
			
		}
		
		edges[i]=tmp;
		
		sortEdges(edges,start,i-1);
		sortEdges(edges,i+1,last);
	}
//
//	int i,j;
//
//    for (i=0; i<elen; i++)
//    {
//        for (j=i+1; j<elen; j++)
//        {
//            if (edges[i].weight > edges[j].weight)
//            {
//                // 交换"边i"和"边j"
//                swap(edges[i], edges[j]);
//            }
//        }
//    }
}

int AdjList::getEnd(int vends[], int i)
{
	while(vends[i]!=0)
	{
		i=vends[i];
	}
	
	return i;
}

int main()
{
	char vexs[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
	EData *edges[]=
	{
		new EData('C','E',1),
		new EData('A','B',20),
		new EData('B','C',7),
		new EData('A','D',21),
		new EData('B','D',13),
		new EData('B','E',5),
		new EData('D','E',10),
		new EData('D','F',14),
		new EData('E','F',22),
		new EData('F','G',4),
		new EData('E','G',15),
		new EData('E','H',6),
		new EData('G','H',11),
		new EData('H','I',2),
		new EData('H','L',9),
		new EData('H','K',8),
		new EData('K','L',16),
		new EData('G','I',3),
		new EData('I','K',12),
		new EData('G','J',19),
		new EData('I','J',18),
		new EData('J','K',17),
	};
	
	int vlen=sizeof(vexs)/sizeof(vexs[0]);
	int elen=sizeof(edges)/sizeof(edges[0]);
	
	AdjList* adjlist;
	
	adjlist=new AdjList(vexs,vlen,edges,elen);
	adjlist->print();
	cout<<endl<<"********************"<<endl;
	cout<<endl<<"Kruskal Pocess:"<<endl;
	adjlist->kruskal();
	return 0;
}












