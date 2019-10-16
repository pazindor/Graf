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
	string nazwa_cpp[10];
	string polaczenia_cpp[10][10];  // [Numer pliku][Jego polaczenia] 
	string nazwa_h[10];
	string polaczenia_h[10][10];  // [Numer pliku][Jego polaczenia] 
	int licznik_cpp;
	int licznik_h;
	string linijki_cpp[10];
	string linijki_h[10];
	string tekst;


	fstream plik;
	int licznik = 0;
	string linia;

public:
	void pozyskaj();				// pozyskuje nazwy plikow .cpp i .h
	void wczytaj_polaczenia();		//szuka polaczen miedzy plikami
	string licz_linie(string);		//liczy linie
	string szukaj_wage(string);
	void wyslij_stringa();
};
