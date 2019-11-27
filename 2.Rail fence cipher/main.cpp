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

void usunSpacje(string & wiadomosc){

     unsigned int i=0;
     while (true)
     {
      i = wiadomosc.find(' ',i);
      if (i!=string::npos)
       wiadomosc.replace(i,1,"");
       else break;
    }





}

void szyfruj(int klucz, string wiadomosc){
    cout<<"Klucz: "<<klucz<<"\nwiadomosc: "<<wiadomosc<<endl;
    char tablica[klucz][wiadomosc.length()];
    //czyszczenie tablicy
    for(int i =0; i<klucz; i++){
        for (int j=0; j<wiadomosc.length(); j++){
            tablica[i][j]='_';
        }
    }
    //iter - iterator, stan - przechodzenie na ukos w odpowiednia strone
    int wiersz=1, kolumna=1, stan=1;
    tablica[0][0]=wiadomosc[0];
    while(kolumna<wiadomosc.length()){
        tablica[wiersz][kolumna]=wiadomosc[kolumna];
        if(wiersz==0) stan = 1;
        else if(wiersz==klucz-1) stan=-1;
        wiersz+=stan;
        kolumna++;
        //cout<<"tutaj?\n";

    }

    //testowe wypisanie
    for(int i =0; i<klucz; i++){
        for (int j=0; j<wiadomosc.length(); j++){
            cout<<" "<<tablica[i][j];
        }
        cout<<endl;
    }

    string szyfrogram;
    for(int i =0; i<klucz; i++){
        for(int j=0; j<wiadomosc.length(); j++){
            if(tablica[i][j]!='_')
            szyfrogram+=tablica[i][j];
        }
    }
    cout<<"Zaszyfrowana wiadomosc: "<<szyfrogram<<endl;








    system("PAUSE");
}

void odszyfruj(int klucz, string wiadomosc){
    int kierunek = 1, index=0;
    //zliczanie ile na 1 wierszu, ile na drugim, ile na trzecim... w zaleznosci od klucza
    int tab[klucz] = {0};

    for(int i=0; i<wiadomosc.length(); i++){
        if(index==klucz-1) kierunek=-1;
        if(index==0) kierunek=1;
        tab[index]++;
        index+=kierunek;
    }
    for(int i=0; i<klucz; i++)
        cout<<" test: "<<tab[i]<<endl;


    char tab_desz[klucz][int(wiadomosc.length()/klucz)*2];

    //wyczyszczenie pamieci
        for(int i =0; i<klucz; i++){
            for (int j=0; j<(int(wiadomosc.length()/klucz))*2; j++){
            tab_desz[i][j]='\0';
        }
    }

    //wypelnienie pierwszego wiersza
    int iter=0;
    for(int j=0; j<tab[0]*2; j+=2){
        tab_desz[0][j]=wiadomosc[iter];
        iter++;
    }
    if(klucz>2){
        //wype³nianie pozosta³ych bez ostatniego wiersza
        iter=tab[0];
        for(int i =1; i<klucz-1; i++){
            for(int j=0; j<tab[i];j++){
                    tab_desz[i][j]=wiadomosc[iter];
                    //j++;
                iter++;
            }
        }
    }
    //wype³nienie ostatniego wiersza
    iter=wiadomosc.length()-tab[klucz-1];
    for(int j=0; j<tab[klucz-1]*2; j+=2){
        tab_desz[klucz-1][j]=wiadomosc[iter];
        iter++;
    }

        //testowe wypisanie
    for(int i =0; i<klucz; i++){
        for (int j=0; j<int(wiadomosc.length()/klucz)*2; j++){
            cout<<" "<<tab_desz[i][j];
        }
        cout<<endl;
    }


    string odszyfrowany;
    for(int i=0; i<int(wiadomosc.length()/klucz)*2;i++){
        for(int j = 0; j<klucz; j++){
            if(tab_desz[j][i]!='\0'){
                    odszyfrowany+=tab_desz[j][i];
            }
        }

        if(i<int(wiadomosc.length()/klucz)*2) i++;
        else break;
        for(int k =klucz-1; k>=0; k--){
            if(tab_desz[k][i]!='\0'){
                odszyfrowany+=tab_desz[k][i];
            }
        }


    }
    cout<<" Odszyfrowana wiadomosc: "<<odszyfrowany<<endl;
    system("PAUSE");
}

int main()
{
    while(true)
    {
        //system("cls");
        int opcja;
        cout<<endl;
        cout<<"Piotr Pieprzyk L2\nSzyfr plotkowy\n 1.Zaszyfruj.\n 2.Odszyfruj\n 0.Wyjdz\n";
        cin>>opcja;
        string  wiadomosc;
        int klucz;
        switch(opcja)
        {
        case 1:

            cout<<"Podaj klucz: ";
            cin.sync();
            //getline(std::cin, klucz);
            cin>>klucz;
            cin.sync();
            cout<<"Podaj tekst do zaszyfrowania: ";
            getline(std::cin, wiadomosc);
            //naWielkie(klucz);
            naWielkie(wiadomosc);
            usunSpacje(wiadomosc);
            szyfruj(klucz, wiadomosc);
            break;
        case 2:
            cout<<"Podaj klucz: ";
            cin.sync();
            //getline(std::cin, klucz);
            cin>>klucz;
            cin.sync();
            cout<<"Podaj zaszyfrowana wiadomosc ";
            getline(std::cin, wiadomosc);
            //naWielkie(klucz);
            naWielkie(wiadomosc);
            usunSpacje(wiadomosc);
            odszyfruj(klucz, wiadomosc);
            break;

        case 0:
            exit(0);
        }

    }
}
