#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include"Plants.h"
#include"MainMenu.h"
#include"Scoreboard.h"
#include"Zombie.h"
#include <ctime>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace sf;
using namespace std;

const string filename = "player_scores.txt";
//Drawing the background
void createBack1(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("Images/backwindow.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

//Drawing the map

void createMap1(RenderWindow& window) {
	//Drawing a map
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("Images/grid.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(185.5, 76.5);
	window.draw(s_map);
}

void displayhighscore(RenderWindow& window,int highscore)
{
	Font highfont;
	Text highs;
	highfont.loadFromFile("Play Pretend.otf");
	highs.setFont(highfont);
	highs.setPosition(10, 650);
	highs.setString("Highest score: " + to_string(highscore));
	highs.setCharacterSize(30);
	highs.setFillColor(Color::Black);
	window.draw(highs);
}
	//////////////////////
	//   Class for Sun	//
	//////////////////////
class Sun {
private:
	int x;
	int y;
	Texture sunt;
	Sprite sunsprite;
public:
	Sun(int x=700,int y=0):x(x),y(y){
		sunt.loadFromFile("Images/sun.png");
		sunsprite.setTexture(sunt);
		sunsprite.setTextureRect(sf::IntRect(0, 0, 35, 35));
		sunsprite.setScale(2.0f, 2.0f);
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
	void drawSun(RenderWindow& window)
	{
		sunsprite.setPosition(x, y);
		window.draw(sunsprite);
	}
	void movesun()
	{
		if ((y == 250 )&&( y == -10))
		{
			y = -10;
			return;
		}
			y += 5;
	}
};

class Levels {
private:

	Texture sunflo;
	Sprite sunflosprite;
	
	Texture le1;
	Sprite le1sprite;
	 
	Texture nut;
	Sprite nutsprite;

protected:
	Text levels;
	Font levelsfont;
public:
	Levels(){
	}

		//////////////////////////
		//						//
		//   Drawing image on	//
		//   the top of screen	//
		//						//
		//////////////////////////
	void drawlevel1(RenderWindow& window){
		le1.loadFromFile("Images/img1.png");
		le1sprite.setTexture(le1);
		le1sprite.setPosition(320, 0);
		le1sprite.setScale(1.1f, 1.1f);
		window.draw(le1sprite);
		sunflo.loadFromFile("Images/unnamed.jpg");
		sunflosprite.setTexture(sunflo);
		sunflosprite.setPosition(200, 0);
		sunflosprite.setScale(1.1f, 1.1f);
		window.draw(sunflosprite);

		levelsfont.loadFromFile("Play Pretend.otf");
		levels.setFont(levelsfont);
		levels.setPosition(250, 200);
		levels.setString("	Level \nCompleted");
		levels.setCharacterSize(100);
		levels.setFillColor(Color::Black);
	}
	void drawlevel2(RenderWindow& window)
	{
		nut.loadFromFile("Images/aa2.jpeg");
		nutsprite.setTexture(nut);
		nutsprite.setPosition(440, 0);
		nutsprite.setScale(1.1f, 1.1f);
		window.draw(nutsprite);
	}
	virtual void draw(RenderWindow& window, Score& score, Clock& sunclock,int &lives,int highscore) = 0;
	
};


	//////////////////////////
	//						//
	//		LEVEL 1			//
	//						//
	//////////////////////////
class BeginnerGarden : public Levels
{
private:
	int xpos[20];   ///  To save the positions of palnts 
	int ypos[20];

	int sunposx[20];	// to save the position of sunflowers
	int sunposy[20];
	
	int noofplants;
	int noofsunflowers;
	int peacount;
	int Zombieindex;

	int livecount[10];   //for Zombie count lives 3 pea hitting
	bool safe[10];
	bool flag = false;
	
	bool zombieexist[10];
	bool zombieflag;

	bool flag1[20];		// For plants
	bool flag2[20];	    // For sunflowers

	bool pant;          // For plants draw
	bool shirt;			//For Sunflower draw
	bool clockflag;
	bool endcheck;

	Clock sunflowerclock[20];  //Clock For drawing sun 
	Clock sunclock;
	Clock oneclock;
	Clock zombieclock;
	Clock levelendclock;

	SimpleZombie zm[10];
	Peashootor plant[20];
	Sun sun;
	Pea pea1[20];
	Sunflower sf[20];
	Sun sss[20];
public:
	BeginnerGarden(){
		for (int i = 0; i < 20; i++)
		{
			flag1[i] = false;
			flag2[i] = false;
		}
		for (int i = 0; i < 10; i++)
		{
			livecount[i] = 0;
			safe[i] = true;
			zombieexist[i] = true;
		}
		peacount = 0;
		zombieflag = false;
		Zombieindex = 0;
		noofplants = 0;
		noofsunflowers = 0;
		pant = false;
		shirt = false;
		endcheck = false;
	}
	virtual void draw(RenderWindow& window, Score& score,Clock& scoreclock,int &lives,int highscore) override
	{
		sf::Music bgMusic;
		bgMusic.openFromFile("stranger.mp3");
		bgMusic.play();
		bgMusic.setVolume(50);
		while (window.isOpen())
		{
			srand(time(NULL));
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
						int x1 = Mouse::getPosition(window).x;
						int y1 = Mouse::getPosition(window).y;
						//////////////////////////////////////////
						//	Check to draw plant or sunflower	//
						//////////////////////////////////////////
						if (x1 >= 260 && x1 <= 340 && y1 >= 0 && y1 <= 50)
						{
							pant = true;
							shirt = false;
						}
						else if (x1 >= 150 && x1 <= 250 && y1 >= 0 && y1 <= 50)
						{
							shirt = true;
							pant = false;
						}
					}
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
							///////////////////////////////////////////////
							//     TO draw plant or sunflower in grid    //
							///////////////////////////////////////////////
							if (shirt==true)
							{
								if (score.getsun() >= 100)
								{
									int x2 = Mouse::getPosition(window).x;
									int y2 = Mouse::getPosition(window).y;
									sunposx[noofsunflowers] = ((x2 / 73) * 96) - 5;
									sunposy[noofsunflowers] = ((y2 / 74) * 109.4) - 20;
									if (sunposx[noofsunflowers] >= 187 &&
										sunposx[noofsunflowers] <= 955 &&
										sunposy[noofsunflowers] >= 89 &&
										sunposx[noofsunflowers] <= 527)
									{
										sf[noofsunflowers].draw(window, sunposx[noofsunflowers], sunposy[noofsunflowers]);
										sss[noofsunflowers].setx(sunposx[noofsunflowers]);
										sss[noofsunflowers].sety(sunposy[noofsunflowers]);
										sss[noofsunflowers].drawSun(window);
										flag2[noofsunflowers] = true;
										noofsunflowers++;
										sunflowerclock[noofsunflowers].restart();
										score.setsun(score.getsun() - 100);
										pant = false;
										shirt = false;
									}
								}
							}
							else if (pant==true)
							{
								if (score.getsun() >= 100)
								{
									int x_axis = Mouse::getPosition(window).x;
									int y_axis = Mouse::getPosition(window).y;
									//cout << x_axis << " " << y_axis << endl;
									xpos[noofplants] = ((x_axis / 73) * 96) - 5;
									ypos[noofplants] = ((y_axis / 74) * 109.4) - 20;
									if (xpos[noofplants] >= 187 &&
										xpos[noofplants] <= 955 &&
										ypos[noofplants] >= 89 &&
										ypos[noofplants] <= 527)
									{
										plant[noofplants].draw(window, xpos[noofplants], ypos[noofplants]);
										flag1[noofplants] = true;
										pea1[noofplants].setpeax(xpos[noofplants] + 60);
										pea1[noofplants].setpeay(ypos[noofplants] + 6);
										noofplants++;
										score.setsun(score.getsun() - 100);
										shirt = false;
										pant = false;
									}
								}
							}
					}
					
				}
			}
			
			//Create a background
			createBack1(window);
			createMap1(window);
			drawlevel1(window);
			displayhighscore(window, highscore);
			scoreclock = score.drawScore(window, scoreclock);
			
			////////////////////////
			// Sun clock checking //
			////////////////////////
			if (sunclock.getElapsedTime().asSeconds() >= 10)
			{
				flag = true;
				sun.setx(700);
				sun.sety(0);
				sun.drawSun(window);
				sunclock.restart();
			}
			if (flag == true) {
				sun.drawSun(window);
				sun.movesun();
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
						int x4 = Mouse::getPosition(window).x;
						int y4 = Mouse::getPosition(window).y;
						//////////////////////////////////////////
						//	Check to draw plant or sunflower	//
						//////////////////////////////////////////
						cout << sun.getx() <<" " << sun.gety() << endl;
						cout << x4 << " " << y4 << endl;
					}
				}
			}
			if (sun.gety() >= 250)
			{
				flag = false;
			}

			////////////////////////////////////////////
			// 1st Zombie drawing clock after 30 sec  //
			////////////////////////////////////////////
			if (oneclock.getElapsedTime().asSeconds() >= 30)
			{
				if (Zombieindex == 0) {
					zombieflag = true;
					zm[Zombieindex].setx(1100);
					zm[Zombieindex].sety(((rand() % 5) * 109.4)+5);
					Zombieindex++;
					zombieclock.restart();
				}
			}
			///////////////////////////////////
			// Draw each zombie after 12 sec //
			///////////////////////////////////
			if (Zombieindex != 0) {
				if (zombieclock.getElapsedTime().asSeconds() >=12)
				{
					if (Zombieindex < 10)
					{
						zm[Zombieindex].setx(1100);
						zm[Zombieindex].sety(((rand()%5) * 109.4)+5);
						Zombieindex++;
						zombieclock.restart();
					}
				}
			}
			for (int i = 0; i < Zombieindex; i++)
			{
				zm[i].move();
				zm[i].drawZombie(window);
				if (zm[i].getx() < 0&&safe[i]==true&&zombieexist[i]==true)
				{
					zm[i].setx(-200);
					lives++;
					safe[i] = false;
				}

			}
			for (int i = 0; i < noofplants; i++)
			{
				if (flag1[i] == true)
				{
					plant[i].draw(window,xpos[i],ypos[i]);
					if (zombieflag == true)
					{
						if (pea1[i].getx() >= 990)
						{
							pea1[i].setpeax(xpos[i]+60);
						}
						pea1[i].movePea();
						pea1[i].drawPea(window);
					}
				}
			}

			for (int i = 0; i < noofsunflowers; i++)
			{
				if (flag2[i] == true)
				{
					sf[i].draw(window, sunposx[i], sunposy[i]);
					if (sunflowerclock[i].getElapsedTime().asSeconds() >= 5)
					{
						clockflag = true;
						sss[i].setx(sunposx[i]);
						sss[i].sety(sunposy[i]);
						sss[i].drawSun(window);
					}
					if (sunflowerclock[i].getElapsedTime().asSeconds() >= 8)
					{
						score.setsun(score.getsun() + 25);
						sunflowerclock[i].restart();
						clockflag = false;
					}
				}
			}

			//////////////////////////////////////////
			//										//
			//		Zombie Collosion with Plant		//
			//										//
			//////////////////////////////////////////

			for(int i = 0;i<noofplants;i++){
				for(int j=0;j<Zombieindex;j++){
					//////////////////////////////
					//	Height of pea=30		//
					//	Width  of pea=30		//
					//  Height of zombie=121	//
					//	Width  of zombie=75		//
					//////////////////////////////
					if (pea1[i].getx()+1 >= zm[j].getx()+50 && 
						pea1[i].getx() <= zm[j].getx()+70 &&
						pea1[i].gety()+1>=zm[j].gety()&&
						pea1[i].gety()<=zm[j].gety()+100) {
						pea1[i].setpeax(xpos[i]+60);
						livecount[j]+=1;
						if (livecount[j] == 3) {
							zm[j].setx(-200);
							zombieexist[j] = false;
							score.setscore(score.getscore() + 100);
						}
						}
				}
			}
				//////////////////////////////////
				//	   Level completion check   //
				//////////////////////////////////
				if (zombieexist[9] == false)
				{
					if (endcheck == false) {
						endcheck = true;
						levelendclock.restart();
					}
				}
			if (endcheck == true)
			{
				window.draw(levels);
				if (levelendclock.getElapsedTime().asSeconds() >= 5)
					score.setsun(0);
				    break;
					return;
			}
			if (lives == 3)
			{
				return;
			}
			window.display();
		}
	}
};

	//////////////////////////
	//						//
	//		LEVEL 2			//
	//						//
	//////////////////////////

