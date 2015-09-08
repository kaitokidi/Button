#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h>
#include "button.h"
#include <time.h>

using namespace std;

int main() {

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), L"Buttons", sf::Style::Resize|sf::Style::Close);
    Button button;
    button.setPosition(0,0);
    button.setSize(window.getSize().x/20, window.getSize().x/40);
    button.setText("Penguin");
    Button button2 = button;
    Button button3 = button;
//    button2.disableClickEffect();
    //GAME LOOP
    while(window.isOpen()){
        //Loop for handling events
        sf::Event event;
        while(window.pollEvent(event)){
            button.handleEvent(event);
            button2.handleEvent(event);
            button3.handleEvent(event);
            switch (event.type){
                //Close event
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    //Do nothing
                    break;
            }
            if (event.type == sf::Event::Closed) { window.close(); exit(0);}
            if (event.type == sf::Event::KeyPressed){ if (event.key.code == sf::Keyboard::Escape) { window.close(); exit(0); } }
        }

        if(button.hasBeenClicked()) button.setPosition(rand()%(window.getSize().x - window.getSize().x/20), rand()%(window.getSize().y - window.getSize().x/20));
        if(button3.hasBeenClicked()) button3.setPosition(rand()%(window.getSize().x - window.getSize().x/20), rand()%(window.getSize().y - window.getSize().x/20));
        button.setTextResizeButton(" Penguinpenguinpenguin ");
        button3.setTextResizeText(" Penguins ");
        //std::cout << button.getSize().x << std::endl;
        //Clear the window
        window.clear();
        button.draw(window);
        button2.draw(window);
        button3.draw(window);
        window.display();
    }
}

