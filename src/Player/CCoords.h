#pragma once

/**
* @brief Class represents coordinates value
*/
class CCoords {

public:
    int direction;
    int x;
    int y;

    /**
	 * @brief Full constructor
	 */
    CCoords(int direction, int x, int y);

    /**
	 * @brief Default constructor
	 */
    CCoords();

};