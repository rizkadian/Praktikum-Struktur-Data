#include <iostream>
#include <fstream>
#include <istream>
#define MAX 5

using namespace std;

struct DataStack{
    string nik[MAX], nama[MAX], jeniskelamin[MAX];
};
DataStack stack;

struct DataQueue{
    string nik[MAX], nama[MAX], jeniskelamin[MAX];
};
DataQueue queue;

struct DataPrioritas{
	string prioritas;
	string cek, h, jk;
	struct DataPrioritas *lanjut;
};
DataPrioritas *n, *t, *que, *ptr;

class covid{ 
	public:
		//materi 6 :: Stack dengan Array	
		void pushStack();
		void popStack();
		void printStack();
		int clearStack();
		void transaksiStack();
		//materi 7 :: Queue dengan Array Circular
		bool IsEmpty();
		bool IsFull();
    void tambahQueue();
  	void hapusQueue();
  	void tampilQueue();
    void clearQueue();
  	void transaksiQueue();
  	//materi 8 :: Antrian Berprioritas
    void Antrian();
		void insertAntrian(string z, string y, string x, string u);
		void deleteAntrian();
		void cetakAntrian();
		void transaksiAntrian();
    //lain-lain
		void tescovid();
    void datapemesan();
    void kembalimenu();
    void kembalimenu2();
	private:
		int top = -1;
		int head = -1;
    int tail = -1;
		int piltes, pilmenu, pildata, harga, saldo, tanggalpem, jumlahpeng; 
		string prioritas, kembali, lanjut, nik, nama, jeniskelamin; 
		string namapem, alamatpem, teleponpem, bulanpem, tahunpem; 
};

void covid::pushStack(){
	if(top == MAX-1) {
		cout << endl << " Stack Sudah Penuh" << endl;
  }
	else {
    top++;
    cin.ignore();
    cout << endl;
		cout << " Menginputkan Data Pengunjung" << endl;
  	cout << " NIK           : "; 
  	getline(cin, stack.nik[top]);
  	cout << " Nama          : ";
		getline(cin, stack.nama[top]); 
  	cout << " Jenis Kelamin : "; 
  	getline(cin, stack.jeniskelamin[top]);
  }
}

void covid::popStack(){
  if(top == -1) {
    cout << endl << " Stack Kosong " << endl;
  }
	else {
    cout << endl << " Data Telah Dihapus" << endl;
    top--;
  }
}

int covid::clearStack(){
	cout << endl << " Data Stack Berhasil Dihapus " << endl;
	return top = -1;
}

void covid::printStack(){
	if (top == -1) {
 		cout << endl << " Stack Kosong " << endl;
  }
  else {
    cout << endl << " Isi Data Stack" << endl;
 		for (int i=top; i>=0; i--){
 			cout << endl;
      cout << " NIK           : " << stack.nik[i] << endl;
			cout << " Nama          : " << stack.nama[i] << endl;
			cout << " Jenis Kelamin : " << stack.jeniskelamin[i] << endl;
 		}
  }
}

