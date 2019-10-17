#include"Diagram.h"

using namespace std;

int Wezel:: licznik = 0;

Wezel::Wezel(float x, float y)
{
	licznik++;		//do switcha
	float t_X, t_Y;
	shape.setPosition(t_X, t_Y);
	shape.setFillColor(Color::Magenta);
	shape.setRadius(this->circleRadius);

	int liczba_wezlow;

	Wezel* wezly = new Wezel[liczba_wezlow];

	for (size_t i = 0; i < liczba_wezlow; i++) {
		
	}
	
	switch (licznik)
	{
	case 1:
		shape.setOrigin(this->circleRadius, this->circleRadius); // do ustalenia polozenia
		break;
	case 2:
		shape.setOrigin(this->circleRadius-150,this->circleRadius);
		break;
	case 3:
		shape.setOrigin(400,450);
		break;

	case 4:
		shape.setOrigin(200, 300);
		break;

	case 5:
		shape.setOrigin(600, 300);
		break;
	default:
		cout << "Koniec" << endl;
	}
	cout << "Licznik wezlow: " << licznik << endl;
}

Wezel::Wezel(float t_X, float t_Y)
{
	licznik++;
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->circleRadius);
	shape.setFillColor(Color::Yellow);
	switch (licznik)
	{	
	case 1:
		shape.setOrigin(this->circleRadius, this->circleRadius); // do ustalenia polozenia
		break;
	case 2:
		shape.setOrigin(400, 300);
		break;
	case 3:
		shape.setOrigin(400, 450);
		break;

	case 4:
		shape.setOrigin(200, 300);
		break;

	case 5:
		shape.setOrigin(600, 300);
		break;
	}
	cout <<"Licznik wezlow: "<< licznik << endl;
}

void Wezel::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state); 
}
