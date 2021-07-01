#pragma once

#include "CCoords.h"

/**
* @brief Class represents template for bullet properties
*/
class CBullet {

public:

    /**
	 * @brief Method updates bullet due to its logic
	 */
    virtual void Move() = 0;

    /**
	 * @brief Method sets X-coordinate
     * @param[in] x coordinate
	 */
    void setX(int x) {
        this->coords.x = x;
    }

    /**
	 * @brief Method sets Y-coordinate
     * @param[in] y-coordinate
	 */
    void setY(int y) {
        this->coords.y = y;
    }

    /**
	 * @brief Method returns bullet's coordinates
	 */
    CCoords getCoords() const {
        return coords;
    }

    /**
	 * @brief Method returns bullet's animation step
	 */
    int getStep () const {
        return step;
    }

    /**
	 * @brief Method sets the direction of moving
     * @param[in] direction
	 */
    void setDirection(int direction) {
        coords.direction = direction;
    }

    /**
	 * @brief Method returns the damage of bullet
	 */
    int getDamage() const {
        return damage;
    }

    /**
	 * @brief Method tells if the bullet is corrupted
	 */
    bool isCorrupted() const {
        return corrupted;
    }

    /**
	 * @brief Method sets bullet to corrupted condition
	 */
    void setCorrupted() {
        corrupted = true;
    }

    /**
	 * @brief Method set coords of the striker
     * @note the knife must follow the owner
	 */
    void setOwnerCoords(CCoords coords) {
        ownerCoords = coords;
    }

    /**
	 * @brief Default destructor
	 */
    virtual ~CBullet() {
    }

protected:
    CCoords coords;
    CCoords ownerCoords;
    bool corrupted = false;
    int frameTime = 0;
    int framesPerSecond = 60;
    int step = 0;
    int damage = 0;
};

