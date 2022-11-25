#include <iostream>
#include <fstream>
#define MAX 100
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

struct DataStack{
    string x, y, z;
    DataStack *next;
};
DataStack *head=NULL, *bantu;

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
		//materi 6 :: Stack dengan Array
		void pushStack(string x, string y, string z);
		void popStack();
		void printStack();
		void topStack();
		void transaksiStack();
		//materi 1 :: Class dan Rekursif
		int rekursif(int a, int b);
		void kembalimenu();
		void datapemesan();
		void tescovid();
		void login();
		void menu();
		void tujuann(); 
		void kelass();
		void identitas();	
		void pembayaran();	
		void cetak();
	private:
		int piltes, jmlpeng, pilmenu, pil, tujuan, pilihan, pilharga, jumlah, penumpang, harga;
		int pilihdata, saldo, tagpem, tagpem1, a, b, haripem, haritib, tanggalpem;
		string username, password, tuj, namapem,  lanjut, kmenu, nik, nama, jeniskelamin;
		string alamatpem, teleponpem, bulanpem, tahunpem, kelas, j;
		string nampen[50], idpen[50]; //materi 3 :: Array Dinamis
};

bool isEmpty(){
    if(head == NULL){
        return true;
	}
    else {
    	return false;
	}
}

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

void kereta::pushStack(string x, string y, string z){
	DataStack *baru = new DataStack;
	baru->x = x;
	baru->y = y;
	baru->z = z;
	baru->next = head;
	head = baru;
}

void kereta::popStack(){
    if(isEmpty() == false){
    	DataStack *baru = new DataStack;
    	baru = head;
		head = head->next;
		delete baru;
		cout << endl << " Data Telah Dihapus" << endl;
    } 
	else {
        cout << endl << " Stack Kosong " << endl;
    }
}

void kereta::printStack(){
    bantu = head;
    if (isEmpty() == false){
    	cout << endl << " Isi Data Stack" << endl;
        while(bantu != NULL){
        	cout << endl;
        	cout << " NIK           : " << bantu->x << endl;
			cout << " Nama          : " << bantu->y << endl;
			cout << " Jenis Kelamin : " << bantu->z << endl;
            bantu = bantu->next;
		}
    } 
	else {
        cout << endl << " Stack Kosong " << endl;
    }
}

void kereta::topStack(){
    DataStack *top = head;
    cout << endl << " Isi Data Top Stack" << endl << endl;
    cout << " NIK           : " << top->x << endl;
	cout << " Nama          : " << top->y << endl;
	cout << " Jenis Kelamin : " << top->z << endl;
}

