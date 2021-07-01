//
// Created by Евгений on 5/30/21.
//

#include "CUIMainMenuManager.h"

bool CUIMainMenuManager::initialize(SDL_Renderer* renderer) {
    SDL_Surface * buffer = IMG_Load("assets/sprites/StartButton.png");
    if(!buffer) {
        return false;
    }
    playButtonImage = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/TrainButton.png");
    if(!buffer) {
        return false;
    }
    trainButtonImage = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/QuitButton.png");
    if(!buffer) {
        return false;
    }
    quitButtonImage = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/pics/Inferno.png");
    if(!buffer) {
        return false;
    }
    infernoImage = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/pics/Dust.png");
    if(!buffer) {
        return false;
    }
    dustImage = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/pics/Nuke.png");
    if(!buffer) {
        return false;
    }
    nukeImage = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/CheckedCheckBox.png");
    if(!buffer) {
        return false;
    }
    textureChecked = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/UncheckedCheckBox.png");
    if(!buffer) {
        return false;
    }
    textureUnchecked = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    playButton = new CButton(CCoords(1,0,0), renderer, playButtonImage);
    playButton->setCoords(CCoords(1,600-87,50));
    trainButton = new CButton(CCoords(1,0,0), renderer, trainButtonImage);
    trainButton->setCoords(CCoords(1,600-87,170));
    quitButton = new CButton(CCoords(1,0,0), renderer, quitButtonImage);
    quitButton->setCoords(CCoords(1,600-87,290));
    label = new CUIText({255,255,255,255}, "Counter Strike -1.6", 30);
    label->setCoords(CCoords(1,20,10));
    mapOptionLabel = new CUIText({255,255,255,255}, "Choose the map:", 20);
    mapOptionLabel->setCoords(CCoords(1,20,400));
    mapInfernoLabel = new CUIText({255,255,255,255}, "de-inferno", 15);
    mapInfernoLabel->setCoords(CCoords(1,160,470));
    mapDustLabel = new CUIText({255,255,255,255}, "de-dust2", 15);
    mapDustLabel->setCoords(CCoords(1,510,470));
    mapNukeLabel = new CUIText({255,255,255,255}, "de-nuke", 15);
    mapNukeLabel->setCoords(CCoords(1,860,470));
    mapInferno = new CImageView(CCoords(1,0,0), renderer, infernoImage);
    mapInferno->setCoords(CCoords(1,150,500));
    mapInferno->setSize(CCoords(1, 200, 125));
    mapDust = new CImageView(CCoords(1,0,0), renderer, dustImage);
    mapDust->setCoords(CCoords(1,500,500));
    mapDust->setSize(CCoords(1, 200, 125));
    mapNuke = new CImageView(CCoords(1,0,0), renderer, nukeImage);
    mapNuke->setCoords(CCoords(1,850,500));
    mapNuke->setSize(CCoords(1, 200, 125));
    checkInferno = new CCheckBox(CCoords(1,0,0), renderer, textureUnchecked, textureChecked);
    checkInferno->setCoords(CCoords(1,150+63,650));
    checkDust = new CCheckBox(CCoords(1,0,0), renderer, textureUnchecked, textureChecked);
    checkDust->setCoords(CCoords(1,500+63,650));
    checkNuke = new CCheckBox(CCoords(1,0,0), renderer, textureUnchecked, textureChecked);
    checkNuke->setCoords(CCoords(1,850+63,650));
    checkInferno->select();
    return true;
}

bool CUIMainMenuManager::draw(SDL_Renderer * renderer) {
    playButton->draw(renderer);
    trainButton->draw(renderer);
    quitButton->draw(renderer);
    label->draw(renderer);
    mapInferno->draw(renderer);
    mapDust->draw(renderer);
    mapNuke->draw(renderer);
    mapOptionLabel->draw(renderer);
    mapInfernoLabel->draw(renderer);
    mapDustLabel->draw(renderer);
    mapNukeLabel->draw(renderer);
    checkInferno->draw(renderer);
    checkDust->draw(renderer);
    checkNuke->draw(renderer);
    return true;
}

CUIMainMenuManager::CUIMainMenuManager() {

}

void CUIMainMenuManager::update(SDL_Event e,const Uint8 *keystates, SDL_Renderer * renderer) {
    switch (e.type) {
        case SDL_MOUSEBUTTONUP:
            if (trainButton->isSelected() && e.button.button == SDL_BUTTON_LEFT) {
                chosenOption = TRAIN;
                running = false;
            }
            if (playButton->isSelected() && e.button.button == SDL_BUTTON_LEFT) {
                chosenOption = GAME;
                running = false;
            }
            if (quitButton->isSelected() && e.button.button == SDL_BUTTON_LEFT) {
                chosenOption = QUIT;
                running = false;
            }
            if (checkInferno->isCovered() && e.button.button == SDL_BUTTON_LEFT) {
                checkInferno->select();
                checkDust->unselect();
                checkNuke->unselect();
                selectedMap = INFERNO;
            } else if (checkDust->isCovered() && e.button.button == SDL_BUTTON_LEFT) {
                checkInferno->unselect();
                checkDust->select();
                checkNuke->unselect();
                selectedMap = DUST;
            } else if (checkNuke->isCovered() && e.button.button == SDL_BUTTON_LEFT) {
                checkInferno->unselect();
                checkDust->unselect();
                checkNuke->select();
                selectedMap = NUKE;
            }
            break;
    }
}

CUIMainMenuManager::~CUIMainMenuManager() {
    delete checkInferno;
    delete checkDust;
    delete checkNuke;

    delete playButton;
    delete trainButton;
    delete quitButton;

    delete label;
    delete mapOptionLabel;
    delete mapInfernoLabel;
    delete mapNukeLabel;
    delete mapDustLabel;

    delete mapDust;
    delete mapInferno;
    delete mapNuke;

    if (infernoImage != nullptr)
        SDL_DestroyTexture(infernoImage);
    if (dustImage != nullptr)
        SDL_DestroyTexture(dustImage);
    if (nukeImage != nullptr)
        SDL_DestroyTexture(nukeImage);
    if (quitButtonImage != nullptr)
        SDL_DestroyTexture(quitButtonImage);
    if (playButtonImage != nullptr)
        SDL_DestroyTexture(playButtonImage);
    if (trainButtonImage != nullptr)
        SDL_DestroyTexture(trainButtonImage);
}

CUIMainMenuManager::Map CUIMainMenuManager::getMap() const {
    return selectedMap;
}

CUIMainMenuManager::Option CUIMainMenuManager::getOption() const {
    return chosenOption;
}

void CUIMainMenuManager::updateAutomatedObjects(SDL_Event e, const Uint8 *keystates, SDL_Renderer *renderer) {}
