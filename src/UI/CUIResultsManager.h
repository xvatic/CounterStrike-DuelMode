#pragma once

#include <memory>
#include <map>
#include <vector>
#include "CUIManager.h"
#include "CButton.h"
#include "CUIText.h"
#include "CImageView.h"
#include "CCheckBox.h"
#include "SDL_mixer.h"

/**
* @brief Class represent UI Manager of result scene
*/
class CUIResultsManager : public CUIManager {

    CButton * quitButton;
    CUIText * label;
    CUIText * resultLabel;
    CUIText * firstPlace = nullptr;
    CUIText * secondPlace = nullptr;
    CUIText * thirdPlace = nullptr;
    CUIText * fourthPlace = nullptr;
    CUIText * fifthPlace = nullptr;
    SDL_Texture * quitButtonImage;

    std::multimap<int, std::pair<std::string, std::pair <int,int>>> scoreboard;
public:
    enum Result {WON, LOSS};

private:
    Result scoredResult = LOSS;

public:
    /**
	 * @brief Method initialize all components
     * @param[in] renderer Renderer
	 */
    bool initialize(SDL_Renderer* renderer) override;

    /**
	 * @brief Full constructor
     * @param[in] data scoreboard
     * @param[in] r result of recent game
	 */
    CUIResultsManager(std::multimap<int, std::pair<std::string, std::pair <int,int>>> data, Result r);

    /**
	 * @brief Method draw bullet
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
	 * @brief Default destructor
	 */
    ~CUIResultsManager();
};
