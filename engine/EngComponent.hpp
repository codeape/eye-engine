#ifndef ENGCOMPONENT_HPP
#define ENGCOMPONENT_HPP

class EngComponent {
public:
    virtual ~EngComponent();
    virtual void update() = 0;
};

#endif
