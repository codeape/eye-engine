#ifndef ENGMANAGER_HPP
#define ENGMANAGER_HPP

#include "EngContainer.hpp"

#include <vector>

class EngManager {
public:
    EngManager();
    virtual ~EngManager();

    virtual void startLoop();
private:
    std::vector<EngContainer *> containers; // vector instead
};

#endif
