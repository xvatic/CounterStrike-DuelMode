#pragma once

#include "CBullet.h"

/**
* @brief Class represents ranged weapon logic
*/
class CRangedBullet : public CBullet {

public:

    /**
	 * @brief Method moves a bullet due to its logic
	 */
    void Move() override;

    /**
	 * @brief Default constructor
	 */
    CRangedBullet();

    /**
	 * @brief Default destructor
	 */
    ~CRangedBullet();

};