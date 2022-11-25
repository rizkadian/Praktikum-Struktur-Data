#include<iostream>
using namespace std;
class kereta{
	public:
		//materi 1 :: class dan rekursif
		void login();
		void tujuann(); 
		void kelass(); 
		void identitas();
		void pembayaran();	
		void cetak();
		int rekursif(int a, int b);	
	private:
		int tujuan, pilihan, pilharga, jumlah, penumpang, harga, saldo, tagpem, tagpem1, a, b;
		string nampen[100], idpen[100]; // materi 3 :: array dinamis
		string username, password, tuj, namapem, alamatpem, teleponpem, tanggalpem, bulanpem, tahunpem, kelas, lanjut;
		string pilkelas[4]={"Ekonomi", "Eksekutif", "Bisnis"}; // materi 2 :: array statis
};
void kereta::login(){
	cout << "====================================================" << endl;
  	cout << "     PROGRAM PEMESANAN TIKET KERETA DI SEMARANG" << endl;
  	cout << "====================================================" << endl;
	cout << "Silahkan Login Ke Akun Anda" << endl;
  	cout << " Username  : "; 
  	cin >> username;
  	cout << " Password  : ";
  	cin >> password;
  	cout << " Saldo     : "; 
  	cin >> saldo;
  	cout << endl;
}
void kereta::tujuann(){
	cout << "====================================================" << endl;
  	cout << "               TUJUAN KEBERANGKATAN" << endl;
  	cout << "====================================================" << endl;
	cout << " 1. Surabaya                       3. Bandung" << endl;
	cout << " 2. Jakarta                        4. Yogyakarta" << endl;
	cout << "====================================================" << endl;
	cout << " Pilih tujuan keberangkatan (1-4) : ";
	cin >> tujuan;
	cout << endl;
}
void kereta::kelass(){
	if (tujuan==1){
		tuj = "Surabaya";
		cout << "====================================================" << endl;
		cout << "|   (1)Ekonomi    |  (2)Eksekutif   |  (3)Bisnis   |" << endl;
		cout << "====================================================" << endl;
		cout << "|   Rp 100.000    |   Rp 300.000    |  Rp 400.000  |" << endl;
		cout << "====================================================" << endl;
		cout << "Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilihan;
		if (pilihan==1) {
			pilharga = 100000; kelas = pilkelas[0];
		} else if (pilihan==2){
			pilharga = 300000; kelas = pilkelas[1];
		} else if (pilihan==3){
			pilharga = 400000; kelas = pilkelas[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
		}
	}
	else if (tujuan==2){
		tuj = "Jakarta";
		cout << "====================================================" << endl;
		cout << "|   (1)Ekonomi    |  (2)Eksekutif   |   (3)Bisnis  |" << endl;
		cout << "====================================================" << endl;
		cout << "|  Rp 90.000      |   Rp 250.000    | Rp 350.000   |" << endl;
		cout << "====================================================" << endl;
		cout << "Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilihan;
		if (pilihan==1) {
			pilharga = 90000; kelas = pilkelas[0];
		} else if (pilihan==2){
			pilharga = 250000; kelas = pilkelas[1];
		} else if (pilihan==3){
			pilharga = 350000; kelas = pilkelas[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
		}
	}
	else if (tujuan==3){
		tuj = "Bandung";
		cout << "====================================================" << endl;
		cout << "|   (1)Ekonomi    |  (2)Eksekutif   |   (3)Bisnis  |" << endl;
		cout << "====================================================" << endl;
		cout << "|  Rp 80.000      |   Rp 200.000    | Rp 300.000   |" << endl;
		cout << "====================================================" << endl;
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilihan;
		if (pilihan==1) {
			pilharga = 80000; kelas = pilkelas[0];
		} else if (pilihan==2){
			pilharga = 200000; kelas = pilkelas[1];
		} else if (pilihan==3){
			pilharga = 300000; kelas = pilkelas[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
		}
	}
	else if (tujuan==4){
		tuj = "Yogyakarta";
		cout << "====================================================" << endl;
		cout << "|   (1)Ekonomi    |  (2)Eksekutif   |   (3)Bisnis  |" << endl;
		cout << "====================================================" << endl;
		cout << "|  Rp 70.000      |   Rp 150.000    | Rp 250.000   |" << endl;
		cout << "====================================================" << endl;
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilihan;
		if (pilihan==1) {
			pilharga = 70000; kelas = pilkelas[0];
		} else if (pilihan==2){
			pilharga = 150000; kelas = pilkelas[1];
		} else if (pilihan==3){
			pilharga = 250000; kelas = pilkelas[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
		}
	}
	else {
		cout << " Maaf, Tujuan Tidak Tersedia. " << endl;
	}
	cout << endl;
}
void kereta::identitas(){
	cout << "====================================================" << endl;
	cout << "                   DATA PEMESANAN" << endl;
	cout << "====================================================" << endl;
	cin.ignore(1,'\n');
	cout << "Masukkan nama pemesan : ";
	getline(cin, namapem);
	cout << "Masukkan alamat pemesan : ";
	getline(cin, alamatpem);
	cout << "Masukkan telepon pemesan : ";
	cin >> teleponpem;
	cout << "Masukkan tanggal pemesanan (01-31) : ";
	cin >> tanggalpem;
	cout << "Masukkan bulan pemesanan (01-12) : ";
	cin >> bulanpem;
	cout << "Masukkan tahun pemesanan : ";
	cin >> tahunpem;
	cout << endl;
	cout << "====================================================" << endl;
	cout << "                   DATA PENUMPANG" << endl;
	cout << "====================================================" << endl;
	cout << "Masukkan jumlah penumpang : ";
	cin >> jumlah;
	cin.ignore(1,'\n');
	for (int i = 0; i < jumlah; i++) {
		cout << "Nama Penumpang Ke - " << i+1 << " : ";
		getline(cin, nampen[i]);
		cout << "ID Penumpang (nim) : ";
		getline(cin, idpen[i]);
	}
	cout << endl;
}
int kereta::rekursif(int a, int b){
	if (b==1)
		return a;
	else
		return a+kereta::rekursif(a, b-1);		
};
void kereta::pembayaran(){
	cout << "==============================================================" << endl;
	cout << "                       DETAIL PEMESANAN" << endl;
	cout << "==============================================================" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|                        Data Pemesan                        |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Nama              = " << namapem << endl;
	cout << " Alamat            = " << alamatpem << endl;
	cout << " Telepon           = " << teleponpem << endl;
	cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|  Nama  Kereta  |   Berangkat   |    Tiba    |    Kelas     |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "     BINRIZDA        Semarang      " << tuj << "     " << kelas << endl << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|        Nama Penumpang         |           NO ID            |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int i = 0; i < jumlah; i++) {
		cout << "         " << nampen[i] << "                    "<< idpen[i] << endl;
	}
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|                      Data Pembayaran                       |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Jumlah Penumpang                              = " << jumlah << " Penumpang" << endl;
	cout << " Kelas                                         = " << kelas << endl;
	cout << " Harga                                         = " << pilharga << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Total Bayar                                   = " << kereta::rekursif(pilharga, jumlah) << endl;
	cout << "==============================================================" << endl;	
	cout << endl;
}
void kereta::cetak(){
	cout << " Melanjutkan Pembayaran (y/n) : ";
	cin >> lanjut;
}
int main(){
	kereta aa;
	aa.login();
	aa.tujuann(); 
	aa.kelass(); 
	aa.identitas();
	aa.pembayaran();
	aa.cetak();
	return 0;
}