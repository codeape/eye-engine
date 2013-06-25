#include "EngSubject.hpp"

#include <algorithm>

EngSubject::EngSubject() {

}

EngSubject::~EngSubject(){
    unlinkObservers();
}

void updateObserverItem(EngObserver * aObserver) {
    aObserver->update();
}

void unlinkObserverItem(EngObserver * aObserver) {
    aObserver->unlink();
}

bool EngSubject::removeObserver(EngObserver *aObserver) {
    aObserver->unlink();
    return 1 == mObservers.erase(aObserver);
}

bool EngSubject::addObserver(EngObserver *aObserver) {
    std::pair<std::set<EngObserver *>::iterator, bool> status;
    status = mObservers.insert(aObserver);
    return status.second;
}

void EngSubject::updateObservers() {
    std::for_each(mObservers.begin(), mObservers.end(), updateObserverItem);
}

void EngSubject::unlinkObservers() {
    std::for_each(mObservers.begin(), mObservers.end(), updateObserverItem);
}
