//Final Project Prototype
// Kevin Hatley
#include<iostream>
#include<string>
#include<vector>
#include"FireSpell.h"
#include"Player.h"// includes the Player class file
#include"Levels.h"//includes the Levels file
#include"Graphics.h"
#include"Goblin.h"
//#include<cstdlib>
#include<SFML\Audio.hpp>// smart fast media library
#include<SFML\Graphics.hpp>

using namespace std;// using the standard library namespace
using namespace sf;// smart fast namespace


void Menu();
void MusicMenu();
void StartGame();
int WinMain();




int main()
{
	
	
	WinMain();
	//Menu();
	
	//needs if statement to open music menu whenever m is pressed or something of that sort

	//exit
	//int exit;
	//cin >> exit;
	return 0;
}
void Menu()
{
	cout << "Welcome to -FINAL PROJECT-\n";
	cout << "Title Menu:\n";
	cout << "1 - Start Game\n";
	cout << "2 - Music Menu\n";
	cout << "3 - Exit\n";
	cout << "You Pick: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		StartGame();
		break;
	case 2:
		MusicMenu();
		break;
	case 3:
		
		cout << "Good-Bye!";
		break;
	default:
		break;
	}
}
void MusicMenu()
{
	//cout << "---Music Menu---\n";// outputs a string
	//
	//int ans = 0;// decalres integer varibale called ans
	//do// begin loop with out test condition
	//{
	//	cout << "1 - Increase Volume\n";// outputs a string
	//	cout << "2 - Decrease Volume\n";// outputs a string
	//	cout << "3 - Pause\n";// outputs a string
	//	cout << "4 - Play\n";// outputs a string
	//	cout << "5 - Close Music Menu\n";// outputs a string
	//	cout << " Your choice: ";// outputs a string
	//	cin >> ans;//requests user input
	//	switch (ans)// checks the value of the integer ans
	//	{
	//	case 1:// if == 1
	//		
	//		cout << "increased volume\n";
	//		break;
	//	case 2://if ==2
	//		volume -= 2.5;
	//		cout << "decreased volume\n";
	//		break;
	//	case 3://if == 3
	//		music.pause();
	//		cout << "Music paused\n";
	//		break;
	//	case 4:// if == 4
	//		music.play();
	//		cout << "Music played\n";
	//		break;
	//	case 5:// if == 5
	//		cout << "Back to game!\n";
	//		switch (LevelReference)
	//		{
	//		case 0:
	//			StartGame();
	//			break;
	//		case 1:
	//			LevelOne();
	//			break;

	//		case 2:
	//			LevelTwo();
	//			break;
	//		}
	//		break;
	//	default:
	//		cout << "not an option\n";
	//		break;

	//	}
	//	
	//} while (ans != 5);
}
void StartGame()
{
	Player P1;
	
	cout << "---Player Customization---\n";
	P1.SetNameAge();
	//cout << "Your name is: " << P1.GetName() << endl;
	P1.SetType();
	P1.PlayerInfo();
	

	LevelOne();
	

}
