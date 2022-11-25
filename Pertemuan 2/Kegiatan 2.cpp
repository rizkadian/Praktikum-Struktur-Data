#include <iostream>
#include <stdio.h>
#define maks 5		
using namespace std;
class Array1D{
	friend ostream& operator<<(ostream&, const Array1D&);
	friend istream& operator>>(istream&, Array1D&);
	public:						
		Array1D();				
		void cetak();			
		void geser_kiri();		
		void geser_kanan();		
		char A[maks];
};
Array1D::Array1D(){
	for(int i=0;i<maks;i++){
		A[i]='0';
	}
}
void Array1D::cetak(){
	for(int i=0; i<maks; i++){
		cout<<A[i]<<" ";
	}
}
ostream& operator<<(ostream& out, Array1D& x){
	for(int i=0; i<maks; i++){
		cout<<x.A[i]<<" ";
	}
	cout<<endl;
	return out;
}
istream& operator>>(istream& in, Array1D& x){
	int posisi;
	for(int i=0; i<maks; i++){
		cout<<"Mengisi array pada posisi ke 	: ";
		in>>posisi;
		if(posisi>0 && posisi <=maks){
			cout<<"Masukkan elemen array-nya \t: ";
			in>>x.A[posisi-1];
		}else{
			cout<<"Anda memasukkan posisi di luar range...";
		}
	}
	return in;
}
void Array1D::geser_kanan(){
	int n = maks;
	int temp = A[n-1];
	for(int i=n; i>=0; i--){
		A[i+1]=A[i];
	}
	A[0]=temp;
}
void Array1D::geser_kiri(){
	int n=maks;
	int temp = A[0];
	for(int i=0; i<n; i++){
		A[i]=A[i+1];
	}
	A[n-1]=temp;
}
main(){
	Array1D x;
	cout<<"Array masih kosong 		: "<<x;
	cin>>x;
	cout<<"Isi Array saat ini 		: "<<x;
	x.geser_kiri();
	cout<<"Isi Array setelah digeser ke kiri  	: "<<x;
	x.geser_kanan();
	cout<<"Isi Array setelah digeser ke kanan 	: "<<x;
	return 0;
}