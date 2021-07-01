#include "CRangedBullet.h"


void CRangedBullet::Move() {
    switch (this->coords.direction) {
        case 1:
            this->coords.x += 3;
            break;
        case 6:
            this->coords.x += 3;
            break;
        case 7:
            this->coords.x += 3;
            break;
        case 2:
            this->coords.x -= 3;
            break;
        case 5:
            this->coords.x -= 3;
            break;
        case 8:
            this->coords.x -= 3;
            break;
        case 3:
            this->coords.y -= 3;
            break;
        case 4:
            this->coords.y += 3;
            break;

    }
}

CRangedBullet::CRangedBullet() {
    damage = 20;
}

CRangedBullet::~CRangedBullet() {
}
