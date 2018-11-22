#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

struct Adresat
{
    int idAdresata = 0;
    string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "";
};

vector<Adresat> ksiazkaAdresowa;

void wczytajAdresatowZPliku(vector<Adresat> &ksiazkaAdresowa, ifstream &plik);
void wyswietlKsiazkeAdresowa (vector<Adresat> &ksiazkaAdresowa);

int main()
{
    int iloscAdresatow = 0;
    //char wybor;

    ifstream plik("ksiazka_adresowa.txt");

    //iloscAdresatow =
    wczytajAdresatowZPliku(ksiazkaAdresowa, plik);
    wyswietlKsiazkeAdresowa (ksiazkaAdresowa);

    //cin.get();
    plik.close();


    return 0;
}

void wczytajAdresatowZPliku(vector<Adresat> &ksiazkaAdresowa, ifstream &plik)
{
    string linia;

    while (getline(plik, linia))
    {
        Adresat osoba;
        istringstream iss(linia);
        string slowo;
        for (int i = 0; i < linia.length(); i++) {
            if (linia[i] != '|')
                slowo += linia[i];
            else if (linia[i] == '|') {
                    iss >> osoba.idAdresata;
                    i = linia.length();
            }
        }

        //cin.clear();
        //string idA;
        //getline(iss, osoba.idAdresata = atoi(linia.c_str()), '|');
        //osoba.idA = atoi(linia.c_str());

        getline(iss, osoba.imie, '|');
        getline(iss, osoba.nazwisko, '|');
        getline(iss, osoba.nrTelefonu, '|');
        getline(iss, osoba.email, '|');
        getline(iss, osoba.adres, '|');


        ksiazkaAdresowa.push_back(osoba);
    }

}

void wyswietlKsiazkeAdresowa (vector<Adresat> &ksiazkaAdresowa)
{
    for (int i = 0; i < ksiazkaAdresowa.size(); ++i)
    {
        cout << ksiazkaAdresowa[i].idAdresata << "aaa" << ksiazkaAdresowa[i].imie << "bbb"
        << ksiazkaAdresowa[i].nazwisko << "ccc" << ksiazkaAdresowa[i].nrTelefonu << "ddd"
        << ksiazkaAdresowa[i].email << "eee" << ksiazkaAdresowa[i].adres << endl;
    }
}
