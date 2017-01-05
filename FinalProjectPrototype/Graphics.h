#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"FireSpell.h"
#include<SFML\Audio.hpp>// smart fast media library
#include<SFML\Graphics.hpp>
#include<ctime>
#include"Goblin.h"
using namespace std;// using the standard library namespace
using namespace sf;// smart fast namespace


vector<FireSpell*> Spells;
void AddSpell(FireSpell* Fb);
//Clock clock;
int WinMain()
{
	//Menu();

	//sfml graphics
	RenderWindow window(VideoMode(900, 700), "Dungeon Defender");
	RenderWindow MusicWindow(VideoMode(400, 250), "Music Menu");
	RenderWindow Instructions(VideoMode(400, 250), "Instructions");
	RenderWindow End(VideoMode(400, 250), "Game Over");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	Instructions.setVisible(true);
	MusicWindow.setVisible(false);
	MusicWindow.setActive(false);
	End.setVisible(false);
	End.setActive(false);

#pragma region GoblinRegion
	Goblin goblin(425.0f, 175.0f);
	
	Goblin goblin1(375.0f, 350.0f);
	Goblin goblin2(575.0f, 250.0f);
	Goblin goblin3(175.0f, 290.0f);
	Goblin goblin4(675.0f, 400.0f);
	Goblin goblin5(775.0f, 450.0f);

	goblin.alive;
	goblin1.alive;
	goblin2.alive;
	goblin3.alive;
	goblin4.alive;
	goblin5.alive;
	//goblin.Charge();
#pragma endregion

#pragma region Sprite/Texture
	const int WinWidth = 600;
	srand(static_cast<unsigned int>(time(0)));
	int Lives = 3;
	int GoblinSkulls = 0;
	int i = 0;
	float time = 0.0f;
	float PrevTime = 0.0f;
	float spX = 425;
	float spY = 600;
	float FirespX = spX;
	float FirespY = spY - 10.0f;

	Texture texture;
	Sprite sprite1;
	sprite1.setPosition(spX, spY);
	texture.loadFromFile("Wizard.png");
	sprite1.setTexture(texture);



#pragma endregion

#pragma region MusicFile
	Music music;// needs sfml. audio package and sfml.system package
	music.openFromFile("TheScrew.wav");// loads audio file
	music.play();// plays music
	music.setVolume(10);// volume at level 10
	music.setLoop(true);// is on loop
	float	volume = 10.0f;// declares float variable called volume
#pragma endregion

#pragma region// Text
	Font font;
	font.loadFromFile("Xanadu.TTF");
	Text text("Dungeon Defender", font, 200U);// initialization
	//text.setStyle(Text::Underlined);
	Text hearts("Lives:", font, 100);
	Text Hp( to_string(Lives), font, 1);
	Text Skulls(to_string(GoblinSkulls), font, 1);
	Text Kills("Kills:", font, 100);
	Text Directions("Instructions", font, 1);
	Text Direction1("- A & D Keys move player left and right", font, 1);
	Text Direction2("- Up Arrow Key shoots fire spell", font, 1);
	Text Direction3("- Only one fire spell at a time", font, 1);
	Text Direction4("- Last as long as you can", font, 1);
	Text Direction5("- If a Goblin makes it past you, you lose one live", font, 1);
	Text Direction6("- The I key opens/closes the Instruction window", font, 1);
	Text MusicTitle("Music/Pause Menu", font, 20u);
	Text Musicop1("Press '1' to Increase Volume", font, 20U);
	Text Musicop2("Press '2' to Decrease Volume", font, 20U);
	Text Musicop3("Press '3' to Pause Music", font, 20U);
	Text Musicop4("Press '4' to Play Music", font, 20U);
	Text OpenMenuText("Press 'P' to open 'Music/Pause Menu'", font, 20U);
	Text CloseMenuText("Press 'P' to close 'Music/Pause Menu'", font, 20u);
	Text Lost("Game Over!", font, 1);
	Text EndScore(to_string(GoblinSkulls), font, 1);
	Text FinalScore("Final Score:", font, 1);
	Lost.setCharacterSize(40);
	Lost.setFillColor(Color::Green);
	Lost.getFillColor();
	Lost.setPosition(95, 50);
	EndScore.setCharacterSize(25);
	EndScore.setFillColor(Color::Green);
	EndScore.getFillColor();
	EndScore.setPosition(250, 130);
	FinalScore.setCharacterSize(25);
	FinalScore.setFillColor(Color::Green);
	FinalScore.getFillColor();
	FinalScore.setPosition(100, 130);

	//Color color;
	//color = Color::Red;
	//text.setString("Dungeon Crawler");// override of text
	text.setCharacterSize(90);// override of text
	text.setFillColor(Color::Red);// over ride
	//text.getStyle();				  //text.setColor(color);
	text.getFillColor();
	text.setPosition(75, 15);
	hearts.setCharacterSize(30);
	hearts.setFillColor(Color::Red);
	hearts.getFillColor();
	hearts.setPosition(50, 150);
	Hp.setCharacterSize(30);
	Hp.setFillColor(Color::Red);
	Hp.getFillColor();
	Hp.setPosition(135, 150);
	Kills.setCharacterSize(30);
	Kills.setFillColor(Color::Red);
	Kills.getFillColor();
	Kills.setPosition(725, 150);
	Skulls.setCharacterSize(30);
	Skulls.setFillColor(Color::Green);
	Skulls.getFillColor();
	Skulls.setPosition(800, 150);
	OpenMenuText.setFillColor(Color::Red);
	OpenMenuText.getFillColor();
	OpenMenuText.setCharacterSize(20);
	OpenMenuText.setPosition(275, 660);
	CloseMenuText.setFillColor(Color::Red);
	CloseMenuText.getFillColor();
	CloseMenuText.setCharacterSize(18);
	CloseMenuText.setPosition(50, 210);

	Directions.setCharacterSize(20);
	Directions.setStyle(Text::Underlined);
	Directions.getStyle();
	Direction1.setCharacterSize(14);
	Direction2.setCharacterSize(14);
	Direction3.setCharacterSize(14);
	Direction4.setCharacterSize(14);
	Direction5.setCharacterSize(14);
	Direction6.setCharacterSize(14);
	Directions.setFillColor(Color::Red);
	Direction1.setFillColor(Color::Red);
	Direction2.setFillColor(Color::Red);
	Direction3.setFillColor(Color::Red);
	Direction4.setFillColor(Color::Red);
	Direction5.setFillColor(Color::Red);
	Direction6.setFillColor(Color::Red);
	Directions.getFillColor();
	Direction1.getFillColor();
	Direction2.getFillColor();
	Direction3.getFillColor();
	Direction4.getFillColor();
	Direction5.getFillColor();
	Direction6.getFillColor();
	Directions.setPosition(150, 20);
	Direction1.setPosition(25, 40);
	Direction2.setPosition(25, 60);
	Direction3.setPosition(25, 80);
	Direction4.setPosition(25, 100);
	Direction5.setPosition(25, 120);
	Direction6.setPosition(25, 140);
	

	MusicTitle.setCharacterSize(35);
	MusicTitle.setStyle(Text::Underlined);
	MusicTitle.getStyle();
	MusicTitle.setFillColor(Color::Red);
	MusicTitle.getFillColor();
	MusicTitle.setPosition(65, 10);

	Musicop1.setCharacterSize(16);
	Musicop1.setFillColor(Color::Red);
	Musicop1.getFillColor();
	Musicop1.setPosition(100, 70);

	Musicop2.setCharacterSize(16);
	Musicop2.setFillColor(Color::Red);
	Musicop2.getFillColor();
	Musicop2.setPosition(100, 100);

	Musicop3.setCharacterSize(16);
	Musicop3.setFillColor(Color::Red);
	Musicop3.getFillColor();
	Musicop3.setPosition(100, 130);

	Musicop4.setCharacterSize(16);
	Musicop4.setFillColor(Color::Red);
	Musicop4.getFillColor();
	Musicop4.setPosition(100, 160);

#pragma endregion

#pragma region FireBallManager

	FireSpell firespell;
#pragma endregion



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			//while (goblin.alive == true)
			//{
			goblin.Charge();
			goblin1.Charge();
			goblin2.Charge();
			goblin3.Charge();
			goblin4.Charge();
			goblin5.Charge();
			//}
			time += 0.2f;

			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::D)
				{
					spX = spX + 5;
					sprite1.setPosition(spX, spY);
					//circ.setPosition(200, 200);
				}

			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::A)
				{
					spX = spX - 5.0f;
					sprite1.setPosition(spX, spY);
				}
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::P)
				{
					MusicWindow.setActive(true);
					MusicWindow.setVisible(true);

				}

				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::I)
					{
						Instructions.setActive(true);
						Instructions.setVisible(true);
						

					}

				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Up)//create fire ball upon space press
					{
						PrevTime = time;
						i++;
						if (Spells.empty())
						{
							AddSpell(new FireSpell());
							Spells[0]->spX = spX;
							Spells[0]->spY = spY - 10.0f;
							Spells[0]->FireSprite.setPosition(Spells[0]->spX, Spells[0]->spY);
							if (Spells[0]->FireSprite.getTexture() == NULL)
							{
								Spells[0]->FireSprite.setTexture(Spells[0]->FireBall);
							}
							Spells[0]->SpellState = 1;
							Spells[0]->GetState();

						}
						
						//aSpells[0]->Range();


					}
				}
				if (!Spells.empty())
				{

					Spells[0]->FireSprite.move(0, -2.0f);

				}

				if (time > (PrevTime + 7.0f) && !Spells.empty())
				{

					Spells[0]->~FireSpell();
					Spells.pop_back();
					//--;

				}