void kereta::transaksiStack(){
	bantu = head;
    if (isEmpty() == false){
    	cout << endl <<  "==============================================================" << endl;
		cout << "                       DETAIL PEMESANAN" << endl;
		cout << "==============================================================" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << "|                        Data Pemesan                        |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << " Nama              = " << namapem << endl;
		cout << " Alamat            = " << alamatpem << endl;
		cout << " Telepon           = " << teleponpem << endl;
		cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
    	cout << "-" << tahunpem << endl << endl;
    	cout << "--------------------------------------------------------------" << endl;
		cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		bantu = head;
		while (bantu != NULL){
			cout << "    " << bantu->x << "         ";
   			cout << bantu->y << "          " << bantu->z << endl;
			bantu = bantu->next;
		}
		cout << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << "|                      Detail Transaksi                      |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << " Jumlah Pengunjung                             = ";
		cin >> jmlpeng; 
		cout << " Harga                                         = " << 50000 << endl;
		cout << "--------------------------------------------------------------" << endl;
  		cout << " Total Bayar                                   = " << 50000*jmlpeng << endl;
		cout << "==============================================================" << endl << endl;
    	cout << " Melanjutkan Pembayaran (y/n) : ";
    	cin >> lanjut;
    	if(lanjut=="y"||lanjut=="Y") {
			cout << " Masukkan Saldo Anda : ";
			cin >> saldo;
			if(saldo>=(50000*jmlpeng)) {
				cout << " Sisa Saldo Anda : " << saldo-(50000*jmlpeng) << endl << endl;
				cout << "==============================================================" << endl;
 				cout << "         STRUK PEMESANAN TES GENOSE STASIUN SEMARANG" << endl;
	  			cout << "==============================================================" << endl;
	  			cout << "--------------------------------------------------------------" << endl;
				cout << "|                        Data Pemesan                        |" << endl;
	  			cout << "--------------------------------------------------------------" << endl;
	  			cout << " Nama              = " << namapem << endl;
	  			cout << " Alamat            = " << alamatpem << endl;
				cout << " Telepon           = " << teleponpem << endl;
	  			cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
          		cout << "-" << tahunpem << endl << endl;
    			cout << "--------------------------------------------------------------" << endl;
  				cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
	  			cout << "--------------------------------------------------------------" << endl;
	  			bantu = head;
        		while (bantu != NULL){
					cout << "    " << bantu->x << "         ";
      				cout << bantu->y << "          " << bantu->z << endl;
					bantu = bantu->next;
				}
	  			cout << "==============================================================" << endl;
	  			ofstream file("tesgenose.txt");
				if(!file.is_open()) {
					cout << " Tidak Bisa Membuka File." << endl;
				}
        		else {
					file << "==============================================================" << endl;
	  	  			file << "         STRUK PEMESANAN TES GENOSE STASIUN SEMARANG" << endl;
	  	  			file << "==============================================================" << endl;
		  			file << "--------------------------------------------------------------" << endl;
	  			  	file << "|                        Data Pemesan                        |" << endl;
	  				file << "--------------------------------------------------------------" << endl;
	  	  			file << " Nama              = " << namapem << endl;
	  	  			file << " Alamat            = " << alamatpem << endl;
		  			file << " Telepon           = " << teleponpem << endl;
	  			  	file << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
          			file << "-" << tahunpem << endl << endl;
    	  			file << "--------------------------------------------------------------" << endl;
	  	  			file << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
		  			file << "--------------------------------------------------------------" << endl;
	  			  	bantu = head;
        			while (bantu != NULL){
						file << "    " << bantu->x << "         ";
      					file << bantu->y << "          " << bantu->z << endl;
						bantu = bantu->next;
					}
					file << endl;
	  			  	file << "--------------------------------------------------------------" << endl;
	  				file << "|                      Detail Transaksi                      |" << endl;
	  		  		file << "--------------------------------------------------------------" << endl;
	  			  	file << " Jumlah Pasien                                 = " << jmlpeng << " Pengunjung" << endl;
	  			 	file << " Harga                                         = " << 50000 << endl;
	  		 		file << "--------------------------------------------------------------" << endl;
  			  		file << " Total Bayar                                   = " << 50000*jmlpeng << endl;
       				file << " Bayar                                         = " << saldo << endl;
        	  		file << " Kembali                                       = " << saldo-(50000*jmlpeng) << endl;
	  			  	file << "==============================================================" << endl;
				}
				cout << endl;
				cout << "--------------------- TRANSAKSI  BERHASIL ---------------------" << endl;
				cout << "|                                                             |" << endl;
				cout << "|  Wajib membawa Kartu Keluarga / KTP pada saat tes Covid-19  |" << endl;
				cout << "|                                                             |" << endl;
				cout << "---------------------------------------------------------------" << endl << endl;
				kereta::kembalimenu();	
			}
      		else {
				cout << endl << " Maaf, Saldo Anda Tidak Mencukupi. " << endl << endl;
				kereta::kembalimenu();
			}		
		}
   	 	else {
			cout << endl << "-------------------- PEMESANAN DIBATALKAN --------------------" << endl << endl;
			kereta::kembalimenu();
		}  
		cout << endl;
		}
	else {
        cout << endl << " Stack Kosong " << endl;
    }
}

int kereta::rekursif(int a, int b){
	if (b==1)
		return a;
	else
		return a+kereta::rekursif(a, b-1);		
}

void kereta::kembalimenu(){
	cout << " Kembali Ke Menu Utama (y/n) : ";
    cin >> kmenu;
    if (kmenu=="y" || kmenu=="Y"){
       	kereta::menu();
	} 
	else {
		
	}
}

void kereta::datapemesan() {
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
}

void kereta::login(){
	cout << "====================================================" << endl;
  	cout << "         APLIKASI PROGRAM STASIUN SEMARANG" << endl;
  	cout << "====================================================" << endl;
	cout << "Silahkan Login Ke Akun Anda" << endl;
  	cout << " Username  : "; 
  	cin >> username;
  	cout << " Password  : "; 
  	cin >> password;
  	cout << endl;
}

