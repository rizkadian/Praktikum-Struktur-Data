#include<iostream>
using namespace std;

struct dataktp{
	string nik, nama, tanggallahir, jeniskelamin, darah, alamat, rt, rw, desa, kecamatan, agama, status, pekerjaan, kewarganegaraan;
	dataktp *next;
	dataktp *prev;
}; 

class ktp{
	public:
		void createData(string nik, string nama, string tanggallahir, string jeniskelamin, string darah, string alamat, string rt, string rw, string desa, string kecamatan, string agama, string status, string pekerjaan, string kewarganegaraan);	
		void tambahDepan(string nik, string nama, string tanggallahir, string jeniskelamin, string darah, string alamat, string rt, string rw, string desa, string kecamatan, string agama, string status, string pekerjaan, string kewarganegaraan);
		void hapusDepan();
		void printData();
		void output();
	private:
		dataktp *head, *tail, *cur, *newNode, *hapus, *t;
};

void ktp::createData(string nik, string nama, string tanggallahir, string jeniskelamin, string darah, string alamat, string rt, string rw, string desa, string kecamatan, string agama, string status, string pekerjaan, string kewarganegaraan){
    head = new dataktp();
   	head->nik = nik;
    head->nama = nama;
    head->tanggallahir = tanggallahir;
    head->jeniskelamin = jeniskelamin;
    head->darah = darah;
    head->alamat = alamat;
    head->rt = rt;
    head->rw = rw;
    head->desa = desa;
    head->kecamatan = kecamatan;
    head->agama = agama;
    head->status = status;
    head->pekerjaan = pekerjaan;
    head->kewarganegaraan = kewarganegaraan;
    head->next = NULL;
	tail = head;
}
void ktp::tambahDepan(string nik, string nama, string tanggallahir, string jeniskelamin, string darah, string alamat, string rt, string rw, string desa, string kecamatan, string agama, string status, string pekerjaan, string kewarganegaraan){
	newNode = new dataktp();
    newNode->nik = nik;
    newNode->nama = nama;
	newNode->tanggallahir = tanggallahir;
    newNode->jeniskelamin = jeniskelamin;
    newNode->darah = darah;
    newNode->alamat = alamat;
    newNode->rt = rt;
    newNode->rw = rw;
    newNode->desa = desa;
    newNode->kecamatan = kecamatan;
    newNode->agama = agama;
    newNode->status = status;
    newNode->pekerjaan = pekerjaan;
    newNode->kewarganegaraan = kewarganegaraan;
    newNode->next = head;
    newNode->next = head;
	head = newNode;
}
void ktp::hapusDepan(){
	hapus = head;
	head = head->next;
	delete hapus;
}
void ktp::printData(){
	cur = head;
	while( cur != NULL){
		cout << "===========================================================" << endl;
		cout << "                   PROVINSI JAWA TENGAH" << endl;
		cout << "                     KABUPATEN KLATEN" << endl;
		cout << "===========================================================" << endl;
		cout << " NIK               : " << cur->nik << endl;
		cout << " Nama              : " << cur->nama << endl;
		cout << " Tempat/Tgl Lahir  : " << cur->tanggallahir << endl; 
		cout << " Jenis Kelamin     : " << cur->jeniskelamin << "         Gol. Darah: " << cur->darah << endl;
		cout << " Alamat            : " << cur->alamat << endl;
		cout << "     RT/RW         : " << cur->rt << "/" << cur->rw << endl;
		cout << "     Kel/Desa      : " << cur->desa << endl;
		cout << "     Kecamatan     : " << cur->kecamatan << endl;     
		cout << " Agama             : " << cur->agama << endl;
		cout << " Status Perkawinan : " << cur->status << endl;
		cout << " Pekerjaan         : " << cur->pekerjaan << endl;
		cout << " Kewarganegaraan   : " << cur->kewarganegaraan << endl;
		cout << " Berlaku Hingga    : SEUMUR HIDUP" << endl;
		cout << "===========================================================" << endl;
		cur = cur->next;		
		cout << endl ;
	}
}
void ktp::output(){
	cout << endl << "------------------------- DATA AWAL -----------------------" << endl << endl;
	createData("1111111111111111", "RIZKA DIANRANI", "KLATEN, 28-10-2003", "PEREMPUAN", "A", "CCCCCCCC", "002", "007", "BBBBBBBB", "AAAAAAAAA", "ISLAM", "BELUM KAWIN", "PELAJAR/MAHASISWA", "WNI");
	printData();
	cout << "----------------------- TAMBAH DEPAN ----------------------" << endl << endl;
	tambahDepan("2222222222222222", "NADIA PUSPARANI", "KLATEN, 30-12-2006", "PEREMPUAN", "O", "CCCCCCCC", "002", "007", "BBBBBBBB", "AAAAAAAAA", "ISLAM", "BELUM KAWIN", "PELAJAR/MAHASISWA", "WNI");
	printData();
	cout << "------------------------ HAPUS DEPAN ----------------------" << endl << endl;
	hapusDepan();
	printData();
}

int main(){
	ktp a;
	a.output();
	return 0;
}