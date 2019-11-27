//Piotr Pieprzyk L2, szyfr Bacona
#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;
string tablica[] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa",
                    "aabab", "aabba", "aabbb", "abaaa","abaaa", "abaab",
                    "ababa", "ababb", "abbaa", "abbab", "abbba",
                      "abbbb", "abbbb", "baaab", "baaba", "baabb", "baabb",
                      "babaa", "babab",  "babba", "babbb"};

void naMale(string tekst){
    for(int i=0; i<tekst.length();i++){
        if(tekst[i]>=65 && tekst[i]<=90)
            tekst[i]=tekst[i]+32;
    }
}

void szyfruj(){
    string szyfruj;
    cout<<"Podaj tekst do zaszyfrowania: ";
    cin.sync();
    getline(std::cin, szyfruj);
    naMale(szyfruj);
    //zmienna dajaca wynikowy string
    string zaszyfrowany ="";
    for(int i=0; i<szyfruj.length();i++){
        //znak-'a' = odpowiada indeksowi w tablicy
        zaszyfrowany+=tablica[szyfruj[i]-'a'];
        zaszyfrowany+=" ";
    }
    cout<<"Zaszyfrowany: "<<zaszyfrowany<<endl;
    system("PAUSE");
}

void deszyfruj(){
    string deszyfrowany;
    cout<<"Podaj tekst do odszyfrowania: ";
    cin.sync();
    getline(std::cin, deszyfrowany);
    naMale(deszyfrowany);
    //wynikowy odszyfrowany tekst
    string odszyfrowany ="";
    //zmienna do "zbierania" ciagu np. "aaaaa"
    string tmp="";
    //po zaszyfrowanym tekscie, indeksowanie co 6 = 5znakow + spacja
    for(int i=0; i<deszyfrowany.length(); i+=6){
            //indeksowanie co jeden, i+j = wlasciwy indeks 0-4, 6-10
            for(int j=0; j<5; j++){
                    tmp+=deszyfrowany[i+j];
            }
            //cout<<"Po wpisaniu: "<<tmp<<endl;
            //26 = dlugosc tablicy
            //sprawdzanie ciagu po calej globalnej tablicy
            for(int k=0; k<26; k++){
                if(tablica[k]==tmp){
                        odszyfrowany+=char(k+65);
                        break;
                }
            }
            tmp="";
    }
    cout<<"Odszyfrowany: "<<odszyfrowany<<endl;
    system("PAUSE");
}
int main()
{
    while(true){

        system("cls");
        int opcja;
        cout<<"Piotr Pieprzyk L2\nSzyfr Bacona\n 1.Zaszyfruj.\n 2.Odszyfruj\n 0.Wyjdz\n";
        cin>>opcja;

	    switch(opcja)
        {
        case 1:
            szyfruj();
            break;
        case 2:
            deszyfruj();
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}
