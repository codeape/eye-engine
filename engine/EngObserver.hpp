#ifndef ENGOBSERVER_HPP
#define ENGOBSERVER_HPP

#include "EngComponent.hpp"
#include "EngSubject.hpp"

class EngObserver : public EngComponent {
public:
    EngObserver();
    virtual ~EngObserver();
    void update();
    void unlink();
protected:
    virtual void updateObserver() = 0;
    virtual void unlinkObserver() = 0;
private:
    bool mObserverCalled;
};

#endif
