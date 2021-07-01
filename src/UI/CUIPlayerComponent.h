#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "CUITile.h"
#include "CUIBulletComponent.h"
#include "../Player/CCoords.h"
#include "../Player/CPlayer.h"
#include "../Map/CTexture.h"
#include "../Player/CPersonPlayer.h"
#include "../Player/CEnemyPlayer.h"

/**
* @brief Class represents graphical appearance of character
*/
class CUIPlayerComponent {

    SDL_Texture * texture;
    SDL_Texture * textureBullet;
    SDL_Texture * textureKnife;
    SDL_Rect sRect, dRect, collisionRect;
    CPlayer * playerOptions;
    CCoords enemyCoords = CCoords(0,0,0);
    int spriteColumn = 0;

public:
    enum Side {PLAYER, ENEMY};

    /**
	 * @brief Default constructor
	 */
    CUIPlayerComponent() {} ;

    /**
	 * @brief Method sets location
	 */
    void setCoords (CCoords coords);

    /**
	 * @brief Full constructor
     * @param[in] renderer renderer
     * @param[in] s playing side
     * @param[in] sprites textures for animation
     * @param[in] knifeSprites texture for knifeAnimation
     * @param[in] bullet  bullet texture
	 */
    CUIPlayerComponent(SDL_Renderer * renderer, Side s, SDL_Texture * sprites, SDL_Texture * knifeSprites, SDL_Texture * bullet);

    /**
	 * @brief Method draw bullet
     * @param[in] renderer Renderer
	 */
    void draw(SDL_Renderer * renderer);

    /**
	 * @brief Method updates character due to its logic
     * @param[in] e input events
     * @param[in] keystates keys conditions
     * @param[in] tiles list of map elements
     * @param[in] bonuses dropped bonuses
     * @param[in] shots active ally bullets
	 */
    void update(SDL_Event e, const Uint8 *keystates, std::vector<CUITile*> & tiles, std::vector<std::unique_ptr<CImageView>> & bonuses, std::vector<std::unique_ptr<CUIBulletComponent>> & shots);

    /**
	 * @brief Method checks the successful strikes
     * @param[in] shots active opponent bullets
	 */
    void checkHit(std::vector<std::unique_ptr<CUIBulletComponent>> & shots);

    /**
	 * @brief Method give a player's score
	 */
    int getScore();

    /**
	 * @brief Method give a point to player
	 */
    void addScore();

    /**
	 * @brief Method give a health of player
	 */
    int getHealth();

    /**
	 * @brief Method heal the player to full and set the default coords
	 */
    void refresh();

    /**
	 * @brief Method set the opponent coords
     * @note AI need to get the precise location of the player
	 */
    void setEnemyCoords(CCoords coords);

    /**
	 * @brief Method give a coords of player
	 */
    CCoords getCoords();

    /**
	 * @brief Method give a destination rect
	 */
    SDL_Rect getDestRect();
    /**
	 * @brief Default destructor
	 */
    ~CUIPlayerComponent();

};
