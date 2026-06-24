#include <SDL.h>
#include <iostream>

#include "framework/Game.h"

int main(int argc, char* argv[])
{
    Game game;

    if (!game.Initialize())
    {
        return -1;
    }

    game.Run();
    game.Shutdown();

    return 0;
}
