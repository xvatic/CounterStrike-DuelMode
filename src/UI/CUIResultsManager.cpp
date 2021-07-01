#include "CUIResultsManager.h"


bool CUIResultsManager::initialize(SDL_Renderer * renderer) {
    SDL_Surface * buffer = IMG_Load("assets/sprites/ConfirmButton.png");
    if(!buffer) {
        return false;
    }
    quitButtonImage = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);

    quitButton = new CButton(CCoords(1,0,0), renderer, quitButtonImage);
    quitButton->setCoords(CCoords(1,50,700));
    label = new CUIText({255,255,255,255}, "Scoreboard:", 40);
    label->setCoords(CCoords(1,100,200));
    std::string message;

    if (scoredResult == WON) {
        message = "YOU WON ! ";
    } else {
        message = "YOU LOSS :( ";
    }

    resultLabel = new CUIText({255,255,255,255}, message, 40);
    resultLabel->setCoords(CCoords(1,500,100));
    std::map<int, std::pair<std::string, std::pair <int,int>>>::iterator iterator;
    iterator = scoreboard.end();

    if (scoreboard.empty())
        return true;
    --iterator;
    firstPlace = new CUIText({255,255,255,255}, iterator->second.first + " score:" + std::to_string(iterator->second.second.first) + " : " + std::to_string(iterator->second.second.second), 40);
    firstPlace->setCoords(CCoords(1,500,300));

    if (iterator == scoreboard.begin())
        return true;
    --iterator;
    secondPlace = new CUIText({255,255,255,255}, iterator->second.first + " score:" + std::to_string(iterator->second.second.first) + " : " + std::to_string(iterator->second.second.second), 40);
    secondPlace->setCoords(CCoords(1,500,400));

    if (iterator == scoreboard.begin())
        return true;
    --iterator;
    thirdPlace = new CUIText({255,255,255,255}, iterator->second.first + " score:" + std::to_string(iterator->second.second.first) + " : " + std::to_string(iterator->second.second.second), 40);
    thirdPlace->setCoords(CCoords(1,500,500));

    if (iterator == scoreboard.begin())
        return true;
    --iterator;
    fourthPlace= new CUIText({255,255,255,255}, iterator->second.first + " score:" + std::to_string(iterator->second.second.first) + " : " + std::to_string(iterator->second.second.second), 40);
    fourthPlace->setCoords(CCoords(1,500,600));

    if (iterator == scoreboard.begin())
        return true;
    --iterator;
    fifthPlace = new CUIText({255,255,255,255}, iterator->second.first + " score:" + std::to_string(iterator->second.second.first) + " : " + std::to_string(iterator->second.second.second), 40);
    fifthPlace->setCoords(CCoords(1,500,700));
    return true;
}

bool CUIResultsManager::draw(SDL_Renderer * renderer) {
    quitButton->draw(renderer);
    label->draw(renderer);

    if (firstPlace != nullptr)
        firstPlace->draw(renderer);
    if (secondPlace != nullptr)
        secondPlace->draw(renderer);
    if (thirdPlace != nullptr)
        thirdPlace->draw(renderer);
    if (fourthPlace != nullptr)
        fourthPlace->draw(renderer);
    if (fifthPlace != nullptr)
        fifthPlace->draw(renderer);

    resultLabel->draw(renderer);
    return true;
}

CUIResultsManager::CUIResultsManager(std::multimap<int, std::pair<std::string, std::pair <int,int>>> data, Result r) {
    scoreboard = data;
    scoredResult = r;
}

void CUIResultsManager::update(SDL_Event e,const Uint8 *keystates, SDL_Renderer * renderer) {
    switch (e.type) {
        case SDL_MOUSEBUTTONUP:
            if (quitButton->isSelected() && e.button.button == SDL_BUTTON_LEFT) {
                running = false;
            }
            break;
    }
}

void CUIResultsManager::updateAutomatedObjects(SDL_Event e, const Uint8 *keystates, SDL_Renderer *renderer) {

}

CUIResultsManager::~CUIResultsManager() {
    delete quitButton;
    delete label;

    delete firstPlace;
    delete secondPlace;
    delete thirdPlace;
    delete fourthPlace;
    delete fifthPlace;

    delete resultLabel;
    if (quitButtonImage != nullptr)
        SDL_DestroyTexture(quitButtonImage);

}