void covid::transaksiStack(){
	if (top == -1) {
 		cout << endl << " Stack Kosong " << endl;
    cout << endl;
    covid::kembalimenu();
  }
  else {
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
    cout << "-" << tahunpem << endl;
    cout << " Jenis Tes Covid   = Genose" << endl;
    cout << "--------------------------------------------------------------" << endl;
		cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
		cout << "--------------------------------------------------------------" << endl;
 		for (int i=top; i>=0; i--){
 			cout << "    " << stack.nik[i] << "         ";
   		cout << stack.nama[i] << "          " << stack.jeniskelamin[i] << endl;
 		}
		cout << "--------------------------------------------------------------" << endl;
		cout << "|                      Detail Transaksi                      |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << " Jumlah Pengunjung                             = ";
		cin >> jumlahpeng; 
		cout << " Harga                                         = " << 50000 << endl;
		cout << "--------------------------------------------------------------" << endl;
  	cout << " Total Bayar                                   = " << 50000*jumlahpeng << endl;
		cout << "==============================================================" << endl << endl;
    cout << " Melanjutkan Pembayaran (y/n) : ";
    cin >> lanjut;
    if(lanjut=="y"||lanjut=="Y") {
			cout << " Masukkan Saldo Anda : ";
			cin >> saldo;
			if(saldo>=(50000*jumlahpeng)) {
				cout << " Sisa Saldo Anda : " << saldo-(50000*jumlahpeng) << endl << endl;
				cout << "==============================================================" << endl;
 				cout << "         STRUK PEMESANAN TES GENOSE STASIUN YOGYAKARTA" << endl;
	  		cout << "==============================================================" << endl;
	  		cout << "--------------------------------------------------------------" << endl;
				cout << "|                        Data Pemesan                        |" << endl;
	  		cout << "--------------------------------------------------------------" << endl;
	  		cout << " Nama              = " << namapem << endl;
	  		cout << " Alamat            = " << alamatpem << endl;
				cout << " Telepon           = " << teleponpem << endl;
	  		cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
        cout << "-" << tahunpem << endl;
        cout << " Jenis Tes Covid   = Genose" << endl;
    		cout << "--------------------------------------------------------------" << endl;
  			cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
	  		cout << "--------------------------------------------------------------" << endl;
	  		for (int i=top; i>=0; i--){
 					cout << "    " << stack.nik[i] << "         ";
   				cout << stack.nama[i] << "          " << stack.jeniskelamin[i] << endl;
 				}
	  		cout << "==============================================================" << endl;

        ofstream file("invoice covid.txt", ios::app);

				file << "==============================================================" << endl;
	  	  file << "         STRUK PEMESANAN TES GENOSE STASIUN YOGYAKARTA" << endl;
	  	  file << "==============================================================" << endl;
		  	file << "--------------------------------------------------------------" << endl;
	  		file << "|                        Data Pemesan                        |" << endl;
	  		file << "--------------------------------------------------------------" << endl;
	  	  file << " Nama              = " << namapem << endl;
	  	  file << " Alamat            = " << alamatpem << endl;
		  	file << " Telepon           = " << teleponpem << endl;
	  		file << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
        file << "-" << tahunpem << endl;
        file << " Jenis Tes Covid   = Genose" << endl;
    	  file << "--------------------------------------------------------------" << endl;
	  	  file << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
		  	file << "--------------------------------------------------------------" << endl;
	  		for (int i=top; i>=0; i--){
 					file << "    " << stack.nik[i] << "         ";
   				file << stack.nama[i] << "          " << stack.jeniskelamin[i] << endl;
 				}
	  		file << "--------------------------------------------------------------" << endl;
	  	  file << "|                      Detail Transaksi                      |" << endl;
	  		file << "--------------------------------------------------------------" << endl;
	  		file << " Jumlah Pasien                                 = " << jumlahpeng << " Pengunjung" << endl;
	  		file << " Harga                                         = " << 50000 << endl;
	  		file << "--------------------------------------------------------------" << endl;
  			file << " Total Bayar                                   = " << 50000*jumlahpeng << endl;
        file << " Bayar                                         = " << saldo << endl;
        file << " Kembali                                       = " << saldo-(50000*jumlahpeng) << endl;
	  		file << "==============================================================" << endl;
				file << endl;
				cout << endl;
				cout << "--------------------- TRANSAKSI  BERHASIL ---------------------" << endl;
				cout << "|                                                             |" << endl;
				cout << "|  Wajib membawa Kartu Keluarga / KTP pada saat tes Covid-19  |" << endl;
				cout << "|                                                             |" << endl;
				cout << "---------------------------------------------------------------" << endl << endl;
				covid::kembalimenu();	
			}
      else {
				cout << endl << " Maaf, Saldo Anda Tidak Mencukupi. " << endl << endl;
				covid::kembalimenu();
			}		
		}
   	else {
			cout << endl << "-------------------- PEMESANAN DIBATALKAN --------------------" << endl << endl;
			covid::kembalimenu();
		}  
		cout << endl;
	}
}

bool covid::IsEmpty(){ 
  if(tail == -1){
    return true;
  }
  else{
    return false;
  }
}

bool covid::IsFull(){
  if(tail == MAX-1){
    return true;
  }
 	else{
  	return false;
  }
}

