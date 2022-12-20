#include <iostream>
#include "lqueue.h"
#include "btnode.h"
#include "xcept.h"
using namespace std;
template <class T>
void Visit(BinaryTreeNode<T> *x) {
	cout << x->data << ' ';
}
template <class T>
void PreOrder(BinaryTreeNode<T> *t) {
	if (t) {
		Visit(t);
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}
template <class T>
void InOrder(BinaryTreeNode<T> *t) {
	if (t) {
		InOrder(t->LeftChild);
		Visit(t);
	InOrder(t->RightChild);
	}
}
template <class T>
void PostOrder(BinaryTreeNode<T> *t) {
	if (t) {
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}
template <class T>
void LevelOrder(BinaryTreeNode<T> *t) {
LinkedQueue<BinaryTreeNode<T>*> Q;

	while (t) {
	Visit(t);
	if (t->LeftChild) Q.Add(t->LeftChild);
	if (t->RightChild) Q.Add(t->RightChild);
	try {Q.Delete(t);}
	catch (OutOfBounds) {return;}
	}
}
int main() {
	BinaryTreeNode<int> x, y, z;
	x.data = 1;
	y.data = 2;
	z.data = 3;
	x.LeftChild = &y;
	x.RightChild = &z;
	y.LeftChild = y.RightChild = z.LeftChild = z.RightChild = 0;
	cout << endl;
	cout << " Kunjungan Inorder : ";
	InOrder(&x);
	cout << endl;
	cout << " Kunjungan Preorder : ";
	PreOrder(&x);
	cout << endl;
	cout << " Kunjungan Postorder : ";
	PostOrder(&x);
	cout << endl;
	cout << " Kunjungan Level order : ";
	LevelOrder(&x);
	cout << endl;
}