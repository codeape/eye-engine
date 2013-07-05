#ifndef ENGMANAGER_HPP
#define ENGMANAGER_HPP

#include <SFML/Graphics.hpp>

#include <vector>

class EngContainer;

class EngManager {
public:
                                EngManager();
    virtual                     ~EngManager();

    virtual void                startLoop();

    virtual void                addContainer( EngContainer * );
    void                        updateContainers( EngContainer * );
private:
    std::vector<EngContainer *> containers;
    sf::RenderWindow *          win;
};

#endif
