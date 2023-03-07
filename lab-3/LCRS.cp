#include <iostream>
using namespace std;

//单链表，存放Simple Tree结点
template <typename Type> class List {
public:
  class Node {
  public:
    Type data;
    Node *next;
  };

  List();
  ~List();

  bool empty() const;
  int size();
  int front();
  Node *begin();
  Node *end();
  int count(int);

  void push_front(Type t);
  Type pop_front();
  void erase(int);

private:
  Node *head;
};

//普通树的数据结构
template <typename T> class SimpleTree {
public:
  SimpleTree(T &t = T(), SimpleTree * = NULL);

  T getValue() const;
  SimpleTree *getParent() const;
  int degree() const;
  bool isRoot() const;
  bool isLeaf() const;
  SimpleTree *getChild(int n) const;
  int height() const;

  void insert(T &);
  void attach(SimpleTree *);
  void detach();

private:
  T value;
  SimpleTree *parent;
  List<SimpleTree *> children;
};

//左孩子右兄弟树的数据结构
struct LCRS {
  int data;
  LCRS *leftChild;
  LCRS *rightSib;
};

LCRS *createLCRS(int *roots, int *data, int temp);
void inOrder(LCRS *root);

//队列，存放LCRS结点
template <typename Type> class Queue {
public:
  Queue(int = 100);
  ~Queue();
  bool empty() const;
  Type getFront() const;
  void push(Type &n);
  Type pop();

private:
  int size;
  int front;
  int back;
  int capacity;
  Type *arr;
};

template <typename Type> List<Type>::List() { head = NULL; }

template <typename Type> List<Type>::~List() { delete head; }

template <typename Type> bool List<Type>::empty() const {
  if (head == NULL) {
    return true;
  }

  else {
    return false;
  }
}

template <typename Type> int List<Type>::size() {}

template <typename Type> int List<Type>::front() {
  if (empty()) {
    cout << "The list is empty!" << endl;
    return;
  }

  else {
    return begin()->value;
  }
}

template <typename Type> typename List<Type>::Node *List<Type>::begin() {
  return head;
}

template <typename Type> typename List<Type>::Node *List<Type>::end() {
  return NULL;
}

template <typename Type> int List<Type>::count(int n) {
  int cnt = 0;

  for (Node *p = begin(); p != end(); p = p->next()) {
    if (p->value() == n) {
      cnt++;
    }
  }

  return cnt;
}

template <typename Type> void List<Type>::push_front(Type t) {
  if (empty()) {
    head = new Node(t, NULL);
  }

  else {
    head = new Node(t, begin());
  }
}

template <typename Type> Type List<Type>::pop_front() {
  if (empty()) {
    cout << "The list is empty!" << endl;
    return;
  }

  else {
    int tmp = front();
    Node *p = head;
    head = head->next();
    delete p;
    return tmp;
  }
}

template <typename Type> void List<Type>::erase(int n) {
  for (Node *p = begin(); p != end(); p = p->next()) {
    if (p->value() == n) {
      p->next = p->next->next;
    }
  }
}

template <typename T> SimpleTree<T>::SimpleTree(T &obj, SimpleTree *p) {
  value = obj;
  parent = p;
}

template <typename T> T SimpleTree<T>::getValue() const { return value; }

template <typename T> SimpleTree<T> *SimpleTree<T>::getParent() const {
  return parent;
}

template <typename T> int SimpleTree<T>::degree() const {
  return children.getLength();
}

template <typename T> bool SimpleTree<T>::isRoot() const {
  if (getParent() == NULL) {
    return true;
  }

  else {
    return false;
  }
}

template <typename T> bool SimpleTree<T>::isLeaf() const {
  if (degree() == 0) {
    return true;
  }

  else {
    return false;
  }
}

template <typename T> SimpleTree<T> *SimpleTree<T>::getChild(int n) const {
  if (n >= degree() || n < 0) {
    return NULL;
  }

  else {
    T *child = children.head();

    for (int i = 1; i < n; i++) {
      child = child->next();
    }

    return child->value();
  }
}

