#include "CEnemyPlayer.h"

void CEnemyPlayer::fetchMoves(int direction, CCoords enemyCoords) {
    double distance = sqrt(pow(fabs(coords.y - enemyCoords.y),2) + pow(fabs(coords.x - enemyCoords.x),2));

    if (distance < 300) {
        shootingRange = true;
    } else {
        shootingRange = false;
    }

    double tg = fabs(coords.y - enemyCoords.y) / fabs(coords.x - enemyCoords.x);

    if (tg <= 0.414) {
        if (enemyCoords.x <= coords.x) {
            if (enemyCoords.y <= coords.y) {
                coords.direction = 2;
                coords.x -= 4;
            } else {
                coords.direction = 2;
                coords.x -= 4;
            }
        } else {
            if (enemyCoords.y <= coords.y) {
                coords.direction = 1;
                coords.x += 4;
            } else {
                coords.direction = 1;
                coords.x += 4;
            }
        }
    } else if (tg > 0.414 && tg <= 2.414) {
        if (enemyCoords.x <= coords.x) {
            if (enemyCoords.y <= coords.y) {
                coords.direction = 8;
                coords.y -= 3;
                coords.x -= 3;
            } else {
                coords.direction = 5;
                coords.y += 3;
                coords.x -= 3;
            }
        } else {
            if (enemyCoords.y <= coords.y) {
                coords.direction = 6;
                coords.y -= 3;
                coords.x += 3;
            } else {
                coords.direction = 7;
                coords.y += 3;
                coords.x += 3;
            }
        }
    } else {
        if (enemyCoords.x <= coords.x) {
            if (enemyCoords.y <= coords.y) {
                coords.direction = 3;
                coords.y -= 4;
            } else {
                coords.direction = 4;
                coords.y += 4;
            }
        } else {
            if (enemyCoords.y <= coords.y) {
                coords.direction = 3;
                coords.y -= 4;
            } else {
                coords.direction = 4;
                coords.y += 4;
            }
        }
    }

    frameTime++;

    if (framesPerSecond/frameTime == 6) {
        frameTime = 0;
        step = (step+1) % 4;
    }
}

bool CEnemyPlayer::meleeShot(const Uint8 * keystates) const {
    return false;
}

bool CEnemyPlayer::rangedShot(const Uint8 * keystates) const {
    if (shootingRange) {
        if (rand() % 10 + 1 < 3) {
            return true;
        }
    }
    return false;
}

void CEnemyPlayer::setDefaultCoords() {
    coords.direction = 2;
    coords.x = 1120;
    coords.y = 400;
}

CEnemyPlayer::~CEnemyPlayer() {
}



