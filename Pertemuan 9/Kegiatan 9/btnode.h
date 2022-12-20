template <class T> class BinaryTree;
template <class T>
class BinaryTreeNode{
	template <class U>
	friend void Visit(BinaryTreeNode<U> *);
	template <class U>
	friend void InOrder(BinaryTreeNode<U> *);
	template <class U>
	friend void PreOrder(BinaryTreeNode<U> *);
	template <class U>
	friend void PostOrder(BinaryTreeNode<U> *);
	template <class U>
	friend void LevelOrder(BinaryTreeNode<U> *);
	friend int main();
public:
	BinaryTreeNode(){
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& e){
		data = e;
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& e, BinaryTreeNode *l, BinaryTreeNode *r){
		data = e;
		LeftChild = l;
		RightChild = r;
	}
private:
	T data;
	BinaryTreeNode<T> *LeftChild, *RightChild;
};