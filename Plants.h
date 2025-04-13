#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

class Plants {
private:
public:
	Plants(){}
	virtual void draw(RenderWindow& window, int xa, int ya) = 0;
};
class Peashootor : public Plants {
private:
	int x;
	int y;
	Texture p1;
	Sprite peashootersprite;
public:
	Peashootor(int x_axis=0,int y_axis=0):x(x_axis),y(y_axis){
		p1.loadFromFile("Images/pi.png");
		peashootersprite.setTexture(p1);
		peashootersprite.setTextureRect(sf::IntRect(0, 0, 35, 39));
		peashootersprite.setScale(2.0f, 2.0f);
	}

	void setx(int x)
	{
	this->x = x;
	}
	void sety(int y)
	{
	this->y = y;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	virtual void draw(RenderWindow& window,int xa,int ya) override
	{
		x = xa;
		y = ya;
		peashootersprite.setPosition(x, y);
		window.draw(peashootersprite);
	}
};
class Sunflower :public Plants
{
private:
	int x;
	int y;
	Texture sf;
	Sprite sfsprite;
public:
	Sunflower(int x = 0, int y = 0) :x(x), y(y)
	{
		sf.loadFromFile("Images/im.png");
		sfsprite.setTexture(sf);
		//sfsprite.setTextureRect(sf::IntRect(0, 0, 35, 39));
		sfsprite.setScale(0.8f, 0.8f);
	}
	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	virtual void draw(RenderWindow& window, int xa, int ya) override
	{
		this->x = xa;
		this->y = ya;
		sfsprite.setPosition(x, y);
		window.draw(sfsprite);
	}
};
class Wallnut :public Plants
{
private:
	int x;
	int y;
	Texture wl;
	Sprite wlsprite;
public:
	Wallnut(int x = 0, int y = 0) :x(x), y(y)
	{
		wl.loadFromFile("Images/walnut.png");
		wlsprite.setTexture(wl);
		//sfsprite.setTextureRect(sf::IntRect(0, 0, 35, 39));
		wlsprite.setScale(1.2f, 1.2f);
	}
	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	void move()
	{
		x+=1;
	}
	virtual void draw(RenderWindow& window, int xa, int ya) override
	{
		/*this->x = xa;
		this->y = ya;*/
		wlsprite.setPosition(x, y);
		window.draw(wlsprite);
	}
};
class Pea {
private:
	int peax;
	int peay;
	Texture pe;
	Sprite peaw;
public:
	Pea(int x = 0, int y = 0) :peax(x), peay(y)
	{
		pe.loadFromFile("Images/bigpea.png");
		peaw.setTexture(pe);
		//pea.setTextureRect(sf::IntRect(0, 0, 35, 39));
		peaw.setScale(0.6f, 0.6f);
	}
	void movePea()
	{
		peax += 4;
	}
	void setpeax(int x)
	{
		this->peax = x;
	}
	void setpeay(int y)
	{
		this->peay = y;
	}
	int getx() {
		return peax;
	}
	int gety() {
		return peay;
	}

	void drawPea(RenderWindow& window)
	{
		//cout << peax << "{}" << peay << endl;
		peaw.setPosition(peax, peay);
		window.draw(peaw);
	}
};