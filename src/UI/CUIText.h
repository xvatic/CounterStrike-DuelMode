#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Player/CCoords.h"

/**
* @brief Class represents the text with input ability
*/
class CUIText {

    SDL_Texture * texture{};
    SDL_Rect dRect{};
    TTF_Font * font;
    SDL_Color color{};
    int textSize = 14;
    std::string message;
    bool selected{};

public:
    /**
	 * @brief Default constructor
	 */
    CUIText() {};

    /**
	 * @brief Method sets location
	 */
    void setCoords (CCoords coords);

    /**
	 * @brief Full constructor
     * @param[in] message text to display
     * @param[in] textSize font size
     * @param[in] generalPath path to font
	 */
    CUIText(SDL_Color, const std::string & message, int textSize);

    /**
	 * @brief Method draw text
     * @param[in] renderer Renderer
	 */
    void draw(SDL_Renderer * renderer);

    /**
	 * @brief Default destructor
	 */
    std::string getText() const;

    /**
	 * @brief Method set the passed text
	 */
    void setText(const std::string & text);

    /**
	 * @brief Method add a passed string to text
	 */
    void append(const std::string & text);

    /**
	 * @brief Method erase one char from text
	 */
    void erase();

    /**
	 * @brief Default destructor
     */
    ~CUIText();

};
