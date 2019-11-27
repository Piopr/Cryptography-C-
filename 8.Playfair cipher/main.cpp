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

void szyfruj(string key, string text){
    //usuwanie powtarzajacych sie znakow z klucza
    int test =key.length();
    for(int i=0; i<test; i++){
        for(int j=0; j<i; j++){
                if(key[i]==key[j])
                    key.replace(i,1,"");
        }
    }
    //zamiast tablicy 5x5 tworzymy liste o dlugosci 25

    char lista[25]={'\0'};

    //wpisanie do niej klucza:
    //zmienna przechowujaca ostatni indeks po wpisaniu klucza:
    int last_index = 0;
    for(int i=0; i<key.length(); i++){
        lista[i]=key[i];
        last_index=i;
    }
    //uzupelnienie pozostalymi znakami, wersja bez 'q'
    char znak='A';
    for(int i = last_index+1; i<25; i++){
        //sprawdzamy, czy wystapil juz znak z klucza
        bool czy_powtorka=false;
        for(int j=0; j<i; j++){
            if(lista[j]==znak) czy_powtorka=true;
        }
        if(!czy_powtorka && znak!='Q') lista[i]=znak;
        else i--;
        znak++;
    }
    //tworzenie tablicy szyfrujacej:
    char tab[5][5];
    for(int i=0; i<25; i++) tab[int(i/5)][(5+i)%5]=lista[i];


    cout<<endl;
    //testowe wypisanie
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<" "<<tab[i][j];
        }
        cout<<endl;
    }

    //sprawdzenie dlugosci wiadomosci. Jesli nieparzysta, to na koncu dodaj 'X';
    if(text.length()%2!=0) text.append("X");
    cout<<endl<<"wiadomosc: "<<text<<endl;
    //zamiana tablicy znakow na stringa po metodê find
    string tablica = lista;
    string szyfrogram;
    for(int i=0; i<text.length(); i+=2){
            char znak1 = text[i];
            char znak2= text[i+1];

            //sprawdzanie wiersza:
            if(int(tablica.find(znak1)/5) == int(tablica.find(znak2)/5))
            {
                szyfrogram+=tab[int(tablica.find(znak1)/5)][(tablica.find(znak1)+1)%5];
                szyfrogram+=tab[int(tablica.find(znak2)/5)][(tablica.find(znak2)+1)%5];
                //cout<<endl<<znak1<<" i " <<znak2<<" sa w tym samym wierszu!"<<endl;
            }
            //sprawdzanie kolumn
            else if(tablica.find(znak1)%5 == tablica.find(znak2)%5){
                if(int(tablica.find(znak1)/5+1)>4)
                    szyfrogram+=tab[0][tablica.find(znak1)%5];
                else szyfrogram+=tab[int(tablica.find(znak1)/5+1)][tablica.find(znak1)%5];
                if(int(tablica.find(znak2)/5+1)>4)
                    szyfrogram+=tab[0][tablica.find(znak2)%5];
                else szyfrogram+=tab[int(tablica.find(znak2)/5+1)][tablica.find(znak2)%5];
               //cout<<endl<<znak1<<" i " <<znak2<<" sa w tej samej kolumnie!"<<endl;
            }
            //pozostale przypadki
            else {
                //cout<<endl<<znak1<<" i "<<znak2<<" pozostala opcja."<<endl;
                szyfrogram+=tab[int(tablica.find(znak1)/5)][tablica.find(znak2)%5];
                szyfrogram+=tab[int(tablica.find(znak2)/5)][tablica.find(znak1)%5];
            }


    }

    cout<<"Szyfrogram: "<<szyfrogram<<endl;
    system("pause");
    }