void covid::tambahQueue(){
	if (covid::IsEmpty()) {
    head = tail = 0;
  }
	else {
    tail++;
  }
  cin.ignore();
  cout << endl;
	cout << " Menginputkan Data Pengunjung" << endl;
  cout << " NIK           : "; 
  getline(cin, queue.nik[tail]);
  cout << " Nama          : ";
	getline(cin, queue.nama[tail]); 
  cout << " Jenis Kelamin : "; 
  getline(cin, queue.jeniskelamin[tail]);
  cout << endl;
}

void covid::hapusQueue(){
	if(covid::IsEmpty()){
    cout << endl << " Queue Kosong" << endl;
  }
	else {
		cout << endl << " Data Telah Dihapus" << endl;
    for(int a=head; a<tail; a++) {
      queue.nik[a] = queue.nik[a+1];
      queue.nama[a] = queue.nama[a+1];
      queue.jeniskelamin[a] = queue.jeniskelamin[a+1];
    }
    tail--;
    if(tail == -1) {
      head = -1;
    }
  }
}

void covid::clearQueue(){
	cout << endl << " Data Queue Berhasil Dihapus " << endl;
  head = tail = -1;
}

void covid::tampilQueue(){
	if(covid::IsEmpty()){
    cout << endl << " Queue Kosong" << endl << endl;
  }
	else {
		cout << endl << " Isi Data Queue" << endl << endl;
    for(int a=head; a<=tail; a++){
      cout << " NIK           : " << queue.nik[a] << endl;
			cout << " Nama          : " << queue.nama[a] << endl;
			cout << " Jenis Kelamin : " << queue.jeniskelamin[a] << endl;
			cout << endl;
    }
  }
}

