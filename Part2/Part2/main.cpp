#include "Game.h"

int main()
{

    //Initialise random seed
    srand(static_cast<unsigned>(time(NULL)));

    //Initialize game object
    Game game;

    // game loop
    while (game.running() && !game.getEndGame())
    {
        game.update();

        game.render();
    }

    return 0;
}