#include<iostream>
using namespace std;

struct dataktp{
	string nik, nama, tempatlahir, tanggallahir, bulanlahir, tahunlahir, jeniskelamin;
	string darah, alamat, rt, rw, desa, kecamatan, agama, status, pekerjaan, kewarganegaraan;
	dataktp *next;
	dataktp *prev;
}; 
dataktp *head = NULL;
dataktp *tail = NULL;
dataktp *baru, *temp;

class ktp{
	public:
		int isEmpty();
		void createData();	
		void tambahDepan();
		void tambahBelakang();
		void hapusDepan();
		void hapusBelakang();
		void printData();
		void output();
	private:
};

int ktp::isEmpty(){
	if(head == NULL)
		return 1;
	else
		return 0;
}

void ktp::createData(){
    baru = new dataktp();
    cout << "-----------------------------------------------------------" << endl;
	cout << "  MENGINPUT DATA KTP SESUAI KARTU KELUARGA (HURUF KAPITAL)" << endl;
	cout << "-----------------------------------------------------------" << endl;
   	cout << " NIK                   : "; cin >> baru->nik;
    cout << " NAMA                  : "; cin >> baru->nama;
    cout << " TEMPAT LAHIR          : "; cin >> baru->tempatlahir;
    cout << " TANGGAL LAHIR (01-31) : "; cin >> baru->tanggallahir;
    cout << " BULAN LAHIR (01-12)   : "; cin >> baru->bulanlahir;
    cout << " TAHUN LAHIR           : "; cin >> baru->tahunlahir;
    cout << " JENIS KELAMIN         : "; cin >> baru->jeniskelamin;
    cout << " GOLONGAN DARAH        : "; cin >> baru->darah;
    cout << " DUKUH                 : "; cin >> baru->alamat;
    cout << " RT                    : "; cin >> baru->rt;
    cout << " RW                    : "; cin >> baru->rw;
    cout << " DESA                  : "; cin >> baru->desa;
    cout << " KECAMATAN             : "; cin >> baru->kecamatan;
    cout << " AGAMA                 : "; cin >> baru->agama;
    cout << " STATUS                : "; cin >> baru->status;
    cout << " PEKERJAAN             : "; cin >> baru->pekerjaan;
    cout << " KEWARGANEGARAAN       : "; cin >> baru->kewarganegaraan;
    baru->prev = baru;
	baru->next = baru;
	cout << "-----------------------------------------------------------" << endl << endl;
}
void ktp::tambahDepan(){
	ktp::createData();
	if(head == NULL) {
 		head=baru;
 		tail=baru;
 	} else {
		baru->next = head;
		head->prev = baru;
		baru->prev = tail;
		tail->next = baru;
		head = baru;
	}
	cout << " Data depan berhasil diinputkan ke sistem!" << endl <<endl;
}
void ktp::tambahBelakang(){
	baru->next = baru;
	baru->prev = baru;
    ktp::createData();
    if(head == NULL)
 	{
		head=baru;
 		tail=baru;
 		head->next = head;
 		head->prev = head;
 		tail->next = tail;
 		tail->prev = tail;
 	}
	else
    {
        tail->next = baru;
 		baru->prev = tail;
 		tail = baru;
 		tail->next = head;
 		head->prev = tail;
	}
	cout << " Data belakang berhasil diinputkan ke sistem!" << endl <<endl;
}
void ktp::hapusDepan(){
	temp = head;
	if (head == NULL){
		cout << " Linked list kosong!" << endl << endl;
	} else {
		if(head == tail){
			head = NULL;
			tail = NULL;
		} else {
			head = head->next;
			head->prev = tail;
			tail->next = head;
		}
		delete temp;
		baru = head;
		cout << " Data depan berhasil dihapus!" << endl << endl;
	}
}
void ktp::hapusBelakang(){
	temp = tail;
	if (head == NULL){
		cout << " Linked list kosong!" << endl << endl;
	} else {
		if(head == tail){
			head = NULL;
			tail = NULL;
		} else {
			tail = tail->prev;
			tail->next = head;
			head->prev = tail;
		}
		delete temp;
		baru = head;
		cout << " Data belakang berhasil dihapus!" << endl << endl;
	}
}
void ktp::printData(){
	temp = head;
	if(head == NULL){
        cout << " Data kosong!" << endl << endl;
    } else {
    	do {
    		cout << "-----------------------------------------------------------" << endl;
			cout << "                   PROVINSI JAWA TENGAH" << endl;
			cout << "                     KABUPATEN KLATEN" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << " NIK               : " << temp->nik << endl;
			cout << " Nama              : " << temp->nama << endl;
			cout << " Tempat/Tgl Lahir  : " << temp->tempatlahir << ", " << temp->tanggallahir << "-" << temp->bulanlahir << "-" << temp->tahunlahir << endl; 
			cout << " Jenis Kelamin     : " << temp->jeniskelamin << "         Gol. Darah: " << temp->darah << endl;
			cout << " Alamat            : " << temp->alamat << endl;
			cout << "     RT/RW         : " << temp->rt << "/" << temp->rw << endl;
			cout << "     Kel/Desa      : " << temp->desa << endl;
			cout << "     Kecamatan     : " << temp->kecamatan << endl;     
			cout << " Agama             : " << temp->agama << endl;
			cout << " Status Perkawinan : " << temp->status << endl;
			cout << " Pekerjaan         : " << temp->pekerjaan << endl;
			cout << " Kewarganegaraan   : " << temp->kewarganegaraan << endl;
			cout << " Berlaku Hingga    : SEUMUR HIDUP" << endl;
			cout << "-----------------------------------------------------------" << endl;
			temp = temp->next;		
			cout << endl ;
		}while(temp != head);
	}
}

int main(){
	ktp a;
	int pilih;
	do {
		cout << "===========================================================" << endl;
		cout << "       MENU MENGINPUT DATA KTP - LINKED LIST CIRCULAR" << endl;
		cout << "===========================================================" << endl;
		cout << " 1. Tambah Depan" << endl;
		cout << " 2. Tambah Belakang" << endl;
		cout << " 3. Hapus Depan" << endl;
		cout << " 4. Hapus Belakang" << endl;
		cout << " 5. Cetak Data" << endl;
		cout << " 6. Selesai" << endl;
		cout << "===========================================================" << endl << endl;
		cout << " Masukkan pilihan anda : ";
		cin >> pilih;
		cout <<  endl;
		switch (pilih){
            case 1:	
				a.tambahDepan();
				break;
			case 2:	
				a.tambahBelakang();
				break;
            case 3:
				a.hapusDepan();
				break;
			case 4:
				a.hapusBelakang();
				break;
            case 5:
				a.printData();
				break;
            case 6:
            	return 0;
                break;
        }    	
	} while (pilih != 7);
	return 0;
}