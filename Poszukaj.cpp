#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Naglowki.h"
#include <io.h>




using namespace std;

void Poszukaj:: method_pozyskaj()		//spacja
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


	for (int i = 0; i < (ILE_PLIKOW_CPP); i++) {
		if (nazwa_cpp[i] == "graf.cpp") {
			fstream file;
			file.open(nazwa_cpp[i], ios::in);
			string linia;
			int j = 0;
			while (getline(file, linia)) {
				if (linia[0] == 'v') {
					if (linia[5] == 'f') {
						functionNames[j] = linia.erase(0,5);
						functionNames[j].erase(19, functionNames[j].length());
						liczbaMetod++;
						j++;
					}
				}


			}
			file.close();
		}
	}

	for(int  i = 0; i < (ILE_PLIKOW_H); i++){
		if (nazwa_h[i] == "Naglowki.h") {
			fstream file;
			file.open(nazwa_h[0], ios::in);
			string spacja;
			int j = liczbaMetod;
			while (getline(file, spacja, ' ')) {
				if (spacja[0] == 'm') {
					if (spacja[5] == 'd') {
						functionNames[j] = spacja;
						liczbaMetod++;
						j++;
					}
				}


			}
			file.close();
		}
	}
	
	for (int i = 1; i < (ILE_PLIKOW_H); i++)
	{
		SzukamDalej = _findnext(uchwyt, &danePliku);
		nazwa_cpp[licznik_h] = danePliku.name;

		licznik_h++;

	}

	_findclose(uchwyt);

}
///////////////////////////////////////////////////////
void Poszukaj:: method_wczytaj_polaczenia()		//spacja
{
	

	for (int i = 0; i < (ILE_PLIKOW_CPP); i++)	//Dla funkcji
	{
		if (nazwa_cpp[i] == "graf.cpp") {
			plik.open(nazwa_cpp[i], ios::in);
			
			while (getline(plik, linia)) {
				if (linia[0] == 'f') {
					if (linia[1] == 'u') {
						wielkosc_0++;
						
					}
				}

			}
			plik.close();
		}
		else if (nazwa_cpp[i] == "Poszukaj.cpp") {
			plik.open(nazwa_cpp[i], ios::in);
			string spacja;
			while (getline(plik, spacja, ' ')) {
				if (spacja == functionNames[4]) { wielkosc_4++; }
			}
			plik.close();
		}
		else if (nazwa_cpp[i] == "Projekt_Graf.cpp") {
			plik.open(nazwa_cpp[i], ios::in);
			string spacja;

			while (getline(plik, spacja, ' ')) {
				if (spacja == functionNames[1]) { wielkosc_1++; }
				else if (spacja == functionNames[2]) { wielkosc_2++; }
				else if (spacja == functionNames[3]) { wielkosc_3++; }
				else if (spacja == functionNames[5]) { wielkosc_5++; }

			}
			plik.close();
		}
	}




	ostringstream s0;
	s0 << wielkosc_0;
	string S_wielkosc_0 = s0.str();
	
	ostringstream s1;
	s1 << wielkosc_1;
	string S_wielkosc_1 = s1.str();
	
	ostringstream s2;
	s2 << wielkosc_2;
	string S_wielkosc_2 = s2.str();
	
	ostringstream s3;
	s3 << wielkosc_3;
	string S_wielkosc_3 = s3.str();
	
	ostringstream s4;
	s4 << wielkosc_4;
	string S_wielkosc_4 = s4.str();
	
	ostringstream s5;
	s5 << wielkosc_5;
	string S_wielkosc_5 = s5.str();

	for (int i = 0; i < (ILE_PLIKOW_CPP); i++)	//Dla funkcji
	{
		if (nazwa_cpp[i] == "graf.cpp") {
			plik.open(nazwa_cpp[i], ios::in);
			string strzalka = "->";
			
			while (getline(plik, linia)) {
				if (linia[0] == 'v')
				{
					if (linia[16] == 'm')
					{
						
						streampos iOdczytanaPozycja = plik.tellg();
						fstream file;
						file.open(nazwa_cpp[i], ios::in);
						string spacja;
						file.seekg(iOdczytanaPozycja);
						
						while (getline(file, linia)) {		//
							if (linia[0] == 'f') {
								if (linia[4] == 't') {
									waga_f++;
									wyjscie2[0] = "\"" + functionNames[5] + "(" + S_wielkosc_5 + ")" + "\"" + strzalka + "\"" + functionNames[0] + "(" + S_wielkosc_0 + ")\"";
								}
							}
						}
						file.close();
					}
				}
			}
			plik.close();
		}
		else if (nazwa_cpp[i] == "Poszukaj.cpp") {
			plik.open(nazwa_cpp[i], ios::in);
			int ktore_polaczenie = 0;
			string strzalka = "->";
			while (getline(plik, linia)) {
				if (linia[0] == 'v')
				{
					if (linia[24] == 'c')
					{
						
						streampos iOdczytanaPozycja = plik.tellg();
						fstream file;
						file.open(nazwa_cpp[i], ios::in);
						string spacja;
						file.seekg(iOdczytanaPozycja);
						while (getline(file, spacja, ' ')) {
							if(spacja.length()<19){
								if (spacja[0] == 'm') {
									if (spacja[7] == 's') {
										waga_m++;
										wyjscie2[1] = "\"" + functionNames[2] + "(" + S_wielkosc_2 + ")" + "\"" + strzalka + "\""+ functionNames[4] + "(" + S_wielkosc_4 + ")\"";
									

									}
								}
							}
						}
						file.close();
					}
				}
				
			}
			plik.close();
			
		}
		
	}
	string dig = "digraph G {";
	ostringstream wf;
	wf << waga_f;
	string waga_f = wf.str();
	ostringstream wm;
	wm << waga_m;
	string waga_m = wm.str();
	string strzalka = "->";
	wyjscie2[0] =  wyjscie2[0] + "[ label = \"" + waga_f + "\" ];\n";
	wyjscie2[1] =  wyjscie2[1] + "[ label = \"" + waga_m + "\" ];\n";
	wyjscie2[2] = "\"" + functionNames[1] + "("+ S_wielkosc_1 +")" +  "\"" +  "; \n";
	wyjscie2[3] = "\"" + functionNames[3] +"(" +  S_wielkosc_3 + ")" + "\"" + "; \n";
	tekst2 = dig + wyjscie2[0] + wyjscie2[1] + wyjscie2[2] + wyjscie2[3] + "}";

	for (int i = 0; i < (ILE_PLIKOW_CPP); i++)	//Dla plikow cpp
	{
		plik.open(nazwa_cpp[i], ios::in);
		int ktore_polaczenie = 0; // kataloguje polaczenia w tablicy 2-wymiarowej
		string strzalka = "->";

		while (getline(plik, linia))
		{
			if (linia[0] == '#')
			{
				if (linia[9] == '"')
				{
					polaczenia_cpp[i][ktore_polaczenie] = linia.erase(0, 10);
					polaczenia_cpp[i][ktore_polaczenie].erase(polaczenia_cpp[i][ktore_polaczenie].length() - 1, polaczenia_cpp[i][ktore_polaczenie].length());
					wyjscie[i] = "\"" + polaczenia_cpp[i][ktore_polaczenie] + "(" + linijki_h[0] + ")\"" + strzalka + "\"" + nazwa_cpp[i] + "(" + linijki_cpp[i]+ ")\"" + "[ label = \"" + method_szukaj_wage (nazwa_cpp[i]) + "\" ];\n";		//spacja
					ktore_polaczenie++;
				}
			}
		}
		plik.close();
	}
	tekst = dig + wyjscie[0] + wyjscie[1] + wyjscie[2] + "}";
}
////////////////////////////////////////////////////////////////
string Poszukaj:: method_licz_linie(string nazwa_pliku)		//spacja
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
////////////////////////////////////////////////////////////////
string Poszukaj:: method_szukaj_wage(string plik1)		//spacja
{


	int waga = 0;

	ostringstream ss;


	if (plik1 == "Projekt_Graf.cpp")
	{
		fstream file;
		file.open(plik1, ios::in);
		string spacja;

		while (getline(file, spacja, ' ')) {

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

			if (spacja.length() >= 5) {

				if (spacja[0] == 'm') {
					if (spacja[5] == 'd') {
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

			if (spacja[0] == 'm') {
				if (spacja[5] == 'd') {
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