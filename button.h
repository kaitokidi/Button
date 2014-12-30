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
    
    /* Return true if the button has been clicked */
    bool hasBeenClicked();

    //TODO implement this
    float timeSinceLastClick();

    /* Set the text on the button */
    void setText(std::string s);
    
    /* Set the text on the button and scale the button 
    so the text fits on it */
    void setTextResize(std::string s);

    //TODO this
    void enableClickEffect();
    void disableClickEffect();

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

    sf::Text text;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture pressed_texture;
    float time_since_last_click;

};

#endif // BUTTON_H
