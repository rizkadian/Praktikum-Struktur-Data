#include <iostream>
#include <fstream>
using namespace std;

struct DataSingle{
	string tujuan1;
	DataSingle *next1;
}; 
DataSingle *head1, *tail1, *cur1, *newNode1, *del1;

struct DataDouble{
    string tujuan2;
    DataDouble *prev2;
    DataDouble *next2;
}; 
DataDouble *head2, *tail2, *cur2, *newNode2, *del2;

struct DataCircular{
	string tujuan3;
	DataCircular *prev3;
	DataCircular *next3;
}; 
DataCircular *head3, *tail3, *cur3, *newNode3, *del3, *baru3;

class kereta{ 
	public:
		//materi 4 :: Single linked list 
		void createDataSingle(string tujuan1);
		void tambahAwalSingle(string tujuan1);
		void deleteAwalSingle();
		void printDataSingle();
		//materi 5 :: Double linked list & Circular Double linked list
		void createDataDouble(string tujuan2);
		void tambahAwalDouble(string tujuan2);
		void tambahAkhirDouble(string tujuan2);
		void deleteAkhirDouble();
		void printDataDouble();
		void createDataCircular(string tujuan3);
		void tambahAwalCircular(string tujuan3);
		void tambahAkhirCircular(string tujuan3);
		void deleteAkhirCircular();
		void printDataCircular();	
		//materi 1 :: Class dan Rekursif
		int rekursif(int a, int b);
		void login();
		void tujuann(); 
		void kelass();
		void identitas();	
		void pembayaran();	
		void cetak();
	private:
		int pil, tujuan, pilihan, pilharga, jumlah, penumpang, harga;
		int saldo, tagpem, tagpem1, a, b, haripem, haritib, tanggalpem;
		string username, password, tuj, namapem,  lanjut;
		string alamatpem, teleponpem, bulanpem, tahunpem, kelas;
		string nampen[50], idpen[50]; //materi 3 :: Array Dinamis
};
void kereta::createDataSingle(string tujuan1){
	head1 = new DataSingle();
	head1->tujuan1 = tujuan1;	
	head1->next1 = NULL;
	tail1 = head1;
}
void kereta::tambahAwalSingle(string tujuan1){
	newNode1 = new DataSingle();
	newNode1->tujuan1 = tujuan1;
	newNode1->next1 = head1;
	head1 = newNode1;
}
void kereta::deleteAwalSingle(){
    del1 = head1;
    head1 = head1->next1;
    delete del1;
}
void kereta::printDataSingle(){
	cur1 = head1;
	while(cur1 != NULL){
		cout << "         " << cur1->tujuan1;
		cur1 = cur1->next1;		
	}
}
void kereta::createDataDouble(string tujuan2){
    head2 = new DataDouble();
    head2->tujuan2 = tujuan2;
    head2->prev2 = NULL;
    head2->next2 = NULL;
    tail2 = head2;
}
void kereta::tambahAwalDouble(string tujuan2){
    newNode2 = new DataDouble();
	newNode2->tujuan2 = tujuan2;
	newNode2->prev2 = NULL;
    newNode2->next2 = head2;
    head2->prev2 = newNode2;
    head2 = newNode2;
}
void kereta::tambahAkhirDouble(string tujuan2){
    newNode2 = new DataDouble();
    newNode2 -> tujuan2 = tujuan2;
    newNode2 -> prev2 = tail2;
    newNode2-> next2 = NULL;
    tail2->next2 = newNode2;
    tail2 = newNode2;
}
void kereta::deleteAkhirDouble(){
    del2 = tail2;
    tail2 = tail2->prev2;
    tail2->next2 = NULL;
    delete del2;
}
void kereta::printDataDouble(){
	cur2 = head2;
	while(cur2 != NULL){
		cout << "         " << cur2->tujuan2;
		cur2 = cur2->next2;		
	}
}
void kereta::createDataCircular(string tujuan3){
    head3 = new DataCircular();
	head3->tujuan3 = tujuan3;
	head3->prev3 = head3;
	head3->next3 = head3;
	tail3 = head3;
}
void kereta::tambahAwalCircular(string tujuan3){
	newNode3 = new DataCircular();
    newNode3->tujuan3 = tujuan3;
    newNode3->prev3 = tail3;
    newNode3->next3 = head3;
    head3->prev3 = newNode3;
    tail3->next3 = newNode3;
	head3 = newNode3;
}
void kereta::tambahAkhirCircular(string tujuan3){
	newNode3 = new DataCircular();
	newNode3->tujuan3 = tujuan3;
    newNode3->prev3 = tail3;
    newNode3->next3 = head3;
    tail3->next3 = newNode3;
    head3->prev3 = newNode3;
    tail3 = newNode3;
}
void kereta::deleteAkhirCircular(){
	del3 = tail3;
    tail3 = tail3->prev3;
   	tail3->next3 = head3;
   	head3->prev3 = tail3;
   	delete del3;
}
void kereta::printDataCircular(){
	cur3 = head3;
    while (cur3->next3 != head3){
		cout << cur3->tujuan3 << endl;
    	cur3 = cur3->next3;
    }
}
int kereta::rekursif(int a, int b){
	if (b==1)
		return a;
	else
		return a+kereta::rekursif(a, b-1);		
}
void kereta::login(){
	cout << "====================================================" << endl;
  	cout << "     PROGRAM PEMESANAN TIKET KERETA DI SEMARANG" << endl;
  	cout << "====================================================" << endl;
	cout << "Silahkan Login Ke Akun Anda" << endl;
  	cout << " Username  : "; 
  	cin >> username;
  	cout << " Password  : "; 
  	cin >> password;
  	cout << endl;
}
void kereta::tujuann(){
	kereta::createDataCircular("----------------------------------------------------");
  	kereta::tambahAwalCircular("               TUJUAN KEBERANGKATAN");
  	kereta::tambahAwalCircular("====================================================");
  	kereta::deleteAkhirCircular();
  	kereta::tambahAkhirCircular("----------------------------------------------------");
  	kereta::tambahAkhirCircular("----------------------------------------------------");
	kereta::printDataCircular();
	kereta::createDataSingle(" 2. Surabaya"); 
	kereta::tambahAwalSingle(" 1. Jakarta"); 	
	kereta::tambahAwalSingle(" 2. Surabaya"); 
	kereta::deleteAwalSingle(); 
	kereta::printDataSingle();
	cout << endl;
	kereta::createDataDouble(" 4. Yogyakarta");
	kereta::tambahAwalDouble(" 3. Bandung");
	kereta::tambahAkhirDouble(" 4. Yogyakarta");
	kereta::deleteAkhirDouble();
	kereta::printDataDouble();
	cout << endl;
	cout << "====================================================" << endl;
	cout << " Pilih Tujuan Keberangkatan (1-4) : ";
	cin >> tujuan;
	cout << endl;
}
void kereta::kelass(){
	string pilkelas[4] = {"Ekonomi", "Eksekutif", "Bisnis"}; //materi 2 :: Array Statis
	if (tujuan==1){
		tuj = "Jakarta";
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
		tuj = "Surabaya";
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
	cout << "Masukkan Nama Pemesan : ";
	getline(cin, namapem);
	cout << "Masukkan Alamat Pemesan : ";
	getline(cin, alamatpem);
	cout << "Masukkan Telepon Pemesan : ";
	cin >> teleponpem;
	cout << "Masukkan Tanggal Pemesanan (01-31) : ";
	cin >> tanggalpem;
	cout << "Masukkan Bulan Pemesanan (01-12) : ";
	cin >> bulanpem;
	cout << "Masukkan Tahun Pemesanan : ";
	cin >> tahunpem;
	cout << endl;
	cout << "====================================================" << endl;
	cout << "                   DATA PENUMPANG" << endl;
	cout << "====================================================" << endl;
	cout << "Masukkan Jumlah Penumpang : ";
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
	cout << "     BINRIZDA        Semarang      " << tuj << "     " << kelas << endl;
	cout << "                    " << tanggalpem+1 << "-" << bulanpem << "-";
	cout << tahunpem << "     " << tanggalpem+2 << "-" << bulanpem << "-" << tahunpem << endl << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|        Nama Penumpang         |           NO ID            |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int i = 0; i < jumlah; i++) {
		cout << "         " << nampen[i] << "                  "<< idpen[i] << endl;
	}
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|                      Detail Transaksi                      |" << endl;
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
	if(lanjut=="y"||lanjut=="Y"){
		cout << " Masukkan Saldo Anda : ";
		cin >> saldo;
		if(saldo>=kereta::rekursif(pilharga, jumlah)){
			cout << " Sisa Saldo Anda : " << saldo-kereta::rekursif(pilharga, jumlah) << endl << endl;
    		cout << "==============================================================" << endl;
			cout << "                     DETAIL TIKET KERETA" << endl;
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
			cout << "     BINRIZDA        Semarang      " << tuj << "     " << kelas << endl;
			cout << "                    " << tanggalpem+1 << "-" << bulanpem << "-";
			cout << tahunpem << "     " << tanggalpem+2 << "-" << bulanpem << "-" << tahunpem << endl << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "|        Nama Penumpang         |           NO ID            |" << endl;
			cout << "--------------------------------------------------------------" << endl;
			for (int i=0; i<jumlah; i++) {
				cout << "         " << nampen[i] << "                  "<< idpen[i] << endl;
			}
			cout << "==============================================================" << endl;
			
			ofstream file("tiketkereta.txt");
			if(!file.is_open()){
				cout << " Tidak Bisa Membuka File." << endl;
			}else{
				file << "==============================================================" << endl;
				file << "                       DETAIL TRANSAKSI                       " << endl;
				file << "==============================================================" << endl;
				file << " Jumlah Penumpang                              = " << jumlah << " Penumpang" << endl;
				file << " Kelas                                         = " << kelas << endl;
				file << " Harga                                         = " << pilharga << endl;
				file << "--------------------------------------------------------------" << endl;
				file << " Total Bayar                                   = " << kereta::rekursif(pilharga, jumlah) << endl;
				file << "==============================================================" << endl << endl;
				file << "Tiket Kereta" << endl << endl;
				file << "==============================================================" << endl;
				file << "                     DETAIL TIKET KERETA" << endl;
				file << "==============================================================" << endl;
				file << "--------------------------------------------------------------" << endl;
				file << "|                        Data Pemesan                        |" << endl;
				file << "--------------------------------------------------------------" << endl;
				file << " Nama              = " << namapem << endl;
				file << " Alamat            = " << alamatpem << endl;
				file << " Telepon           = " << teleponpem << endl;
				file << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
				file << endl;
				file << "--------------------------------------------------------------" << endl;
				file << "|  Nama  Kereta  |   Berangkat   |    Tiba    |    Kelas     |" << endl;
				file << "--------------------------------------------------------------" << endl;
				file << "     BINRIZDA        Semarang      " << tuj << "     " << kelas << endl;
				file << "                    " << tanggalpem+1 << "-" << bulanpem << "-";
				file << tahunpem << "     " << tanggalpem+2 << "-" << bulanpem << "-" << tahunpem << endl;
				file << endl;
				file << "--------------------------------------------------------------" << endl;
				file << "|        Nama Penumpang         |           NO ID            |" << endl;
				file << "--------------------------------------------------------------" << endl;
				for (int i=0; i<jumlah; i++) {
					file << "         " << nampen[i] << "                  "<< idpen[i] << endl;
				}
				file << "==============================================================" << endl;
				file << endl;
				for (int i=0; i<jumlah; i++) {
					file << "Tiket Penumpang Ke - " << i+1 << endl;
					file << endl;
					file << "==============================================================" << endl;
					file << " KERETA API                                     BOARDING PASS" << endl;
					file << "--------------------------------------------------------------" << endl;
					file << " Nama / Name                    Kodebooking / Bookingcode" << endl;
					file << " " << nampen[i] << "                 0000" << i+1 << endl;
					file << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
					file << " " << idpen[i] << "                     " << kelas << endl;
					file << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
					file << " BINRIZDA                       0000" << i+1 << endl;
					file << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
					file << " Semarang                       " << tuj << endl;
					file << " " << tanggalpem+1 << "-" << bulanpem << "-" << tahunpem;
					file << "                     " << tanggalpem+2 << "-" << bulanpem << "-" << tahunpem << endl;
					file << "--------------------------------------------------------------" << endl;
					file << "                              Check In At Semarang ";
					file << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
					file << "==============================================================" << endl;
					file << endl;
				}
			}
			cout << endl << "--------------------- TRANSAKSI BERHASIL ---------------------" << endl << endl;
		}else{
			cout << endl << " Maaf, Saldo Anda Tidak Mencukupi. " << endl;
		}		
	}else{
		cout << endl << "-------------------- PEMESANAN DIBATALKAN --------------------" <<endl;
	}
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