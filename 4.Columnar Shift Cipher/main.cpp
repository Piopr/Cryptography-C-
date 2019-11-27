#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>

using namespace std;

void naWielkie(string & tekst)
{
    for(int i=0; i<tekst.length(); i++)
    {
        if(tekst[i]>='a' && tekst[i]<='z')
            tekst[i]=tekst[i]-32;
    }
}


void szyfruj(string klucz, string wiadomosc)
{

    cout<<"Klucz to: "<<klucz<<" wiadomosc to: "<<wiadomosc<<endl;
    //ilosc wierszy:
    //jesli modulo dlugoscSzyfrowanego i klucz nie jest równe 0:

    //ilosc wierszy = wiadomosc/klucz
    //jesli nie:
    //ilosc wierszy = wiadomosc/klucz +1

    int wiersze = int(wiadomosc.length()/klucz.length())+1;
    //tworzenie tablicy o rozmiarze wiersze i dlugosc klucza;
    char tablica[wiersze][klucz.length()];

    int tabKolejnosc[klucz.length()];
    int kolejnosc_tmp=1;

    //###zapisanie kolejnosci liter w alfabecie z klucza
    //przechodzenie po zakresie A-Z
    //przechodzenie po calym kluczu
    //sprawdzanie, czy w danym indeksie klucza znajduje sie (po kolei) dany znak
    //jesli tak, to przypisz iterator kolejnosc_tmp do danego indeksu i zwieksz iterator
    for(char asci_tmp= 'A'; asci_tmp<='Z'; asci_tmp++)
    {
        for(int i=0; i<klucz.length(); i++)
        {
            if(klucz[i]==asci_tmp)
            {
                tabKolejnosc[i]=kolejnosc_tmp;
                kolejnosc_tmp++;
            }
        }
    }

    //###testowe wypisanie tabKolejnosc:
    for(int i=0; i<klucz.length(); i++)
    {
        cout<<tabKolejnosc[i];
    }

    //##zapisywanie wiadomosci w tabeli
    //przechodzenie po wierszach
    //przechodzenie po kolumnach
    //jesli wyszlo poza zakres szyfrowanej wiadomosci, to w tabeli przypisz '_'
    //jezeli jest w zakresie, przypisz znak z wiadomosci
    for(int i=0; i<wiersze; i++)
    {
        for(int j=0; j<klucz.length(); j++)
        {
            if((i*klucz.length())+j>=wiadomosc.length())
            {
                //cout<<"warunek 1\n";
                tablica[i][j]='_';
            }
            else
            {
                //cout<<"warunek 2, powinienem dodac: "<<wiadomosc[(i*klucz.length())+j]<<endl;
                tablica[i][j]=wiadomosc[(i*klucz.length())+j];
            }

        }
    }

    //###testowe wypisanie tabeli:
    cout<<endl;
    for(int i=0; i<wiersze; i++)
    {
        for(int j=0; j<klucz.length(); j++)
        {
            cout<<" "<<tablica[i][j];
        }
        cout<<endl;
    }

    //##tworzenie finalnej, zaszyfrowanej wiadomosci:
    string zaszyfrowana;
    int tmp=1;
    for(int iter=0; iter<klucz.length(); iter++)
        for(int i=0; i<klucz.length(); i++)
        {
            if(tabKolejnosc[i]==tmp)
            {
                for(int j=0; j<wiersze; j++)
                {
                    //if(tablica[j][i]!='_')
                    zaszyfrowana+=tablica[j][i];
                }
                tmp++;
            }
        }
    cout<<"Zaszyfrowana wiadomosc to: "<<zaszyfrowana<<endl;

    system("PAUSE");
}

