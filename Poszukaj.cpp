#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Naglowki.h"
#include <io.h>




using namespace std;

void Poszukaj:: pozyskaj()
{
	//pozyskuje nazwy plikow .cpp

	_finddata_t danePliku;
	long uchwyt = _findfirst("*.cpp", &danePliku);
	
	nazwa_cpp[0] = danePliku.name;
	
	licznik_cpp = 1;
	
	int SzukamDalej;


	for (int i = 1; i < (ILE_PLIKOW_CPP); i++)
	{
		SzukamDalej = _findnext(uchwyt, &danePliku);
		nazwa_cpp[licznik_cpp] = danePliku.name;
		
		licznik_cpp++;
		
	} 

	_findclose(uchwyt);

	//pozyskuje nazwy plikow .h

	uchwyt = _findfirst("*.h", &danePliku);

	nazwa_h[0] = danePliku.name;
	
	licznik_h = 1;
	


	for (int i = 1; i < (ILE_PLIKOW_H); i++)
	{
		SzukamDalej = _findnext(uchwyt, &danePliku);
		nazwa_cpp[licznik_h] = danePliku.name;
		
		licznik_h++;
		
	}

	_findclose(uchwyt);

}

void Poszukaj:: wczytaj_polaczenia()
{
	//Dla plikow cpp

	for (int i = 0; i < (ILE_PLIKOW_CPP); i++)
	{
		plik.open(nazwa_cpp[i], ios::in);
		int ktore_polaczenie = 0; // kataloguje polaczenia w tablicy 2-wymiarowej

		string strzalka = "->";
		string dig = "digraph G {";

		while (getline(plik, linia))
		{
			if (linia[0] == '#')
			{
				if (linia[9] == '"')
				{
					polaczenia_cpp[i][ktore_polaczenie] = linia.erase(0, 10);
					polaczenia_cpp[i][ktore_polaczenie].erase(polaczenia_cpp[i][ktore_polaczenie].length() - 1, polaczenia_cpp[i][ktore_polaczenie].length());
					wyjscie[i] = polaczenia_cpp[i][ktore_polaczenie].erase(polaczenia_cpp[i][ktore_polaczenie].length()-2, polaczenia_cpp[i][ktore_polaczenie].length()) + linijki_h[0] +  strzalka + nazwa_cpp[i].erase(nazwa_cpp[i].length() - 4, nazwa_cpp[i].length())  + linijki_cpp[i] + "[ label = \"" + szukaj_wage(nazwa_cpp[i]) + "\" ];\n";
					ktore_polaczenie++;
				}
			}
		}

		tekst = dig + wyjscie[0] + wyjscie[1] + wyjscie[2] + "}";

		plik.close();
	}
}

string Poszukaj:: licz_linie(string nazwa_pliku)
{
	fstream plik1;
	int ilosc = 0;
	string linijka;

	plik1.open(nazwa_pliku, ios::in);

	while (!plik1.eof())
	{
 		getline(plik1, linijka);
		ilosc++;
	}

	ostringstream ss;
	ss << ilosc;
	string iloscs = ss.str();

	plik1.close();
	return iloscs;
}

string Poszukaj:: szukaj_wage(string plik1)
{
	//string szukam[7] = { "o1","pozyskaj" ,"licz_linie" ,"szukaj_wage","wczytaj_polaczenia","wyslij_stringa","#include \"Naglowki.h\"" };

	int waga = 0;

	ostringstream ss;
	

	if (plik1 == "Projekt_Graf.cpp")
	{
		fstream file;
		file.open(plik1, ios::in);
		string spacja;

		while (getline(file, spacja, ' ' )) { 
			
			if (spacja[0] == 'o') {
				if (spacja[1] == '1') {
					waga++;
				}
			}
		}
		
		file.close();
	}

	else if (plik1 == "Poszukaj.cpp")
	{
		fstream file;
		file.open(plik1, ios::in);
		string spacja;

		while (getline(file, spacja, ' ')) {
		
			if (spacja.length()>=5) {

				if (spacja[0] == 'p') {
					if (spacja[3] == 'y') {
						waga++;
					}
				}
				else if (spacja[0] == 'w') {
					if (spacja[5] == 'a') {
						waga++;
					}
				}
				else if (spacja[0] == 'l') {
					if (spacja[5] == 'l') {
						waga++;
					}
				}
				else if (spacja[0] == 's') {
					if (spacja[5] == 'j') {
						waga++;
					}
				}
				
			}
		}

		file.close();
	} 
	else if (plik1 == "graf.cpp")
	{
		fstream file;
		file.open(plik1, ios::in);
		string spacja;

		while (getline(file, spacja, ' ')) {

			if (spacja[0] == 'w') {
				if (spacja[6] == '_') {
					waga++;
				}
			}


		}

		file.close();
	}

	ss << waga;
	string wagas = ss.str();
	return wagas;
}