#include "EngManager.hpp"
#include "EngContainer.hpp"

#include <algorithm>

EngManager::EngManager() : containers(){
    win = NULL;
    containers.reserve(50);
}

EngManager::~EngManager() {

}

void EngManager::updateContainers( EngContainer *container ) {
    container->update( win );
}


void EngManager::startLoop() {
    sf::RenderWindow window( sf::VideoMode(200, 200), "SFML works!" );
    win = &window;
    sf::CircleShape shape( 100.f );
    shape.setFillColor( sf::Color::Green );

    while ( window.isOpen() )
    {
        sf::Event event;
        while ( window.pollEvent(event) )
        {
            if ( event.type == sf::Event::Closed )
                window.close();
        }

        std::for_each( containers.begin(),
                       containers.end(),
                       std::bind1st(std::mem_fun(&EngManager::updateContainers),
                                   this ) );

        window.clear();
        window.draw( shape );
        window.display();
    }
}

void EngManager::addContainer( EngContainer *container ) {
    containers.push_back( container );
}
