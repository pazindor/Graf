#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>

using namespace sf;
using namespace std;

class Wezel : public sf::Drawable
{
public:
	static int licznik;
	Wezel(float t_X, float t_Y);
	Wezel(float, float);
	~Wezel() = default;

	CircleShape shape;
	const float circleRadius{ 25.0f };
	void draw(RenderTarget& target, RenderStates state) const override;
};