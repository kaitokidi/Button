#include "button.h"

Button::Button(){
    text.setString("");
    clicked = false;
    is_clicked = false;
    clickEffect = true;

    if(!font.loadFromFile("defaultFont.otf")){ std::cerr << "Can't find the font file" << std::endl; }
    setFont(font);
    setCharacterSize(9);
    setColor(sf::Color::Red);

    if(!texture.loadFromFile("defaultButton.png")) std::cerr << "Default texture not loaded" << std::endl;
    else sprite.setTexture(texture);

    if(!pressed_texture.loadFromFile("defaultPressedButton.png")) std::cerr << "presedButton text. not loaded" << std::endl;

    setPosition(0,0);
}

void Button::setColor(sf::Color c){text.setColor(c); }

void Button::setCharacterSize(uint u){ text.setCharacterSize(u); }

void Button::setFont(sf::Font f){ font = f; text.setFont(font); }


void Button::setPosition(sf::Vector2f position){
    sprite.setPosition(position);
    //TODO set text on the center of sprite
//    text.setPosition(position.x, position.y + sprite.getGlobalBounds().height/2);
}
void Button::setPosition(float x, float y){
    setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Button::getPosition(){
    return sprite.getPosition();
}

void Button::setSize(sf::Vector2f size){
    sprite.setScale(size.x/sprite.getGlobalBounds().width, size.y/sprite.getGlobalBounds().height);
    //TODO set text size
}

void Button::setSize(float x, float y){ setSize(sf::Vector2f(x,y)); }

bool Button::isClicked(){ return is_clicked; }

bool Button::hasBeenClicked(){
    bool r = clicked;
    if(clicked) clicked = false;
    return r;
}

float Button::timeSinceLastClick(){ return clock.getElapsedTime().asSeconds(); }

void Button::setText(std::string s = "Click"){ text.setString(s); }

//TODO fix it, is broken
void Button::setTextResize(std::string s = "Click"){
    text.setString(s);
    float charSize = text.getCharacterSize();
    float length = charSize * (text.getString().getSize() +2);
    this->setSize(sf::Vector2f(length,sprite.getGlobalBounds().height));
}

void Button::draw(sf::RenderWindow& w){
    sf::Vector2f position = getPosition();
    text.setPosition(position.x + sprite.getGlobalBounds().width/2 - text.getGlobalBounds().width/2, position.y + sprite.getGlobalBounds().height/2 - text.getGlobalBounds().height/2);
    w.draw(sprite);
    w.draw(text);
}

void Button::setTexture(std::string name){
    if(!texture.loadFromFile(name)) std::cerr << "Default texture not loaded on setTexture" << std::endl;
    else sprite.setTexture(texture); }

void Button::setPressedTexture(std::string name){
    if(!pressed_texture.loadFromFile(name)) std::cerr << "presedButton text. not loaded on Setter" << std::endl; }

void Button::enableClickEffect(){ clickEffect = true; }
void Button::disableClickEffect(){ clickEffect = false; }

void Button::handleEvent(sf::Event e){
    if(e.type == sf::Event::MouseButtonPressed){
        if (e.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f click(e.mouseButton.x, e.mouseButton.y);

            if(click.x > sprite.getPosition().x && click.x < sprite.getPosition().x+sprite.getGlobalBounds().width){
                if(click.y > sprite.getPosition().y && click.y < sprite.getPosition().y+sprite.getGlobalBounds().height){
                    clicked = true;
                    is_clicked = true;
                    clock.restart();
                    if(clickEffect && sprite.getTexture() == &texture) sprite.setTexture(pressed_texture);
                }
            }
        }

    }
    if(e.type == sf::Event::MouseButtonReleased){
        if (e.mouseButton.button == sf::Mouse::Left) {
            //sf::Vector2f click(e.mouseButton.x, e.mouseButton.y);

            //if(click.x > sprite.getPosition().x && click.x < sprite.getPosition().x+sprite.getGlobalBounds().width){
              //  if(click.y > sprite.getPosition().y && click.y < sprite.getPosition().y+sprite.getGlobalBounds().height){
                    is_clicked = false;
                    if(clickEffect && sprite.getTexture() != &texture) sprite.setTexture(texture);
                //}
            //}
        }
    }
}
