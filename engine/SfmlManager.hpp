#ifndef SFMLMANAGER_HPP
#define SFMLMANAGER_HPP

#include "EngManager.hpp"

class SfmlManager  : public EngManager {
public:
    SfmlManager();
    virtual ~SfmlManager();

    virtual void startLoop();
};

#endif
