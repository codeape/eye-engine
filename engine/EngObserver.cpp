#include "EngObserver.hpp"

EngObserver::EngObserver(){
    this->mObserverCalled = false;
}

EngObserver::~EngObserver() {

}

void EngObserver::update() {
    if (!mObserverCalled) {
        this->mObserverCalled = true;
        this->updateObserver();
        this->mObserverCalled = false;
    }
}
