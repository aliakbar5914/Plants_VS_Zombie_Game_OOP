#pragma once
#include <SFML/Graphics.hpp>
#include"Plants.h"
#include"MainMenu.h"
#include"Scoreboard.h"
#include <ctime>
using namespace sf;
using namespace std;

class Zombie
{
public:
	virtual void drawZombie(RenderWindow& window) = 0;
};
class SimpleZombie : public Zombie{
private:
	int x;
	int y;
	int num;
	Texture zb[5];
	Sprite zbsprite;
public:
	SimpleZombie(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
		string path = "C:/Users/DAR LAPTOPS/Desktop/OOP project/OOP project/Zombies/simple";
		num = 0;
		for (int i = 0; i < 5; i++)
		{
			string pathe = path + to_string(i + 1) + ".png";
			zb[i].loadFromFile(pathe);
		}
		//zbsprite.setTextureRect(sf::IntRect(0, 0, 30, 39));
		zbsprite.setScale(1.0f, 1.0f);
	}
	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	void move()
	{
		x -= 1;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	virtual void drawZombie(RenderWindow& window) override
	{
		if (num == 5)
			num = 0;
		zbsprite.setTexture(zb[num++]);
		if (num == 5)
			num = 0;
		zbsprite.setPosition(x, y);
		window.draw(zbsprite);
	}
};

class DancingZombie : public Zombie {
private:
	int x;
	int y;
	Texture zb1[14];
	Sprite zbsprite1;
	int tex_num;
public:
	DancingZombie(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
		string path = "C:/Users/DAR LAPTOPS/Desktop/OOP project/OOP project/Zombies/dancer zombie/dancer";
		tex_num = 0;
		for (int i = 0; i < 14; i++) {

			string pathe = path + to_string(i + 1) + ".png";
			zb1[i].loadFromFile(pathe);
		}
		zbsprite1.setScale(0.8f, 0.8f);
	}


	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	void move()
	{
		x -= 1.1;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	virtual void drawZombie(RenderWindow& window) override
	{
		if (tex_num == 14)
			tex_num = 0;
		zbsprite1.setTexture(zb1[tex_num++]);
		if (tex_num == 14)
			tex_num = 0;
		zbsprite1.setPosition(x, y);
		window.draw(zbsprite1);
	}
};
class FlyingZombie : public Zombie {
private:
	int x;
	int y;
	Texture zb2[42];
	Sprite zbsprite2;
	int tex_num;
public:
	FlyingZombie(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
		string path = "C:/Users/DAR LAPTOPS/Desktop/OOP project/OOP project/Zombies/Ballon Zombie/ballon zombie";
		tex_num = 0;
		for (int i = 0; i < 42; i++) {

			string pathe = path + to_string(i + 1) + ".png";
			zb2[i].loadFromFile(pathe);
		}
		zbsprite2.setScale(1.0f, 1.0f);
	}


	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	void move()
	{
		x -= 1.4;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	virtual void drawZombie(RenderWindow& window) override
	{
		if (tex_num == 42)
			tex_num = 0;
		zbsprite2.setTexture(zb2[tex_num++]);
		if (tex_num == 42)
			tex_num = 0;
		zbsprite2.setPosition(x, y);
		window.draw(zbsprite2);
	}
};

class FootballZombie : public Zombie {
private:
	int x;
	int y;
	Texture zb3[29];
	Sprite zbsprite3;
	int tex_num;
public:
	FootballZombie(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
		string path = "C:/Users/DAR LAPTOPS/Desktop/OOP project/OOP project/Zombies/football zombie/footbll";
		tex_num = 0;
		for (int i = 0; i < 29; i++) {

			string pathe = path + to_string(i + 1) + ".png";
			zb3[i].loadFromFile(pathe);
		}
		zbsprite3.setScale(1.0f, 1.0f);
	}


	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	void move()
	{
		x -= 1;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	virtual void drawZombie(RenderWindow& window) override
	{
		if (tex_num == 29)
			tex_num = 0;
		zbsprite3.setTexture(zb3[tex_num++]);
		if (tex_num == 29)
			tex_num = 0;
		zbsprite3.setPosition(x, y);
		window.draw(zbsprite3);
	}
};

class ConeZombie : public Zombie {
private:
	int x;
	int y;
	Texture zb4[63];
	Sprite zbsprite4;
	int tex_num;
public:
	ConeZombie(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
		string path = "C:/Users/DAR LAPTOPS/Desktop/OOP project/OOP project/Zombies/conehead zombie/conehead";
		tex_num = 0;
		for (int i = 0; i < 63; i++) {

			string pathe = path + to_string(i + 1) + ".png";
			zb4[i].loadFromFile(pathe);
		}
		zbsprite4.setScale(1.0f, 1.0f);
	}


	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	void move()
	{
		x -= 2;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	virtual void drawZombie(RenderWindow& window) override
	{
		if (tex_num == 63)
			tex_num = 0;
		zbsprite4.setTexture(zb4[tex_num++]);
		if (tex_num == 63)
			tex_num = 0;
		zbsprite4.setPosition(x, y);
		window.draw(zbsprite4);
	}
};
class Disp
{
private:
	int x;
	int y;
	Texture cl[11];
	Sprite clsprite;
	int tex_num;
public:
	Disp(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
		string path = "C:/Users/DAR LAPTOPS/Desktop/OOP project/OOP project/Images/s";
		tex_num = 0;
		for (int i = 0; i < 11; i++) {

			string pathe = path + to_string(i + 1) + ".png";
			cl[i].loadFromFile(pathe);
		}
		clsprite.setScale(1.2f, 1.2f);
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
	 void drawZombie(RenderWindow& window)
	{
		if (tex_num == 11)
			tex_num = 0;
		clsprite.setTexture(cl[tex_num++]);
		if (tex_num == 11)
			tex_num = 0;
		clsprite.setPosition(x, y);
		window.draw(clsprite);
	}
};