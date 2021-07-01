#pragma once

#include "CTexture.h"

/**
* @brief Class represents space texture properties
*/
class CSpaceTexture : public CTexture {

    /**
	 * @brief Method tells that space is not collidable
	 */
    bool ifCollide() const override;

    /**
	 * @brief Method tells that space is not destroyable
	 */
    bool ifDestroyable() const override;

public:

    /**
	 * @brief Default destructor
	 */
    ~CSpaceTexture();

};
