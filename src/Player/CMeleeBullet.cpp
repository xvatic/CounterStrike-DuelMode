#include "CMeleeBullet.h"

void CMeleeBullet::Move() {
    coords = ownerCoords;
    frameTime++;
    step += 1;

    if (step == 6) {
        corrupted = true;
    }
}

CMeleeBullet::CMeleeBullet() {
    damage = 80;
}

CMeleeBullet::~CMeleeBullet() {
}
