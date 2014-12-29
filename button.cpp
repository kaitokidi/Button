#include "button.h"

Button::Button(): sf::Sprite(){

    text = "";
    clicked = false;
    is_clicked = false;
    time_since_last_click = 0.0;
}

void Button::setSize(){

}

bool Button::isClicked(){
    return false;
}

bool Button::hasBeenClicked(){
    return false;
}

float Button::timeSinceLastClick(){
    return 0.0;
}

void Button::setText(std::string s){

}

void Button::setTextResize(std::string s = "pene"){

}

void Button::draw(sf::RenderWindow w){
    sf::Sprite::draw(w 	, sf::RenderStates::Default);

}
