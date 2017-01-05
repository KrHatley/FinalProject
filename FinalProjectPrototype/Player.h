#pragma once
#include<iostream>
#include<string>

using namespace std;

class Player 
{
public:
	Player();
	void SetNameAge();
	double GetDmg();
	//string GetName();
	void PlayerInfo();
	void SetType();
	string name;
	int Age;
	


private:
	string m_Name;
	string Type;
	double Atk;
	double strikeSpd;
	double Dmg;
	int Hp;
};
Player::Player() 
{}
void Player::SetNameAge()
{
	cout << "Enter the Player Name: ";
	string name;
	cin >> name;
	cout << "Name set\n";
	cout << "Enter Age:";
	cin >> Age;
	cout << "Age set\n";
	m_Name = name;
}
//string Player::GetName()
//{
//	return m_Name;
//}
void Player::PlayerInfo()
{
	cout << "---Player Stats---\n";
	cout << "Name: " << m_Name << endl;
	cout << "Age: " << Age << endl;
	cout << "Class: " <<Type << endl;
	cout << "Damage: " << GetDmg() << endl;
	cout << "Health Points: " << Hp << endl;
}
void Player::SetType()
{
	cout << "Select a Class: " << endl;
	cout << "1 - Warrior" << endl;
	cout << "2 - Rouge " << endl;
	cout << "3 - Mage" << endl;
	cout << "You pick: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Type = "Warrior";
		Atk = 5.0;
		strikeSpd = 1.3;
		Hp = 10;
		break;
	case 2:
		Type = "Rouge";
		Atk = 3.5;
		strikeSpd = 1.7;
		Hp = 7;
		break;
	case 3:
		Type = "Mage";
		Atk = 7.0;
		strikeSpd = 1.0;
		Hp = 5;
		break;
	default:
		cout << "Not an option";
		break;
	}
}
double Player::GetDmg()
{
	Dmg = Atk * strikeSpd;
	return Dmg;
}
