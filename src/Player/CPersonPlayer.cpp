#include "CPersonPlayer.h"


void CPersonPlayer::fetchMoves(int direction, CCoords enemyCoords) {
    if (framesPerSecond/frameTime != 15) {
        frameTime++;
        return;
    }
    frameTime = 1;
    if (direction == 0) {
        return;
    }

    switch (direction) {
        case 3:
            coords.y -= 4;
            break;
        case 4:
            coords.y += 4;
            break;
        case 2:
            coords.x -= 4;
            break;
        case 1:
            coords.x += 4;
            break;
        case 8:
            coords.y -= 3;
            coords.x -= 3;
            break;
        case 6:
            coords.y -= 3;
            coords.x += 3;
            break;
        case 7:
            coords.y += 3;
            coords.x += 3;
            break;
        case 5:
            coords.y += 3;
            coords.x -= 3;
            break;
    }

    coords.direction = direction;
    stepTickRate++;

    if (framesPerSecond/stepTickRate == 6) {
        stepTickRate = 0;
        step = (step+1) % 4;
    }
}

bool CPersonPlayer::meleeShot(const Uint8 * keystates) const {
    if (keystates != nullptr) {
        if (keystates[SDL_SCANCODE_SPACE]) {
            return true;
        }
    }
    return false;
}

bool CPersonPlayer::rangedShot(const Uint8 * keystates) const {
    if (keystates != nullptr) {
        if (keystates[SDL_SCANCODE_RIGHT]) {
            return true;
        }
    }
    return false;
}

void CPersonPlayer::setDefaultCoords() {
    coords.direction = 1;
    coords.x = 80;
    coords.y = 400;
}

CPersonPlayer::~CPersonPlayer() {
}





