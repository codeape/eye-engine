#include "EngManager.hpp"
#include "Player.hpp"
#include "EngKeyboardComp.hpp"

int main(int argc, char **argv) {
    EngManager manager;

    EngKeyboardComp keyBoard;
    Player p;
    p.addcomponent(&keyBoard);

    manager.addContainer( &p );

    manager.startLoop();

    return 0;
}
