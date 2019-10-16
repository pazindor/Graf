#pragma once
#include <iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include "wezel.h"


class Graf {
public:
	int ilosc_wezlow;
	sf::RenderWindow window{ sf::VideoMode{800, 600}, "Diagram" };
	sf::Event event;
	Graf();
	~Graf();

	void inicjalizacja();   //rysuje wezly grafu;
	void rysowanie();
};