void deszyfruj(string key, string text){
    //usuwanie powtarzajacych sie znakow z klucza
    int test =key.length();
    for(int i=0; i<test; i++){
        for(int j=0; j<i; j++){
                if(key[i]==key[j])
                    key.replace(i,1,"");
        }
    }
    //zamiast tablicy 5x5 tworzymy liste o dlugosci 25

    char lista[25]={'\0'};

    //wpisanie do niej klucza:
    //zmienna przechowujaca ostatni indeks po wpisaniu klucza:
    int last_index = 0;
    for(int i=0; i<key.length(); i++){
        lista[i]=key[i];
        last_index=i;
    }
    //uzupelnienie pozostalymi znakami, wersja bez 'q'
    char znak='A';
    for(int i = last_index+1; i<25; i++){
        //sprawdzamy, czy wystapil juz znak z klucza
        bool czy_powtorka=false;
        for(int j=0; j<i; j++){
            if(lista[j]==znak) czy_powtorka=true;
        }
        if(!czy_powtorka && znak!='Q') lista[i]=znak;
        else i--;
        znak++;
    }
    //tworzenie tablicy szyfrujacej:
    char tab[5][5];
    for(int i=0; i<25; i++) tab[int(i/5)][(5+i)%5]=lista[i];


    cout<<endl;
    //testowe wypisanie
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<" "<<tab[i][j];
        }
        cout<<endl;
    }

    //sprawdzenie dlugosci wiadomosci. Jesli nieparzysta, to na koncu dodaj 'X';
    if(text.length()%2!=0) text.append("X");
    cout<<endl<<"wiadomosc: "<<text<<endl;
    //zamiana tablicy znakow na stringa po metodê find
    string tablica = lista;
    string szyfrogram;
    for(int i=0; i<text.length(); i+=2){
            char znak1 = text[i];
            char znak2= text[i+1];
            //int teempe = tablica.find(znak1);
            //cout<<teempe<<endl;
            //sprawdzanie wiersza:
            if(int(tablica.find(znak1)/5) == int(tablica.find(znak2)/5))
            {
                if(int(tablica.find(znak1))%5-1<0 || int(tablica.find(znak1))==0) szyfrogram+=tab[int(tablica.find(znak1)/5)][4];
                    else szyfrogram+=tab[int(tablica.find(znak1)/5)][(tablica.find(znak1)-1)%5];
                if(int(tablica.find(znak2))%5-1<0 || int(tablica.find(znak2))==0) szyfrogram+=tab[int(tablica.find(znak2)/5)][4];
                    else szyfrogram+=tab[int(tablica.find(znak2)/5)][(tablica.find(znak2)-1)%5];
                //cout<<endl<<znak1<<" i " <<znak2<<" sa w tym samym wierszu!"<<endl;
            }
            //sprawdzanie kolumn
            else if(tablica.find(znak1)%5 == tablica.find(znak2)%5){
                if(int(tablica.find(znak1)/5-1)<0)
                    szyfrogram+=tab[4][tablica.find(znak1)%5];
                else szyfrogram+=tab[int(tablica.find(znak1)/5-1)][tablica.find(znak1)%5];
                if(int(tablica.find(znak2)/5-1)<0)
                    szyfrogram+=tab[4][tablica.find(znak2)%5];
                else szyfrogram+=tab[int(tablica.find(znak2)/5-1)][tablica.find(znak2)%5];
               //cout<<endl<<znak1<<" i " <<znak2<<" sa w tej samej kolumnie!"<<endl;
            }
            //pozostale przypadki
            else {
                //cout<<endl<<znak1<<" i "<<znak2<<" pozostala opcja."<<endl;
                szyfrogram+=tab[int(tablica.find(znak1)/5)][tablica.find(znak2)%5];
                szyfrogram+=tab[int(tablica.find(znak2)/5)][tablica.find(znak1)%5];
            }


    }

    cout<<"Odszyfrowana wiadomosc: "<<szyfrogram<<endl;
    system("pause");
    }



int main()
{
    while(true)
    {
        system("cls");
        int opcja;
        cout<<"Piotr Pieprzyk, Michal Roman L2\nSzyfr playfair\n 1.Zaszyfruj.\n 2.Odszyfruj\n 0.Wyjdz\n";
        cin>>opcja;
        string  wiadomosc;
        string klucz;
        switch(opcja)
        {
        case 1:

            cout<<"Podaj klucz: ";
            cin.sync();
            getline(std::cin, klucz);
            //cin>>klucz;
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
            //cin>>klucz;
            cin.sync();
            cout<<"Podaj tekst do odszyfrowania: ";
            getline(std::cin, wiadomosc);
            naWielkie(klucz);
            naWielkie(wiadomosc);

            deszyfruj(klucz, wiadomosc);

            break;
        case 0:
            exit(0);

        }

    }
    return 0;
}
