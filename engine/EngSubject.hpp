#ifndef ENGSUBJECT_HPP
#define ENGSUBJECT_HPP

#include "EngObserver.hpp"
#include <set>

class EngSubject {
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
