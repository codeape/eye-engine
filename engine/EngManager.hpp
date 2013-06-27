#ifndef ENGMANAGER_HPP
#define ENGMANAGER_HPP

class EngManager {
public:
    EngManager();
    virtual ~EngManager();

    virtual void startLoop() = 0;
};

#endif