class ZombieOutskirts : public Levels
{
private:
	int xpos[20];
	int ypos[20];
	int sunposx[20];
	int sunposy[20];
	int walposx[20];
	int walposy[20];
	int noofplants;
	int noofsunflowers;
	int peacount;
	int Zombieindex;
	int livecount[5];
	int noofwalnut;
	bool safe[5];
	bool flag = false;
	bool zombieexist[5];
	bool zombieflag;
	bool flag1[20];
	bool flag2[20];
	bool flag3[20];
	bool pant;
	bool shirt;
	bool km;
	bool clockflag;
	bool endcheck;
	Clock sunflowerclock[20];
	Clock sunclock;
	Clock oneclock;
	Clock zombieclock;
	Clock levelendclock;
	SimpleZombie zm[5];
	
	Peashootor plant[20];
	Sun sun;
	Pea pea1[20];
	Sunflower sf[20];
	Sun sss[20];
	Wallnut wn[20];
	
	DancingZombie dz[2];
	int nfdancinfz;
	int hj[2] = { 1,1 };
	bool dancingz[2];
	bool safe1[2];
	Clock dancz[2];

	FlyingZombie fz;
	bool flyingz;
	bool safe2;
	int nooffz;
	int hk=1 ;
	bool swag;
	Clock flyclock;

