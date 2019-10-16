#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include "graf.h"

extern constexpr float radius = 25.;
class Wezel {
public:
	sf::CircleShape shape;	
	std::string nazwa;

	Wezel();
	~Wezel() = default;
};
