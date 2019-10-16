#pragma once
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Naglowki.h"

void rysuj_graf(std::string graph) {
	//tlumaczenie 
	
	
	string dotPath = "C:\\Users\\Patryk\\Desktop\\Projekt_Graf\\graphviz-2.38\\release\\bin\\dot.exe ";	//sciezka do pliku
	string tempFile = "temp.dot";		//tworzy tymczasowy plik o nazwie temp.dot
	string outFile = "out.png";			//koncowy plik o rozszerzeniu png

	ofstream out;
	out.open(tempFile.c_str(), std::ios::out);	//zapis???
	out << graph << std::endl;
	out.close();

	system((dotPath + " " + tempFile + " -Tpng -o " + outFile).c_str());		//komenda ktora normalnie sie wpisuje w cmd
/*
	std::ofstream plik_wyjsciowy;
	std::string nazwa_pliku;

	plik_wyjsciowy.open(nazwa_pliku.c_str(), std::ios::out);		//zapis  do pliku
	plik_wyjsciowy << (graph);
	plik_wyjsciowy.close();							//zamykanie pliku

	system(("C:\\Users\\Patryk\\Desktop\\Projekt_Graf\\graphviz-2.38\\release\\bin\\dot.exe " + nazwa_pliku + "  -Tpng -o graf.png").c_str());    //musisz sobie zamienic na swoja sciezke 
			//chyba musi byc na tej samej partycji co projekt */
}

void Poszukaj:: wyslij_stringa()
{
	rysuj_graf(tekst);
}
