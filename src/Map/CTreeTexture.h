#pragma once

#include "CTexture.h"

/**
* @brief Class represents tree texture properties
*/
class CTreeTexture: public CTexture {

    /**
	 * @brief Method that tree is collidable
	 */
    bool ifCollide() const override;

    /**
	 * @brief Method that tree is destroyable
	 */
    bool ifDestroyable() const override;

public:

    /**
	 * @brief Default destructor
	 */
    ~CTreeTexture();

};
