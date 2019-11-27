#include <iostream>
#include <string>
#include<windows.h>

//Piotr Pieprzyk L2


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
	cout<<"Piotr Pieprzyk L2 - szyfr przestawieniowy.\nWybierz opcje: "<<endl<<"1.Zaszyfruj"<<endl<<"2.Deszyfruj"<<endl<<"3.Wyjdz"<<endl;

}
void szyfruj(){
	cout<<"Podaj tekst do zaszyfrowania: ";
	string tekst_do_zasz;
	getline(std::cin, tekst_do_zasz);
	getline(std::cin, tekst_do_zasz);//pobieranie ciagu znakow, 2razy, bo cos nie dzialalo (czysczenie bufora?)
	cout<<"Tekst, ktory bedzie szyfrowany: "<<tekst_do_zasz<<endl;
	string zaszyfrowany = tekst_do_zasz;
	for(int i=0 ;i<zaszyfrowany.length();i+=2){//przechodzenie tablicy znakow co dwa znaki, zamiana babelkowa
            //sprawdzamy, czy aktualny znak jest spacj¹
            if(zaszyfrowany[i]==' '){
                    i-=1;//by pomijac tylko jeden znak, brak zamiany

            }
            //czy kolejny znak jest spacj¹. Jeœli tak, to zwiêksz iterator o 2
            else if(zaszyfrowany[i+1]==' '){
                //nic nie rob, brak zamiany takze w przyszlym
            }
            //jeœli nie wyjdziemy poza zakres, to zamieniamy znaki
            else if(!(i+1>=zaszyfrowany.length())){
                char tmp=zaszyfrowany[i];//tymczasowa do zamiany
                zaszyfrowany[i]=zaszyfrowany[i+1];//zamiana pierwszy z deugim
                zaszyfrowany[i+1]=tmp;//do drugiego przypisujemy pierwszy
            }
	}
	cout<<"Zaszyfrowany wyraz: "<<zaszyfrowany<<endl;
	system("pause");
}

void deszyfruj(){
    cout<<"Podaj tekst do odszyfrowania: ";
	string tekst_do_odsz;
	getline(std::cin, tekst_do_odsz);
	getline(std::cin, tekst_do_odsz);//pobieranie ciagu znakow, 2razy, bo cos nie dzialalo (czyszczenie bufora?)
	cout<<"Tekst, ktory bedzie odszyforwywany: "<<tekst_do_odsz<<endl;
	string odszyfrowany = tekst_do_odsz;
	//deszyfrowanie takie samo, jak szyfrowanie
	for(int i=0 ;i<odszyfrowany.length();i+=2){
            if(!(odszyfrowany[i]>'a' && odszyfrowany[i]<'z' && odszyfrowany[i]>'A' && odszyfrowany[i]<'Z')){
                i-=1;//by pomijac tylko jeden znak
            }
            else if(!(odszyfrowany[i]>'a' && odszyfrowany[i]<'z' && odszyfrowany[i]>'A' && odszyfrowany[i]<'Z')){
                //nic nie rob, brak zamiany takze w przyszlym
            }
            else if(!(i+1>=odszyfrowany.length())){
                char tmp=odszyfrowany[i];
                odszyfrowany[i]=odszyfrowany[i+1];
                odszyfrowany[i+1]=tmp;
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
