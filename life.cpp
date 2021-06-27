#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "game_properties.cpp"
#include "cell.cpp"
sf::RenderWindow window(sf::VideoMode(wRes, hRes), "Life");
sf::Color aliveColor[6] = 
    {
        sf::Color(255, 0, 0),sf::Color(0, 255, 0),
        sf::Color(0, 0, 255),sf::Color(255, 0, 255),
        sf::Color(255, 255, 0),sf::Color(0, 255, 255)
    };
sf::Color deadColor = (darkmode ? sf::Color(0, 0, 0) : sf::Color(255, 255, 255));
int random_x() {return rand()%x_size;}
int random_y() {return rand()%y_size;}
bool next_state(Cell cell)
{
    if (!(cell.alive))
    {
        bool exists = std::find(std::begin(mod2), std::end(mod2), cell.neighbours) != std::end(mod2);
        return exists;
    }
    else if (cell.alive)
    {
        bool exists = std::find(std::begin(mod1), std::end(mod1), cell.neighbours) != std::end(mod1);
        return exists;
    }
    else return false;
}
void draw_cell(int posX, int posY, int xSize, int ySize, Cell cell) {
	float x = posX;
	float y = posY;

	sf::RectangleShape cellShape(sf::Vector2f(xSize, ySize));
	cellShape.setPosition(x*10, y*10);
    if (cell.age < 7 && cell.age > 0) cellShape.setFillColor(aliveColor[cell.age-1]);
    else if (cell.age >= 7) cellShape.setFillColor(aliveColor[5]);
    else cellShape.setFillColor(deadColor);
	cellShape.setOutlineThickness(gridSize);
	cellShape.setOutlineColor(darkmode ? sf::Color(0, 0, 0) : sf::Color(255, 255, 255));
    window.draw(cellShape);
}
void display_board(Cell board[x_size][y_size])
{
    window.clear((darkmode ? sf::Color::Black : sf::Color::White));
    for(int y=0;y<y_size;y++)
    {
        for(int x=0;x<x_size;x++)
        {
            draw_cell(x,y,xSize,ySize,board[x][y]);
        }
    }
    window.display();
}
int main()
{
    srand (time(NULL));
    long long iteration = 0;
    int alive_count = 0;
    //float fps = 1000000/speed;
    Cell board[x_size][y_size];
    for (int x=0;x<x_size;x++)
    {
        for (int y=0;y<y_size;y++)
        {
            board[x][y].alive = false;
        }
    }
    while(random_count>0)
    {
        board[random_x()][random_y()].alive = true;
        random_count--;
    }
        // board[1][2].alive = true;
        // board[2][2].alive = true;
        // board[3][2].alive = true;
        // board[3][1].alive = true;
        // board[2][0].alive = true;
        // board[x_size-1][5].alive = true;
        // board[x_size-1][6].alive = true;
        // board[x_size-1][7].alive = true;
        // board[4][0] = true;
        //board[6][3] = true;
    while(window.isOpen())
    {
        sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
        Cell new_board[x_size][y_size];
        for (int y=0;y<y_size;y++)
            {
                for (int x=0;x<x_size;x++)
                {
                    compute_neighbours(board,x,y);
                }   
            }
            display_board(board);
            usleep(speed);
            //std::system("clear");
            alive_count = 0;
            for (int y = 0; y < y_size; y++)
            {
                for (int x = 0; x < x_size; x++)
                {
                   if (next_state(board[x][y])) //3
                    {
                        alive_count++;
                        new_board[x][y].alive = true;
                        new_board[x][y].age++;
                    }
                   else
                    {
                        new_board[x][y].alive = false;
                        new_board[x][y].age = 0;
                    }
                   
                   board[x][y] = new_board[x][y];
                }
            }
            std::cout << "Iteration: " << ++iteration << " Alive count: " << alive_count << '\n';
    }
}