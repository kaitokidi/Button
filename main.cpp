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
//    button2.disableClickEffect();
    //GAME LOOP
    while(window.isOpen()){
        //Loop for handling events
        sf::Event event;
        while(window.pollEvent(event)){
            button.handleEvent(event);
            button2.handleEvent(event);
            switch (event.type){
                //Close event
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    //Do nothing
                    break;
            }
        }

        if(button.hasBeenClicked()) button.setPosition(rand()%(window.getSize().x - window.getSize().x/20), rand()%(window.getSize().y - window.getSize().x/20));


        //Clear the window
        window.clear();
        button.draw(window);
        button2.draw(window);
        window.display();
    }
}

