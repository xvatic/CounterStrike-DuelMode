#pragma once

#include "CGameMode.h"
#include "../Player/CEnemyPlayer.h"
#include "../Player/CPersonPlayer.h"
#include "../UI/CUITrainManager.h"

/**
* @brief Class represents external manager in Training Mode
*/
class CTrainingMode : public CGameMode {

CUITrainManager * trainingScreen;

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
    void execute(CGame & game) override;

};
