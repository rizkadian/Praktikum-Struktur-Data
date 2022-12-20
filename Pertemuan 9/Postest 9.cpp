#include <iostream>
using namespace std;

class BinaryTree{
	private:
		struct nodeTree{
			nodeTree* kiri;
			nodeTree* kanan;
			char data;
		};
		nodeTree* akar;
	public:
		BinaryTree(){
			akar = NULL;
		}
		bool isEmpty() const {
			return akar==NULL; 
		}
		void CetakInorder();
		void inorder(nodeTree*);
		void CetakPreorder();
		void preorder(nodeTree*);
		void CetakPostorder();
		void postorder(nodeTree*);
		void input(char);
};

void BinaryTree::input(char d){
	nodeTree* t = new nodeTree;
	nodeTree* parent;
	t->data = d;
	t->kiri = NULL;
	t->kanan = NULL;
	parent = NULL;
	
	if(isEmpty()) akar = t;
	else{
		nodeTree* cur;
		cur = akar;
	while(cur){
		parent = cur;
		if(t->data > cur->data) cur = cur->kanan;
		else cur = cur->kiri;
	}

	if(t->data < parent->data)
		parent->kiri = t;
		else
		parent->kanan = t;
	}
}

void BinaryTree::CetakInorder(){
	inorder(akar);
}

void BinaryTree::inorder(nodeTree* p){
	if(p != NULL){
		inorder(p->kiri);
		cout << " " << p->data << " ";
		inorder(p->kanan);
	}
}

void BinaryTree::CetakPostorder(){
	postorder(akar);
}

void BinaryTree::postorder(nodeTree* p){
	if(p != NULL){
		cout << " " << p->data << " ";
		postorder(p->kiri);
		postorder(p->kanan);
	} else return;
}

void BinaryTree::CetakPreorder(){
	preorder(akar);
}

void BinaryTree::preorder(nodeTree* p){
	if(p != NULL){
		preorder(p->kiri);
		preorder(p->kanan);
		cout << " " << p->data << " ";
	} else return;
}

int main(){
	BinaryTree bt;
	char data;
	int i = 1, batas = 12;
	cout << " !! MASUKKAN DATA POHON !! " << endl << endl;
	while(i<=batas){
		cout << " Data ke - [" << i << "] : ";
		cin >> data;
		bt.input(data);
		i++;
	}
	cout << endl;
	cout << " In-Order   : ";
	bt.CetakInorder();
	cout << endl << endl;
	cout << " Post-Order : ";
	bt.CetakPostorder();
	cout << endl << endl;
	cout << " Pre-Order  : ";
	bt.CetakPreorder();
	cout << endl;
	return 0;
}