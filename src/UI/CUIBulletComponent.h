#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "CUITile.h"
#include "../Player/CCoords.h"
#include "../Player/CPlayer.h"
#include "../Map/CTexture.h"
#include "../Player/CEnemyPlayer.h"
#include "../Player/CMeleeBullet.h"
#include "../Player/CRangedBullet.h"

/**
* @brief Class represents graphical appearance of bullet
*/
class CUIBulletComponent {

    SDL_Texture * texture;
    SDL_Rect sRect, dRect;
    CBullet * bulletOption;

public:
    enum Type {MELEE, RANGED};

    /**
	 * @brief Default constructor
	 */
    CUIBulletComponent() {};

    /**
	 * @brief Method sets location
	 */
    void setCoords (CCoords coords) const;

    /**
	 * @brief Full constructor
     * @param[in] t bullet type
     * @param[in] texture texture
	 */
    CUIBulletComponent(Type t, SDL_Texture * texture);

    /**
	 * @brief Method draw bullet
     * @param[in] renderer Renderer
	 */
    void draw(SDL_Renderer * renderer);

    /**
	 * @brief Method updates bullet due to its logic
	 */
    void update(CCoords coords);

    /**
	 * @brief Method tell if the bullet is corrupted
	 */
    bool ifCorrupted() const;

    /**
	 * @brief Method set the currupted condition to bullet
     * @note the corrupted bullet need to be destroyed
	 */
    void setCorrupted();

    /**
	 * @brief Method give a destination rect of the tile
     * @note const ref is enough to check collisions
	 */
    const SDL_Rect & getDestRect() const;

    /**
	 * @brief Method give a bullet's damage
	 */
    int getDamage() const;

    /**
	 * @brief Default destructor
	 */
    ~CUIBulletComponent();

};