void kereta::menu(){
	system("cls");
	cout << "====================================================" << endl;
  	cout << "                MENU STASIUN SEMARANG" << endl;
  	cout << "----------------------------------------------------" << endl;
	cout << " 1. Pesan Tiket" << endl;
	cout << " 2. Tes COVID 19" << endl;
	cout << " 3. Keluar" << endl;
  	cout << "====================================================" << endl;
  	cout << " Masukkan Pilihan Menu : ";
  	cin >> pilmenu;
  	cout << endl;
  	switch (pilmenu){ 
  		case 1 : 
      		kereta::tujuann(); 
	    	kereta::kelass(); 
	    	kereta::identitas();
	    	kereta::pembayaran();
	    	kereta::cetak();
    		break; 
    	case 2 : 
      		kereta::tescovid();
    		break;   
    	case 3 :
    		break;
  	}
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
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
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
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
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
			if(!file.is_open()) {
				cout << " Tidak Bisa Membuka File." << endl;
			}
			else {
				file << "==============================================================" << endl;
				file << "                       DETAIL TRANSAKSI                       " << endl;
				file << "==============================================================" << endl;
				file << " Jumlah Penumpang                              = " << jumlah << " Penumpang" << endl;
				file << " Kelas                                         = " << kelas << endl;
				file << " Harga                                         = " << pilharga << endl;
				file << "--------------------------------------------------------------" << endl;
				file << " Total Bayar                                   = " << kereta::rekursif(pilharga, jumlah) << endl;
				file << " Bayar                                         = " << saldo << endl;
				file << " Kembali                                       = " << saldo-kereta::rekursif(pilharga, jumlah) << endl;
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
			cout << endl;
			cout << "--------------------- TRANSAKSI  BERHASIL ---------------------" << endl;
			cout << "|                                                             |" << endl;
			cout << "| Penumpang wajib membawa surat keterangan hasil tes COVID-19 |" << endl;
			cout << "|                                                             |" << endl;
			cout << "---------------------------------------------------------------" << endl << endl;
          	kereta::kembalimenu();
		}
		else {
			cout << endl << " Maaf, Saldo Anda Tidak Mencukupi. " << endl << endl;
			kereta::kembalimenu();
		}		
	}
	else {
		cout << endl << "-------------------- PEMESANAN DIBATALKAN --------------------" << endl << endl;
		kereta::kembalimenu();
	}
}

void kereta::tescovid(){
  	cout << "====================================================" << endl;
  	cout << "         MENU TES COVID-19 STASIUN SEMARANG" << endl;
  	cout << "----------------------------------------------------" << endl;
	cout << " 1. Tes Genose                           Rp. 50.000" << endl;
	cout << " 2. Tes PCR                              Rp. 90.000" << endl;
 	cout << " 3. Tes Antigen                          Rp. 70.000" << endl;
  	cout << "====================================================" << endl;
  	cout << " Masukkan Pilihan Menu : ";
  	cin >> piltes;
  	if (piltes == 1) {
  		cout << endl;
  		cout << "====================================================" << endl;
  		cout << "                     TES GENOSE" << endl;
		cout << "                   DATA PEMESANAN" << endl;
		cout << "====================================================" << endl;
    	kereta::datapemesan();
	  	do {
		  	cout << "====================================================" << endl;
		  	cout << "                  DATA PENGUNJUNG" << endl;
		  	cout << "----------------------------------------------------" << endl;
		  	cout << " 1. Tambah Data (Push)" << endl;
		  	cout << " 2. Hapus Data (Pop)" << endl;
		  	cout << " 3. Lihat Data" << endl;
		  	cout << " 4. Lihat Data Pertama (Top)" << endl;
      		cout << " 5. Selesai" << endl;
		  	cout << "====================================================" << endl;
		  	cout << " Masukkan Pilihan Anda : ";
		  	cin >> pilihdata;
		  	switch(pilihdata){
			  	case 1 : 
				  	cin.ignore(1,'\n');
        			cout << endl;
					cout << " Menginputkan Data Pengunjung" << endl;
  					cout << " NIK           : "; 
  					getline(cin, nik);
  					cout << " Nama          : "; 
  					getline(cin, nama);
  					cout << " Jenis Kelamin : "; 
  					getline(cin, jeniskelamin);
            		kereta::pushStack(nik, nama, jeniskelamin);
				  	break;
			  	case 2 : 
					kereta::popStack();
				  	break;
				case 3 : 
				  	kereta::printStack();
				  	break;
			  	case 4 : 
				  	kereta::topStack();
				  	break;
			  	case 5 :
          			kereta::transaksiStack();
	        		break;
			  	default : 
				  	cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
				  	cout << endl;
          			kereta::kembalimenu();
				  	break;
		  	}
		  	cout << endl;
	  	} while(pilihdata != 5);
  	}
  	else if (piltes == 2) {
  		cout << endl;
  		cout << "====================================================" << endl;
  		cout << "                      TES  PCR" << endl;
		cout << "                   DATA PEMESANAN" << endl;
		cout << "====================================================" << endl;
  	}
  	else if (piltes == 3) {
  		cout << endl;
  		cout << "====================================================" << endl;
  		cout << "                    TES  ANTIGEN" << endl;
		cout << "                   DATA PEMESANAN" << endl;
		cout << "====================================================" << endl;
  	}
  	else {
    	cout << " Menu Tidak Tersedia" << endl;
  	}
}

int main(){
	kereta aa;
	aa.login();
	aa.menu(); 
	return 0;
}