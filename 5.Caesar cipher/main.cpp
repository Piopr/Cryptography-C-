#include <iostream>
#include <string>
#include<windows.h>

//Piotr Pieprzyk L2

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
	cout<<"Wybierz opcje: "<<endl<<"1.Zaszyfruj"<<endl<<"2.Deszyfruj"<<endl<<"3.Wyjdz"<<endl;

}
void szyfruj(){
	cout<<"Podaj tekst do zaszyfrowania: ";
	string tekst_do_zasz;
	getline(std::cin, tekst_do_zasz);
	getline(std::cin, tekst_do_zasz);
	cout<<"Tekst, ktory bedzie szyfrowany: "<<tekst_do_zasz<<endl;
	//cin.get();
	//cout<<tekst_do_zasz[0]<<" test test0"<<endl;
	//cout<<"Dlugosc tekstu: "<<tekst_do_zasz.length()<<endl;
	//cout<<"Wartosc z tablicy asci: "<<int(tekst_do_zasz[0])<<endl;

	//zakres w asci od A do Z: 65-90
	//zakres w asci od a-z: 97-122
	string zaszyfrowany = tekst_do_zasz;
	for(int i=0 ;i<zaszyfrowany.length();i++){
            //dla duzych od A do W, zwykle przesuniecie
        if((int(zaszyfrowany[i])>=65 && int(zaszyfrowany[i])<=87)){
            zaszyfrowany[i]=(zaszyfrowany[i]+3);
        } //dla duzych XYZ, cofniecie o ilosc znakow w alfabecie i przesuniecie
        else if(int(zaszyfrowany[i])>87 && int(zaszyfrowany[i])<=90){
            zaszyfrowany[i]=(zaszyfrowany[i]-26+3);
        }//dla malych a-w, zwykle przesuniecie
        else if((int(zaszyfrowany[i])>=97 && int(zaszyfrowany[i])<=119)){
            zaszyfrowany[i]=(zaszyfrowany[i]+3);
        }//dla malych xyz, cofniecie o ilosc znakow w alfabecie i przesuniecie
        else if(int(zaszyfrowany[i])>119 && int(zaszyfrowany[i])<=122){
            zaszyfrowany[i]=(zaszyfrowany[i]-26+3);
        }
	}
	cout<<"Zaszyfrowany wyraz: "<<zaszyfrowany<<endl;
	system("pause");
}

void deszyfruj(){
    cout<<"Podaj tekst do odszyfrowania: ";
	string tekst_do_odsz;
	getline(std::cin, tekst_do_odsz);
	getline(std::cin, tekst_do_odsz);
	cout<<"Tekst, ktory bedzie odszyforwywany: "<<tekst_do_odsz<<endl;
	//cin.get();
	//cout<<tekst_do_odsz[0]<<" test test0"<<endl;
	//cout<<"Dlugosc tekstu: "<<tekst_do_odsz.length()<<endl;
	//cout<<"Wartosc z tablicy asci: "<<int(tekst_do_odsz[0])<<endl;

	//zakres w asci od A do Z: 65-90
	//zakres w asci od a-z: 97-122
	string odszyfrowany = tekst_do_odsz;
	for(int i=0 ;i<odszyfrowany.length();i++){
            //dla duzych, od D-Z, przesuniecie w lewo o 3
        if((int(odszyfrowany[i])>=68 && int(odszyfrowany[i])<=90)){
            odszyfrowany[i]=(odszyfrowany[i]-3);
        }// dla duzych ABC, do przedu o alfabet, przesuniecie w lewo o 3
        else if(int(odszyfrowany[i])>=65 && int(odszyfrowany[i])<=67)
        {
            odszyfrowany[i]=(odszyfrowany[i]+26-3);
        }
        else if((int(odszyfrowany[i])>='d' && int(odszyfrowany[i])<='z')){
            odszyfrowany[i]=(odszyfrowany[i]-3);
        }
        else if((int(odszyfrowany[i])>='a' && int(odszyfrowany[i])<='c')){
            odszyfrowany[i]=(odszyfrowany[i]+26-3);
        }

	}
	cout<<"Odszyfrowany wyraz: "<<odszyfrowany<<endl;
	system("pause");
}

int main(int argc, char** argv) {

	while(true){
	int opcja=0;
	menu();
	cin>>opcja;
	switch(opcja){
		case 1:
			szyfruj();
			system("cls");
			break;
		case 2:
			deszyfruj();
			system("cls");
			break;
		case 3:
			exit(1);
		default:
			cout<<"Wybrano zla opcje."<<endl;
			break;
	}
	}


	return 0;
}