	FootballZombie bz[2];
	bool footballz[2];
	bool safe3[2];
	int nfb;
	int hl[2] = { 1,1 };
	Clock ballclock[2];

	ConeZombie cz[2];
	bool conez[2];
	bool safe4[2];
	int ncz;
	int hm[2] = { 1,1 };
	Clock czclock[2];

	Disp disp;
	Clock dispclock;
	bool display = false;
public:
	ZombieOutskirts() {
		for (int i = 0; i < 20; i++)
		{
			flag1[i] = false;
			flag2[i] = false;
			flag3[i] = false;
		}
		for (int i = 0; i < 5; i++)
		{
			livecount[i] = 0;
			safe[i] = true;
			zombieexist[i] = true;
		}
		for (int j = 0; j < 2; j++)
		{
			dancingz[j] = true;
			safe1[j] = true;

			footballz[j] = true;
			safe3[j] = true;

			conez[j] = true;
			safe4[j] = true;
		}
		flyingz = false;
		safe2 = true;
		swag = false;
		peacount = 0;
		zombieflag = false;
		Zombieindex = 0;
		noofplants = 0;
		noofsunflowers = 0;
		pant = false;
		shirt = false;
		km = false;
		endcheck = false;
		noofwalnut = 0;
		nfdancinfz = 0;
		nooffz = 0;
		nfb = 0;
		ncz = 0;
	}
	virtual void draw(RenderWindow& window, Score& score, Clock& scoreclock, int& lives,int highscore) override
	{
		sf::Music bgMusic;
		bgMusic.openFromFile("stranger.mp3");
		bgMusic.play();
		bgMusic.setVolume(50);
		while (window.isOpen())
		{
			srand(time(NULL));
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
						int x1 = Mouse::getPosition(window).x;
						int y1 = Mouse::getPosition(window).y;
						/////////////////////////////////////////////////////////
						//     TO draw plant or sunflower or walnut in grid    //
						/////////////////////////////////////////////////////////
						if (x1 >= 260 && x1 <= 340 && y1 >= 0 && y1 <= 50)
						{
							pant = true;
							shirt = false;
							km = false;
						}
						else if (x1 >= 150 && x1 <= 250 && y1 >= 0 && y1 <= 50)
						{
							shirt = true;
							pant = false;
							km = false;
						}
						else if (x1 >= 360 && x1 <= 440 && y1 >= 0 && y1 <= 50)
						{
							shirt = false;
							pant = false;
							km = true;
						}
					}
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
						if (shirt == true)
						{
							if (score.getsun() >= 100)
							{
								int x2 = Mouse::getPosition(window).x;
								int y2 = Mouse::getPosition(window).y;
								sunposx[noofsunflowers] = ((x2 / 73) * 96) - 5;
								sunposy[noofsunflowers] = ((y2 / 74) * 109.4) - 20;
								if (sunposx[noofsunflowers] >= 187 &&
									sunposx[noofsunflowers] <= 955 &&
									sunposy[noofsunflowers] >= 89 &&
									sunposx[noofsunflowers] <= 527)
								{
									sf[noofsunflowers].draw(window, sunposx[noofsunflowers], sunposy[noofsunflowers]);
									sss[noofsunflowers].setx(sunposx[noofsunflowers]);
									sss[noofsunflowers].sety(sunposy[noofsunflowers]);
									sss[noofsunflowers].drawSun(window);
									flag2[noofsunflowers] = true;
									noofsunflowers++;
									sunflowerclock[noofsunflowers].restart();
									score.setsun(score.getsun() - 100);
									pant = false;
									shirt = false;
									km = false;
								}
							}
						}
						else if (pant == true)
						{
							if (score.getsun() >= 100)
							{
								int x_axis = Mouse::getPosition(window).x;
								int y_axis = Mouse::getPosition(window).y;
								//cout << x_axis << " " << y_axis << endl;
								xpos[noofplants] = ((x_axis / 73) * 96) - 5;
								ypos[noofplants] = ((y_axis / 74) * 109.4) - 20;
								if (xpos[noofplants] >= 187 &&
									xpos[noofplants] <= 955 &&
									ypos[noofplants] >= 89 &&
									ypos[noofplants] <= 527)
								{
									plant[noofplants].draw(window, xpos[noofplants], ypos[noofplants]);
									flag1[noofplants] = true;
									pea1[noofplants].setpeax(xpos[noofplants] + 60);
									pea1[noofplants].setpeay(ypos[noofplants] + 6);
									noofplants++;
									score.setsun(score.getsun() - 100);
									shirt = false;
									pant = false;
									km = false;
								}
							}
						}
						else if (km == true)
						{

							if (score.getsun() >= 50)
							{
								int x3 = Mouse::getPosition(window).x;
								int y3 = Mouse::getPosition(window).y;
								//cout << x_axis << " " << y_axis << endl;
								walposx[noofwalnut] = ((x3 / 73) * 96) - 5;
								walposy[noofwalnut] = ((y3 / 74) * 109.4) - 20;
								if (walposx[noofwalnut] >= 187 &&
									walposx[noofwalnut] <= 955 &&
									walposy[noofwalnut] >= 89 &&
									walposy[noofwalnut] <= 527)
								{
									wn[noofwalnut].setx(walposx[noofwalnut]);
									wn[noofwalnut].sety(walposy[noofwalnut]);
									wn[noofwalnut].draw(window, walposx[noofwalnut], walposy[noofwalnut]);
									flag3[noofwalnut] = true;
									noofwalnut++;
									score.setsun(score.getsun() - 50);
									shirt = false;
									pant = false;
									km = false;
								}
							}
						}
					}

				}
			}

			//Create a background
			createBack1(window);
			createMap1(window);
			drawlevel1(window);
			drawlevel2(window);
			displayhighscore(window,highscore);
			scoreclock = score.drawScore(window, scoreclock);

			if (sunclock.getElapsedTime().asSeconds() >= 10)
			{
				flag = true;
				sun.setx(700);
				sun.sety(0);
				sun.drawSun(window);
				sunclock.restart();
			}
			if (flag == true) {
				sun.drawSun(window);
				sun.movesun();
			}
			if (sun.gety() >= 250)
			{
				flag = false;
			}
			if (oneclock.getElapsedTime().asSeconds() >= 30)
			{
				if (Zombieindex == 0) {
					zombieflag = true;
					zm[Zombieindex].setx(1100);
					zm[Zombieindex].sety(((rand() % 5) * 109.4) + 5);
					Zombieindex++;
					zombieclock.restart();
					dancz[nfdancinfz].restart();
					flyclock.restart();
					czclock[ncz].restart();
				}
			}
			if (Zombieindex != 0) {
				if (zombieclock.getElapsedTime().asSeconds() >= 12)
				{
					if (Zombieindex < 5)
					{
						zm[Zombieindex].setx(1100);
						zm[Zombieindex].sety(((rand() % 5) * 109.4) + 5);
						Zombieindex++;
						zombieclock.restart();
					}
				}
			}

			for (int i = 0; i < Zombieindex; i++)
			{
				zm[i].move();
				zm[i].drawZombie(window);
				if (zm[i].getx() < 0 && safe[i] == true && zombieexist[i] == true)
				{
					zm[i].setx(-200);
					lives++;
					safe[i] = false;
					zombieexist[i] = false;
				}

			}
			if (Zombieindex != 0) {
				if (nfdancinfz < 2) {
					if (dancz[nfdancinfz].getElapsedTime().asSeconds() >= 17)
					{
						dz[nfdancinfz].setx(1100);
						dz[nfdancinfz].sety(((rand() % 5) * 109.4) + 35);
						nfdancinfz++;
						dancingz[nfdancinfz] = true;
						dancz[nfdancinfz].restart();
					}
				}
			}
	
			for (int i = 0; i < nfdancinfz; i++)
			{
				if(dancingz[i]==true)
				dz[i].drawZombie(window);
				dz[i].move();
				if (dz[i].getx() < 0 && dancingz[i]==true && safe1[i]==true)
				{
					dz[i].setx(-200);
					lives++;
					safe1[i] = false;
					dancingz[i] = false;
				}
			}

			if (Zombieindex != 0) {
				if (ncz < 2)
				{
					if (czclock[ncz].getElapsedTime().asSeconds() >= 23)
					{
							cz[ncz].setx(1100);
							cz[ncz].sety(((rand() % 5) * 109.4) + 5);
							ncz++;
							czclock[ncz].restart();
					}
				}
			}

			for (int i = 0; i < ncz; i++)
			{
				cz[i].move();
				cz[i].drawZombie(window);
				if (cz[i].getx() < 0 && safe4[i] == true && conez[i] == true)
				{
					cz[i].setx(-200);
					lives++;
					safe4[i] = false;
					conez[i] = false;
				}

			}
			for (int i = 0; i < noofplants; i++)
			{
				if (flag1[i] == true)
				{
					plant[i].draw(window, xpos[i], ypos[i]);
					if (zombieflag == true)
					{
						if (pea1[i].getx() >= 990)
						{
							pea1[i].setpeax(xpos[i] + 60);
						}
						pea1[i].movePea();
						pea1[i].drawPea(window);
					}
				}
			}
			for (int i = 0; i < noofwalnut; i++)
			{
				if (flag3[i] == true)
				{
					wn[i].draw(window,0,0);
					wn[i].move();
					if (wn[i].getx() >= 1000)
					{
						wn[i].setx(1400);
					}
				}
			}
			for (int i = 0; i < noofsunflowers; i++)
			{
				if (flag2[i] == true)
				{
					sf[i].draw(window, sunposx[i], sunposy[i]);
					if (sunflowerclock[i].getElapsedTime().asSeconds() >= 5)
					{
						clockflag = true;
						sss[i].setx(sunposx[i]);
						sss[i].sety(sunposy[i]);
						sss[i].drawSun(window);
					}
					if (sunflowerclock[i].getElapsedTime().asSeconds() >= 8)
					{
						score.setsun(score.getsun() + 25);
						sunflowerclock[i].restart();
						clockflag = false;
					}
				}
			}
			
			//////////////////////////////////////////
			//										//
			//	Simple Zombie Collosion with Plant	//
			//										//
			//////////////////////////////////////////
			
			for (int i = 0; i < noofplants; i++) {
				for (int j = 0; j < Zombieindex; j++) {
					//////////////////////////////
					//	Height of pea=30		//
					//	Width  of pea=30		//
					//  Height of zombie=121	//
					//	Width  of zombie=75		//
					//////////////////////////////
					if (pea1[i].getx() + 1 >= zm[j].getx() + 50 &&
						pea1[i].getx() <= zm[j].getx() + 70 &&
						pea1[i].gety() + 1 >= zm[j].gety() &&
						pea1[i].gety() <= zm[j].gety() + 100) {
						pea1[i].setpeax(xpos[i] + 60);
						livecount[j] += 1;
						if (livecount[j] == 3) {
							zm[j].setx(-200);
							zombieexist[j] = false;
							score.setscore(score.getscore() + 100);
						}
					}
				}
			}

			//////////////////////////////////////////
			//										//
			//	Simple Zombie Collosion with Walnut	//
			//										//
			//////////////////////////////////////////

			for (int i = 0; i < noofwalnut; i++) {
				for (int j = 0; j < Zombieindex; j++) {
					//////////////////////////////
					//	Height of pea=30		//
					//	Width  of pea=30		//
					//  Height of zombie=121	//
					//	Width  of zombie=75		//
					//////////////////////////////
					if (wn[i].getx() + 1 >= zm[j].getx() + 50 &&
						wn[i].getx() <= zm[j].getx() + 70 &&
						wn[i].gety() + 1 >= zm[j].gety() &&
						wn[i].gety() <= zm[j].gety() + 100) {
							zm[j].setx(-200);
							zombieexist[j] = false;
							score.setscore(score.getscore() + 100);
							disp.setx(wn[i].getx());
							disp.sety(wn[i].gety());
							dispclock.restart();
							display = true;
							wn[i].setx(1400);
					}
				}
			}
			//////////////////////////////////////////
			//										//
			//	Dance Zombie Collosion with Plant	//
			//										//
			//////////////////////////////////////////
			for (int i = 0; i < noofplants; i++) {
				for (int j = 0; j < nfdancinfz; j++) {
					//////////////////////////////
					//	Height of pea=30		//
					//	Width  of pea=30		//
					//  Height of zombie=121	//
					//	Width  of zombie=75		//
					//////////////////////////////
					if (pea1[i].getx() + 1 >= dz[j].getx() + 50 &&
						pea1[i].getx() <= dz[j].getx() + 70 &&
						pea1[i].gety() + 1 >= dz[j].gety() &&
						pea1[i].gety() <= dz[j].gety() + 100) {
						pea1[i].setpeax(xpos[i] + 60);
						cout << hj[j] << " J: " << j << endl;
						hj[j]++;
						if (hj[j] == 4) {
							dz[j].setx(-200);
							dancingz[j] = false;
							score.setscore(score.getscore() + 200);
						}
					}
				}
			}

			//////////////////////////////////////////
			//										//
			//	Dance Zombie Collosion with walnut	//
			//										//
			//////////////////////////////////////////
			for (int i = 0; i < noofwalnut; i++) {
				for (int j = 0; j < nfdancinfz; j++) {
					//////////////////////////////
					//	Height of pea=30		//
					//	Width  of pea=30		//
					//  Height of zombie=121	//
					//	Width  of zombie=75		//
					//////////////////////////////
					if (wn[i].getx() + 1 >= dz[j].getx() + 50 &&
						wn[i].getx() <= dz[j].getx() + 70 &&
						wn[i].gety() + 1 >= dz[j].gety() &&
						wn[i].gety() <= dz[j].gety() + 100) {
						dz[j].setx(-200);
						dancingz[j] = false;
						score.setscore(score.getscore() + 200);
						disp.setx(wn[i].getx());
						disp.sety(wn[i].gety());
						dispclock.restart();
						display = true;
						wn[i].setx(1400);
					}
				}
			}

			//////////////////////////////////////////////
			//											//
			//	conehead Zombie Collosion with Plant	//
			//											//
			//////////////////////////////////////////////
			for (int i = 0; i < noofplants; i++) {
				for (int j = 0; j < ncz; j++) {
					//////////////////////////////
					//	Height of pea=30		//
					//	Width  of pea=30		//
					//  Height of zombie=121	//
					//	Width  of zombie=75		//
					//////////////////////////////
					if (pea1[i].getx() + 1 >= cz[j].getx()  &&
						pea1[i].getx() <= cz[j].getx() + 70 &&
						pea1[i].gety() + 1 >= cz[j].gety() &&
						pea1[i].gety() <= cz[j].gety() + 100) {
						pea1[i].setpeax(xpos[i] + 60);
						cout << hm[j] << " J: " << j << endl;
						hm[j]++;
						if (hm[j] == 4) {
							cz[j].setx(-200);
							conez[j] = false;
							score.setscore(score.getscore() + 100);
						}
					}
				}
			}

			//////////////////////////////////////////
			//										//
			//Conehead Zombie Collosion with walnut	//
			//										//
			//////////////////////////////////////////
			for (int i = 0; i < noofwalnut; i++) {
				for (int j = 0; j < ncz; j++) {
					//////////////////////////////
					//	Height of pea=30		//
					//	Width  of pea=30		//
					//  Height of zombie=121	//
					//	Width  of zombie=75		//
					//////////////////////////////
					if (wn[i].getx() + 1 >= cz[j].getx() + 20 &&
						wn[i].getx() <= cz[j].getx() + 70 &&
						wn[i].gety() + 1 >= cz[j].gety() &&
						wn[i].gety() <= cz[j].gety() + 100) {
						cz[j].setx(-200);
						conez[j] = false;
						score.setscore(score.getscore() + 200);
						disp.setx(wn[i].getx());
						disp.sety(wn[i].gety());
						dispclock.restart();
						display = true;
						wn[i].setx(1400);
					}
				}
			}
			if (display == true)
			{
				disp.drawZombie(window);
				if (dispclock.getElapsedTime().asSeconds() > 2)
				{
					display = false;
				}
			}


				//////////////////////////////////
				//	   Level completion check   //
				//////////////////////////////////
			if (zombieexist[4] == false)
			{
				for (int i = 0; i < 2; i++)
				{
					if (conez[i] != false && dancingz[i] != false)
					{
						break;
					}
						if (endcheck == false) {
							endcheck = true;
							levelendclock.restart();
						}
				}
			}
			if (endcheck == true)
			{
				window.draw(levels);
				if (levelendclock.getElapsedTime().asSeconds() >= 5)
					return;
			}
			if (lives == 3)
			{
				return;
			}
			window.display();
		}
	}
};
class Game {
	Score score;
	string name;

