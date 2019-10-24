#pragma once
#pragma once
#include <iostream>
#include <fstream>

//DEFINICJE 
constexpr auto ILE_PLIKOW_CPP = 3;
constexpr auto ILE_PLIKOW_H = 1;

using namespace std;

class Poszukaj
{
public:
	string wyjscie[10];
	string wyjscie2[10];
	string nazwa_cpp[10];
	string polaczenia_cpp[10][10];  // [Numer pliku][Jego polaczenia] 
	string nazwa_h[10];
	string polaczenia_h[10][10];  // [Numer pliku][Jego polaczenia] 
	int licznik_cpp;
	int licznik_h;
	string linijki_cpp[10];
	string linijki_h[10];
	string tekst;
	string tekst2;
	string functionNames[10];
	int liczbaMetod;
	string polaczenia_f[10][10];
	int wielkosc_0, wielkosc_1, wielkosc_2, wielkosc_3, wielkosc_4, wielkosc_5;
	int waga_f,waga_m;
	fstream plik;
	int licznik = 0;
	string linia;

public: 
	 void method_pozyskaj () ;				 // pozyskuje nazwy plikow .cpp i .h spacja
	 void method_wczytaj_polaczenia () ;		 //szuka polaczen miedzy plikami spacja
	 string method_licz_linie (string) ;		 //liczy linie spacja
	 string method_szukaj_wage (string) ;		//spacja
	 void method_wyslij_stringa () ;			//spacja
};