#pragma region Goblin
				if (goblin.alive)
				{
					goblin.Charge();
				}
				else
				{
					goblin.GoblinSprite.setPosition(800, 800);
				}
				if (goblin.GoblinSprite.getPosition().y >= 600)
				{
					--Lives;
					Hp.setString(to_string(Lives));
					goblin.GoblinSprite.setPosition(goblin.spX, -601);
					goblin.dead;
				}
				if (!Spells.empty())
				{
					if (goblin.GoblinSprite.getGlobalBounds().intersects(Spells[0]->FireSprite.getGlobalBounds()))
					{
						GoblinSkulls += 1;
						Skulls.setString(to_string(GoblinSkulls));
						goblin.GoblinSprite.setPosition((rand() % WinWidth), 100);
						
						Spells[0]->~FireSpell();
						Spells.pop_back();
					}
				}
#pragma endregion
#pragma region Goblin1
				if (goblin1.alive)
				{
					goblin1.Charge();
				}
				else
				{
					goblin1.GoblinSprite.setPosition(800, 800);
				}
				if (goblin1.GoblinSprite.getPosition().y >= 600)
				{
					--Lives;
					Hp.setString(to_string(Lives));
					goblin1.GoblinSprite.setPosition(goblin1.spX, -601);
					goblin1.dead;
				}
				if (!Spells.empty())
				{
					if (goblin1.GoblinSprite.getGlobalBounds().intersects(Spells[0]->FireSprite.getGlobalBounds()))
					{
						GoblinSkulls += 1;
						Skulls.setString(to_string(GoblinSkulls));
						goblin1.GoblinSprite.setPosition((rand()% WinWidth), 100);
						
						Spells[0]->~FireSpell();
						Spells.pop_back();
					}
				}
