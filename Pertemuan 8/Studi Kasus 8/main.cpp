#include <iostream>
#include <fstream>
#include <istream>
#include <stdlib.h>
#include "class_kereta.h"
#include "class_covid.h"
#define MAX 5

using namespace std;

int main(){
	kereta k; 
  covid c;
  int pilutama;
  system("clear");
  cout << "==============================================================" << endl;
  cout << "|                                                            |" << endl;
  cout << "|                      STASIUN YOGYAKARTA                    |" << endl;
  cout << "|  Rabu, Kec. Prambanan, Kabupaten Sleman, Yogyakarta 87417  |" << endl;
  cout << "|                                                            |" << endl;
  cout << "==============================================================" << endl << endl;
  cout << "==============================================================" << endl;
  cout << "                         MENU UTAMA" << endl;
	cout << "--------------------------------------------------------------" << endl;
  cout << " 1. Tiket Kereta" << endl;
  cout << " 2. Tes Covid" << endl;
  cout << "==============================================================" << endl;
  cout << " Masukkan Pilihan Menu : ";
  cin >> pilutama;
  if (pilutama==1){
    k.menu();
  }
  else if (pilutama==2){
    c.tescovid();
  }
  else{
  	main();
  }
	return 0;
}