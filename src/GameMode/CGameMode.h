#pragma once

#include "../Game/CGame.h"

/**
* @brief Class represents external manager of different modes
*/
class CGameMode {

    /**
	 * @brief Method that parse any data from UI
     * @param[in] tools & settings
	 */
    virtual int fetchInput(CGame & game) = 0;

    /**
	 * @brief Method that declares a logic of swithes between scenes in this mode
     * @param[in] tools & settings
	 */
    virtual void execute(CGame & game) = 0;

};