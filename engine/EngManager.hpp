#ifndef ENGMANAGER_HPP
#define ENGMANAGER_HPP

#include "EngContainer.hpp"

#include <vector>

class EngManager {
public:
    EngManager();
    virtual ~EngManager();

    virtual void startLoop();

    virtual void addContainer(EngContainer *);
    void updateContainers(EngContainer *);
private:
    std::vector<EngContainer *> containers;
};

#endif
