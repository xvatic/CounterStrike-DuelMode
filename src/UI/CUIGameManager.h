#pragma once

#include <memory>
#include <vector>
#include <fstream>
#include "CUIManager.h"
#include "CButton.h"
#include "CUIText.h"
#include "CImageView.h"
#include "CCheckBox.h"
#include "CUITile.h"
#include "CUIPlayerComponent.h"
#include "CUIBulletComponent.h"
#include "../Player/CPlayer.h"

/**
* @brief Class represent UI Manager of game scene
*/
class CUIGameManager : public CUIManager {

    CUIText * scoreLabel = nullptr;
    CUIText * enemyLabel = nullptr;
    CUIText * playerLabel = nullptr;
    CUIText * playerHPLabel = nullptr;
    CUIText * enemyHPLabel = nullptr;
    CImageView * heartPlayer;
    CImageView * heartEnemy;
    SDL_Texture * loadedTextureBrick = nullptr;
    SDL_Texture * loadedTextureStone = nullptr;
    SDL_Texture * loadedTextureTree = nullptr;
    SDL_Texture * loadedTextureHeart = nullptr;
    SDL_Texture * loadedTextureMelee = nullptr;
    SDL_Texture * loadedTextureRanged = nullptr;
    SDL_Texture * loadedTextureLeaveButton = nullptr;
    SDL_Texture * loadedTexturePowerUp = nullptr;
    SDL_Texture * playerSprites = nullptr;
    CUIPlayerComponent * player;
    CUIPlayerComponent * enemy;
    std::string nickname;
    std::vector<std::string> rawMap;
    std::vector<CUITile*> mapTiles;
    std::vector<std::unique_ptr<CUIBulletComponent>> shotsPlayer;
    std::vector<std::unique_ptr<CUIBulletComponent>> shotsEnemy;
    std::vector<std::unique_ptr<CImageView>> bonusesDropped;

public:
    enum Map {DUST, INFERNO, NUKE};

private:
    Map selectedMap = INFERNO;

public:

    /**
	 * @brief Method refresh the map
     * @param[in] renderer Renderer
	 */
    void fetchMap (SDL_Renderer* renderer);

    /**
	 * @brief Method gives player score
	 */
    int getPlayerScore() const;

    /**
	 * @brief Method gives enemy score
	 */
    int getEnemyScore() const;

    /**
	 * @brief Method initialize all components
     * @param[in] renderer Renderer
	 */
    bool initialize(SDL_Renderer* renderer) override;

    /**
	 * @brief Full constructor
     * @param[in] nickname player's nickname
     * @param[in] m chosen map
	 */
    CUIGameManager(const std::string & nickname, Map m);

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
    void updateAutomatedObjects(SDL_Event e,const Uint8 * keystates, SDL_Renderer * renderer) override;

    /**
	 * @brief Default destructor
	 */
    ~CUIGameManager();

};
