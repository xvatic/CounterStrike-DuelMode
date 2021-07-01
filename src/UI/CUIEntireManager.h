#pragma once

#include "CUIManager.h"
#include "CButton.h"
#include "CUIText.h"
#include "CCheckBox.h"

/**
* @brief Class represent UI Manager of entire scene
*/
class CUIEntireManager : public CUIManager {

    CButton * button;
    CUIText * textInput;
    CUIText * label;
    CUIText * labelMusic1;
    CUIText * labelMusic2;
    CUIText * labelMusic3;
    CCheckBox * checkBoxMusic1;
    CCheckBox * checkBoxMusic2;
    CCheckBox * checkBoxMusic3;
    SDL_Texture * confirmButtonImage = nullptr;
    SDL_Texture * textureChecked = nullptr;
    SDL_Texture * textureUnchecked = nullptr;
    std::string enteredNickname;
    int chosenTrack = 1;

public:

    /**
	 * @brief Method initialize all components
     * @param[in] renderer Renderer
	 */
    bool initialize(SDL_Renderer* renderer) override;

    /**
	 * @brief Default constructor
	 */
    CUIEntireManager();

    /**
	 * @brief Method draw whole scene
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
	 * @brief Method give a music chosen by user
	 */
    int getTrack() const;

    /**
	 * @brief Method give a nickname chosen by user
	 */
    std::string getNickname() const;
    /**
	 * @brief Default destructor
	 */
    ~CUIEntireManager();

};
