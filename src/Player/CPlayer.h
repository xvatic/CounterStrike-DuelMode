#pragma once

#include <vector>
#include <SDL.h>
#include "CCoords.h"
#include "CBullet.h"

/**
* @brief Class represents template for character's logic
*/
class CPlayer {

public:

    /**
	 * @brief Method performs character's moving
     * @param[in] direction moving direction
     * @param[in] enemyCoords opponent location
	 */
    virtual void fetchMoves(int direction, CCoords enemyCoords) = 0;

    /**
	 * @brief Method performs character's moving
     * @param[in] direction moving direction
	 */
    virtual bool meleeShot(const Uint8 * keystates) const = 0;

    /**
	 * @brief Method performs character's moving
     * @param[in] direction moving direction
	 */
    virtual bool rangedShot(const Uint8 * keystates) const = 0;

    /**
	 * @brief Method performs reset character's location
	 */
    virtual void setDefaultCoords() = 0;

    /**
	 * @brief Method returns a character's score
	 */
    int getScore() {
        return score;
    }

    /**
	 * @brief Method returns a character's health
	 */
    int getHealth() const {
        return health;
    }

    /**
	 * @brief Method set's character's X-coordinate
     * @param[in] x coordinate
	 */
    void setX(int x) {
        this->coords.x = x;
    }

    /**
	 * @brief Method set's character's Y-coordinate
     * @param[in] y coordinate
	 */
    void setY(int y) {
        this->coords.y = y;
    }

    /**
	 * @brief Method get a character one point
	 */
    void addScore() {
        score+=1;
    }

    /**
	 * @brief Method refresher character's health and removes buff
	 */
    void refresh() {
        boosted = false;
        health = 100;
    }

    /**
	 * @brief Method returns coordinates
	 */
    CCoords getCoords() {
        return coords;
    }

    /**
	 * @brief Method returns animation step
	 */
    int getStep () {
        return step;
    }

    /**
	 * @brief Method damages character
	 */
    void Damage (int damage) {
        if (!boosted) {
            health -= damage;
        }
    }

    /**
	 * @brief Method heals character
	 */
    void Heal (int hp) {
        health += hp;
        if (health >= 100) {
            health = 100;
        }
    }

    /**
	 * @brief Method gives character a buff
	 */
    void boost () {
        boosted = true;
    }

    /**
	 * @brief Method tells if AI bot can shoot
	 */
    bool isRange () {
        return shootingRange;
    }

    /**
	 * @brief Default virtual destructor
     * @note Should be virtual because of polymorfismus
	 */
    virtual ~CPlayer() {
    }

protected:
    bool shootingRange = false;
    int frameTime = 1;
    int stepTickRate = 0;
    bool boosted = false;
    const int framesPerSecond = 60;
    int step = 0;
    int score = 0;
    int health = 100;
    CCoords coords;
};
