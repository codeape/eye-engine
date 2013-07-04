#include "EngManager.hpp"
#include "Player.hpp"

int main(int argc, char **argv) {
    EngManager manager;

    Player p;
    manager.addContainer(&p);

    manager.startLoop();

    return 0;
}