void deszyfruj(string klucz, string wiadomosc)
{

    //dlugosc wiadomosci z pominieciem znaku '_'
    int dlugosc =0;
    for(int i =0; i<wiadomosc.length(); i++){
            if(wiadomosc[i]!='_') dlugosc++;
    }
    int wiersze = int(dlugosc/klucz.length())+1;


    //tworzenie tablicy o rozmiarze wiersze i dlugosc klucza;
    char tablica[wiersze][klucz.length()]= {' '};
    int tabKolejnosc[klucz.length()];


    //###zapisanie kolejnosci liter w alfabecie z klucza
    //przechodzenie po zakresie A-Z
    //przechodzenie po calym kluczu
    //sprawdzanie, czy w danym indeksie klucza znajduje sie (po kolei) dany znak
    //jesli tak, to przypisz iterator kolejnosc_tmp do danego indeksu i zwieksz iterator

    int kolejnosc_tmp=1;
    for(char asci_tmp= 'A'; asci_tmp<='Z'; asci_tmp++)
    {
        for(int i=0; i<klucz.length(); i++)
        {
            if(klucz[i]==asci_tmp)
            {
                tabKolejnosc[i]=kolejnosc_tmp;
                kolejnosc_tmp++;
            }
        }
    }

    //###testowe wypisanie tabKolejnosc:
    for(int i=0; i<klucz.length(); i++)
    {
        cout<<tabKolejnosc[i];
    }




    //Przerzucenie zaszyfrowanej wiadomosci do tablicy, rozmiar taki sam, jak w przypadku szyfrowania

    //aby uzupełnić tablicę ilosc wykonan = dlugosc klucza
    int tmpKolej =0;//index znaku z zaszyfrowanej wiadomosci od ktorego zaczac
    for(int i=0; i<klucz.length(); i++){
            //sprawdzanie tablicy z kluczem w poszukiwaniu właściwego indeksu kolumny
            int tmpKolumna=0;
            for(int j = 0; j<klucz.length(); j++){
                    //zapisanie indeksu kolumny
                if(i+1==tabKolejnosc[j]) {
                    tmpKolumna=j;
                    //cout<<"\nIndex kolumny: "<<tmpKolumna;
                    break;
                }

            }

            for(int k = 0; k<wiersze; k++){
                tablica[k][tmpKolumna]=wiadomosc[tmpKolej];
                if(tmpKolej+1>=wiadomosc.length()) break;
                //cout<<" tmp kolejnosc: "<<tmpKolej<<endl;
                tmpKolej++;
            }
            //cout<<endl;
    }

    //###testowe wypisanie tabeli:
    cout<<endl;
    for(int i=0; i<wiersze; i++)
    {
        for(int j=0; j<klucz.length(); j++)
        {
            cout<<" "<<tablica[i][j];
        }
        cout<<endl;
    }
    string odszyfrowana;
    for(int i=0; i<wiersze; i++)
    {
        for(int j=0; j<klucz.length(); j++)
        {
            if(tablica[i][j]!='_') odszyfrowana+=tablica[i][j];
        }
        cout<<endl;
    }

    cout<<"Odszyfrowana wiadomosc: "<<odszyfrowana<<endl;




system("PAUSE");
}

int main()
{
    cout << "" << endl;
    //cout<<koniec;

    while(true)
    {
        system("cls");
        int opcja;
        cout<<"Piotr Pieprzyk L2\nSzyfr przestawieniowy kolumnowy\n 1.Zaszyfruj.\n 2.Odszyfruj\n 0.Wyjdz\n";
        cin>>opcja;
        string klucz, wiadomosc;
        switch(opcja)
        {
        case 1:

            cout<<"Podaj klucz: ";
            cin.sync();
            getline(std::cin, klucz);
            cin.sync();
            cout<<"Podaj tekst do zaszyfrowania: ";
            getline(std::cin, wiadomosc);
            naWielkie(klucz);
            naWielkie(wiadomosc);
            szyfruj(klucz, wiadomosc);
            break;
        case 2:
            cout<<"Podaj klucz: ";
            cin.sync();
            getline(std::cin, klucz);
            cin.sync();
            cout<<"Podaj tekst do odszyfrowania: ";
            getline(std::cin, wiadomosc);
            naWielkie(klucz);
            naWielkie(wiadomosc);
            deszyfruj(klucz, wiadomosc);
            //deszyfruj();
            break;
        case 0:
            exit(0);
        }

    }




    return 0;
}
