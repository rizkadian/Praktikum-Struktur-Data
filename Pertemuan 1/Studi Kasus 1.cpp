#include<iostream>
using namespace std;
class kereta{
	public:
		// materi 1 :: class dan rekursif
		void login();
		void tujuan(); 
		void kelas(); 
		void identitas();
		void pembayaran();	
		void cetak();
		void rekursif(int harga, int penumpang);
	private:
		int kelas, tujuan, id;
		string username, password, nama, alamat, telepon, tanggalpesan, namakereta, keberangkatan, tiba, penumpang;
};
void kereta::rekursif(int harga, int penumpang){
	if (penumpang==1)
		return harga;
	else
		return harga+rekursif(harga, penumpang-1);	
}
void kereta::login(){
}
void kereta::tujuan(){
}
void kereta::kelas(){
}
void kereta::identitas(){
}
void kereta::pembayaran(){
}
void kereta::cetak(){
}
int main(){
	cout<<"PROGRAM PEMESANAN TIKET KERETA"<<endl;
	kereta a;
	a.login();
	a.tujuan(); 
	a.kelas(); 
	a.identitas();
	a.pembayaran();
	a.cetak();
	return 0;
}