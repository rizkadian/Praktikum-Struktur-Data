#include <iostream>
#define MAX 100
using namespace std;

struct dataktp{
	char nik[50], nama[50], tempatlahir[50], tanggallahir[50], bulanlahir[50], tahunlahir[50], jeniskelamin[50];
	char darah[50], alamat[50], rt[50], rw[50], desa[50], kecamatan[50], agama[50], status[50], pekerjaan[50], kewarganegaraan[50];
}; 
struct dataktp ktp;
struct dataktp stack[MAX];

class postest{
	public:
		void init(void);
		void push(struct dataktp ktp);
		void baca(void);
	private:
		struct dataktp entridata(void);
		struct dataktp pop(void);
		struct dataktp info;
};
int full(void);
int empty(void);
void display(struct dataktp ktp);
int i, top, jawab;

struct dataktp pop(void){
	if(empty() != true) {
		ktp = stack[top];
		top--;
		display(ktp);
		return ktp;
	} 
	else {
		cout << " Stack Kosong" << endl;	
	}
}

int full(void){
	if(top == MAX-1) 
		return(true);
	else 
		return(false);
}

int empty(void){
	if(top == -1) 
		return(true);
	else 
		return(false);
}

void postest::init(void){
	top = -1;
}

void postest::push(struct dataktp ktp){
	if(full() != true) {
		top++;
		stack[top] = ktp;
	} 
	else {
		cout << " Stack Sudah Penuh" << endl;
	} 
}

void postest::baca(void){
	cout << endl << " Isi Data Stack" << endl;
	if(top>-1) {
		for(i=0; i<=top; i++){
			cout << endl << "-----------------------------------------------------------" << endl;
			cout << "                   PROVINSI JAWA TENGAH" << endl;
			cout << "                     KABUPATEN KLATEN" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << " NIK               : " << stack[i].nik << endl;
			cout << " Nama              : " << stack[i].nama << endl;
			cout << " Tempat/Tgl Lahir  : " << stack[i].tempatlahir << ", " << stack[i].tanggallahir << "-" << stack[i].bulanlahir << "-" << stack[i].tahunlahir << endl; 
			cout << " Jenis Kelamin     : " << stack[i].jeniskelamin << "         Gol. Darah: " << stack[i].darah << endl;
			cout << " Alamat            : " << stack[i].alamat << endl;
			cout << "     RT/RW         : " << stack[i].rt << "/" << stack[i].rw << endl;
			cout << "     Kel/Desa      : " << stack[i].desa << endl;
			cout << "     Kecamatan     : " << stack[i].kecamatan << endl;     
			cout << " Agama             : " << stack[i].agama << endl;
			cout << " Status Perkawinan : " << stack[i].status << endl;
			cout << " Pekerjaan         : " << stack[i].pekerjaan << endl;
			cout << " Kewarganegaraan   : " << stack[i].kewarganegaraan << endl;
			cout << " Berlaku Hingga    : SEUMUR HIDUP" << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
	} 
	else {
		cout << endl << " Data Kosong" << endl;
	}
}

struct dataktp entridata(void){
	struct dataktp ktp;
	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "  MENGINPUT DATA KTP SESUAI KARTU KELUARGA (HURUF KAPITAL)" << endl;
	cout << "-----------------------------------------------------------" << endl;
   	cout << " NIK                   : "; cin >> ktp.nik;
    cout << " NAMA                  : "; cin >> ktp.nama;
    cout << " TEMPAT LAHIR          : "; cin >> ktp.tempatlahir;
    cout << " TANGGAL LAHIR (01-31) : "; cin >> ktp.tanggallahir;
    cout << " BULAN LAHIR (01-12)   : "; cin >> ktp.bulanlahir;
    cout << " TAHUN LAHIR           : "; cin >> ktp.tahunlahir;
    cout << " JENIS KELAMIN         : "; cin >> ktp.jeniskelamin;
    cout << " GOLONGAN DARAH        : "; cin >> ktp.darah;
    cout << " DUKUH                 : "; cin >> ktp.alamat;
    cout << " RT                    : "; cin >> ktp.rt;
    cout << " RW                    : "; cin >> ktp.rw;
    cout << " DESA                  : "; cin >> ktp.desa;
    cout << " KECAMATAN             : "; cin >> ktp.kecamatan;
    cout << " AGAMA                 : "; cin >> ktp.agama;
    cout << " STATUS                : "; cin >> ktp.status;
    cout << " PEKERJAAN             : "; cin >> ktp.pekerjaan;
    cout << " KEWARGANEGARAAN       : "; cin >> ktp.kewarganegaraan;
	cout << "-----------------------------------------------------------" << endl;
	return(ktp);
}

void display(struct dataktp ktp){
	cout << "-----------------------------------------------------------" << endl;
	cout << "                   PROVINSI JAWA TENGAH" << endl;
	cout << "                     KABUPATEN KLATEN" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << " NIK               : " << ktp.nik << endl;
	cout << " Nama              : " << ktp.nama << endl;
	cout << " Tempat/Tgl Lahir  : " << ktp.tempatlahir << ", " << ktp.tanggallahir << "-" << ktp.bulanlahir << "-" << ktp.tahunlahir << endl; 
	cout << " Jenis Kelamin     : " << ktp.jeniskelamin << "         Gol. Darah: " << ktp.darah << endl;
	cout << " Alamat            : " << ktp.alamat << endl;
	cout << "     RT/RW         : " << ktp.rt << "/" << ktp.rw << endl;
	cout << "     Kel/Desa      : " << ktp.desa << endl;
	cout << "     Kecamatan     : " << ktp.kecamatan << endl;     
	cout << " Agama             : " << ktp.agama << endl;
	cout << " Status Perkawinan : " << ktp.status << endl;
	cout << " Pekerjaan         : " << ktp.pekerjaan << endl;
	cout << " Kewarganegaraan   : " << ktp.kewarganegaraan << endl;
	cout << " Berlaku Hingga    : SEUMUR HIDUP" << endl;
	cout << "-----------------------------------------------------------" << endl;
}

int main(){
	postest a;
	int pilih;
	a.init();
	do {
		cout << "===========================================================" << endl;
		cout << "       MENU MENGINPUT DATA KTP - ARRAY STACK DINAMIS" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << " 1. Tambah Data" << endl;
		cout << " 2. Hapus Data Awal" << endl;
		cout << " 3. Lihat Data" << endl;
		cout << " 4. Hapus Semua Data" << endl;
		cout << " 5. Selesai" << endl;
		cout << "===========================================================" << endl << endl;
		cout << " Masukkan Pilihan Anda : ";
		cin >> pilih;
		switch(pilih){
			case 1 : 
				ktp = entridata();
				a.push(ktp);
				break;
			case 2 : 
				cout << endl << " Data Yang Dihapus" << endl << endl;
				ktp = pop();
				break;
			case 3 : 
				a.baca();
				break;
			case 4 : 
				a.init();
				cout << endl << " Data Telah Dikosongkan" << endl;
				break;
			case 5 :
				return 0;
			default : 
				cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
				break;
		}
		cout << endl;
	} while(pilih != 5);
	return 0;
}