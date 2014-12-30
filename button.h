#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string.h>

class Button{

public:

    /* Initialize the private variables */
    Button();

    /* Set the size passed as parameter */
    void setSize(float x, float y);
    void setSize(sf::Vector2f size);

    /* The return indicates if the button is
    clicked or not*/
    bool isClicked();

    /* Set the position of the button */
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);
    
    /* Return the position of the button*/
    sf::Vector2f getPosition();

    /* Return true if the button has been clicked */
    bool hasBeenClicked();

    /* Return the time since the last time the button
    has been clicked (returned in a float as seconds)*/
    float timeSinceLastClick();

    /* Set the text on the button */
    void setText(std::string s);
    
    /* Set the text on the button and scale the button 
    so the text fits on it */
    void setTextResize(std::string s);

    //TODO this
    void enableClickEffect();
    void disableClickEffect();

    /*Set the size of the characters of the button text*/
    void setCharacterSize(uint u);

    /*Set the color of the button's text*/
    void setColor(sf::Color c);

    /*Set the Font passed as a parameter as the one used by the button*/
    void setFont(sf::Font f);

    /* Set the Texture that will be used as default button image */
    void setTexture(std::string name);
    
    /* Set the Texture that will be used as default button pressed image */
    void setPressedTexture(std::string name);

    /* Draw the button on the window passed as parameter */
    void draw(sf::RenderWindow &w);

    /* Update the private variables if needed acordingly to the event*/
    void handleEvent(sf::Event e);

private:

    bool clicked;
    bool is_clicked;
    bool clickEffect;

    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture pressed_texture;
    float time_since_last_click;

};

#endif // BUTTON_H
