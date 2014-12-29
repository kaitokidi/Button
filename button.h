#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string.h>

class Button : public sf::Sprite{

public:
    Button();

    void setSize();

    bool isClicked();
    bool hasBeenClicked();

    float timeSinceLastClick();

    void setText(std::string s);
    void setTextResize(std::string s);

    void enableClickEffect();
    void disableClickEffect();

    void draw(sf::RenderWindow w);

private:
    bool clicked;
    bool is_clicked;
    float time_since_last_click;
    std::string text;

};

#endif // BUTTON_H
