#include <iostream>
#include <fstream>
#include <istream>

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

struct DataPohon{
	string namapen, idpen, tujuan, tanggalpemm, bulanpem, tahunpem, berangkat, tiba;      
  DataPohon *kiri;      
	DataPohon *kanan;     
};
DataPohon *baru, *phn;

//materi 1 :: Class dan Rekursif
class kereta{ 
	public:
		int rekursif(int a, int b);
    void menu();
		void kembalimenu();
    void kembalimenu2();
		void datapemesan();
    void tujuanKAJJ(); 
    void jadwalKAJJ();
		void kelasKAJJ();
		void identitasKAJJ();	
		void transaksiKAJJ();	
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
    //materi 9 :: Pohon
		void tambahPohon(DataPohon **akar, string namapen, string idpen, string tujuan, string tanggalpemm, string bulanpem, string tahunpem, string berangkat, string tiba);
    void lihatinorderPohon(DataPohon *akar);
		void lihatpreorderPohon(DataPohon *akar);
		void lihatpostorderPohon(DataPohon *akar);
		void inorderPohon(DataPohon *akar);
		void preorderPohon(DataPohon *akar);
		void postorderPohon(DataPohon *akar);
		void tujuanKRL(); 
    void jadwalKRL();
		void identitasKRL();	
		//materi 10 :: Pohon Setimbang
    void tujuanCITLINK(); 
    void jadwalCITLINK();
		void identitasCITLINK();	
		void transaksiCITLINK();
    void cetakCITLINK();
	private:
		int piltes, pilmenu, piltujuan, pildata, pilkelas, piljadwal, pilihdata, pilpohon; // variabel memilih
		int harga, saldo, tanggalpem, jumlahpen, jumlahpeng; // variabel transaksi
		string kotatujuan, kelas; // variabel lain-lain
		string username, password, lanjut, kembali; // variabel login dan memilih
		string namapem, alamatpem, teleponpem, bulanpem, tahunpem; // variabel data pemesanan
    string namapen, idpen, tanggalpemm;
		string kelaskereta[4] = {"Ekonomi", "Eksekutif", "Bisnis"}; // materi 2 :: Array Statis
		string namapenn[50], idpenn[50]; // materi 3 :: Array Dinamis
    string namakereta, tiba, berangkat, tujuan;
		// pem (pemesan), pen (penumpang), peng (pengunjung)
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

void kereta::tambahPohon(DataPohon **akar, string namapen, string idpen, string tujuan, string tanggalpemm, string bulanpem, string tahunpem, string berangkat, string tiba){
	baru = new DataPohon; 
	if((*akar) == NULL){   		                                      
    baru->namapen = namapen;   
  	baru->idpen = idpen;
    baru->tujuan = tujuan;   
  	baru->tanggalpemm = tanggalpemm;
    baru->bulanpem = bulanpem;   
  	baru->tahunpem = tahunpem;
    baru->berangkat = berangkat;   
  	baru->tiba = tiba;
  	baru->kiri = NULL;       
  	baru->kanan = NULL;  
  	(*akar) = baru;         
  	(*akar)->kiri = NULL;         
  	(*akar)->kanan = NULL;
	}
  else if(idpen < (*akar)->idpen){
   	kereta::tambahPohon(&(*akar)->kiri, namapen, idpen, tujuan, tanggalpemm, bulanpem, tahunpem, berangkat, tiba);	
	} 
   else if(idpen > (*akar)->idpen){
   	kereta::tambahPohon(&(*akar)->kanan, namapen, idpen, tujuan, tanggalpemm, bulanpem, tahunpem, berangkat, tiba);
	}   
	else if(idpen == (*akar)->idpen){
		cout << endl << " Item Sudah Ada" << endl;
	} 
}

void kereta::lihatpreorderPohon(DataPohon *akar){
	if(akar != NULL){
		cout << endl;
		cout << " ID Penumpang (nim) : " << akar->idpen << endl;
		cout << " Nama Penumpang     : " << akar->namapen << endl;        
   	kereta::lihatpreorderPohon(akar->kiri),            
   	kereta::lihatpreorderPohon(akar->kanan);           
  } else return;
}

void kereta::lihatinorderPohon(DataPohon *akar){
	if(akar != NULL){
   	kereta::lihatinorderPohon(akar->kiri),
		cout << endl;         
   	cout << " ID Penumpang (nim) : " << akar->idpen << endl;
		cout << " Nama Penumpang     : " << akar->namapen << endl;        
		kereta::lihatinorderPohon(akar->kanan);        
  } else return;
} 

void kereta::lihatpostorderPohon(DataPohon *akar){
	if(akar != NULL){
   	kereta::lihatpostorderPohon(akar->kiri),       
   	kereta::lihatpostorderPohon(akar->kanan);
		cout << endl;      
		cout << " ID Penumpang (nim) : " << akar->idpen << endl;
		cout << " Nama Penumpang     : " << akar->namapen << endl;      
  } else return;
}

void kereta::preorderPohon(DataPohon *akar){
	if(akar != NULL){
		cout << endl;
    cout << "==============================================================" << endl;
	  cout << " KERETA API                                     BOARDING PASS" << endl;
	  cout << "--------------------------------------------------------------" << endl;
    cout << " Nama / Name                    Kodebooking / Bookingcode" << endl;
	  cout << " " << akar->namapen << "                 00XXX" << endl;
	  cout << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
	  cout << " " << akar->idpen << "                     Ekonomis" << endl;
	  cout << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
	  cout << " KRL                            00XXX"  << endl;
	  cout << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
	  cout << " Yogyakarta                     " << akar->tujuan << endl;
	  cout << " " << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem;
	  cout << "                     " << akar->tanggalpemm << "-" << akar->bulanpem;
    cout << "-" << akar->tahunpem << endl;
    cout << " " << akar->berangkat << "                          " << akar->tiba << endl;
	  cout << "--------------------------------------------------------------" << endl;
	  cout << "                            Check In At Yogyakarta ";
	  cout << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem << endl;
	  cout << "==============================================================" << endl;  

    ofstream doks("tiket KRL.txt", ios::app);
    
    doks << "==============================================================" << endl;
	  doks << " KERETA API                                     BOARDING PASS" << endl;
	  doks << "--------------------------------------------------------------" << endl;
    doks << " Nama / Name                    Kodebooking / Bookingcode" << endl;
	  doks << " " << akar->namapen << "                 00XXX" << endl;
	  doks << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
	  doks << " " << akar->idpen << "                     Ekonomis" << endl;
	  doks << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
	  doks << " KRL                            00XXX"  << endl;
	  doks << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
	  doks << " Yogyakarta                     " << akar->tujuan << endl;
	  doks << " " << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem;
	  doks << "                     " << akar->tanggalpemm << "-";
    doks << akar->bulanpem << "-" << akar->tahunpem << endl;
    doks << " " << akar->berangkat << "                          " << akar->tiba << endl;
	  doks << "--------------------------------------------------------------" << endl;
	  doks << "                            Check In At Yogyakarta ";
	  doks << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem << endl;
	  doks << "==============================================================" << endl;
	  doks << endl;
   	kereta::preorderPohon(akar->kiri),            
   	kereta::preorderPohon(akar->kanan);           
  	} else return;
}

void kereta::inorderPohon(DataPohon *akar){
	if(akar != NULL){
   	kereta::inorderPohon(akar->kiri),
		cout << endl;
    cout << "==============================================================" << endl;
	  cout << " KERETA API                                     BOARDING PASS" << endl;
	  cout << "--------------------------------------------------------------" << endl;
    cout << " Nama / Name                    Kodebooking / Bookingcode" << endl;
	  cout << " " << akar->namapen << "                 00XXX" << endl;
	  cout << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
	  cout << " " << akar->idpen << "                     Ekonomis" << endl;
	  cout << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
	  cout << " KRL                            00XXX"  << endl;
	  cout << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
	  cout << " Yogyakarta                     " << akar->tujuan << endl;
	  cout << " " << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem;
	  cout << "                     " << akar->tanggalpemm << "-" << akar->bulanpem;
    cout << "-" << akar->tahunpem << endl;
    cout << " " << akar->berangkat << "                          " << akar->tiba << endl;
	  cout << "--------------------------------------------------------------" << endl;
	  cout << "                            Check In At Yogyakarta ";
	  cout << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem << endl;
	  cout << "==============================================================" << endl; 

    ofstream doks("tiket KRL.txt", ios::app);
    
    doks << "==============================================================" << endl;
	  doks << " KERETA API                                     BOARDING PASS" << endl;
	  doks << "--------------------------------------------------------------" << endl;
    doks << " Nama / Name                    Kodebooking / Bookingcode" << endl;
	  doks << " " << akar->namapen << "                 00XXX" << endl;
	  doks << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
	  doks << " " << akar->idpen << "                     Ekonomis" << endl;
	  doks << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
	  doks << " KRL                            00XXX"  << endl;
	  doks << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
	  doks << " Yogyakarta                     " << akar->tujuan << endl;
	  doks << " " << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem;
	  doks << "                     " << akar->tanggalpemm << "-";
    doks << akar->bulanpem << "-" << akar->tahunpem << endl;
    doks << " " << akar->berangkat << "                          " << akar->tiba << endl;
	  doks << "--------------------------------------------------------------" << endl;
	  doks << "                            Check In At Yogyakarta ";
	  doks << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem << endl;
	  doks << "==============================================================" << endl;
	  doks << endl;
		kereta::inorderPohon(akar->kanan);        
  } else return;
} 

void kereta::postorderPohon(DataPohon *akar){
	if(akar != NULL){
   	kereta::postorderPohon(akar->kiri),       
   	kereta::postorderPohon(akar->kanan);
		cout << endl;
    cout << "==============================================================" << endl;
	  cout << " KERETA API                                     BOARDING PASS" << endl;
	  cout << "--------------------------------------------------------------" << endl;
    cout << " Nama / Name                    Kodebooking / Bookingcode" << endl;
	  cout << " " << akar->namapen << "                 00XXX" << endl;
	  cout << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
	  cout << " " << akar->idpen << "                     Ekonomis" << endl;
	  cout << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
	  cout << " KRL                            00XXX"  << endl;
	  cout << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
	  cout << " Yogyakarta                     " << akar->tujuan << endl;
	  cout << " " << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem;
	  cout << "                     " << akar->tanggalpemm << "-" << akar->bulanpem;
    cout << "-" << akar->tahunpem << endl;
    cout << " " << akar->berangkat << "                          " << akar->tiba << endl;
	  cout << "--------------------------------------------------------------" << endl;
	  cout << "                            Check In At Yogyakarta ";
	  cout << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem << endl;
	  cout << "==============================================================" << endl;     

    ofstream doks("tiket KRL.txt", ios::app);
    
    doks << "==============================================================" << endl;
	  doks << " KERETA API                                     BOARDING PASS" << endl;
	  doks << "--------------------------------------------------------------" << endl;
    doks << " Nama / Name                    Kodebooking / Bookingcode" << endl;
	  doks << " " << akar->namapen << "                 00XXX" << endl;
	  doks << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
	  doks << " " << akar->idpen << "                     Ekonomis" << endl;
	  doks << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
	  doks << " KRL                            00XXX"  << endl;
	  doks << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
	  doks << " Yogyakarta                     " << akar->tujuan << endl;
	  doks << " " << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem;
	  doks << "                     " << akar->tanggalpemm << "-";
    doks << akar->bulanpem << "-" << akar->tahunpem << endl;
    doks << " " << akar->berangkat << "                          " << akar->tiba << endl;
	  doks << "--------------------------------------------------------------" << endl;
	  doks << "                            Check In At Yogyakarta ";
	  doks << akar->tanggalpemm << "-" << akar->bulanpem << "-" << akar->tahunpem << endl;
	  doks << "==============================================================" << endl;
	  doks << endl;
  } else return;
}

int kereta::rekursif(int a, int b){
	if (b==1)
		return a;
	else
		return a+kereta::rekursif(a, b-1);		
}

void kereta::kembalimenu(){
	cout << " Kembali Ke Menu Utama (y/n) : ";
  cin >> kembali;
  if (kembali=="y" || kembali=="Y"){
    kereta::menu();
	} 
	else {		
	}
}

void kereta::kembalimenu2(){
	cout << " Ketik 'y' Untuk Kembali : ";
  cin >> kembali;
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
}

void kereta::menu(){
  system("clear");
  cout << "==============================================================" << endl;
  cout << "|                                                            |" << endl;
  cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
  cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
  cout << "|                                                            |" << endl;
  cout << "==============================================================" << endl << endl;
  cout << "==============================================================" << endl;
  cout << "                    MENU UTAMA TIKET KERETA" << endl;
	cout << "--------------------------------------------------------------" << endl;
  cout << " 1. Tiket Kereta Api Jarak Jauh (KAJJ)" << endl;
  cout << " 2. Tiket Kereta Commuter Line (KRL)" << endl;
  cout << " 3. Tiket Kereta Bandara (RAILINK)" << endl;
  cout << " 4. EXIT" << endl;
  cout << "==============================================================" << endl;
  cout << " Masukkan Pilihan Menu : ";
  cin >> pilmenu;
  if (pilmenu==1){
    kereta::tujuanKAJJ(); 
    kereta::jadwalKAJJ();
		kereta::kelasKAJJ();
		kereta::identitasKAJJ();	
		kereta::transaksiKAJJ();	
  }
  else if (pilmenu==2){
    cout << endl;
    do {
      system ("clear");
      cout << "==============================================================" << endl;
      cout << "|                                                            |" << endl;
      cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
      cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
      cout << "|                                                            |" << endl;
      cout << "==============================================================" << endl;
      cout << "                   KERETA COMMUTER LINE (KRL) " << endl;
      cout << "==============================================================" << endl;
		  cout << "                        DATA PENUMPANG" << endl;
			cout << "--------------------------------------------------------------" << endl;
   		cout << " 1. Tambah Data" << endl;
		  cout << " 2. Lihat InOrder" << endl;
			cout << " 3. Lihat PreOrder" << endl;
	  	cout << " 4. Lihat PostOrder" << endl;
      cout << " 5. Selesai InOrder" << endl;
      cout << " 6. Selesai PreOrder" << endl;
	  	cout << " 7. Selesai PostOrder" << endl;
      cout << "==============================================================" << endl;
    	cout << " Masukkan Pilihan Anda : ";
      cin >> pilihdata;
    	switch (pilihdata){
        case 1:
    			kereta::tujuanKRL(); 
          kereta::jadwalKRL();
		      kereta::identitasKRL();	
          kereta::tambahPohon(&phn, namapen, idpen, tujuan, tanggalpemm, bulanpem, tahunpem, berangkat, tiba);
          cout << endl;
          break;
        case 2:
          kereta::lihatinorderPohon(phn);
          cout << endl;
  			  kereta::kembalimenu2();
          break;
        case 3:
          kereta::lihatpreorderPohon(phn);
          cout << endl;
  			  kereta::kembalimenu2();
          break;
        case 4:
          kereta::lihatpostorderPohon(phn);
          cout << endl;
  			  kereta::kembalimenu2();
          break;
        case 5:
          kereta::inorderPohon(phn);
          cout << endl;
			    cout << "------------------ PEMESANAN TIKET BERHASIL ------------------" << endl;
          cout << endl;
          kereta::kembalimenu();
          break;
        case 6:
          kereta::preorderPohon(phn);
          cout << endl;
          cout << "------------------ PEMESANAN TIKET BERHASIL ------------------" << endl;
          cout << endl;
          kereta::kembalimenu();
          break;
        case 7:
          kereta::postorderPohon(phn);
          cout << endl;
          cout << "------------------ PEMESANAN TIKET BERHASIL ------------------" << endl;
          cout << endl;
          kereta::kembalimenu();
          break;
        default:
          cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
				  cout << endl;
          kereta::kembalimenu();
          break;
      }
    } while (pilihdata < 5);
  }
  else if (pilmenu==3){
    kereta::tujuanCITLINK(); 
    kereta::jadwalCITLINK();
		kereta::identitasCITLINK();	
		kereta::transaksiCITLINK();
  }
  else{
    cout << endl;
  }
}

void kereta::tujuanKAJJ(){
  cout << endl;
  kereta::createDataCircular("--------------------------------------------------------------");
  kereta::tambahAwalCircular("         TUJUAN KEBERANGKATAN KERETA JARAK JAUH (KAJJ)");
	kereta::tambahAwalCircular("==============================================================");
  kereta::deleteAkhirCircular();
  kereta::tambahAkhirCircular("--------------------------------------------------------------");
  kereta::tambahAkhirCircular("--------------------------------------------------------------");
	kereta::printDataCircular();
	kereta::createDataSingle(" 2. Surabaya"); 
	kereta::tambahAwalSingle(" 1. Jakarta"); 	
	kereta::tambahAwalSingle(" 2. Surabaya"); 
  kereta::deleteAwalSingle(); 
	kereta::printDataSingle();
	cout << endl;
	kereta::createDataDouble(" 4. Semarang");
	kereta::tambahAwalDouble(" 3. Bandung");
	kereta::tambahAkhirDouble(" 4. Semarang");
	kereta::deleteAkhirDouble();
	kereta::printDataDouble();
	cout << endl;
	cout << "==============================================================" << endl;
	cout << " Pilih Tujuan Keberangkatan (1-4) : ";
	cin >> piltujuan;
  if (piltujuan==1){
    tujuan = "Jakarta";
  }
  else if(piltujuan==2){
    tujuan = "Surabaya";
  }
  else if(piltujuan==3){
    tujuan = "Bandung";
  }
  else if(piltujuan==4){
    tujuan = "Semarang";
  }
  else{
    cout << endl;
    cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	cout << endl;
    kereta::kembalimenu();
  }
}

void kereta::jadwalKAJJ(){
  cout << endl;
  cout << "==============================================================" << endl;
  cout << "              JADWAL KERETA JARAK JAUH (KAJJ)" << endl;
  cout << "--------------------------------------------------------------" << endl;
  cout << " 1. BINRIZDA                                        09.00 WIB" << endl;
  cout << " 2. CEPATIID                                        11.00 WIB" << endl;
  cout << " 3. GOKERETA                                        14.00 WIB" << endl;
  cout << " 4. MARINAIK                                        16.00 WIB" << endl;
  cout << " 5. SUPERKER                                        18.00 WIB" << endl;
  cout << "==============================================================" << endl;
  cout << " Masukkan Pilihan Menu : ";
  cin >> piljadwal;
  if (piltujuan==1){
    if(piljadwal==1){
      namakereta = "BINRIZDA";
      berangkat = "09.00";
      tiba = "13.00";
    }
    else if(piljadwal==2){
      namakereta = "CEPATIID";
      berangkat = "11.00";
      tiba = "15.00";
    }
    else if(piljadwal==3){
      namakereta = "GOKERETA";
      berangkat = "14.00";
      tiba = "18.00";
    }
    else if(piljadwal==4){
      namakereta = "MARINAIK";
      berangkat = "16.00";
      tiba = "20.00";
    }
    else if(piljadwal==5){
      namakereta = "SUPERKER";
      berangkat = "18.00";
      tiba = "22.00";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }  
  }
  else if (piltujuan==2){
    if(piljadwal==1){
      namakereta = "BINRIZDA";
      berangkat = "09.00";
      tiba = "11.00";
    }
    else if(piljadwal==2){
      namakereta = "CEPATIID";
      berangkat = "11.00";
      tiba = "14.00";
    }
    else if(piljadwal==3){
      namakereta = "GOKERETA";
      berangkat = "14.00";
      tiba = "17.00";
    }
    else if(piljadwal==4){
      namakereta = "MARINAIK";
      berangkat = "16.00";
      tiba = "19.00";
    }
    else if(piljadwal==5){
      namakereta = "SUPERKER";
      berangkat = "18.00";
      tiba = "21.00";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }  
  }
  else if (piltujuan==3){
    if(piljadwal==1){
      namakereta = "BINRIZDA";
      berangkat = "09.00";
      tiba = "11.00";
    }
    else if(piljadwal==2){
      namakereta = "CEPATIID";
      berangkat = "11.00";
      tiba = "13.00";
    }
    else if(piljadwal==3){
      namakereta = "GOKERETA";
      berangkat = "14.00";
      tiba = "16.00";
    }
    else if(piljadwal==4){
      namakereta = "MARINAIK";
      berangkat = "16.00";
      tiba = "18.00";
    }
    else if(piljadwal==5){
      namakereta = "SUPERKER";
      berangkat = "18.00";
      tiba = "20.00";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }  
  }
  else if (piltujuan==4){
    if(piljadwal==1){
      namakereta = "BINRIZDA";
      berangkat = "09.00";
      tiba = "10.00";
    }
    else if(piljadwal==2){
      namakereta = "CEPATIID";
      berangkat = "11.00";
      tiba = "12.00";
    }
    else if(piljadwal==3){
      namakereta = "GOKERETA";
      berangkat = "14.00";
      tiba = "15.00";
    }
    else if(piljadwal==4){
      namakereta = "MARINAIK";
      berangkat = "16.00";
      tiba = "17.00";
    }
    else if(piljadwal==5){
      namakereta = "SUPERKER";
      berangkat = "18.00";
      tiba = "19.00";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }  
  }
  else{
    cout << endl;
    cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	cout << endl;
    kereta::kembalimenu();
  }
}

void kereta::kelasKAJJ(){
  cout << endl;
	string kelaskereta[4] = {"Ekonomi", "Eksekutif", "Bisnis"}; //materi 2 :: Array Statis
	if (piltujuan==1){
		cout << "==============================================================" << endl;
		cout << "|    (1)Ekonomi     |    (2)Eksekutif    |     (3)Bisnis     |" << endl;
		cout << "==============================================================" << endl;
		cout << "|    Rp 100.000     |     Rp 300.000     |     Rp 400.000    |" << endl;
		cout << "==============================================================" << endl;
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilkelas;
		if (pilkelas==1) {
			harga = 100000; kelas = kelaskereta[0];
		} else if (pilkelas==2){
			harga = 300000; kelas = kelaskereta[1];
		} else if (pilkelas==3){
			harga = 400000; kelas = kelaskereta[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
      cout << endl;
      kereta::kembalimenu();
		}
	}
	else if (piltujuan==2){
		cout << "==============================================================" << endl;
		cout << "|    (1)Ekonomi     |    (2)Eksekutif    |     (3)Bisnis     |" << endl;
		cout << "==============================================================" << endl;
		cout << "|    Rp 90.000      |     Rp 250.000     |     Rp 350.000    |" << endl;
		cout << "==============================================================" << endl;
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilkelas;
		if (pilkelas==1) {
			harga = 90000; kelas = kelaskereta[0];
		} else if (pilkelas==2){
			harga = 250000; kelas = kelaskereta[1];
		} else if (pilkelas==3){
			harga = 350000; kelas = kelaskereta[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
      cout << endl;
      kereta::kembalimenu();
		}
	}
	else if (piltujuan==3){
		cout << "==============================================================" << endl;
		cout << "|    (1)Ekonomi     |    (2)Eksekutif    |     (3)Bisnis     |" << endl;
		cout << "==============================================================" << endl;
		cout << "|     Rp 80.000     |     Rp 200.000     |     Rp 300.000    |" << endl;
		cout << "==============================================================" << endl;
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilkelas;
		if (pilkelas==1) {
			harga = 80000; kelas = kelaskereta[0];
		} else if (pilkelas==2){
			harga = 200000; kelas = kelaskereta[1];
		} else if (pilkelas==3){
			harga = 300000; kelas = kelaskereta[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
      cout << endl;
      kereta::kembalimenu();
		}
	}
	else if (piltujuan==4){
		cout << "==============================================================" << endl;
		cout << "|    (1)Ekonomi     |    (2)Eksekutif    |     (3)Bisnis     |" << endl;
		cout << "==============================================================" << endl;
		cout << "|    Rp 70.000     |      Rp 150.000     |     Rp 250.000    |" << endl;
		cout << "==============================================================" << endl;
		cout << " Masukkan Pilihan Kelas Anda (1-3) : ";
		cin >> pilkelas;
		if (pilkelas==1) {
			harga = 70000; kelas = kelaskereta[0];
		} else if (pilkelas==2){
			harga = 150000; kelas = kelaskereta[1];
		} else if (pilkelas==3){
			harga = 250000; kelas = kelaskereta[2];
		} else {
			cout << " Maaf, Pilihan Kelas Tidak Tersedia. " << endl;
      cout << endl;
      kereta::kembalimenu();
		}
	}
	else {
		cout << " Maaf, Tujuan Tidak Tersedia. " << endl;
    cout << endl;
    kereta::kembalimenu();
	}
}

void kereta::identitasKAJJ(){
  cout << endl;
  cout << "==============================================================" << endl;
	cout << "                         DATA PEMESANAN" << endl;
	cout << "==============================================================" << endl;
	kereta::datapemesan();
	cout << endl;
	cout << "==============================================================" << endl;
	cout << "                         DATA PENUMPANG" << endl;
	cout << "==============================================================" << endl;
	cout << "Masukkan Jumlah Penumpang : ";
	cin >> jumlahpen;
	cin.ignore(1,'\n');
	for (int i = 0; i < jumlahpen; i++) {
		cout << "Nama Penumpang Ke - " << i+1 << " : ";
		getline(cin, namapenn[i]);
		cout << "ID Penumpang (nim) : ";
		getline(cin, idpenn[i]);
	}
}

void kereta::transaksiKAJJ(){
  cout << endl;
  cout << "==============================================================" << endl;
	cout << "                       DETAIL PEMESANAN" << endl;
	cout << "==============================================================" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|                        Data Pemesan                        |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Nama              = " << namapem << endl;
	cout << " Alamat            = " << alamatpem << endl;
	cout << " Telepon           = " << teleponpem << endl;
	cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
  cout << " Jenis Kereta      = Kereta Jarak Jauh (KAJJ)" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|  Nama  Kereta  |   Berangkat   |    Tiba    |    Kelas     |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "     " << namakereta <<"       Yogyakarta     " << tujuan << "       " << kelas << endl;
	cout << "                    " << tanggalpem+1 << "-" << bulanpem << "-";
	cout << tahunpem << "     " << tanggalpem+1 << "-" << bulanpem << "-" << tahunpem << endl;
  cout << "                      " << berangkat << "          " << tiba << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|        Nama Penumpang         |           NO ID            |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int i = 0; i < jumlahpen; i++) {
		cout << "         " << namapenn[i] << "                  "<< idpenn[i] << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << "|                      Detail Transaksi                      |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Jumlah Penumpang                              = " << jumlahpen << " Penumpang" << endl;
	cout << " Kelas                                         = " << kelas << endl;
	cout << " Harga                                         = " << harga << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Total Bayar                                   = " << kereta::rekursif(harga, jumlahpen) << endl;
	cout << "==============================================================" << endl;	
	cout << endl;
  cout << " Melanjutkan Pembayaran (y/n) : ";
	cin >> lanjut;
	if(lanjut=="y"||lanjut=="Y"){
		cout << " Masukkan Saldo Anda : ";
		cin >> saldo;
		if(saldo>=kereta::rekursif(harga, jumlahpen)){
			cout << " Sisa Saldo Anda : " << saldo-kereta::rekursif(harga, jumlahpen) << endl << endl;
    	cout << "==============================================================" << endl;
			cout << "                     DETAIL TIKET KERETA" << endl;
			cout << "==============================================================" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "|                        Data Pemesan                        |" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << " Nama              = " << namapem << endl;
			cout << " Alamat            = " << alamatpem << endl;
			cout << " Telepon           = " << teleponpem << endl;
			cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
      cout << " Jenis Kereta      = Kereta Jarak Jauh (KAJJ)" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "|  Nama  Kereta  |   Berangkat   |    Tiba    |    Kelas     |" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "     " << namakereta <<"       Yogyakarta     " << tujuan << "       " << kelas << endl;
	    cout << "                    " << tanggalpem+1 << "-" << bulanpem << "-";
	    cout << tahunpem << "     " << tanggalpem+1 << "-" << bulanpem << "-" << tahunpem << endl;
      cout << "                      " << berangkat << "          " << tiba << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    cout << "|        Nama Penumpang         |           NO ID            |" << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    for (int i = 0; i < jumlahpen; i++) {
		    cout << "         " << namapenn[i] << "                  "<< idpenn[i] << endl;
	    }    
			cout << "==============================================================" << endl;
			
			ofstream file("invoice kereta.txt", ios::app);
      
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
      file << " Jenis Kereta      = Kereta Jarak Jauh (KAJJ)" << endl;
      file << "--------------------------------------------------------------" << endl;
			file << "|  Nama  Kereta  |   Berangkat   |    Tiba    |    Kelas     |" << endl;
			file << "--------------------------------------------------------------" << endl;
      file << "     " << namakereta <<"       Yogyakarta     " << tujuan << "       " << kelas << endl;
	    file << "                    " << tanggalpem+1 << "-" << bulanpem << "-";
	    file << tahunpem << "     " << tanggalpem+1 << "-" << bulanpem << "-" << tahunpem << endl;
      file << "                      " << berangkat << "          " << tiba << endl;
	    file << "--------------------------------------------------------------" << endl;
	    file << "|        Nama Penumpang         |           NO ID            |" << endl;
	    file << "--------------------------------------------------------------" << endl;
	    for (int i = 0; i < jumlahpen; i++) {
		    file << "         " << namapenn[i] << "                  "<< idpenn[i] << endl;
	    }  
      file << "--------------------------------------------------------------" << endl;
			file << "|                       DETAIL TRANSAKSI                     |" << endl;
			file << "--------------------------------------------------------------" << endl;
			file << " Jumlah Penumpang                              = " << jumlahpen << " Penumpang" << endl;
			file << " Kelas                                         = " << kelas << endl;
			file << " Harga                                         = " << harga << endl;
			file << "--------------------------------------------------------------" << endl;
			file << " Total Bayar                                   = " << kereta::rekursif(harga, jumlahpen) << endl;
			file << " Bayar                                         = " << saldo << endl;
			file << " Kembali                                       = " << saldo-kereta::rekursif(harga, jumlahpen) << endl;
			file << "==============================================================" << endl;
			file << endl;
      ofstream doks("tiket KAJJ.txt", ios::app);
			for (int i=0; i<jumlahpen; i++) {
				doks << "==============================================================" << endl;
				doks << " KERETA API                                     BOARDING PASS" << endl;
				doks << "--------------------------------------------------------------" << endl;
  			doks << " Nama / Name                    Kodebooking / Bookingcode" << endl;
				doks << " " << namapenn[i] << "                 0000" << i+1 << endl;
				doks << " Nomor Identitas / Id Number    Tipe Penumpang / Pax Type" << endl;
				doks << " " << idpenn[i] << "                     " << kelas << endl;
				doks << " Kereta Api / Train             No Tempat Duduk / Seat Number" << endl;
				doks << " " << namakereta << "                       0000" << i+1 << endl;
				doks << " Berangkat / Departure          Perkiraan Tiba / Eta" << endl;
			  doks << " Yogyakarta                     " << tujuan << endl;
		  	doks << " " << tanggalpem+1 << "-" << bulanpem << "-" << tahunpem;
				doks << "                     " << tanggalpem+1 << "-" << bulanpem << "-" << tahunpem << endl;
        doks << " " << berangkat << "                          " << tiba << endl;
				doks << "--------------------------------------------------------------" << endl;
				doks << "                            Check In At Yogyakarta ";
				doks << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
				doks << "==============================================================" << endl;
				doks << endl;
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

void kereta::tujuanKRL(){
  cout << endl;
  cout << "==============================================================" << endl;
  cout << "       TUJUAN KEBERANGKATAN KERETA COMMUTER LINE (KRL)" << endl;
  cout << "--------------------------------------------------------------" << endl;
  cout << " 1. Solo      Rp 10.000                3. Klaten     Rp 5.000          " << endl;
  cout << " 2. Delanggu  Rp 7.500                 4. Prambanan  Rp 2.500" << endl;
  cout << "==============================================================" << endl;
	cout << " Pilih Tujuan Keberangkatan (1-4) : ";
	cin >> piltujuan;
  if (piltujuan==1){
    tujuan = "Solo";
    harga = 10000;
  }
  else if(piltujuan==2){
    tujuan = "Delanggu";
    harga = 7500;
  }
  else if(piltujuan==3){
    tujuan = "Klaten";
    harga = 5000;
  }
  else if(piltujuan==4){
    tujuan = "Prambanan";
    harga = 2500;
  }
  else{
    cout << endl;
    cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	cout << endl;
    kereta::kembalimenu();
  }
} 
void kereta::jadwalKRL(){
  cout << endl;
  cout << "==============================================================" << endl;
  cout << "       JADWAL KEBERANGKATAN KERETA COMMUTER LINE (KRL)" << endl;
  cout << "==============================================================" << endl;
  cout << "        1. 07.00 WIB                      3. 13.00 WIB     " << endl;
  cout << "        2. 10.00 WIB                      4. 16.00 WIB    " << endl;
  cout << "==============================================================" << endl;
  cout << " Masukkan Pilihan Menu : ";
  cin >> piljadwal;
  if(piljadwal==1){
    berangkat = "07.00";
    if (piltujuan==1){
      tiba = "08.50";
    }
    else if(piltujuan==2){
      tiba = "08.20";
    }
    else if(piltujuan==3){
      tiba = "07.50";
    }
    else if(piltujuan==4){
      tiba = "07.20";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else if(piljadwal==2){
    berangkat = "10.00";
    if (piltujuan==1){
      tiba = "11.50";
    }
    else if(piltujuan==2){
      tiba = "11.20";
    }
    else if(piltujuan==3){
      tiba = "10.50";
    }
    else if(piltujuan==4){
      tiba = "10.20";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else if(piljadwal==3){
    berangkat = "13.00";
    if (piltujuan==1){
      tiba = "14.50";
    }
    else if(piltujuan==2){
      tiba = "14.20";
    }
    else if(piltujuan==3){
      tiba = "13.50";
    }
    else if(piltujuan==4){
      tiba = "13.20";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else if(piljadwal==4){
    berangkat = "16.00";
    if (piltujuan==1){
      tiba = "17.50";
    }
    else if(piltujuan==2){
      tiba = "17.20";
    }
    else if(piltujuan==3){
      tiba = "16.50";
    }
    else if(piltujuan==4){
      tiba = "16.20";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else{
    cout << endl;
    cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	  cout << endl;
    kereta::kembalimenu();
  }
}
void kereta::identitasKRL(){
	cout << endl;
  cout << "==============================================================" << endl;
	cout << "                         DATA PENUMPANG" << endl;
	cout << "==============================================================" << endl;
	cin.ignore(1,'\n');
	cout << " Nama Penumpang : ";
	getline(cin, namapen);
	cout << " ID Penumpang   : ";
	getline(cin, idpen);
  cout << " Tanggal Pemesanan (01-31) : ";
	cin >> tanggalpemm;
	cout << " Bulan Pemesanan (01-12) : ";
	cin >> bulanpem;
	cout << " Tahun Pemesanan : ";
	cin >> tahunpem;
}		

void kereta::tujuanCITLINK(){
  cout << "==============================================================" << endl;
  cout << "        TUJUAN KEBERANGKATAN KERETA BANDARA (CITLINK)" << endl;
  cout << "--------------------------------------------------------------" << endl;
  cout << " 1. Bandara Internasional Adisutjipto               Rp 10.000   " << endl;
  cout << " 2. Bandara Internasional Yogyakarta                Rp 15.000" << endl;
  cout << "==============================================================" << endl;
	cout << " Pilih Tujuan Keberangkatan (1-4) : ";
	cin >> piltujuan;
	cout << endl;
  if (piltujuan==1){
    tujuan = "Bandara Internasional Adisutjipto";
    harga = 10000;
  }
  else if(piltujuan==2){
    tujuan = "Bandara Internasional Yogyakarta";
    harga = 15000;
  }
  else{
    cout << endl;
    cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	cout << endl;
    kereta::kembalimenu();
  }
} 
void kereta::jadwalCITLINK(){
  cout << "==============================================================" << endl;
  cout << "        JADWAL KEBERANGKATAN KERETA BANDARA (CITLINK)" << endl;
  cout << "==============================================================" << endl;
  cout << "        1. 08.00 WIB                      3. 12.00 WIB     " << endl;
  cout << "        2. 10.00 WIB                      4. 14.00 WIB    " << endl;
  cout << "==============================================================" << endl;
  cout << " Masukkan Pilihan Menu : ";
  cin >> piljadwal;
  if(piljadwal==1){
    berangkat = "08.00";
    if (piltujuan==1){
      tiba = "08.15";
    }
    else if(piltujuan==2){
      tiba = "08.30";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else if(piljadwal==2){
    berangkat = "10.00";
    if (piltujuan==1){
      tiba = "10.15";
    }
    else if(piltujuan==2){
      tiba = "10.30";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else if(piljadwal==2){
    berangkat = "12.00";
    if (piltujuan==1){
      tiba = "12.15";
    }
    else if(piltujuan==2){
      tiba = "12.30";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else if(piljadwal==2){
    berangkat = "14.00";
    if (piltujuan==1){
      tiba = "14.15";
    }
    else if(piltujuan==2){
      tiba = "14.30";
    }
    else{
      cout << endl;
      cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	 	  cout << endl;
      kereta::kembalimenu();
    }
  }
  else{
    cout << endl;
    cout << endl << " Maaf, Pilihan Yang Anda Masukkan Salah" << endl;
	  cout << endl;
    kereta::kembalimenu();
  }
}
void kereta::identitasCITLINK(){
  cout << "==============================================================" << endl;
	cout << "                         DATA PEMESANAN" << endl;
	cout << "==============================================================" << endl;
	kereta::datapemesan();
	cout << endl;
  cout << "==============================================================" << endl;
	cout << "                         DATA PENUMPANG" << endl;
	cout << "==============================================================" << endl;
	cin.ignore(1,'\n');
  cout << " Menginputkan Data Penumpang" << endl;
	cout << " Nama Penumpang : ";
	getline(cin, namapen);
	cout << " ID Penumpang   : ";
	getline(cin, idpen);
}	
void kereta::transaksiCITLINK(){
  cout << "==============================================================" << endl;
	cout << "                       DETAIL PEMESANAN" << endl;
	cout << "==============================================================" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|                       Data Penumpang                        |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Nama              = " << namapem << endl;
	cout << " Alamat            = " << alamatpem << endl;
	cout << " Telepon           = " << teleponpem << endl;
	cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
  cout << " Jenis Kereta      = Kereta Bandara (CITLINK)" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|      Nama Kereta      |     Berangkat     |      Tiba      |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "           KRL                Yogyakarta       " << tujuan << endl;
	cout << "                            " << tanggalpem << "-" << bulanpem << "-";
	cout << tahunpem << "      " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
  cout << "                               " << berangkat << "              " << tiba << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|        Nama Penumpang         |           NO ID            |" << endl;
	cout << "--------------------------------------------------------------" << endl;	
	cout << "         " << namapen << "                  "<< idpen << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "|                      Detail Transaksi                      |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Harga                                         = " << harga << endl;
  cout << "--------------------------------------------------------------" << endl;
	cout << " Total Bayar                                   = " << harga << endl;
	cout << "==============================================================" << endl;	
	cout << endl;
  cout << " Melanjutkan Pembayaran (y/n) : ";
	cin >> lanjut;
  if(lanjut=="y"||lanjut=="Y"){
		cout << " Masukkan Saldo Anda : ";
		cin >> saldo;
		if(saldo>=harga){
			cout << " Sisa Saldo Anda : " << saldo-harga << endl << endl;
    	cout << "==============================================================" << endl;
			cout << "                     DETAIL TIKET KERETA" << endl;
			cout << "==============================================================" << endl;
			cout << "--------------------------------------------------------------" << endl;
	    cout << "|                       Data Penumpang                        |" << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    cout << " Nama              = " << namapem << endl;
	    cout << " Alamat            = " << alamatpem << endl;
	    cout << " Telepon           = " << teleponpem << endl;
	    cout << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
      cout << " Jenis Kereta      = Kereta Bandara (CITLINK)" << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    cout << "|      Nama Kereta      |     Berangkat     |      Tiba      |" << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    cout << "           KRL                Yogyakarta       " << tujuan << endl;
	    cout << "                            " << tanggalpem << "-" << bulanpem << "-";
	    cout << tahunpem << "      " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
      cout << "                               " << berangkat << "              " << tiba << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    cout << "|        Nama Penumpang         |           NO ID            |" << endl;
	    cout << "--------------------------------------------------------------" << endl;	
	    cout << "         " << namapen << "                  "<< idpen << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    cout << "|                      Detail Transaksi                      |" << endl;
	    cout << "--------------------------------------------------------------" << endl;
	    cout << " Harga                                         = " << harga << endl;
      cout << "--------------------------------------------------------------" << endl;
	    cout << " Total Bayar                                   = " << harga << endl;
      cout << " Bayar                                         = " << saldo << endl;
			cout << " Kembali                                       = " << saldo-harga << endl;
	    cout << "==============================================================" << endl;	
	    cout << endl;
			
			ofstream file("invoice kereta.txt", ios::app);
      
			file << "==============================================================" << endl;
			file << "                     DETAIL TIKET KERETA" << endl;
			file << "==============================================================" << endl;
			file << "--------------------------------------------------------------" << endl;
	    file << "|                       Data Penumpang                        |" << endl;
	    file << "--------------------------------------------------------------" << endl;
	    file << " Nama              = " << namapem << endl;
	    file << " Alamat            = " << alamatpem << endl;
	    file << " Telepon           = " << teleponpem << endl;
	    file << " Tanggal Pemesanan = " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
      file << " Jenis Kereta      = Kereta Bandara (CITLINK)" << endl;
	    file << "--------------------------------------------------------------" << endl;
	    file << "|      Nama Kereta      |     Berangkat     |      Tiba      |" << endl;
	    file << "--------------------------------------------------------------" << endl;
	    file << "           KRL                Yogyakarta       " << tujuan << endl;
	    file << "                            " << tanggalpem << "-" << bulanpem << "-";
	    file << tahunpem << "      " << tanggalpem << "-" << bulanpem << "-" << tahunpem << endl;
      file << "                               " << berangkat << "              " << tiba << endl;
	    file << "--------------------------------------------------------------" << endl;
	    file << "|        Nama Penumpang         |           NO ID            |" << endl;
	    file << "--------------------------------------------------------------" << endl;	
	    file << "         " << namapen << "                  "<< idpen << endl;
	    file << "--------------------------------------------------------------" << endl;
	    file << "|                      Detail Transaksi                      |" << endl;
	    file << "--------------------------------------------------------------" << endl;
	    file << " Harga                                         = " << harga << endl;
      file << "--------------------------------------------------------------" << endl;
	    file << " Total Bayar                                   = " << harga << endl;
      file << " Bayar                                         = " << saldo << endl;
			file << " Kembali                                       = " << saldo-harga << endl;
	    file << "==============================================================" << endl;	
	    file << endl;
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