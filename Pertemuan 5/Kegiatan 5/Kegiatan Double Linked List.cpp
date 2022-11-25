#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode *next;
	TNode *prev;
};
TNode *head=NULL;
TNode *bantu, *bantu2, *baru;

int isEmpty();
void insertDepan();
void insertBelakang();
void insertTengah();
void cetak();

int isEmpty(){
	if(head == NULL)
		return 1;
	else
		return 0;
}

void insertDepan(){
	int value;
	cout << endl << " Masukkan angka : ";
	cin >> value;  
	baru = new TNode; // pembentukan node baru
	baru->data = value; // pemberian nilai terhadap data baru
	baru->next = NULL; // data pertama harus menunjuk ke NULL
	baru->prev = NULL; // data pertama harus menunjuk ke NULL
	if(isEmpty() == 1) {
		head = baru; // head harus selalu berada di depan
		head->next = NULL;
		head->prev = NULL;
	} else {
		baru->next = head; // node baru dihubungkan ke head
		head->prev = baru;  // node head dihubungkan ke node baru
		head = baru; // head harus selalu berada di depan
	}
	cout << " Data Masuk" << endl;
}

void insertBelakang (){
	baru = new TNode;
	int databaru;
	cout << endl << " Masukkan angka : ";
	cin >> databaru;
	baru->data = databaru;
	baru->next = NULL;
	baru->prev = NULL;
	if(isEmpty()==1){
		head = baru;
		head->next = NULL;
		head->prev = NULL;
	} else {
		bantu = head;
		while(bantu->next != NULL){
			bantu = bantu->next;
		}
		bantu->next = baru;
		baru->prev = bantu;
	}
	cout<<" Data masuk " << endl;
}

  
void insertTengah(){
	int value, cari;
	cout << endl << " Masukkan angka : ";
	cin >> value;
	cout << " Ingin anda sisipkan disebelah : ";
	cin >> cari;
	baru = new TNode; // pembentukan node baru
	baru->data = value;  // pemberian nilai terhadap data baru
	baru->next = NULL; // data pertama harus menunjuk ke NULL
	baru->prev = NULL; // data pertama harus menunjuk ke NULL
	bantu = head;  // bantu diletakan di head dulu
	while(bantu->data != cari) {
		bantu = bantu->next; //menggeser hingga didapat data cari
	}
	bantu2 = bantu->next; // menghubungkan ke node setelah yang dicari
	baru->next = bantu2;  // menghubungkan node baru
	bantu2->prev = baru; 
	bantu->next = baru; // menghubungkan ke node sebelum yang dicari
	baru->prev = bantu;
}

void cetak(){
	TNode *bantu;
	bantu = head; 
	if(isEmpty() == 0) {
		while (bantu != NULL) {
			cout << " " << bantu->data; 
			bantu = bantu->next; 
		}
		cout << endl;
	} else {
		cout << endl << " Data Kosong " << endl; 
	}
}

int main(){
	int pilihan;
	do {
		cetak();
		cout << endl;
		cout << "=============================================" << endl;
		cout << "          PROGRAM DOUBLE LINK LIST" << endl;
		cout << "=============================================" << endl;
		cout << " [1] Tambah Depan\n";
		cout << " [2] Tambah Belakang\n";
		cout << " [3] Sisipkan\n";
		cout << " [4] Selesai\n";
		cout << "=============================================" << endl << endl;
		cout << " Masukkan pilihan anda : ";
		cin >> pilihan;	
		switch (pilihan){
			case 1: 
				insertDepan();
				break;
			case 2: 
				insertBelakang();
				break;
			case 3: 
				insertTengah();
				break;
			case 4: 
				return 0;
		}	
	} while(pilihan!=0);
}