void covid::transaksiQueue(){
	if (covid::IsEmpty()){
    cout << endl << " Queue Kosong" << endl;
    cout << endl;
    covid::kembalimenu();
  }
  else {
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
    cout << "-" << tahunpem << endl;
    cout << " Jenis Tes Covid   = PCR" << endl;
  	cout << "--------------------------------------------------------------" << endl;
		cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		for(int a=head; a<=tail; a++){
			cout << "    " << queue.nik[a] << "         ";
      cout << queue.nama[a] << "          " << queue.jeniskelamin[a] << endl;
    }
		cout << "--------------------------------------------------------------" << endl;
		cout << "|                      Detail Transaksi                      |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << " Jumlah Pengunjung                             = ";
		cin >> jumlahpeng; 
		cout << " Harga                                         = " << 90000 << endl;
		cout << "--------------------------------------------------------------" << endl;
  	cout << " Total Bayar                                   = " << 90000*jumlahpeng << endl;
		cout << "==============================================================" << endl << endl;
    cout << " Melanjutkan Pembayaran (y/n) : ";
    cin >> lanjut;
		if(lanjut=="y"||lanjut=="Y") {
			cout << " Masukkan Saldo Anda : ";
			cin >> saldo;
			if(saldo>=(90000*jumlahpeng)) {
				cout << " Sisa Saldo Anda : " << saldo-(90000*jumlahpeng) << endl << endl;
				cout << "==============================================================" << endl;
	  		cout << "          STRUK PEMESANAN TES PCR STASIUN YOGYAKARTA" << endl;
	  		cout << "==============================================================" << endl;
	  		cout << "--------------------------------------------------------------" << endl;
				cout << "|                        Data Pemesan                        |" << endl;
  			cout << "--------------------------------------------------------------" << endl;
	  		cout << " Nama              = " << namapem << endl;
	  		cout << " Alamat            = " << alamatpem << endl;
	  		cout << " Telepon           = " << teleponpem << endl;
				cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
      	cout << "-" << tahunpem << endl;
        cout << " Jenis Tes Covid   = PCR" << endl;
    		cout << "--------------------------------------------------------------" << endl;
	  		cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
				cout << "--------------------------------------------------------------" << endl;
      	for(int a=head; a<=tail; a++){
					cout << "    " << queue.nik[a] << "         ";
      		cout << queue.nama[a] << "          " << queue.jeniskelamin[a] << endl;
      	}
	  		cout << "==============================================================" << endl;
			  	
				ofstream file("invoice covid.txt", ios::app);
        
				file << "==============================================================" << endl;
	  		file << "          STRUK PEMESANAN TES PCR STASIUN YOGYAKARTA" << endl;
    		file << "==============================================================" << endl;
	  		file << "--------------------------------------------------------------" << endl;
    		file << "|                        Data Pemesan                        |" << endl;
	  		file << "--------------------------------------------------------------" << endl;
	  		file << " Nama              = " << namapem << endl;
	  		file << " Alamat            = " << alamatpem << endl;
	  		file << " Telepon           = " << teleponpem << endl;
	  		file << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
   			file << "-" << tahunpem << endl;
        file << " Jenis Tes Covid   = PCR" << endl;
    		file << "--------------------------------------------------------------" << endl;
	  		file << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
	  		file << "--------------------------------------------------------------" << endl;
       	for(int a=head; a<=tail; a++){
					file << "    " << queue.nik[a] << "         ";
      		file << queue.nama[a] << "          " << queue.jeniskelamin[a] << endl;
    		}
	  		file << "--------------------------------------------------------------" << endl;
	  		file << "|                      Detail Transaksi                      |" << endl;
	  		file << "--------------------------------------------------------------" << endl;
	  		file << " Jumlah Pasien                                 = " << jumlahpeng << " Pengunjung" << endl;
	  		file << " Harga                                         = " << 90000 << endl;
	  		file << "--------------------------------------------------------------" << endl;
  			file << " Total Bayar                                   = " << 90000*jumlahpeng << endl;
        file << " Bayar                                         = " << saldo << endl;
        file << " Kembali                                       = " << saldo-(90000*jumlahpeng) << endl;
	  		file << "==============================================================" << endl;
				file << endl;
				cout << endl;
				cout << "--------------------- TRANSAKSI  BERHASIL ---------------------" << endl;
				cout << "|                                                             |" << endl;
				cout << "|  Wajib membawa Kartu Keluarga / KTP pada saat tes Covid-19  |" << endl;
				cout << "|                                                             |" << endl;
				cout << "---------------------------------------------------------------" << endl << endl;
				covid::kembalimenu();
			}
      else {
				cout << endl << " Maaf, Saldo Anda Tidak Mencukupi. " << endl << endl;
				covid::kembalimenu();
			}		
		}
    else {
			cout << endl << "-------------------- PEMESANAN DIBATALKAN --------------------" << endl << endl;
			covid::kembalimenu();
		}  
		cout << endl;
	}
}

void covid::Antrian(){
	n = NULL;
}

void covid::insertAntrian(string z, string y, string x, string u){
	t = new DataPrioritas;
	t->cek = z;
	t->prioritas = y;
	t->h = x;
	t->jk = u;		
	if (n == NULL || y < n->prioritas){
		t->lanjut = n;
		n = t;
	}
	else{
		que = n;
		while (que->lanjut != NULL && que->lanjut->prioritas <= y)
			que = que->lanjut;
			t->lanjut = que->lanjut;
			que->lanjut = t;
	}
}

void covid::deleteAntrian(){
	if (n == NULL){
		cout << endl << " Antrian Kosong" << endl;
	}
	else{
		t = n;
		cout << endl << " Data " << t->cek << " Telah Dihapus" << endl;
		n = n->lanjut;
		free(t);
	}
}

void covid::cetakAntrian(){
	ptr = n;
	if (n == NULL){
		cout << endl << " Antrian Kosong" << endl;
	}
	else{
		while (ptr != NULL){
			cout << endl;
			cout << " Prioritas Ke - "<< ptr->prioritas << endl;
			cout << " NIK           : " << ptr->cek << endl;
			cout << " Nama          : " << ptr->h << endl;
			cout << " Jenis Kelamin : " << ptr->jk << endl;
			ptr = ptr->lanjut;
		}
	}
}