template <typename T> int SimpleTree<T>::height() const {
  //	if(this==NULL)
  //	{
  //		return -1;
  //	}
  //
  //	else
  //	{
  //		int h=0;
  //
  //		for(auto*
  //child=children.begin();child!=children.end();child=child->next)
  //		{
  //			h=h>child->value()->height()?h:
  //child->value()->height();
  //		}
  //
  //		return h;
  //	}
}

template <typename T> void SimpleTree<T>::insert(T &t) {}

template <typename T> void SimpleTree<T>::attach(SimpleTree *obj) {
  //	children.push_back(new SimpleTree(obj,this));
}

template <typename T> void SimpleTree<T>::detach() {
  if (isRoot()) {
    return;
  }

  parent()->children.erase(this);
  parent = NULL;
}

template <typename T> Queue<T>::Queue(int n) {
  size = 0;
  front = 0;
  back = -1;
  capacity = n > 1 ? n : 1;
  arr = new T[capacity];
}

template <typename T> Queue<T>::~Queue() { delete[] arr; }

template <typename T> bool Queue<T>::empty() const {
  if (size == 0) {
    return true;
  }

  else {
    return false;
  }
}

template <typename T> T Queue<T>::getFront() const {
  if (empty()) {
    cout << "The queue is empty" << endl;
    return NULL;
  }

  else {
    return arr[front];
  }
}

template <typename T> void Queue<T>::push(T &n) {
  if (size == capacity) {
    cout << "The queue is full" << endl;
  }

  else {
    back++;
    size++;
    arr[back] = n;
  }
}

template <typename T> T Queue<T>::pop() {
  if (empty()) {
    cout << "The queue is empty" << endl;
    return NULL;
  }

  size--;
  front++;
  return arr[size - 1];
}

int main() {
  int temp;
  int roots[100], data[100];
  LCRS *root;

  cout << "请输入根节点数据：" << endl;
  cin >> temp;

  cout << "请按照层从低往高依次输入各个节点数据：" << endl;
  cout << "PS: root + data 格式，如1 "
          "3表示根节点数据是1，孩子节点数据为3，输入-1 -1结束"
       << endl;
  int cnt = 0;
  cin >> roots[cnt] >> data[cnt];
  while (roots[cnt] != -1 || data[cnt] != -1) {
    cnt++;
    cin >> roots[cnt] >> data[cnt];
  }

  root = createLCRS(roots, data, temp);

  cout << "LCRS的中序排序为：" << endl;
  inOrder(root);
  cout << endl;
}

LCRS *createLCRS(int *roots, int *data, int temp) {
  LCRS *root = NULL;
  LCRS *p;
  root = new LCRS;

  root->data = temp;
  root->leftChild = NULL;
  root->rightSib = NULL;

  Queue<LCRS *> q;
  q.push(root);

  int cnt = 0;
  while (!(roots[cnt] == -1 && data[cnt] == -1)) {
    while (q.getFront()->data != roots[cnt]) {
      q.pop();
    }

    LCRS *tmp = q.getFront();

    if (tmp->leftChild == NULL) {
      p = new LCRS;
      p->data = data[cnt];
      p->leftChild = NULL;
      p->rightSib = NULL;
      tmp->leftChild = p;
      q.push(p);
    }

    else {
      p = tmp->leftChild;

      while (p->rightSib) {
        p = p->rightSib;
      }

      p->rightSib = new LCRS;
      p = p->rightSib;
      p->data = data[cnt];
      p->leftChild = NULL;
      p->rightSib = NULL;
      q.push(p);
    }

    cnt++;
  }

  return root;
}

void inOrder(LCRS *root) {
  if (root == NULL) {
    return;
  }

  inOrder(root->leftChild);
  cout << root->data << " ";
  inOrder(root->rightSib);
}