	string highname;
	int highscore=0;

	string ssname[100];
	int ssscore[100];

	const int i=100;
	string oldname[100];
	int oldscore[100];
	
	int n = 0;
	int jk = 0;
	int lives=0;
	
	Levels* level;
	Clock scoreclock;
public:
	Game(RenderWindow& window,string &name)
	{
		this->name = name;
		window.clear();
		showingscore();
		level = new BeginnerGarden;
		level->draw(window, score, scoreclock,lives,highscore);
		window.clear();
		score.setsun(0);
		delete level;
		if (lives < 3) {
			lives = 0;
			level = new ZombieOutskirts;
			level->draw(window, score, scoreclock, lives,highscore);
		}
		savingscore(window);
	}
	void showingscore()
	{
		ifstream readfile("ScoresStoring.txt");
		if (readfile.is_open())
		{
			string name3;
			int score3;
			while (readfile >> name3 >> score3)
			{
				ssname[jk] = name3;
				ssscore[jk] = score3;
					if (ssscore[jk] > highscore)
					{
						
						highscore = ssscore[jk];
					}
				jk++;
			}
			readfile.close();
		}
	}
	void savingscore(RenderWindow& window)
	{
		//////////////////////////////
		//							//
		//		File Handling		//
		//							//
		//////////////////////////////
		ifstream readfile("ScoresStoring.txt");
		if (readfile.is_open())
		{
			string name1;
			int score1;
			while(readfile >> name1 >>score1)
			{ 
				oldname[n] = name1;
				oldscore[n] = score1;
				n++;
			}
			readfile.close();
		}
		int k = n - 1;
		while (k >= 0 && oldscore[k] < score.getscore())
		{
			oldscore[k + 1] = oldscore[k];
			oldname[k + 1] = oldname[k];
			k--;
		}
		oldscore[k + 1] = score.getscore();
		oldname[k + 1] = name;
		n++;
		ofstream writefile("ScoresStoring.txt");
		if (writefile)
		{
			for (int i = 0; i < n; i++)
			{
				writefile << oldname[i] << " " << oldscore[i] << endl;
			}
		}
		writefile.close();
		window.close();
	}
};