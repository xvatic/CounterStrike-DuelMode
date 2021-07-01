#pragma once

#include "CTexture.h"

/**
* @brief Class brick texture properties
*/
class CBrickTexture : public CTexture {

    /**
	 * @brief Method tells that brick is destroyable
	 */
    bool ifDestroyable() const override;

    /**
	 * @brief Method tells that brick is collidable
	 */
    bool ifCollide() const override;

public:

    /**
	 * @brief Default destructor
	 */
    ~CBrickTexture();

};

