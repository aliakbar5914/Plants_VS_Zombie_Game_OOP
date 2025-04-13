/*
Member1:
	Ali Akbar 
	23i-0697
	CS-F 
Member2:
	M Gulsher khan
	23i-0066 
	CS-F

*/



#include <SFML/Graphics.hpp>
#include"Plants.h"
#include"MainMenu.h"
#include"Scoreboard.h"
#include"Level.h"
#include <ctime>
//#include"../SFML/Images/"
using namespace sf;
using namespace std;


struct coordinats {
	int x;
	int y;
};

int pg = 1000 ;

//Drawing the background
void createBack(RenderWindow& window) {
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

void createMap(RenderWindow& window) {
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

void entername(RenderWindow& window, string& name)
{
	Text t1;
	bool flag = false;
	Text t2;
	Font font;
	font.loadFromFile("Play Pretend.otf");
	t1.setCharacterSize(40);
	t2.setCharacterSize(40);
	t1.setFillColor(Color::Red);
	t2.setFillColor(Color::Red);
	t1.setString("Enter you name : ");
	t1.setFont(font);
	t2.setFont(font);
	t1.setPosition(10, 20);
	t2.setPosition(10, 70);
	while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();


				if (event.type == Event::TextEntered)
				{
					name += static_cast<char>(event.text.unicode);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)&&name.size()>0)
				{
					name.resize(name.size() - 1);
				}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)&&name.size()>1)
					{
						pg = 3;
						return;
					}

			}
			//Create a background
			createBack1(window);
			createMap1(window);
			t2.setString(name);
			window.draw(t1);
			window.draw(t2);
			window.setSize(sf::Vector2u(960, 512));
			window.display();
		}
}
int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	BasicMenu menu(60,60);
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;
	int score1 = 0;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
    		for (int j = 0; j < COLS; j++) {
        		FIELD_GAME_STATUS[i][j] = true;
    		}
	}
	string name;

	Clock timeMoney;
	Clock sunclock;

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();


			if (event.type == Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
				{
					menu.up();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
				{
					menu.down();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
				{
					if (menu.keypressed() == 0)
						pg = 0;

					if (menu.keypressed() == 1)
						pg = 1;

					if (menu.keypressed() == 2)
						pg = 2;
				}

			}
		}

		//Create a background
		createBack(window);
		createMap(window);
	
		menu.drawmenu(window);
		if (pg == 0)
		{
			entername(window, name);
		}
		if (pg == 3)
		{
			Game game(window,name);
		}
		if (pg == 2)
		{
			window.close();
		}
		/*if (pg != 1000)
		{
			break;
		}*/
		window.setSize(sf::Vector2u(960, 512));
		window.display();
	}
	return 0;
}