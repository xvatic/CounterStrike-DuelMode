#pragma once

#include "CPlayer.h"

/**
 * @brief Class represents player moving
 */
class CPersonPlayer : public CPlayer {

public:

    /**
	 * @brief Method perform player's moving
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

    /**
	 * @brief Method moves character to default location
	 */
    void setDefaultCoords() override;

    /**
	 * @brief Deafault destructor
	 */
    ~CPersonPlayer();

};
