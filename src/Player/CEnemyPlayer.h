#pragma once

#include "CPlayer.h"
#include <cmath>
#include <SDL.h>

/**
* @brief Class represents enemy logic
*/
class CEnemyPlayer : public CPlayer {

    /**
	 * @brief Method represents simple AI. Moves according to players coordinates
     * @param[in] direction moving direction
     * @param[in] enemyCoords opponent locaton
	 */
    void fetchMoves(int direction, CCoords enemyCoords) override;

    /**
	 * @brief Method performs character's moving
     * @param[in] direction moving direction
     * @param[in] enemyCoords opponent locaton
	 */
    bool meleeShot(const Uint8 * keystates) const override;

    /**
	 * @brief Method performs character's moving
     * @param[in] direction moving direction
     * @param[in] enemyCoords opponent locaton
	 */
    bool rangedShot(const Uint8 * keystates) const override;

public:

    /**
	 * @brief Method moves character to default location
	 */
    void setDefaultCoords() override;



    /**
	 * @brief Deafault destructor
	 */
    ~CEnemyPlayer();

};