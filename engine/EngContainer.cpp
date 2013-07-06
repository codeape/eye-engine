#include "EngContainer.hpp"
#include "EngComponent.hpp"

#include <algorithm>

void updateContainerItem( EngComponent *component ) {
    component->update();
}

EngContainer::EngContainer() {
    components = NULL;
}

EngContainer::~EngContainer(){
    if ( NULL != components ) {
        delete( components );
    }
}

// separate loop for default container vector?

void EngContainer::addcomponent( EngComponent *component ) {
    if ( NULL == components ) {
        components = new std::vector<EngComponent *>();
    }
    components->push_back(component);
}

void EngContainer::update( sf::RenderWindow * ) {
    std::for_each( components->begin(), components->end(), updateContainerItem );
}

