#include "CUIScreenHandler.h"

bool signalCaught = false;

void signalHandler (int) {
    signalCaught = true;
}

CUIScreenHandler::CUIScreenHandler() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        libInitializationSuccessfully = false;
    }
    if (IMG_Init(IMG_INIT_PNG) < 0) {
        libInitializationSuccessfully = false;
    }
    if (TTF_Init() < 0) {
        libInitializationSuccessfully = false;
    }
}

bool CUIScreenHandler::execute(const std::string & title, CCoords size, CUIManager * cuiManager) {

    window = SDL_CreateWindow(title.c_str(), 10, 100, size.x, size.y, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    this->manager = cuiManager;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    int frameTime = 0;

    if (!this->manager->initialize(renderer)) {
        manager->setTerminationFlag();
        return false;
    }

    SDL_Event e;
    isRunning = true;

    signal(SIGTERM, signalHandler);
    signal(SIGINT, signalHandler);

    while(isRunning)
    {
        int currTicks = SDL_GetTicks();

        const Uint8 * keystates;
        while( SDL_PollEvent( &e ) != 0 )
        {
            keystates = SDL_GetKeyboardState(nullptr);
            switch (e.type) {
                case SDL_QUIT:
                    signalHandler(0);
                    break;
            }
            manager->update(e,keystates, renderer);
        }
        frameTime++;
        if (framesPerSecond / frameTime == 12) {
            frameTime = 0;
            manager->updateAutomatedObjects(e,keystates, renderer);
        }

        manager->draw(renderer);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        if (!manager->isRunning())
            isRunning = false;

        int newTicks = SDL_GetTicks();
        int delta = newTicks - currTicks;
        if (1000/framesPerSecond > delta)
            SDL_Delay(1000/framesPerSecond - delta);
        if (signalCaught) {
            manager->stop();
            manager->setTerminationFlag();
        }

    }


    return true;
}

void CUIScreenHandler::closeWindow() {
    if (renderer != nullptr)
        SDL_DestroyRenderer(renderer);
    if (window != nullptr)
        SDL_DestroyWindow(window);
}

bool CUIScreenHandler::ifLibsWereSuccessfullyInitialized() const {
    return libInitializationSuccessfully;
}

CUIScreenHandler::~CUIScreenHandler() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

