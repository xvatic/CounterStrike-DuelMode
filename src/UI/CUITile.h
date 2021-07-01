#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "CImageView.h"
#include "../Player/CCoords.h"
#include "../Map/CTexture.h"
#include "../Map/CSpaceTexture.h"
#include "../Map/CTreeTexture.h"
#include "../Map/CBrickTexture.h"

/**
* @brief Class represents graphical appearance of tile on map
*/
class CUITile {

    SDL_Texture * texture, * textureHeal, * texturePowerUp;
    SDL_Rect sRect, dRect;
    CTexture * textureProperties;

public:
    enum Texture {SPACE, TREE, BRICK};

    /**
	 * @brief Default constructor
	 */
    CUITile() {};

    /**
	 * @brief Method sets location
	 */
    void setCoords (CCoords coords);

    /**
	 * @brief Full constructor
     * @param[in] coords location
     * @param[in] renderer Renderer
     * @param[in] texture texture of tile
     * @param[in] t type of texture
     * @param[in] textureHeal texture of healing buff
     * @param[in] texturePowerUp texture of buff
	 */
    CUITile(CCoords coords, SDL_Renderer * renderer, Texture t, SDL_Texture * textureSprite, SDL_Texture * texturePowerUp, SDL_Texture * textureHeal);

    /**
	 * @brief Method draw button
     * @param[in] renderer Renderer
	 */
    void draw(SDL_Renderer * renderer) const;

    /**
	 * @brief Method destroys the tile if it is possible
     * @param[in] renderer Renderer
     * @param[in] bonuses dropped bonuses
     * @param[in] generalPath path for loading new texture
	 */
    void destroy(std::vector<std::unique_ptr<CImageView>> & bonuses, SDL_Renderer * renderer);

    /**
	 * @brief Method tell if the tile is collide
	 */
    bool ifCollide() const;

    /**
	 * @brief Method tell if the tile is destroyable
	 */
    bool ifDestroyable() const;

    /**
	 * @brief Method give a destination rect of the tile
     * @note const ref is enough to check collisions
	 */
    const SDL_Rect & getDestRect() const;

    /**
	 * @brief Default destructor
	 */
    ~CUITile();

};
