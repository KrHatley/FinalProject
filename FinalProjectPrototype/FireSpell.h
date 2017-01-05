#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<SFML\Audio.hpp>// smart fast media library
#include<SFML\Graphics.hpp>
#include<ctime>
//#include<algorithm>
using namespace std;
class FireSpell
{
	enum state
	{
		casting, complete 
	};
public:
	int SpellState;
	int GetState();
	float spX;
	float spY;
	FireSpell();
	~FireSpell();
    void Range();
	sf::Texture FireBall;
	sf::Sprite FireSprite;

private:
	
	float FirespX;
	float FirespY;
};

FireSpell::FireSpell()
{
	FireSprite.setPosition(FirespX, FirespY);
	FireBall.loadFromFile("FireBall.png");
	FireSprite.setTexture(FireBall);
	
	
}

FireSpell::~FireSpell()
{
}
void FireSpell::Range()
{
	FirespX = spX;
	FirespY = spY;
	/*while(Casting) 
	{
		FireSprite.setPosition(FirespX,FirespY -= 0.2f);
	}
	*/
}
int	 FireSpell::GetState()
{
	if (casting)
	{
		SpellState = 1;
	}
	if (complete)
	{
		SpellState = 2;
	}
	return SpellState;
}






