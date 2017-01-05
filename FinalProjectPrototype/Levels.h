#pragma once
#include<iostream>
#include<string>


using namespace std;

 int levelNum = 0;
 int& LevelReference = levelNum;
void LevelOne()
{
	cout << "Level One\n";
	cout << " Enter a number and press 'Enter' to advance to level two\n";
	int progress;
	cin >> progress;
	
	levelNum++;
void LevelTwo();
}
void LevelTwo()
{
	cout << "Level two\n";

	levelNum++;
}
