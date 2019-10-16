#pragma once
#include <iostream>
#include "Naglowki.h"


using namespace std;

int main()
{	
	 Poszukaj o1;
	 o1.pozyskaj();
	
	for (int i = 0; i < ILE_PLIKOW_CPP; i++)
	{
		 o1.linijki_cpp[i] = o1.licz_linie( o1.nazwa_cpp[i]);
	}
	for (int i = 0; i < ILE_PLIKOW_H; i++)
	{
		 o1.linijki_h[i] = o1.licz_linie( o1.nazwa_h[i]);
	}

	 o1.wczytaj_polaczenia();
	 o1.wyslij_stringa();

	return 0;
}


