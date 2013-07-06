#include "EngKeyboardComp.hpp"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

void EngKeyboardComp::update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cout << "Left " << std::endl;
    }
}
