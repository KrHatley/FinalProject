#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"FireSpell.h"
#include<SFML\Audio.hpp>// smart fast media library
#include<SFML\Graphics.hpp>
#include<ctime>
using namespace std;// using the standard library namespace
using namespace sf;// smart fast namespace

class Goblin
{
	
public:
	enum GoblinEnum
	{
		dead, alive
	};
	float spX;
	float spY;
	Goblin(float spX, float spY);
	~Goblin();
	Texture Gtexture;
	Sprite GoblinSprite;
	void Charge();
private:
	float GspX;
	float GspY;
};

Goblin::Goblin(float spX, float spY)
{
	Gtexture.loadFromFile("Goblin.png");
	GoblinSprite.setTexture(Gtexture);
	GspX = spX;
	GspY = spY;
	GoblinSprite.setPosition(GspX, GspY);
}

Goblin::~Goblin()
{
}
void Goblin::Charge()
{

	//if (alive)
	//{
	GoblinSprite.move(0, 0.5f);
	//}
		
	
}


