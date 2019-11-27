#include <iostream>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    string tekst, klucz;

    cout<<"Co chcesz zaszyfrowac? Wpisz tekst:";
    getline(cin, tekst);
    cout<<"\ntest tekst: "<<tekst<<endl;
    cout<<"Podaj klucz:";
    //cin.sync();
    getline(cin, klucz);
    char tab[10-klucz.length()][10];
    int temp = 97;

    //dla klucza, wiersz 0

        //for od 0 do klucz.length, wpisanie

    //zapisywanie klucza do tablicy
    for(int i=0; i<klucz.length(); i++){
        tab[0][i]=char(klucz[i]);
    }
    //zapisywanie pozostalych znakow
        //tymczasowa zmienna do znakow ascii
        //iterowac od wiersza = 1 do 10-klucz.length(), by wpisac do wlasciwych wierszy
            //iterowac od 0 do 9, by wpisac do wlasciwych kolumn
                //iterowac po tekscie do zaszyfrowania (od 0 do tekst.length()
                    //jesli znaku z tekstu nie ma w kluczu wpisz do tablicy, zwieksz iterator kolumny/wiersza + tmp znaku ascii
                    //jesli nie, nie zwiekszac iteratora kolumny/wiersza, zwiekszyc ascii
                    //sprawdzac, czy nie wyszliscmy znakow ascii. jesli tak skonczyc wpisywanie do tablicy;

    int tmp = 97;
    //int t=0;//iterator do przejscia po zaszyfrowanym tekscie, pamietac o ograniczniku
    bool flaga_koniec =0;

    //zapisywanie pozostalych znakow
    for(int i=1; i<10-klucz.length(); i++){//iterator wiersza
        cout<<"\przed flaga koniec \n";
        if(flaga_koniec) break;
        cout<<"\po flaga koniec \n";
        for(int j=0; j<10; i++){//iterator kolumny
                cout<<"\przed flaga  \n";
                bool flaga = 0;//flaga do sprawdzania, czy znak znajduje sie w tekscie
                cout<<"\po flaga  \n";
                for(int k=0; k<klucz.length(); k++){//iterator do przechodzenia po tekscie
                        //cout<<"\ndlugosc klucza: "<<klucz.length()<<" wartosc: "<<klucz[k]<<"iteracja: "<<k<<endl;
                        if(tmp==klucz[k]) flaga=1;
                }

                if(!flaga){
                    tab[i][j]=tmp;
                    //t++;
                    tmp++;
                }
                else{
                    tmp++;
                    //t++;
                    i--;
                    j--;
                }
                if(tmp+1>122) flaga_koniec=1;
                if(flaga_koniec) break;

        }
    }
    cout<<"Drukuje se tablice: \n";
    for(int i = 0; i<10-klucz.length();i++){
        for(int j = 0; j<10; j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<"\n";

    }
    return 0;
}
