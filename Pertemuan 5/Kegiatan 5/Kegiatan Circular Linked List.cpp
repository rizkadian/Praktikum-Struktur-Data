#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode *next;
	TNode *prev;
};
TNode *head=NULL;
TNode *baru, *bantu, bantu2;	

int isEmpty();
void insertDepan();
void insertBelakang();
void sisipkan();
void cetak();

int isEmpty(){
	if(head == NULL)
		return 1;
	else
		return 0;
}

void insertDepan(){
	baru = new TNode;
	int value;
	cout << endl << " Masukkan angka : ";
	cin >> value;  
	baru->data = value;
	baru->next = baru;
	baru->prev = baru;
	if(isEmpty() == 1){
		head = baru;
		head->next = head;
		head->prev = head;
	} else {
		bantu = head->prev;
		baru->next = head;
		head->prev = baru;
		head = baru;
		head->prev = bantu;
		bantu->next = head;
	}
	cout << " Data masuk " << endl;
}

void insertBelakang (){
	baru = new TNode;
	int databaru;
	cout << endl << " Masukkan angka : ";
	cin >> databaru;  
	baru->data = databaru;
	baru->next = baru;
	baru->prev = baru;
	if(isEmpty()==1){
		head = baru;
		head->next = head;
		head->prev = head;
	} else {
		bantu = head->prev;
		bantu->next = baru;
		baru->prev = bantu;
		baru->next = head;
		head->prev = baru;
	}
	cout << " Data masuk " << endl;
}

void sisipkan(){
	int value, cari;
	cout << endl << " Masukkan angka : ";
	cin >> value;
	cout << " Ingin anda sisipkan disebelah : ";
	cin >> cari;
	baru = new TNode;
	baru->data = value;
	baru->next = baru;
	bantu = head;
    while(bantu->data != cari)
    bantu = bantu->next;
    baru->next = bantu->next;
    bantu->next = baru; 
}

void cetak(){
	bantu = head;
	if(isEmpty() == 0){
		do {
			cout << " " << bantu->data;
			bantu = bantu->next;
		} while(bantu != head);
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
		cout << "      PROGRAM CIRCULAR DOUBLE LINK LIST" << endl;
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
				sisipkan();
				break;
			case 4: 
				return 0;
		}	
	} while(pilihan!=0);
}
