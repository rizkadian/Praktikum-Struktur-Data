#include <iostream>
using namespace std;

class treeavl{
	public:
		void viewPostOrder(struct DataPohonAVL *root);
	    void viewInOrder(struct DataPohonAVL *root);
	    void viewPreOrder(struct DataPohonAVL *root);
	private:
		int data, height;
};

struct DataPohonAVL{
	int data;
  	int height;
	DataPohonAVL *kiri;
	DataPohonAVL *kanan;
} *root = NULL;

int height(struct DataPohonAVL *N){
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b){
	return (a > b)? a : b;
}

struct DataPohonAVL* newDataPohonAVL(int data){
	struct DataPohonAVL* node = (struct DataPohonAVL*)malloc(sizeof(struct DataPohonAVL));
	node->data = data;
	node->kiri = NULL;
	node->kanan = NULL;
	node->height = 1;
	return(node);
}

struct DataPohonAVL *rightRotate(struct DataPohonAVL *y){
	struct DataPohonAVL *x = y->kiri;
	struct DataPohonAVL *T2 = x->kanan;

	x->kanan = y;
	y->kiri = T2;

	y->height = max(height(y->kiri), height(y->kanan))+1;
	x->height = max(height(x->kiri), height(x->kanan))+1;

	return x;
}

struct DataPohonAVL *leftRotate(struct DataPohonAVL *x){
	struct DataPohonAVL *y = x->kanan;
	struct DataPohonAVL *T2 = y->kiri;

	y->kiri = x;
	x->kanan = T2;

	x->height = max(height(x->kiri), height(x->kanan))+1;
	y->height = max(height(y->kiri), height(y->kanan))+1;

	return y;
}

int getBalance(struct DataPohonAVL *N){
	if (N == NULL)
		return 0;
	return height(N->kiri) - height(N->kanan);
}

struct DataPohonAVL* insert(struct DataPohonAVL* node, int data){
	if (node == NULL){
		return(newDataPohonAVL(data));
	}if (data < node->data){
		node->kiri = insert(node->kiri, data);
	}else if (data > node->data){
		node->kanan = insert(node->kanan, data);
	}else{
		return node;
  	}
  	
	node->height = 1 + max(height(node->kiri), height(node->kanan));
	int balance = getBalance(node);

	if (balance > 1 && data < node->kiri->data){
		return rightRotate(node);
	}if (balance < -1 && data > node->kanan->data){
		return leftRotate(node);
	}if (balance > 1 && data > node->kiri->data){
		node->kiri = leftRotate(node->kiri);
		return rightRotate(node);
	}if (balance < -1 && data < node->kanan->data){
		node->kanan = rightRotate(node->kanan);
		return leftRotate(node);
	}
	return node;
}

struct DataPohonAVL * minValueDataPohonAVL(struct DataPohonAVL* node){
  	struct DataPohonAVL* currentt = node;
  	while (currentt->kiri != NULL)
    	currentt = currentt->kiri;
  	return currentt;
}

void treeavl::viewPreOrder(struct DataPohonAVL *root){
	if(root != NULL){
		cout << " " << root->data; 
		treeavl::viewPreOrder(root->kiri);
		treeavl::viewPreOrder(root->kanan);
	}
}

void treeavl::viewInOrder(struct DataPohonAVL *root){
	if(root != NULL){
		treeavl::viewInOrder(root->kiri);
		cout << " " << root->data;   
		treeavl::viewInOrder(root->kanan);
	}
}

void treeavl::viewPostOrder(struct DataPohonAVL *root){
	if(root != NULL){
		treeavl::viewPostOrder(root->kiri);
		treeavl::viewPostOrder(root->kanan);
		cout << " " << root->data;   
	}
}

int main(){
	int pilihdata, data;
	treeavl a;
    do {
	    cout << "======================================" << endl;
		cout << "  PROGRAM POHON SETIMBANG (TREE AVL)" << endl;
		cout << "--------------------------------------" << endl;
   		cout << " 1. Tambah Data" << endl;
		cout << " 2. Lihat Data" << endl;
		cout << " 3. Selesai" << endl;
      	cout << "======================================" << endl;
    	cout << " Masukkan Pilihan Anda : ";
      	cin >> pilihdata;
    	switch (pilihdata){
        case 1:	
        	cout << endl;
        	cout << " Masukkan angka : ";
        	cin >> data;
	        root = insert(root, data);
	        cout << endl;
          	break;
        case 2:
        	cout << endl << " InOrder   :"; a.viewInOrder(root);
          	cout << endl << " PreOrder  :"; a.viewPreOrder(root);
          	cout << endl << " PostOrder :"; a.viewPostOrder(root);
          	cout << endl << endl;
          	break;
        case 3:
          	return 0;
        default:
          	cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
          	break;
      }
    } while (pilihdata < 3);
}