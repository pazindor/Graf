#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

#include"Diagram.h"

using namespace std;
using namespace sf;

int main()
{

	Wezel wezel(400, 300);
	Wezel wezel1(600, 300);
	Wezel wezel3;
	RenderWindow window{ VideoMode{800, 600}, "Diagram" };
	window.setFramerateLimit(60);
	Event event;
	while(true)
	{
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.draw(wezel);
		window.draw(wezel1);
		window.draw(wezel3);
		window.display();
	}

	return 0;
}