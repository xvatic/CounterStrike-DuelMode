#pragma once

#include <SDL.h>
#include "../Player/CCoords.h"
#include <SDL_image.h>
#include <string>

/**
* @brief Class represents a button
*/
class CButton {

    SDL_Texture * texture;
    SDL_Rect sRect, dRect;
    bool selected;

public:

    /**
	 * @brief Default constructor
	 */
    CButton() {};

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
    CButton(CCoords coords, SDL_Renderer * renderer, SDL_Texture * texture);

    /**
	 * @brief Method draw button
     * @param[in] renderer Renderer
	 */
    void draw(SDL_Renderer * renderer) const;

    /**
	 * @brief Method tells if button is covered
	 */
    bool isSelected () const;

    /**
	 * @brief Default destructor
	 */
    ~CButton();
};