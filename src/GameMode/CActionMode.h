#pragma once

#include "CGameMode.h"
#include "../Player/CPersonPlayer.h"
#include "../Player/CEnemyPlayer.h"
#include "../UI/CUIGameManager.h"
#include "../UI/CUIResultsManager.h"

/**
* @brief Class represents external managin in Action Mode
*/
class CActionMode : public CGameMode {

    CUIGameManager * gameScreen = nullptr;
    CUIResultsManager * resultScreen = nullptr;

public:

    /**
	 * @brief Method that parse the executed manager
     * @param[in] tools & settings
	 */
    int fetchInput(CGame & game) override;

    /**
	 * @brief Method that declares a logic of swithes between scenes in this mode
     * @param[in] tools & settings
	 */
    void execute(CGame &game) override;

};
