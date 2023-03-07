#include <iostream>
using namespace std;

template <typename T>
class AVLNode
{
	public:
		T key;
		int height;
		AVLNode* left;
		AVLNode* right;
		
		AVLNode(T value, AVLNode* l, AVLNode* r):key(value), left(l), right(r){}
};

template <typename T>
class AVL
{
	private:
		AVLNode<T>* root;
		
	public:
		AVL();
		~AVL();
		
		AVLNode<T>* find(T key);
		
		void insert(T key);
		void destroy();
		void print();
		
		int getHeight();
		int getMax(int a, int b);
		
		void preOrder();
        void inOrder();
        void postOrder();

		
	private:
		int getHeight(AVLNode<T>* tree);
		
		void destroy(AVLNode<T>* &tree);
		void print(AVLNode<T>* tree, T key, int d);
		
		AVLNode<T>* find(AVLNode<T>* tree, T key);
		AVLNode<T>* insert(AVLNode<T>* &tree, T key);
		//AVLNode<T>* remove(AVLNode<T>* &tree, AVLNode<T>* t);
		
		void preOrder(AVLNode<T> *tree) const;
        void inOrder(AVLNode<T> *tree) const;
        void postOrder(AVLNode<T> *tree) const;

		
		AVLNode<T>* leftLeftRotation(AVLNode<T>* t1);
		AVLNode<T>* rightLeftRotation(AVLNode<T>* t2);
		AVLNode<T>* leftRightRotation(AVLNode<T>* t3);
		AVLNode<T>* rightRightRotation(AVLNode<T>* t4);
};

template <typename T>
int AVL<T>::getHeight()
{
	return getHeight(root);
}

template <typename T>
int AVL<T>::getHeight(AVLNode<T>* tree)
{
	if(tree!=NULL)
	{
		return tree->height;
	}
	
	else
	{
		return 0;
	}
}

template <typename T>
AVL<T>::AVL()
{
	root=NULL;
}

template <typename T>
AVL<T>::~AVL()
{
	destroy(root);
}

template <typename T>	
AVLNode<T>* AVL<T>::find(T key)
{
	return find(root, key);
}

template <typename T>
void AVL<T>::insert(T key)
{
	insert(root,key);
}

template <typename T>
void AVL<T>::destroy()
{
	destroy(root);
}

template <typename T>
void AVL<T>::print()
{
	print(root,root->key,0);
}



template <typename T>
int AVL<T>::getMax(int a, int b)
{
	return a>b?a:b;
}
		
