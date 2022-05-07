#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Windows.h>

#include "Game.h"
//WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)


int main() {

    //Init game
    Sprites spr = Sprites();
    Resources res = Resources();
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
