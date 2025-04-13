#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

class Score {
private:
	int score = 0;
	int sun = 0;
	Text sn;
	Font font;
	Text sc;
	Text ss1;
	Text ss2;
public:
	Score() {
		if (!font.loadFromFile("Play Pretend.otf"))
		{
			return;
		}
		sc.setFont(font);
		sc.setPosition(10, 10);
		sc.setString("Sun :");
		sc.setCharacterSize(40);
		sn.setFont(font);
		sn.setCharacterSize(40);
		sn.setFillColor(Color::Red);
		sc.setFillColor(Color::Red);
		sn.setPosition(130,10);
		sn.setString(to_string(sun));

		ss1.setFont(font);
		ss1.setPosition(900,5);
		ss1.setString("Score :");
		ss1.setCharacterSize(40);
		ss2.setFont(font);
		ss2.setCharacterSize(40);
		ss2.setFillColor(Color::Red);
		ss1.setFillColor(Color::Red);
		ss2.setPosition(1080, 5);
		ss2.setString(to_string(score));
	}
	Clock drawScore(RenderWindow& window,Clock scoreclock)
	{
		window.draw(sc);
		window.draw(ss1);
		sn.setString(to_string(sun));   /////TO draw the score on screen
		ss2.setString(to_string(score));
		window.draw(sn);
		window.draw(ss2);
		if (scoreclock.getElapsedTime().asSeconds() >= 10)
		{
			sun+=25;
			scoreclock.restart();
		}
		return scoreclock;
	}
	int getsun()
	{
		return sun;
	}
	void setsun(int sun)
	{
		this->sun = sun;
	}
	int getscore()
	{
		return score;
	}
	void setscore(int score)
	{
		this->score = score;
	}
};