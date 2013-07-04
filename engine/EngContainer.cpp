#include "EngContainer.hpp"

EngContainer::EngContainer() {
    components = NULL;
}

EngContainer::~EngContainer(){
    if ( NULL != components ) {
        delete( components );
    }
}

// separate loop for default container vector?

void EngContainer::addcomponent(EngComponent *) {
    if ( NULL == components ) {
        components = new std::vector<EngComponent *>();
    }
    
}

