#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string.h>

class Button{

public:

    Button();

    void setSize(float x, float y);
    void setSize(sf::Vector2f size);

    bool isClicked();

    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);
    /*
     * Return true if the button has been clicked,
    */
    bool hasBeenClicked();

    float timeSinceLastClick();

    void setText(std::string s);
    void setTextResize(std::string s);

    void enableClickEffect();
    void disableClickEffect();

    void setTexture(std::string name);
    void setPressedTexture(std::string name);

    void draw(sf::RenderWindow &w);

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
