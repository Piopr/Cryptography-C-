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

void szyfruj(string klucz, string text){
    //tworzenie tabula recta
    char tab[26][26] = {0};
    int a = 0;
    for(int i = 0; i<26; i++){
        for(int j =0; j<26; j++){
            if(j+a<26){
                tab[i][j] = char('A'+j+a);
            }
            else {
                tab[i][j] = char('A'+j+a-26);
            }
        }
        a++;
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            cout<<' '<<tab[i][j];
        }
        cout<<'\n';
    }
    int index_x =0 , index_y =0;
    int index_klucza = 0;
    string zaszyfrowana;
    int j=0;
    for(int i=0; i<text.length(); i++){
        j=0;
        while(tab[0][j]!=text[i]){
            //cout<<tab[0][j]<<" "<< text[i];
            j++;
        }
        cout<<"Znaleziono kolumne, index: "<< j<<' ';
        int k=0;
        while(tab[k][j]!=klucz[index_klucza]) k++;
        cout<<"Znaleziono index wiersza: "<< k<<endl;
        if(index_klucza=klucz.length()) index_klucza =0;
        zaszyfrowana+=tab[k][0];
        index_klucza++;
    }

    cout<<zaszyfrowana<<endl;

    system("pause");
}



int main()
{
while(true)
    {
        system("cls");
        int opcja;
        cout<<"Piotr Pieprzyk L2\nSzyfr plotkowy\n 1.Zaszyfruj.\n 2.Odszyfruj\n 0.Wyjdz\n";
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
            //usunSpacje(wiadomosc);
            szyfruj(klucz, wiadomosc);
            break;
        case 2:
            //deszyfruj();
            break;
        case 0:
            exit(0);

        }

    }
    return 0;
}
