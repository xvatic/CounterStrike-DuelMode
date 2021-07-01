#pragma once

#include "CBullet.h"

/**
* @brief Class represents melee weapon logic
*/
class CMeleeBullet : public CBullet {

public:

    /**
	 * @brief Method moves a bullet due to its logic
	 */
    void Move() override;

    /**
	 * @brief Default constructor
	 */
    CMeleeBullet();

    /**
	 * @brief Default destructor
	 */
    ~CMeleeBullet();

};
