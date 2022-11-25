#include <iostream>
using namespace std;
class Bilangan{
	friend ostream& operator<<(ostream&, const Bilangan&);
	friend istream& operator>>(istream&, Bilangan&);
	public:
		Bilangan(int a0=0, float b0=0) : a(a0), b(b0) {}
		void banding_int(const Bilangan&, const Bilangan&);
		Bilangan& operator=(const Bilangan&);
		Bilangan operator+(const Bilangan&) const;
		Bilangan operator-()const;
	private:
		int a;
		float b;
};
ostream& operator<<(ostream& out, const Bilangan& x){
	out<<"Bagian integer : "<<x.a<<endl;
	out<<"Bagian float : "<<x.b<<endl;
	return out;
}
void Bilangan::banding_int(const Bilangan& x, const Bilangan& y){
	if(x.a>y.a) cout<<x.a<<"::x lebih besar dari"<<y.a<<"::y";
	else cout<<x.a<<"::x lebih kecil dari "<<y.a<<"::y";
}
Bilangan& Bilangan::operator=(const Bilangan& x){
	a=x.a;
	b=x.b;
	return *this;
}
istream& operator>>(istream& in, Bilangan& x){
	cout<<"\nMasukkan bagian integer : ";
	in>>x.a;
	cout<<"Masukkan bagian float : ";
	in>>x.b;
	return in;
}
Bilangan Bilangan::operator+(const Bilangan& x) const{
	Bilangan cc;
	cc.a=a+x.a;
	cc.b=b+x.b;
	return cc;
}
Bilangan Bilangan::operator-() const{
	Bilangan x;
	x.a=-a;
	x.b=-b;
	return x;
}
int main(){
	Bilangan s, t(-2,3.14), d;
	cout<<"Nilai awal s\n"<<s; //operator biner<<output
	cout<<"Nilai awal t dari deklarasi\n"<<t;
	s=t;	//operator biner=
	cout<<"Setelah s di-assign t\n";
	cout<<"Nilai s\n" <<s;
	cout<<"Masukkan nilai-nilai objek d";
	cin>>d;	//operator>>input
	cout<<"Setelah d+t => \n"<<d+t;	//operator biner +
	cout<<"Nilai d dinegatifkan\n"<<-d;	//operator uner-
}