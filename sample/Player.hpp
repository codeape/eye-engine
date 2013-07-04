#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "EngContainer.hpp"

class Player : public EngContainer {
public:
    Player();
    ~Player();
    void update(sf::RenderWindow *);
};

#endif
