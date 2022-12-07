#include <iostream>
using namespace std;

struct dataktp{
    string nik, nama, tempatlahir, tanggallahir, bulanlahir, tahunlahir, jeniskelamin;
	string darah, alamat, rt, rw, desa, kecamatan, agama, status, pekerjaan, kewarganegaraan;
    dataktp *next;
};
dataktp *depan = NULL, *belakang = NULL, *baru, *temp, *temp1;

class ktp{
    public:
	    void tambahQueuePriority();
    	void hapusQueuePriority();
    	void tampilQueuePriority();
    private:
    	string hapus;
};
    
void ktp::tambahQueuePriority() {
    baru = new dataktp(); cin.ignore(1,'\n');
    cout << "-----------------------------------------------------------" << endl;
	cout << "  MENGINPUT DATA KTP SESUAI KARTU KELUARGA (HURUF KAPITAL)" << endl;
	cout << "-----------------------------------------------------------" << endl;
   	cout << " NIK                   : "; getline(cin, baru->nik);
    cout << " NAMA                  : "; getline(cin, baru->nama);
    cout << " TEMPAT LAHIR          : "; getline(cin, baru->tempatlahir);
    cout << " TANGGAL LAHIR (01-31) : "; getline(cin, baru->tanggallahir);
    cout << " BULAN LAHIR (01-12)   : "; getline(cin, baru->bulanlahir);
    cout << " TAHUN LAHIR           : "; getline(cin, baru->tahunlahir);
    cout << " JENIS KELAMIN         : "; getline(cin, baru->jeniskelamin);
    cout << " GOLONGAN DARAH        : "; getline(cin, baru->darah);
    cout << " DUKUH                 : "; getline(cin, baru->alamat);
    cout << " RT                    : "; getline(cin, baru->rt);
    cout << " RW                    : "; getline(cin, baru->rw);
    cout << " DESA                  : "; getline(cin, baru->desa);
    cout << " KECAMATAN             : "; getline(cin, baru->kecamatan);
    cout << " AGAMA                 : "; getline(cin, baru->agama);
    cout << " STATUS                : "; getline(cin, baru->status);
    cout << " PEKERJAAN             : "; getline(cin, baru->pekerjaan);
    cout << " KEWARGANEGARAAN       : "; getline(cin, baru->kewarganegaraan);
	cout << "-----------------------------------------------------------" << endl << endl;
    if (depan == NULL){
        depan = baru;
    } else {
        belakang -> next = baru;
    }
    belakang = baru;
    belakang -> next = depan;
}

void ktp::hapusQueuePriority() {
    temp = depan;
    if ( depan == NULL ) {
        cout << " Queue Kosong" << endl;
    } else {
        if (depan == belakang) {
            hapus = depan -> nama;
            delete (temp);
            depan = NULL;
            belakang = NULL;
        } else {
            hapus = temp -> nama;
            depan = depan -> next;
            belakang -> next = depan;
            delete (temp);
        } 
		cout << " Data dengan nama '" << hapus << "' berhasil dihapus " << endl << endl;
    }
}

void ktp::tampilQueuePriority() {
    temp = depan;
    temp1 = NULL;
    if ( depan == NULL ) {
        cout << " Queue Kosong" << endl;
    } else {
        cout << " Isi Data Queue" << endl << endl;
        while (temp != temp1) {
            cout << "-----------------------------------------------------------" << endl;
			cout << "                   PROVINSI JAWA TENGAH" << endl;
			cout << "                     KABUPATEN KLATEN" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << " NIK               : " << temp->nik << endl;
			cout << " Nama              : " << temp->nama << endl;
			cout << " Tempat/Tgl Lahir  : " << temp->tempatlahir << ", " << temp->tanggallahir;
			cout << "-" << temp->bulanlahir << "-" << temp->tahunlahir << endl; 
			cout << " Jenis Kelamin     : " << temp->jeniskelamin;
			cout << "         Gol. Darah: " << temp->darah << endl;
			cout << " Alamat            : " << temp->alamat << endl;
			cout << "     RT/RW         : " << temp->rt << "/" << temp->rw << endl;
			cout << "     Kel/Desa      : " << temp->desa << endl;
			cout << "     Kecamatan     : " << temp->kecamatan << endl;     
			cout << " Agama             : " << temp->agama << endl;
			cout << " Status Perkawinan : " << temp->status << endl;
			cout << " Pekerjaan         : " << temp->pekerjaan << endl;
			cout << " Kewarganegaraan   : " << temp->kewarganegaraan << endl;
			cout << " Berlaku Hingga    : SEUMUR HIDUP" << endl;
			cout << "-----------------------------------------------------------" << endl << endl;
            if( temp -> next != temp1 ){
                
            }
            temp = temp -> next;
            temp1 = depan;
        }
    }
}

int main(){
    ktp circular;
    int pilih;
    do {
        cout << "===========================================================" << endl;
		cout << "       MENU MENGINPUT DATA KTP - LINKED LIST CIRCULAR" << endl;
		cout << "===========================================================" << endl;
		cout << " 1. Tambah Data (Enqueue)" << endl;
		cout << " 2. Hapus Data (Dequeue)" << endl;
		cout << " 3. Lihat Data" << endl;
      	cout << " 4. Selesai" << endl;
		cout << "===========================================================" << endl;
		cout << " Masukkan pilihan anda : ";
		cin >> pilih;
		cout <<  endl;
        switch (pilih){
            case 1 : circular.tambahQueuePriority(); break;
            case 2 : circular.hapusQueuePriority(); break;
            case 3 : circular.tampilQueuePriority(); break;
            case 4 : break;
            default:
            	cout << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
            	cout << endl;
           		break;
        }
    } while (pilih != 4);
    return 0;
}
