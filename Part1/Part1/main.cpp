#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"



#include "Game.h"

int main()
{
    //Init srand
    srand(static_cast<unsigned>(time(NULL)));

    //linking plog and logfile to save logs
    plog::init(plog::debug, "log.txt");
    
    //init game engine
    Game game;
    
    //window rendering loop
    while (game.running())
    {
        //Update
        game.update();
        //Render
        game.render();
    }
    //End of app
    return 0;
}