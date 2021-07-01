#include "CActionMode.h"


int CActionMode::fetchInput(CGame & game) {
    if (gameScreen != nullptr) {
        game.setTerminationFlag(gameScreen->getTerminationFlag());
        game.appendScoreboard(std::make_pair(gameScreen->getPlayerScore() - gameScreen->getEnemyScore(), std::make_pair(game.getNickname(), std::make_pair(gameScreen->getPlayerScore(), gameScreen->getEnemyScore()))));
        game.updateFile();
        game.fetchResultsFromFile();
    }
    if (resultScreen != nullptr) {
        game.setTerminationFlag(resultScreen->getTerminationFlag());
    }

    return 0;
}

void CActionMode::execute(CGame & game) {
    switch (game.getSelectedMap()) {
        case CSettings::INFERNO:
            gameScreen = new CUIGameManager(game.getNickname(), CUIGameManager::INFERNO);
            break;
        case CSettings::DUST:
            gameScreen = new CUIGameManager(game.getNickname(), CUIGameManager::DUST);
            break;
        case CSettings::NUKE:
            gameScreen = new CUIGameManager(game.getNickname(), CUIGameManager::NUKE);
            break;
    }

    gameScreen->setMusic(game.getMusic());
    game.executeManager(gameScreen);
    game.fetchResultsFromFile();
    fetchInput(game);
    if (!game.isSuccessfullyFetched() || game.ifTerminationRequired()) {
        delete gameScreen;
        game.closeWindow();
        return;
    }

    game.resetFetchFlag();

    if (gameScreen->getPlayerScore() > gameScreen->getEnemyScore()) {
        resultScreen = new CUIResultsManager(game.getScoreboard(), CUIResultsManager::WON);
    } else {
        resultScreen = new CUIResultsManager(game.getScoreboard(), CUIResultsManager::LOSS);
    }

    delete gameScreen;
    gameScreen = nullptr;
    game.closeWindow();
    game.executeManager(resultScreen);
    fetchInput(game);
    delete resultScreen;
    game.closeWindow();
}