template <typename T>
void AVL<T>::destroy(AVLNode<T>* &tree)
{
	if(tree==NULL)
	{
		return;
	}
	
	if(tree->left!=NULL)
	{
		destroy(tree->left);
	}
	
	if(tree->right!=NULL)
	{
		destroy(tree->right);
	}
	
	delete tree;
}



 
template<class T>
void AVL<T>::preOrder(AVLNode<T> *tree) const
{
    if(tree!=NULL)
    {
        cout<<tree->key<<" ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
 
template<class T>
void AVL<T>::preOrder()
{
    preOrder(root);
}
 
template<class T>
void AVL<T>::inOrder(AVLNode<T> *tree) const
{
    if(tree!=NULL)
    {
        inOrder(tree->left);
        cout<<tree->key<<" ";
        inOrder(tree->right);
    }
}
 
template<class T>
void AVL<T>::inOrder()
{
    inOrder(root);
}
 
template<class T>
void AVL<T>::postOrder(AVLNode<T> *tree) const
{
    if(tree!=NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<<tree->key<<" ";
    }
}
 
template<class T>
void AVL<T>::postOrder()
{
    postOrder(root);
}

template <typename T>
void AVL<T>::print(AVLNode<T>* tree, T key, int d)
{
	if(tree==NULL)
	{
		cout<<"Error!"<<endl;
	}
	
	else
	{
		if(d==0)
		{
			cout<<"root: "<<tree->key<<endl;
		}
		
		else
		{
			cout<<tree->key<<"is "<<key<<"'s "<<(d==-1?"left child":"right child")<<endl;
		}
		
		print(tree->left,tree->key,-1);
		print(tree->right,tree->key,1);
	}
}


template <typename T>		
AVLNode<T>* AVL<T>::find(AVLNode<T>* tree, T key)
{
	if(tree==NULL||tree->key==key)
	{
		return tree;
	}
	
	if(tree->key>key)
	{
		return find(tree->left, key);
	}
	
	else
	{
		return find(tree->right, key);
	}
}

template <typename T>
AVLNode<T>* AVL<T>::insert(AVLNode<T>* &tree, T key)
{
	if(tree==NULL)
	{
		tree=new AVLNode<T>(key, NULL, NULL);
		if(tree==NULL)
		{
			cout<<"error!"<<endl;
			return NULL;
		}
	}
	
	else if(tree->key>key)
	{
		tree->left=insert(tree->left, key);
		
		if(getHeight(tree->left)-getHeight(tree->right)==2)
		{
			if(key<tree->left->key)
			{
				tree=leftLeftRotation(tree);
			}
			
			else
			{
				tree=leftRightRotation(tree);
			}
		}
	}
	
	else
	{
		tree->right=insert(tree->right, key);
		
		if(getHeight(tree->right)-getHeight(tree->left)==2)
		{
			if(key>tree->right->key)
			{
				tree=rightRightRotation(tree);
			}
			
			else
			{
				tree=rightLeftRotation(tree);
			}
		}
	}
	
	tree->height=max(getHeight(tree->left), getHeight(tree->right))+1;
	
	return tree;
}


template <typename T>
AVLNode<T>* AVL<T>::leftLeftRotation(AVLNode<T>* k2)
{
	AVLNode<T>* k1;
		
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	
	k2->height=max(getHeight(k2->left), getHeight(k2->right))+1;
	k1->height=max(getHeight(k1->left), k2->height)+1;
	
	return k1;
}

template <typename T>
AVLNode<T>* AVL<T>::rightLeftRotation(AVLNode<T>* k1)
{
	k1->right=leftLeftRotation(k1->right);
	return rightRightRotation(k1);
}

template <typename T>
AVLNode<T>* AVL<T>::leftRightRotation(AVLNode<T>* k3)
{
	k3->left=rightRightRotation(k3->left);
	return leftLeftRotation(k3);
}

template <typename T>
AVLNode<T>* AVL<T>::rightRightRotation(AVLNode<T>* k1)
{
	AVLNode<T>* k2;
	
	k2=k1->right;
	k1->right=k2->left;
	k2->left=k1;
	
	k1->height=max(getHeight(k1->left), getHeight(k1->right))+1;
	k2->height=max(getHeight(k2->right), k1->height)+1;
	
	return k2;
}

static int arr[]={4,5,2,16,15,7,6,10,13,12,11,10,8,9,1};


int main()
{
	int i, len;
	AVL<int>* tree=new AVL<int>();
	
	len=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"insert one by one: "<<endl;
	for(int i=0; i<len;i++)
	{
		cout<<arr[i]<<" ";
		tree->insert(arr[i]);
	}
	
	cout<<endl<<endl<<"pre order:";
	tree->preOrder();
	cout<<endl<<"in order:";
	tree->inOrder();
	cout<<endl<<"post order:";
	tree->postOrder();
	cout<<endl<<endl;
	
	cout<<"height: "<<tree->getHeight()<<endl<<endl;
	//cout<<"print tree: "<<endl;
//	tree->print();
	
	cout<<"insert 3:"<<endl;
	tree->insert(3);
	cout<<endl<<"pre order:";
	tree->preOrder();
	cout<<endl<<"in order:";
	tree->inOrder();
	cout<<endl<<"post order:";
	tree->postOrder();
	cout<<endl;
	cout<<"height: "<<tree->getHeight()<<endl<<endl;
	
	tree->destroy();
	return 0;
}
