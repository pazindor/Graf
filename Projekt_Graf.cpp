#pragma once
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include "Naglowki.h"


using namespace std;

int main()
{
	Poszukaj o1;
	 o1. method_pozyskaj ();		//spacja

	for (int i = 0; i < ILE_PLIKOW_CPP; i++)
	{
		 o1.linijki_cpp[i] =  o1. method_licz_linie ( o1.nazwa_cpp[i]); //spacja
	}
	for (int i = 0; i < ILE_PLIKOW_H; i++)
	{
		 o1.linijki_h[i] =  o1. method_licz_linie ( o1.nazwa_h[i]);		//spacja
	}

	 o1. method_wczytaj_polaczenia (); //spacja
	 o1. method_wyslij_stringa ();		//spacja



	system("Pause");
	return 0;
}


