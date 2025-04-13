#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
using namespace std;

class BasicMenu
{
private:
	Font font;
	Text menu[3];
	int select_key;
public:
	BasicMenu(float w=0, float h=0)
	{
		if (!font.loadFromFile("Play Pretend.otf"))
		{
			return;
		}
		menu[0].setFont(font);
		menu[0].setFillColor(Color::Yellow);
		menu[0].setString("Play");
		menu[0].setCharacterSize(50);
		menu[0].setPosition(Vector2f(w / 2, h / 4));

		menu[1].setFont(font);
		menu[1].setFillColor(Color::White);
		menu[1].setString("Instructions");
		menu[1].setCharacterSize(50);
		menu[1].setPosition(Vector2f(w / 2, (h / 4)+100));

		menu[2].setFont(font);
		menu[2].setFillColor(Color::White);
		menu[2].setString("Exit");
		menu[2].setCharacterSize(50);
		menu[2].setPosition(Vector2f(w / 2, h / (4)+200));

		select_key = 0;

	}
	void drawmenu(RenderWindow& window)
	{
		for (int i = 0; i < 3; i++)
		{
			window.draw(menu[i]);
		}
	}
	void up()
	{
		if (select_key - 1 >= -1)
		{
			menu[select_key].setFillColor(Color::White);
			select_key--;
			if (select_key == -1)
			{
				select_key = 2;
			}
			menu[select_key].setFillColor(Color::Yellow);
		}
	}
	void down()
	{
		if (select_key + 1 <= 3)
		{
			menu[select_key].setFillColor(Color::White);
			select_key++;
			if (select_key == 3)
			{
				select_key = 0;
			}
			menu[select_key].setFillColor(Color::Yellow);
		}
	}
	void setselectkey(int n) {
		select_key = n;
	}
	int keypressed()
	{
		return select_key;
	}
	~BasicMenu(){}
};