#pragma once

#include <memory>
#include "CUIManager.h"
#include "CButton.h"
#include "CUIText.h"
#include "CImageView.h"
#include "CCheckBox.h"
#include "SDL_mixer.h"

/**
* @brief Class represent UI Manager of main menu scene
*/
class CUIMainMenuManager : public CUIManager {

    CButton * trainButton;
    CButton * playButton;
    CButton * quitButton;
    CUIText * label = nullptr;
    CUIText * mapOptionLabel = nullptr;
    CUIText * mapInfernoLabel = nullptr;
    CUIText * mapNukeLabel = nullptr;
    CUIText * mapDustLabel = nullptr;
    CImageView * mapInferno;
    CImageView * mapNuke;
    CImageView * mapDust;
    CCheckBox * checkInferno;
    CCheckBox * checkDust;
    CCheckBox * checkNuke;
    SDL_Texture * infernoImage = nullptr;
    SDL_Texture * dustImage = nullptr;
    SDL_Texture * nukeImage = nullptr;
    SDL_Texture * quitButtonImage = nullptr;
    SDL_Texture * playButtonImage = nullptr;
    SDL_Texture * trainButtonImage = nullptr;
    SDL_Texture * textureChecked = nullptr;
    SDL_Texture * textureUnchecked = nullptr;

public:
    enum Map {DUST, INFERNO, NUKE};
    enum Option {TRAIN, GAME, QUIT, RESET};

private:
    Map selectedMap = INFERNO;
    Option chosenOption = QUIT;

public:
    /**
	 * @brief Method initialize all components
     * @param[in] renderer Renderer
	 */
    bool initialize(SDL_Renderer* renderer) override;

    /**
	 * @brief Default constructor
	 */
    CUIMainMenuManager();

    /**
	 * @brief Method draw all components
     * @param[in] renderer Renderer
	 */
    bool draw(SDL_Renderer * renderer) override;

    /**
	 * @brief Method update all componnets
     * @param[in] e input events
     * @param[in] keystates keys conditions
     * @param[in] renderer Renderer
	 */
    void update(SDL_Event e,const Uint8 *keystates, SDL_Renderer * renderer) override;

    /**
	 * @brief Method update all automated dynamic components
     * @param[in] e input events
     * @param[in] keystates keys conditions
     * @param[in] renderer Renderer
	 */
    void updateAutomatedObjects(SDL_Event e, const Uint8 *keystates, SDL_Renderer *renderer) override;

    /**
	 * @brief Method give a map chosen by user
	 */
    Map getMap() const;

    /**
	 * @brief Method give an option chosen by user
	 */
    Option getOption() const;

    /**
	 * @brief Default destructor
	 */
    ~CUIMainMenuManager();
};
