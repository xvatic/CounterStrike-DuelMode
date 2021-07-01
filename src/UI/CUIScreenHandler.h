#pragma once

#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <signal.h>
#include <iostream>
#include "CUIManager.h"
#include "CUIScreenHandler.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "../Player/CCoords.h"

/**
* @brief Class represents the rendering tool, that interacts with UI manager
*/
class CUIScreenHandler {
    bool libInitializationSuccessfully = true;
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    CUIManager * manager;
    bool isRunning = false;
    const int framesPerSecond = 60;

public:

    CUIScreenHandler();

    /**
	 * @brief Main loop.
     * @param[in] title window label
     * @param[in] size size of window
     * @param[in] cuiManager UI Manager
	 */
    bool execute(const std::string & title, CCoords size, CUIManager * cuiManager);

    /**
	 * @brief Method tell if sdl libs were successfully initalized
	 */
    bool ifLibsWereSuccessfullyInitialized() const;

    /**
	 * @brief Default destructor
	 */
    ~CUIScreenHandler();

    /**
	 * @brief External window destroying
	 */
    void closeWindow () ;

};
