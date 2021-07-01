#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_rect.h>
#include <curses.h>
#include "Game/CGame.h"
#include "GameMode/CActionMode.h"
#include "GameMode/CMainMenuMode.h"

using namespace std;


int main(int argc, char ** argv) {

    CGame game;

    if (!game.ifSuccessfullyInitialized()) {
        return 0;
    }

    CMainMenuMode mainMenuMode;

    mainMenuMode.execute(game);

    return 0;
}
