#include<iostream>
#include <SFML/Graphics.hpp>

const int windowx = 900;
const int windowy = 900;


using namespace std;
struct Ball
{
    
    sf::CircleShape CircleBall;
    int x,y;
    int x_sum, y_sum;

    Ball():CircleBall(40,400)
    {
        //x = (windowx/2)-40;
        //y = (windowy/2)-40;
        x = 600; y=20;
        x_sum = 2;
        y_sum = 2;
        CircleBall.setPosition(x,y);
    }
    void Movimiento()
    {
        if(x+80 > windowx || x < 0){x_sum = x_sum*(-1);}
        if(y+80>windowy || y < 0){y_sum = y_sum*(-1);}
        x = x+x_sum;
        y = y+y_sum;
        CircleBall.setPosition(x,y);
    }
    void DrawBall(sf::RenderWindow &window)
    {
        window.draw(CircleBall);
        
    }
};



struct Ventana
{
    
    sf::RenderWindow window;
    Ball b1;

    Ventana():window(sf::VideoMode(windowx, windowy), "Bounce")
    {
        window.setFramerateLimit(100);
    };
    
        
    void ShowScreen()
    {
        
        sf::Color ColorWindow(64,59,58);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(ColorWindow);
            b1.DrawBall(window);
            b1.Movimiento();
            window.display();
        }
    }

};