void covid::transaksiAntrian(){
	ptr = n;
	if (n == NULL){
		cout << endl << " Antrian Kosong" << endl;
    cout << endl;
    covid::kembalimenu();
	}
	else{
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
    cout << "-" << tahunpem << endl;
    cout << " Jenis Tes Covid   = Antigen" << endl;
  	cout << "--------------------------------------------------------------" << endl;
		cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		ptr = n;
		while (ptr != NULL){
			cout << "    " << ptr->cek << "         ";
      cout << ptr->h << "          " << ptr->jk << endl;
			ptr = ptr->lanjut;
		}
		cout << "--------------------------------------------------------------" << endl;
		cout << "|                      Detail Transaksi                      |" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << " Jumlah Pengunjung                             = ";
		cin >> jumlahpeng; 
		cout << " Harga                                         = " << 70000 << endl;
		cout << "--------------------------------------------------------------" << endl;
  	cout << " Total Bayar                                   = " << 70000*jumlahpeng << endl;
		cout << "==============================================================" << endl << endl;
    cout << " Melanjutkan Pembayaran (y/n) : ";
    cin >> lanjut;
  	if(lanjut=="y"||lanjut=="Y") {
		  cout << " Masukkan Saldo Anda : ";
		  cin >> saldo;
		  if(saldo>=(70000*jumlahpeng)) {
			  cout << " Sisa Saldo Anda : " << saldo-(70000*jumlahpeng) << endl << endl;
			  cout << "==============================================================" << endl;
 			  cout << "        STRUK PEMESANAN TES ANTIGEN STASIUN YOGYAKARTA" << endl;
  		  cout << "==============================================================" << endl;
			  cout << "--------------------------------------------------------------" << endl;
			  cout << "|                        Data Pemesan                        |" << endl;
	  	  cout << "--------------------------------------------------------------" << endl;
			  cout << " Nama              = " << namapem << endl;
  		  cout << " Alamat            = " << alamatpem << endl;
			  cout << " Telepon           = " << teleponpem << endl;
			  cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
        cout << "-" << tahunpem << endl;
        cout << " Jenis Tes Covid   = Antigen" << endl;
    	  cout << "--------------------------------------------------------------" << endl;
  		  cout << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
	  	  cout << "--------------------------------------------------------------" << endl;
	  	  ptr = n;
	  	  while (ptr != NULL){
				  cout << "    " << ptr->cek << "         ";
      	  cout << ptr->h << "          " << ptr->jk << endl;
				  ptr = ptr->lanjut;
			  }
	  	  cout << "==============================================================" << endl;
				
	  	  ofstream file("invoice covid.txt", ios::app);

			  file << "==============================================================" << endl;
        file << "        STRUK PEMESANAN TES ANTIGEN STASIUN YOGYAKARTA" << endl;
	  	  file << "==============================================================" << endl;
			  file << "--------------------------------------------------------------" << endl;
			  file << "|                        Data Pemesan                        |" << endl;
	  		file << "--------------------------------------------------------------" << endl;
				file << " Nama              = " << namapem << endl;
	  	  file << " Alamat            = " << alamatpem << endl;
				file << " Telepon           = " << teleponpem << endl;
	  		file << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem;
  			file << "-" << tahunpem << endl;
        file << " Jenis Tes Covid   = Antigen" << endl;
    	  file << "--------------------------------------------------------------" << endl;
				file << "|       NIK       |   Nama  Pengunjung   |   Jenis Kelamin   |" << endl;
		  	file << "--------------------------------------------------------------" << endl;
				ptr = n;
	  		while (ptr != NULL){
					file << "    " << ptr->cek << "         ";
      		file << ptr->h << "          " << ptr->jk << endl;
					ptr = ptr->lanjut;
				}
	  		file << "--------------------------------------------------------------" << endl;
	  		file << "|                      Detail Transaksi                      |" << endl;
	  		file << "--------------------------------------------------------------" << endl;
	  		file << " Jumlah Pasien                                 = " << jumlahpeng << " Pengunjung" << endl;
	  		file << " Harga                                         = " << 70000 << endl;
	  	 	file << "--------------------------------------------------------------" << endl;
  			file << " Total Bayar                                   = " << 70000*jumlahpeng << endl;
       	file << " Bayar                                         = " << saldo << endl;
  			file << " Kembali                                       = " << saldo-(70000*jumlahpeng) << endl;
	  		file << "==============================================================" << endl;
			  file << endl;
				cout << endl;
				cout << "--------------------- TRANSAKSI  BERHASIL ---------------------" << endl;
				cout << "|                                                             |" << endl;
				cout << "|  Wajib membawa Kartu Keluarga / KTP pada saat tes Covid-19  |" << endl;
				cout << "|                                                             |" << endl;
				cout << "---------------------------------------------------------------" << endl << endl;
				covid::kembalimenu();	
			}
      else {
				cout << endl << " Maaf, Saldo Anda Tidak Mencukupi. " << endl << endl;
				covid::kembalimenu();
			}		
		}
    else {
			cout << endl << "-------------------- PEMESANAN DIBATALKAN --------------------" << endl << endl;
			covid::kembalimenu();
		}  
		cout << endl;
	}
}