#pragma endregion
#pragma region Goblin2
				if (goblin2.alive)
				{
					goblin2.Charge();
				}
				else
				{
					goblin2.GoblinSprite.setPosition(800, 800);
				}
				if (goblin2.GoblinSprite.getPosition().y >= 600)
				{
					--Lives;
					Hp.setString(to_string(Lives));
					goblin2.GoblinSprite.setPosition(goblin2.spX, -601);
					goblin2.dead;
				}
				if (!Spells.empty())
				{
					if (goblin2.GoblinSprite.getGlobalBounds().intersects(Spells[0]->FireSprite.getGlobalBounds()))
					{
						GoblinSkulls += 1;
						Skulls.setString(to_string(GoblinSkulls));
						goblin2.GoblinSprite.setPosition((rand() % WinWidth), 100);
						
						Spells[0]->~FireSpell();
						Spells.pop_back();
					}
				}
#pragma endregion
#pragma region Goblin3
				if (goblin3.alive)
				{
					goblin3.Charge();
				}
				else
				{
					goblin3.GoblinSprite.setPosition(800, 800);
				}
				if (goblin3.GoblinSprite.getPosition().y >= 600)
				{
					--Lives;
					Hp.setString(to_string(Lives));
					goblin3.GoblinSprite.setPosition(goblin3.spX, -601);
					goblin3.dead;
				}
				if (!Spells.empty())
				{
					if (goblin3.GoblinSprite.getGlobalBounds().intersects(Spells[0]->FireSprite.getGlobalBounds()))
					{
						GoblinSkulls += 1;
						Skulls.setString(to_string(GoblinSkulls));
						goblin3.GoblinSprite.setPosition((rand() % WinWidth), 100);
						
						Spells[0]->~FireSpell();
						Spells.pop_back();
					}
				}
#pragma endregion
#pragma region Goblin4
				if (goblin4.alive)
				{
					goblin4.Charge();
				}
				else
				{
					goblin4.GoblinSprite.setPosition(800, 800);
				}
				if (goblin4.GoblinSprite.getPosition().y >= 600)
				{
					--Lives;
					Hp.setString(to_string(Lives));
					goblin4.GoblinSprite.setPosition(goblin4.spX, -601);
					goblin4.dead;
				}
				if (!Spells.empty())
				{
					if (goblin4.GoblinSprite.getGlobalBounds().intersects(Spells[0]->FireSprite.getGlobalBounds()))
					{
						GoblinSkulls += 1;
						Skulls.setString(to_string(GoblinSkulls));
						goblin4.GoblinSprite.setPosition((rand() % WinWidth), 100);
						
						Spells[0]->~FireSpell();
						Spells.pop_back();
					}
				}
