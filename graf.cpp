#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include "graf.h"

Graf::Graf(){
	std::cin >> ilosc_wezlow;
	//window = new sf::RenderWindow{sf::VideoMode{1366, 768}, "Graf" };
	
	Wezel* wezly = new Wezel[ilosc_wezlow]; // tworzy tablice wezlow na podstawie ilosci podanej
	wezly[0].shape.setOrigin(683, 384); // tworzy wezel maina na srodku ekranu
	wezly[0].shape.setRadius(radius / ilosc_wezlow * 2);
	wezly[0].nazwa = "main.cpp";

	for (int i = 1; i < ilosc_wezlow; i++) {
		for (int j = i + 1; j < ilosc_wezlow; j++) {

		}
	}

	while (true)
	{
		window.clear(sf::Color::Black);
		//////////zeby okno dalo sie zamknac/////////
		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}
		window.draw(wezly[0].shape);
		window.display();
	}
	//////////////////////////////////////////////
	
	//window.draw(wezly[0].shape);
	//window.display();
}

Graf::~Graf() {
}

void Graf::inicjalizacja(){
	//std::cin >> ilosc_wezlow;

}










