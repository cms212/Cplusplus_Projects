#include "main_menu.h"
#include <iostream>

main_menu::main_menu(sf::RenderWindow &window){
    this->window = &window;
    this->menu_snake = new snake(RIGHT, 24, 9);
    this->text_x = 250;
    if (!this->font.loadFromFile("../../Snake/fonts/Roboto-Bold.ttf")){
        cout << "issue loading font";
        this->window->close();
    }

    this->menu_text.setFont(this->font);
    this->menu_text.setString("Welcome to Snake!");
    this->menu_text.setCharacterSize(50);
    this->menu_text.setFillColor(sf::Color::Green);
    this->menu_text.setPosition(this->text_x,100);
    this->text_bounds = this->menu_text.getGlobalBounds();

    this->normal_game_button = sf::RectangleShape(sf::Vector2f(400.0,100.0));
    this->normal_game_button.setPosition(300, 250);
    this->normal_game_button.setFillColor(sf::Color(200,180,33));

    this->button_text.setFont(this->font);
    this->button_text.setString("Normal");
    this->button_text.setCharacterSize(50);
    this->button_text.setFillColor(sf::Color::White);
    this->button_text.setPosition(425,265);
    //cout << this->button_text.getGlobalBounds().height << "\n";
    if(!this->buffer.loadFromFile("../../Snake/wav_files/TitleScreen.wav")){
        cout << "issue loading sound";
        this->window->close();
    }
    this->sound.setBuffer(this->buffer);
    this->sound.play();
    this->frame_count = 0;
    this->menu_stay = true;
    this->snake_length = 0;
};
main_menu:: ~main_menu(){
    delete this->menu_snake;
};
void main_menu::updateMenuSnake(){
    this->menu_snake->updateSnake();
    //cout << "row: " << this->menu_snake->getHeadrow() << "\n";
    //cout << "col: " << this->menu_snake->getHeadcol() << "\n";
    if (this->menu_snake->getHeadcol() == 39 && this->menu_snake->getHeadrow()==9){
        this->menu_snake->setSnakeDirection(DOWN);
    }
    else if (this->menu_snake->getHeadcol() == 39 && this->menu_snake->getHeadrow() == 39){
        this->menu_snake->setSnakeDirection(LEFT);
    }
    else if (this->menu_snake->getHeadcol() == 9 && this->menu_snake->getHeadrow() == 39){
        this->menu_snake->setSnakeDirection(UP);
    }
    else if (this->menu_snake->getHeadcol() == 9 && this->menu_snake->getHeadrow() == 9){
        this->menu_snake->setSnakeDirection(RIGHT);
    }
};
void main_menu::moveText(){
    this->text_x += 1;
    this->menu_text.setPosition(this->text_x, 100);
    if (this->text_x >= 1000){
        this->text_x = 0-this->text_bounds.width;
        this->menu_text.setPosition(this->text_x, 100);
    }
};
void main_menu::menuRun(){
    while (this->menu_stay && this->window->isOpen()){
        
        this->window->clear(sf::Color::Black);
        moveText();
        this->window->draw(this->menu_text);
        this->window->draw(this->normal_game_button);
        this->window->draw(this->button_text);
        updateMenuSnake();
        this->menu_snake->drawSnake(this->window);
        checkSound();
        window->display();
        this->frame_count += 1;
        update_snake_length();
        sf::sleep(sf::milliseconds(10));
        checkButtons();
    }
};
void main_menu::checkButtons(){
    while (this->window->pollEvent(this->event)) {
            if (this->event.type == sf::Event::Closed) {
                this->window->close();
            }
            if(this->event.type == sf::Event::MouseButtonPressed){
                if ((this->event.mouseButton.x >= 300 && this->event.mouseButton.x <= 700)
                    && (this->event.mouseButton.y >= 250 && this->event.mouseButton.y <= 350)){
                        this->menu_stay = false;
                        this->window->clear(sf::Color::Black);
                        this->sound.stop();
                    }
            }
        }
        return;
};

void main_menu::update_snake_length(){
    //cout << "frame: " << this->frame_count << "\n";
    if (this->frame_count == 20){
        this->frame_count = 0;
        if (this->snake_length < 10){
            this->menu_snake->addBlock();
            this->snake_length += 1;
        }
        else{
            this->snake_length = 0;
            int x = this->menu_snake->getHeadcol();
            int y = this->menu_snake->getHeadrow();
            direction d = this->menu_snake->getSnakeDirection();
            delete this->menu_snake;
            this->menu_snake = new snake(d, x, y);
        }
    }
};

void main_menu::checkSound(){
    if(this->sound.getStatus() != sf::Sound::Playing){
        this->sound.play();
    }
};


