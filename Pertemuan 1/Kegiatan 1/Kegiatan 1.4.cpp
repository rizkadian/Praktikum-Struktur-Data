#include<iostream>
using namespace std;
float Pangkat(float x, int n){
	if(n==0) return 1;
	if(n==1) return x;
	if(n%2==1){
		cout << " Masuk bagian ganjil\n";
		return Pangkat(x,n-1)*x;
	}
	else{
		cout << " Masuk bagian genap\n";
		return Pangkat(x*x,n/2);
	}
}
int main(){
	Pangkat(2, 6);
	return 0;
}