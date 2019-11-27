#include <iostream>

using namespace std;

void atbash(string zaszyfr){
    string tekst="";
    for(int i=0; i<zaszyfr.length(); i++){
            //obsluga a-z
                                    // Od najglebszego nawiasu: liczba dajaca od³oœæ znaku od 'Z', 25-poprzednie =
                                    //odleg³oœæ od 'A', wynik ju¿ z odwróconymi znakami

        if(zaszyfr[i]>='a' && zaszyfr[i]<='z'){
            tekst+=char('z'-(25-('z'-zaszyfr[i])));
            //cout<<tekst<<endl;
        }
    //obsluga A-Z
        //Od najglebszego nawiasu: liczba dajaca od³oœæ znaku od 'Z',
        //25-poprzednie = odleg³oœæ od 'A', wynik ju¿ z odwróconymi znakami
        if(zaszyfr[i]>='A' && zaszyfr[i]<='Z'){

            tekst+=char('Z'-(25-('Z'-zaszyfr[i])));
        }
    }
    cout<<" "<<tekst<<endl;


}

int main()
{
    string zaszyfr, odszyfr;
    cout<<"Podaj tekst do zaszyfrowania: ";
    getline(std::cin, zaszyfr);
    cout<<"Zaszyfrowany tekst: ";
    atbash(zaszyfr);
    cout<<"Podaj tekst do odszyfrowania: ";
    getline(std::cin, odszyfr);
    cout<<"Odszyfrowany tekst: ";
    atbash(odszyfr);



    return 0;
}