#pragma endregion
#pragma region Goblin5
				if (goblin5.alive)
				{
					goblin5.Charge();
				}
				else
				{
					goblin5.GoblinSprite.setPosition(800,800);
				}
				if (goblin5.GoblinSprite.getPosition().y >= 600)
				{
					--Lives;
					Hp.setString(to_string(Lives));
					goblin5.GoblinSprite.setPosition(goblin5.spX, -601);
					goblin5.dead;
				}
				if (!Spells.empty())
				{
					if (goblin5.GoblinSprite.getGlobalBounds().intersects(Spells[0]->FireSprite.getGlobalBounds()))
					{
						GoblinSkulls += 1;
						Skulls.setString(to_string(GoblinSkulls));
						goblin5.GoblinSprite.setPosition((rand() % WinWidth), 100);
						
						Spells[0]->~FireSpell();
						Spells.pop_back();
					}
				}
#pragma endregion

#pragma region GameOVer
				if (Lives <= 0)
				{
					EndScore.setString( to_string(GoblinSkulls));
					End.setActive(true);
					End.setVisible(true);
				}
#pragma endregion


			}
			while (MusicWindow.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					MusicWindow.close();
					MusicWindow.setActive(false);
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::P)
					{
						MusicWindow.setVisible(false);
						MusicWindow.setActive(false);
					}
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Num1 || event.key.code == Keyboard::Numpad1)
					{
						volume += 2.5;
						music.setVolume(volume);
					}
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Num2 || event.key.code == Keyboard::Numpad2)
					{
						volume -= 2.5;
						music.setVolume(volume);
					}
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Num3 || event.key.code == Keyboard::Numpad3)
					{
						music.pause();

					}
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Num4 || event.key.code == Keyboard::Numpad4)
					{
						music.play();
					}
				}
			}
			while (Instructions.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					Instructions.close();
					Instructions.setActive(false);
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::I)
					{
						Instructions.setVisible(false);
						Instructions.setActive(false);
					}
				}
			}

#pragma region MusicWindow Drawloop
			MusicWindow.clear();
			MusicWindow.draw(MusicTitle);
			MusicWindow.draw(Musicop1);
			MusicWindow.draw(Musicop2);
			MusicWindow.draw(Musicop3);
			MusicWindow.draw(Musicop4);
			MusicWindow.draw(CloseMenuText);
			MusicWindow.display();
#pragma endregion

#pragma region Instructions Window DrawLoop
			Instructions.clear();
			Instructions.draw(Directions);
			Instructions.draw(Direction1);
			Instructions.draw(Direction2);
			Instructions.draw(Direction3);
			Instructions.draw(Direction4);
			Instructions.draw(Direction5);
			Instructions.draw(Direction6);
			Instructions.display();
#pragma endregion

#pragma region GameOver window Loop
			End.clear();
			End.draw(Lost);
			End.draw(FinalScore);
			End.draw(EndScore);
			End.display();
#pragma endregion

			//WinMain(); come back to this
			window.clear();


#pragma region Goblin sprite drawings
			window.draw(goblin.GoblinSprite);
			window.draw(goblin1.GoblinSprite);
			window.draw(goblin2.GoblinSprite);
			window.draw(goblin3.GoblinSprite);
			window.draw(goblin4.GoblinSprite);
			window.draw(goblin5.GoblinSprite);

#pragma endregion

			

			window.draw(text);
			window.draw(Kills);
			window.draw(hearts);
			window.draw(Hp);
			window.draw(Skulls);
			window.draw(sprite1);
			window.draw(OpenMenuText);
			if (Spells.empty())
			{
				//hello
			}
			else
			{
				window.draw(Spells[0]->FireSprite);
				//if (Spells[1] == NULL)
				//{
				//	//hello
				//}
				//else
				//{
				//	window.draw(Spells[1]->FireSprite);
				//}
				//vector<FireSpell*>::iterator iter = Spells.begin();
				//for (iter = Spells.begin(); iter < Spells.end(); iter++)
				//{
				//	window.draw(Spells[iter]->FireSprite);
				//}

			}
			window.display();

		}
		
	}
	return 0;
}
void AddSpell(FireSpell *Fb)
{
	Spells.push_back(Fb);
}