#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Windows.h>
#include <time.h> 

#include "Game.h"
//WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)


int main() {

    //Init game
    Sprites spr = Sprites();
    Resources res = Resources();
    srand(time(NULL));
    Game game;
    game.initAll();

    while (game.isWindowOpen()) {

        //Update
        game.frameUpdate();

        //Render
        game.render();

    }

    return 0;
}
