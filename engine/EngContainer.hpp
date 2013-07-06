#ifndef ENGCONTAINER_HPP
#define ENGCONTAINER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class EngComponent;

class EngContainer {
public:
                                 EngContainer();
    virtual                      ~EngContainer();
    virtual void                 addcomponent( EngComponent * );
    virtual void                 update( sf::RenderWindow * );
private:
    std::vector<EngComponent *> *components;
};

#endif
