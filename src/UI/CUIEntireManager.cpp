#include "CUIEntireManager.h"


bool CUIEntireManager::initialize(SDL_Renderer * renderer) {
    SDL_Surface * buffer = IMG_Load("assets/sprites/ConfirmButton.png");
    if(!buffer) {
        return false;
    }
    confirmButtonImage = SDL_CreateTextureFromSurface(renderer, buffer);
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
    button = new CButton(CCoords(1,0,0), renderer, confirmButtonImage);
    button->setCoords(CCoords(1,425,600));
    textInput = new CUIText({255,0,0,255}, "", 30);
    textInput->setCoords(CCoords(1,100,400));
    label = new CUIText({255,255,255,255}, "Choose the nickname:", 40);
    label->setCoords(CCoords(1,100,300));
    labelMusic1 = new CUIText({255,255,255,255}, "Spear of Justice", 15);
    labelMusic1->setCoords(CCoords(1,160,50));
    labelMusic2 = new CUIText({255,255,255,255}, "Dummy!", 15);
    labelMusic2->setCoords(CCoords(1,510,50));
    labelMusic3 = new CUIText({255,255,255,255}, "Megalovania", 15);
    labelMusic3->setCoords(CCoords(1,860,50));
    checkBoxMusic1 = new CCheckBox(CCoords(1,0,0), renderer, textureUnchecked, textureChecked);
    checkBoxMusic1->setCoords(CCoords(1,160,100));
    checkBoxMusic2 = new CCheckBox(CCoords(1,0,0), renderer, textureUnchecked, textureChecked);
    checkBoxMusic2->setCoords(CCoords(1,510,100));
    checkBoxMusic3 = new CCheckBox(CCoords(1,0,0), renderer, textureUnchecked, textureChecked);
    checkBoxMusic3->setCoords(CCoords(1,860,100));
    checkBoxMusic1->select();
    return true;
}

bool CUIEntireManager::draw(SDL_Renderer * renderer) {
    button->draw(renderer);
    label->draw(renderer);
    textInput->draw(renderer);
    labelMusic1->draw(renderer);
    labelMusic2->draw(renderer);
    labelMusic3->draw(renderer);
    checkBoxMusic1->draw(renderer);
    checkBoxMusic2->draw(renderer);
    checkBoxMusic3->draw(renderer);
    return true;
}

CUIEntireManager::CUIEntireManager() {}

void CUIEntireManager::update(SDL_Event e,const Uint8 * keystates, SDL_Renderer * renderer) {
    switch (e.type) {
        case SDL_MOUSEBUTTONUP:
            if (button->isSelected() && e.button.button == SDL_BUTTON_LEFT) {
                if (!textInput->getText().empty())
                    running = false;
            }
            if (checkBoxMusic1->isCovered() && e.button.button == SDL_BUTTON_LEFT) {
                checkBoxMusic1->select();
                checkBoxMusic2->unselect();
                checkBoxMusic3->unselect();
                chosenTrack = 1;
            } else if (checkBoxMusic2->isCovered() && e.button.button == SDL_BUTTON_LEFT) {
                checkBoxMusic1->unselect();
                checkBoxMusic2->select();
                checkBoxMusic3->unselect();
                chosenTrack = 2;
            } else if (checkBoxMusic3->isCovered() && e.button.button == SDL_BUTTON_LEFT) {
                checkBoxMusic1->unselect();
                checkBoxMusic2->unselect();
                checkBoxMusic3->select();
                chosenTrack = 3;
            }
            break;
        case SDL_TEXTINPUT:
            if (enteredNickname.size() < 10) {
                textInput->append(e.text.text);
                enteredNickname = textInput->getText();
            }
            break;
    }

    if (keystates[SDL_SCANCODE_BACKSPACE] && textInput->getText().length() > 0) {
        textInput->erase();
        enteredNickname = textInput->getText();
    }

}

void CUIEntireManager::updateAutomatedObjects(SDL_Event e, const Uint8 *keystates, SDL_Renderer *renderer) {
}

int CUIEntireManager::getTrack() const {
    return chosenTrack;
}

std::string CUIEntireManager::getNickname() const {
    return enteredNickname;
}

CUIEntireManager::~CUIEntireManager() {
    delete checkBoxMusic1;
    delete checkBoxMusic2;
    delete checkBoxMusic3;
    delete button;
    delete label;
    delete textInput;
    delete labelMusic1;
    delete labelMusic2;
    delete labelMusic3;

    if (confirmButtonImage != nullptr)
        SDL_DestroyTexture(confirmButtonImage);
    if (textureChecked != nullptr)
        SDL_DestroyTexture(textureChecked);
    if (textureUnchecked != nullptr)
        SDL_DestroyTexture(textureUnchecked);
}


