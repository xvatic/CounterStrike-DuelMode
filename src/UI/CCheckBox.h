#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../Player/CCoords.h"

/**
* @brief Class represents a Check Box
*/
class CCheckBox {

    SDL_Texture * textureChecked = nullptr;
    SDL_Texture * textureUnchecked = nullptr;
    SDL_Rect sRect, dRect;
    bool selected = false;

public:

    /**
	 * @brief Default constructor
	 */
    CCheckBox() {};

    /**
	 * @brief Method sets location
	 */
    void setCoords (CCoords coords);

    /**
	 * @brief Full constructor
     * @param[in] coords location
     * @param[in] renderer Renderer
     * @param[in] generalPath path to textures
	 */
    CCheckBox(CCoords coords, SDL_Renderer * renderer, SDL_Texture * uncheckedTexture, SDL_Texture * checkedTexture);

    /**
	 * @brief Method draw a CheckBox
     * @param[in] renderer Renderer
	 */
    void draw(SDL_Renderer * renderer) const;

    /**
	 * @brief Method tells if button is covered
	 */
    bool isCovered() const;

    /**
	 * @brief Method set the unselect condition
	 */
    void select();

    /**
	 * @brief Method set the selected condition
	 */
    void unselect();

    /**
	 * @brief Method tell if the CheckBox is selected
	 */
    bool isSelected() const;

    /**
	 * @brief Default destructor
	 */
    ~CCheckBox();

};
