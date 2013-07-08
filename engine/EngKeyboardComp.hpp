#ifndef ENGKEYBOARDCOMP_HPP
#define ENGKEYBOARDCOMP_HPP

#include "EngSubject.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <map>

class EngKeyboardComp : public EngSubject {

public:
                    EngKeyboardComp();
    virtual         ~EngKeyboardComp();
    virtual void    update();
    virtual void    registerKey(sf::Keyboard::Key, int);
private:
    std::map<sf::Keyboard::Key, int> keys;
};

#endif

