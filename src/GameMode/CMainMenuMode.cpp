#include "CMainMenuMode.h"


int CMainMenuMode::fetchInput(CGame & game) {
    if (entireScreen != nullptr) {
        game.setTerminationFlag(entireScreen->getTerminationFlag());
        switch (entireScreen->getTrack()) {
            case 1:				
                game.setMusic("SpearofJustice");
                break;
            case 2:
                game.setMusic("Dummy!");
                break;
            case 3:
                game.setMusic("Megalovania");
                break;
        }
        game.setNickname(entireScreen->getNickname());
    }

    if (mainMenuScreen != nullptr) {
        this->chosenOption = mainMenuScreen->getOption();
        game.setTerminationFlag(mainMenuScreen->getTerminationFlag());
        switch (mainMenuScreen->getMap()) {
            case CUIMainMenuManager::DUST:
                game.setMap(CSettings::DUST);
                break;
            case CUIMainMenuManager::INFERNO:
                game.setMap(CSettings::INFERNO);
                break;
            case CUIMainMenuManager::NUKE:
                game.setMap(CSettings::NUKE);
                break;
        }
    }
    return 0;
}

void CMainMenuMode::execute(CGame & game) {
    CActionMode actionMode;
    CTrainingMode trainingMode;

    entireScreen = new CUIEntireManager();
    game.executeManager(entireScreen);
    fetchInput(game);
    delete entireScreen;
    entireScreen = nullptr;
    game.closeWindow();

    bool isQuit = false;

    while (true) {

        if (isQuit || game.ifTerminationRequired()) {
            break;
        }
        mainMenuScreen = new CUIMainMenuManager();
        game.executeManager(mainMenuScreen);
        fetchInput(game);
        delete mainMenuScreen;
        mainMenuScreen = nullptr;
        game.closeWindow();
        if (game.ifTerminationRequired())
            break;
        switch (chosenOption) {
            case CUIMainMenuManager::QUIT:
                isQuit = true;
                break;
            case CUIMainMenuManager::TRAIN:
                trainingMode.execute(game);
                break;
            case CUIMainMenuManager::GAME:
                actionMode.execute(game);
                break;
            case CUIMainMenuManager::RESET:
                break;
        }
    }

}


