#include<iostream>
using namespace std;

struct dataktp{
	string nama, rt, rw, tanggal, bulan, tahun, tempat, alamat, jeniskelamin, desa, kecamatan, darah, nik;	
};

class ktp{
	public:
		void input();
		void cetak();
	private:
		dataktp data;
		string agama[6]={"ISLAM", "KRISTEN", "KATOLIK", "HINDU", "BUDHA"};
		string status[3]={"KAWIN", "BELUM KAWIN"};
		string pekerjaan[6]={"PNS", "PEGAWAI NEGERI", "SWASTA", "BUMN", "PELAJAR/MAHASISWA"};
		string kewarganegaraan[3]={"WNI", "WNA"};
		int pilihanagama, pilihanstatus, pilihanpekerjaan, pilihankewarganegaraan;
};

void ktp::input(){
	cout << "===========================================================" << endl;
	cout << "                  MENGINPUTKAN DATA DIRI" << endl;
	cout << "===========================================================" << endl;
	cout << " n. MASUKKAN DATA MENGGUNAKAN HURUF KAPITAL DAN SESUAI KK" << endl;
	cout << "-----------------------------------------------------------" << endl << endl;
	cout << " NIK               : ";
	cin >> data.nik;
	cin.ignore(260,'\n');
	cout << " NAMA              : ";
	getline(cin, data.nama);
	cout << " TEMPAT LAHIR      : ";
	getline(cin, data.tempat);
	cout << " TANGGAL LAHIR     : ";
	getline(cin, data.tanggal);
	cout << " BULAN LAHIR       : ";
	getline(cin, data.bulan);
	cout << " TAHUN LAHIR       : ";
	getline(cin, data.tahun);
	cout << " JENIS KELAMIN     : ";
	getline(cin, data.jeniskelamin);
	cout << " GOLONGAN DARAH    : ";
	getline(cin, data.darah);
	cout << " DUSUN             : ";
	getline(cin, data.alamat);
	cout << " RT                : ";
	getline(cin, data.rt);
	cout << " RW                : ";
	getline(cin, data.rw);
	cout << " DESA              : ";
	getline(cin, data.desa);
	cout << " KECAMATAN         : ";
	getline(cin, data.kecamatan);
	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "  [1] ISLAM            [2] KRISTEN           [3] KATOLIK" << endl;   
	cout << "  [4] HINDU            [5] BUDHA" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << " Pilih agama anda sesuai KK (1-5) : ";
	cin >> pilihanagama;
	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "  [1] KAWIN            [2] BELUM KAWIN" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << " Pilih status perkawinan anda sesuai KK (1-2) : ";
	cin >> pilihanstatus;
	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "  [1] PNS          [2] PEGAWAI NEGERI         [3] SWASTA" << endl;   
	cout << "  [4] BUMN         [5] PELAJAR/MAHASISWA" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << " Pilih pekerjaan anda sesuai KK (1-5) : ";
	cin >> pilihanpekerjaan;
	cout << endl;   
	cout << "-----------------------------------------------------------" << endl;
	cout << "  [1] WNI              [2] WNA" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << " Pilih kewarganegaraan anda sesuai KK (1-2) : ";
	cin >> pilihankewarganegaraan;
	cout << endl;
}

void ktp::cetak(){
	cout << "===========================================================" << endl;
	cout << "                   PROVINSI JAWA TENGAH" << endl;
	cout << "                     KABUPATEN KLATEN" << endl;
	cout << "===========================================================" << endl;
	cout << " NIK               : " << data.nik << endl;
	cout << " Nama              : " << data.nama << endl;
	cout << " Tempat/Tgl Lahir  : " << data.tempat << ", " << data.tanggal << "-" << data.bulan << "-" << data.tahun << endl;
	cout << " Jenis Kelamin     : " << data.jeniskelamin << "         Gol. Darah: " << data.darah << endl;
	cout << " Alamat            : " << data.alamat << endl;
	cout << "     RT/RW         : " << data.rt << "/" << data.rw << endl;
	cout << "     Kel/Desa      : " << data.desa << endl;
	cout << "     Kecamatan     : " << data.kecamatan;     
	cout << endl;   
	if(pilihanagama==1){
		cout << " AGAMA             : " << agama[0]; 
	}if(pilihanagama==2){
		cout << " AGAMA             : " << agama[1]; 
	}if(pilihanagama==3){
		cout << " AGAMA             : " << agama[2]; 
	}if(pilihanagama==4){
		cout << " AGAMA             : " << agama[3]; 
	}if(pilihanagama==5){
		cout << " AGAMA             : " << agama[4]; 
	}
	cout << endl;
	if(pilihanstatus==1){
		cout << " STATUS            : " << status[0]; 
	}if(pilihanstatus==2){
		cout << " STATUS            : " << status[1]; 
	}
	cout << endl;
	if(pilihanpekerjaan==1){
		cout << " PEKERJAAN         : " << pekerjaan[0];
	}if(pilihanpekerjaan==2){
		cout << " PEKERJAAN         : " << pekerjaan[1];
	}if(pilihanpekerjaan==3){
		cout << " PEKERJAAN         : " << pekerjaan[2];
	}if(pilihanpekerjaan==4){
		cout << " PEKERJAAN         : " << pekerjaan[3];
	}if(pilihanpekerjaan==5){
		cout << " PEKERJAAN         : " << pekerjaan[4];
	}
	cout << endl;   
	if(pilihankewarganegaraan==1){
		cout << " KEWARGANEGARAAN   : " << kewarganegaraan[0];	
	}if(pilihankewarganegaraan==2){
		cout << " KEWARGANEGARAAN   : " << kewarganegaraan[1];	
	}
	cout << endl;
	cout << " Berlaku Hingga    : SEUMUR HIDUP" << endl;
	cout << "===========================================================" << endl;
}

int main(){
	ktp a;
	a.input();
	a.cetak();
}