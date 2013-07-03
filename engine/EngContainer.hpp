#ifndef ENGCONTAINER_HPP
#define ENGCONTAINER_HPP

class EngContainer {
public:
    EngContainer();
    virtual ~EngContainer();

    virtual void update() = 0;
};

#endif
