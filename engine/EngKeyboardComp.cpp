#include "EngKeyboardComp.hpp"

EngKeyboardComp::EngKeyboardComp() : keys() {

}

EngKeyboardComp::~EngKeyboardComp() {

}

void  EngKeyboardComp::registerKey(sf::Keyboard::Key key, int val) {
    keys[key] = val;
}

void EngKeyboardComp::update() {
    std::map<sf::Keyboard::Key, int>::iterator it;
    for ( it = keys.begin(); it != keys.end(); ++it ) {
        if (sf::Keyboard::isKeyPressed(it->first)) {
            // update on it->second;
        }
    }
}
