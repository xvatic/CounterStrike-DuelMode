#pragma once

#include <SDL.h>
#include "../Player/CCoords.h"
#include <SDL_image.h>
#include <string>

/**
* @brief Class represents a Image
*/
class CImageView {

    SDL_Texture * texture;
    SDL_Rect sRect, dRect;

public:
    enum BonusType {NONE, POWERUP, HEAL};

private:
    BonusType selectedBonusType = NONE;

public:

    /**
	 * @brief Default constructor
	 */
    CImageView() {};

    /**
	 * @brief Method sets location
	 */
    void setCoords (CCoords coords);

    /**
	 * @brief Full constructor
     * @param[in] coords location
     * @param[in] renderer Renderer
     * @param[in] texture texture
	 */
    CImageView(CCoords coords, SDL_Renderer * renderer, SDL_Texture * texture);

    /**
	 * @brief Method draw Image
     * @param[in] renderer Renderer
	 */
    void draw(SDL_Renderer * renderer) const;

    /**
	 * @brief Method sets that instance is used to draw a bonus
     * @param[in] bt type of a bonus
	 */
    void setBonusType (BonusType bt);

    /**
	 * @brief Method sets own size
     * @param[in] coords width and height
	 */
    void setSize(CCoords coords);

    /**
	 * @brief Method sets source size
     * @param[in] coords width and height
	 */
    void setSourceSize(CCoords coords);

    /**
	 * @brief Method sets source location
     * @param[in] coords x and y
	 */
    void setSourceCoords(CCoords coords);

    /**
	 * @brief Method give a destination rect of the tile
     * @note that class might be also used as a bonus
	 */
    const SDL_Rect & getDestRect() const;

    /**
	 * @brief Method give a bonus type if the class is used as bonus
	 */
    BonusType getBonusType() const;

    /**
	 * @brief Default destructor
	 */
    ~CImageView();
};
