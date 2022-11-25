#include <iostream>
using namespace std;
class pembalik {
    public:
        pembalik(int angka0=0) : angka(angka0){}
        int mendapat_angka();
        void mengatur_angka(int n);
        void rekursif(int n);
        int iteratif(int n);
    private:
        int angka;
        int angka_balik;
};

void pembalik::mengatur_angka(int n){
    angka = n;
}

int pembalik::mendapat_angka(){
    return angka;
}

int pembalik::iteratif(int n){
    angka_balik = 0;
    while (n>0) {
        angka_balik = angka_balik * 10 + n%10;
        n = n/10;
    }
    return angka_balik;
}

void pembalik::rekursif(int n){
    if (n < 10) cout << n;
    else {
        cout << n % 10;
        pembalik::rekursif(n/10);
    }
}

int main(){
    pembalik test, test2(50);
    int n;
    cout << "Masukkan integer yang akan dibalik : ";
    cin >> n;
    test.mengatur_angka(n);
    cout << "Integer sebelum dibalik : " << test.mendapat_angka() << endl;
    cout << "Integer setelah dibalik";
    cout << "\nSecara Iteratif : " << test.iteratif(test.mendapat_angka());
    cout << "\nSecara Rekursif : "; 
	test.rekursif(test.mendapat_angka());
    return 0;
}