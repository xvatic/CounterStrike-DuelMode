#pragma once

/**
* @brief Class represents template for texture properties
*/
class CTexture {

public:

    /**
	 * @brief Method tells if the texture is collidable
	 */
    virtual bool ifCollide() const = 0;

    /**
	 * @brief Method tells if the texture is destroyable
	 */
    virtual bool ifDestroyable() const = 0;

    /**
	 * @brief Default virtual destructor
     * @note Should be virtual because of polymorfismus
	 */
    virtual ~CTexture() {
    }

};

