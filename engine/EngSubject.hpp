#ifndef ENGSUBJECT_HPP
#define ENGSUBJECT_HPP

#include "EngComponent.hpp"

#include <set>

class EngObserver;

class EngSubject : public EngComponent {
public:
    EngSubject();
    ~EngSubject();
    bool addObserver(EngObserver *);
    bool removeObserver(EngObserver *);
protected:
    void updateObservers();
    void unlinkObservers();
private:
    std::set<EngObserver *> mObservers;
};

#endif
