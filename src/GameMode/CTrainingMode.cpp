#include "CTrainingMode.h"


int CTrainingMode::fetchInput(CGame & game) {
    game.setTerminationFlag(trainingScreen->getTerminationFlag());
    return 0;
}

void CTrainingMode::execute(CGame & game) {

    switch (game.getSelectedMap()) {
        case CSettings::INFERNO:
            trainingScreen = new CUITrainManager(game.getNickname(), CUITrainManager::INFERNO);
            break;
        case CSettings::DUST:
            trainingScreen = new CUITrainManager(game.getNickname(), CUITrainManager::DUST);
            break;
        case CSettings::NUKE:
            trainingScreen = new CUITrainManager(game.getNickname(), CUITrainManager::NUKE);
            break;
    }

    game.executeManager(trainingScreen);
    fetchInput(game);
    delete trainingScreen;
    game.closeWindow();
}



