#pragma once

#include "CGameMode.h"
#include "CActionMode.h"
#include "CTrainingMode.h"
#include "../UI/CUIEntireManager.h"
#include "../UI/CUIMainMenuManager.h"

/**
* @brief Class represents external managin in Main Menu
*/
class CMainMenuMode : public CGameMode {

    CUIEntireManager * entireScreen = nullptr;
    CUIMainMenuManager * mainMenuScreen = nullptr;
    int chosenTrack;
    std::string selectedNickname;
    std::string pathMusic;
    CUIMainMenuManager::Option chosenOption = CUIMainMenuManager::QUIT;

public:

    /**
	 * @brief Method that parse the executed manager
     * @param[in] game tools & settings
	 */
    int fetchInput(CGame & game) override;

    /**
	 * @brief Method that declares a logic of swithes between scenes in this mode
     * @param[in] tools & settings
	 */
    void execute(CGame & game) override;

};