void covid::kembalimenu(){
	cout << " Kembali Ke Menu Utama (y/n) : ";
  cin >> kembali;
  if (kembali=="y" || kembali=="Y"){
  	covid::tescovid();
	} 
	else {	
    return;
	}
}

void covid::kembalimenu2(){
	cout << " Ketik 'y' Untuk Kembali : ";
  cin >> kembali;
}

void covid::datapemesan() {
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

void covid::tescovid(){
  system("clear");
  cout << "==============================================================" << endl;
  cout << "|                                                            |" << endl;
  cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
  cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
  cout << "|                                                            |" << endl;
  cout << "==============================================================" << endl << endl;
  cout << "==============================================================" << endl;
	cout << "                   MENU UTAMA TES COVID-19" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " 1. Tes Genose                                     Rp. 50.000" << endl;
	cout << " 2. Tes PCR                                        Rp. 90.000" << endl;
 	cout << " 3. Tes Antigen                                    Rp. 70.000" << endl;
  cout << " 4. EXIT" << endl;
  cout << "==============================================================" << endl;
	cout << " Masukkan Pilihan Menu : ";
  cin >> piltes;
	if (piltes == 1) {
    system ("clear");
  	cout << "==============================================================" << endl;
    cout << "|                                                            |" << endl;
    cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
    cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
    cout << "|                                                            |" << endl;
    cout << "==============================================================" << endl;
    cout << "                          TES GENOSE " << endl;
		cout << "                        DATA PEMESANAN" << endl;
		cout << "==============================================================" << endl;
    covid::datapemesan();
		do {
      system ("clear");
      cout << "==============================================================" << endl;
      cout << "|                                                            |" << endl;
      cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
      cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
      cout << "|                                                            |" << endl;
      cout << "==============================================================" << endl;
      cout << "                          TES GENOSE " << endl;
		  cout << "==============================================================" << endl;
			cout << "                        DATA PENGUNJUNG" << endl;
	  	cout << "--------------------------------------------------------------" << endl;
	  	cout << " 1. Tambah Data (Push)" << endl;
		  cout << " 2. Hapus Data (Pop)" << endl;
			cout << " 3. Lihat Data" << endl;
	  	cout << " 4. Hapus Semua Data" << endl;
  		cout << " 5. Selesai" << endl;
	  	cout << "==============================================================" << endl;
		  cout << " Masukkan Pilihan Anda : ";
			cin >> pildata;
	  	switch(pildata){
	  	  case 1 : 
          covid::pushStack();
		  	  break;
	  	  case 2 : 
				  covid::popStack();
          cout << endl;
  			  covid::kembalimenu2();
		  	  break;
			  case 3 : 
				  covid::printStack();
          cout << endl;
  			  covid::kembalimenu2();
				  break;
			  case 4 : 
		  	  covid::clearStack();
          cout << endl;
  			  covid::kembalimenu2();
				  break;
			  case 5 :
          covid::transaksiStack();
	        break;
			  default : 
          cout << endl;
				  cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
				  cout << endl;
  			  covid::kembalimenu();
			    break;
		  }
		  cout << endl;
	  } while(pildata < 5);
  }
	else if (piltes == 2) {
  	system ("clear");
  	cout << "==============================================================" << endl;
    cout << "|                                                            |" << endl;
    cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
    cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
    cout << "|                                                            |" << endl;
  	cout << "==============================================================" << endl;
		cout << "                           TES  PCR" << endl;
		cout << "                        DATA PEMESANAN" << endl;
		cout << "==============================================================" << endl;
  	covid::datapemesan();
  	do {
      system ("clear");
      cout << "==============================================================" << endl;
      cout << "|                                                            |" << endl;
      cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
      cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
      cout << "|                                                            |" << endl;
      cout << "==============================================================" << endl;
      cout << "                           TES PCR " << endl;
    	cout << "==============================================================" << endl;
			cout << "                        DATA PENGUNJUNG" << endl;
	  	cout << "--------------------------------------------------------------" << endl;
   		cout << " 1. Tambah Data (Enqueue)" << endl;
		  cout << " 2. Hapus Data (Dequeue)" << endl;
			cout << " 3. Lihat Data" << endl;
	  	cout << " 4. Hapus Semua Data" << endl;
      cout << " 5. Selesai" << endl;
    	cout << "==============================================================" << endl;
    	cout << " Masukkan Pilihan Anda : ";
      cin >> pildata;
    	switch (pildata){
        case 1:
      		covid::tambahQueue();
          break;
      	case 2:
      		covid::hapusQueue();
      		cout << endl;
  			  covid::kembalimenu2();
          break;
        case 3:
      		covid::tampilQueue();
  			  covid::kembalimenu2();
          break;
      	case 4:
          covid::clearQueue();
          cout << endl;
  			  covid::kembalimenu2();
      		break;
        case 5:
          covid::transaksiQueue();
      		cout << endl;
          break;
      	default:
          cout << endl;
          cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
					cout << endl;
    			covid::kembalimenu();
      		break;
     	}
  	} while (pildata < 5);
	}
  else if (piltes == 3) {
  	system ("clear");
  	cout << "==============================================================" << endl;
    cout << "|                                                            |" << endl;
    cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
    cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
    cout << "|                                                            |" << endl;
  	cout << "==============================================================" << endl;
		cout << "                         TES  ANTIGEN" << endl;
		cout << "                        DATA PEMESANAN" << endl;
		cout << "==============================================================" << endl;
  	covid::datapemesan();
  	do {
  		system ("clear");
      cout << "==============================================================" << endl;
      cout << "|                                                            |" << endl;
      cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
      cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
      cout << "|                                                            |" << endl;
      cout << "==============================================================" << endl;
      cout << "                          TES ANTIGEN " << endl;
    	cout << "==============================================================" << endl;
	  	cout << "                        DATA PENGUNJUNG" << endl;
	  	cout << "--------------------------------------------------------------" << endl;
   		cout << " 1. Tambah Data" << endl;
	  	cout << " 2. Hapus Data" << endl;
		  cout << " 3. Lihat Data" << endl;
  		cout << " 4. Selesai" << endl;
     	cout << "==============================================================" << endl;
    	cout << " Masukkan Pilihan Anda : ";
    	cin >> pildata;
     	switch (pildata){
        case 1:
        	cin.ignore(1,'\n');
        	cout << endl;
					cout << " Menginputkan Data Pengunjung" << endl;
  				cout << " NIK           : "; 
  				getline(cin, nik);
  				cout << " Nama          : "; 
  				getline(cin, nama);
  				cout << " Jenis Kelamin : "; 
					getline(cin, jeniskelamin);
  				cout << " Prioritas     : "; 
  				cin >> prioritas;
      		covid::insertAntrian(nik, prioritas, nama, jeniskelamin);
          break;
      	case 2:
          covid::deleteAntrian();
          cout << endl;
  			  covid::kembalimenu2();
      		break;
    		case 3:
          covid::cetakAntrian();
          cout << endl;
  			  covid::kembalimenu2();
      		break;
        case 4:
      		covid::transaksiAntrian();
      		cout << endl;
      		break;
        default:
          cout << endl;
        	cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
			  	cout << endl;
          covid::kembalimenu();
      		break;
    	}
  	} while (pildata < 4); 
	}
	else {
    cout << endl;
  }
}