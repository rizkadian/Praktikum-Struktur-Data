#include<iostream>
using namespace std;

struct dataktp{
	string nama[50], rt[50], rw[50], tanggal[50], bulan[50], tahun[50], tempat[50], alamat[50], jeniskelamin[50], desa[50];	
	string agama[50], status[50], pekerjaan[50], kewarganegaraan[50], kecamatan[50], darah[50], nik[50];
	int jumlah;
};

class ktp{
	public:
		void input();
		void cetak();
	private:
		dataktp data;
};

void ktp::input(){
	cout << "===========================================================" << endl;
	cout << "                  MENGINPUTKAN DATA KTP" << endl;
	cout << "===========================================================" << endl;
	cout << " n. MASUKKAN DATA MENGGUNAKAN HURUF KAPITAL DAN SESUAI KK" << endl;
	cout << "-----------------------------------------------------------" << endl << endl;
	cout << "Masukkan jumlah data yang ingin diinputkan : ";
	cin >> data.jumlah;
	for (int i=0; i<data.jumlah; i++){
		cout << endl << " MASUKKAN DATA KE - " << i+1 << endl << endl;
		cout << " NIK                   : ";
		cin >> data.nik[i];
		cin.ignore(260,'\n');
		cout << " NAMA                  : ";
		getline(cin, data.nama[i]);
		cout << " TEMPAT LAHIR          : ";
		getline(cin, data.tempat[i]);
		cout << " TANGGAL LAHIR (01-31) : ";
		getline(cin, data.tanggal[i]);
		cout << " BULAN LAHIR (01-12)   : ";
		getline(cin, data.bulan[i]);
		cout << " TAHUN LAHIR           : ";
		getline(cin, data.tahun[i]);
		cout << " JENIS KELAMIN         : ";
		getline(cin, data.jeniskelamin[i]);
		cout << " GOLONGAN DARAH        : ";
		getline(cin, data.darah[i]);
		cout << " DUSUN                 : ";
		getline(cin, data.alamat[i]);
		cout << " RT                    : ";
		getline(cin, data.rt[i]);
		cout << " RW                    : ";
		getline(cin, data.rw[i]);
		cout << " DESA                  : ";
		getline(cin, data.desa[i]);
		cout << " KECAMATAN             : ";
		getline(cin, data.kecamatan[i]);
		cout << " AGAMA                 : ";
		getline(cin, data.agama[i]);
		cout << " STATUS PERKAWINAN     : ";
		getline(cin, data.status[i]);
		cout << " PEKERJAAN             : ";
		getline(cin, data.pekerjaan[i]);
		cout << " KEWARGANEGARAAN       : ";
		getline(cin, data.kewarganegaraan[i]);
	}
}

void ktp::cetak(){
	for (int i=0; i<data.jumlah; i++){
		cout << endl << " DATA KE - " << i+1 << endl;
		cout << "===========================================================" << endl;
		cout << "                   PROVINSI JAWA TENGAH" << endl;
		cout << "                     KABUPATEN KLATEN" << endl;
		cout << "===========================================================" << endl;
		cout << " NIK               : " << data.nik[i] << endl;
		cout << " Nama              : " << data.nama[i] << endl;
		cout << " Tempat/Tgl Lahir  : " << data.tempat[i] << ", " << data.tanggal[i] << "-" << data.bulan[i] << "-" << data.tahun[i] << endl;
		cout << " Jenis Kelamin     : " << data.jeniskelamin[i] << "         Gol. Darah: " << data.darah[i] << endl;
		cout << " Alamat            : " << data.alamat[i] << endl;
		cout << "     RT/RW         : " << data.rt[i] << "/" << data.rw[i] << endl;
		cout << "     Kel/Desa      : " << data.desa[i] << endl;
		cout << "     Kecamatan     : " << data.kecamatan[i] << endl;     
		cout << " Agama             : " << data.agama[i] << endl;
		cout << " Status Perkawinan : " << data.status[i] << endl;
		cout << " Pekerjaan         : " << data.pekerjaan[i] << endl;
		cout << " Kewarganegaraan   : " << data.kewarganegaraan[i] << endl;
		cout << " Berlaku Hingga    : SEUMUR HIDUP" << endl;
		cout << "===========================================================" << endl;
	}
}

int main(){
	ktp a;
	a.input();
	a.cetak();
}