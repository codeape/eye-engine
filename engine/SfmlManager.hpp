#ifndef SFMLMANAGER_HPP
#define SFMLMANAGER_HPP

#include "EngManager.hpp"

class SfmlManager  : public EngManager {
    SfmlManager();
    virtual ~SfmlManager();

    virtual void startLoop();
};

#endif
