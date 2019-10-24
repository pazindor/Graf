#pragma once
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Naglowki.h"
using namespace std;
void function_rysuj_graf (string graph, string nazwa) {		//spacja
	//tlumaczenie 


	string sciezka = "D:\\STUDIA\\III_Semestr\\InzynieriaOprogramowania\\Grafmaster\\bin\\dot.exe";	//sciezka do pliku
	string tymczasowy = "temp.dot";		//tworzy tymczasowy plik o nazwie temp.dot
	string wyjscie = nazwa +".png";			//koncowy plik o rozszerzeniu png
	//D:\\STUDIA\\III_Semestr\\In¿ynieriaOprogramowania\\Grafmaster\\bin\\dot.exe
	ofstream out;
	out.open(tymczasowy.c_str(), std::ios::out);	//zapis???
	out << graph << std::endl;
	out.close();

	system((sciezka + " " + tymczasowy + " -Tpng -o " + wyjscie).c_str());		//komenda ktora normalnie sie wpisuje w cmd
/*
	std::ofstream plik_wyjsciowy;
	std::string nazwa_pliku;

	plik_wyjsciowy.open(nazwa_pliku.c_str(), std::ios::out);		//zapis  do pliku
	plik_wyjsciowy << (graph);
	plik_wyjsciowy.close();							//zamykanie pliku

	system(("C:\\Users\\Patryk\\Desktop\\Projekt_Graf\\graphviz-2.38\\release\\bin\\dot.exe " + nazwa_pliku + "  -Tpng -o graf.png").c_str());    //musisz sobie zamienic na swoja sciezke
			//chyba musi byc na tej samej partycji co projekt */
}
/////////////////////////////////////////////////////
void Poszukaj:: method_wyslij_stringa()	//spacja
{	
	string graf1 = "graf1";
function_rysuj_graf (tekst, graf1);		//usunac tab
	string graf2 = "graf2";
function_rysuj_graf (tekst2, graf2);	//usunac tab
	cout << "git" << endl;
}
