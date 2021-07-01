#include "CUIBulletComponent.h"


CUIBulletComponent::CUIBulletComponent(Type t, SDL_Texture * texture) {
    this->texture = texture;

    if (t == MELEE) {
        bulletOption = new CMeleeBullet();
        sRect.w = 100;
        sRect.h = 100;
        sRect.y = 0;
        dRect.w = 50;
        dRect.h = 50;
    } else {
        bulletOption = new CRangedBullet();
        sRect.w = 600;
        sRect.h = 600;
        sRect.x = 0;
        sRect.y = 0;
        dRect.w = 7;
        dRect.h = 7;
    }
}

void CUIBulletComponent::setCoords(CCoords coords) const {
    bulletOption->setX(coords.x);
    bulletOption->setY(coords.y);
    bulletOption->setDirection(coords.direction);
}

void CUIBulletComponent::draw(SDL_Renderer * renderer) {
    sRect.x = (100 * bulletOption->getStep());
    dRect.x = bulletOption->getCoords().x;
    dRect.y = bulletOption->getCoords().y;
    SDL_RenderCopy(renderer, texture, &sRect, &dRect);
}

void CUIBulletComponent::update(CCoords coords) {
    bulletOption->setOwnerCoords(coords);
    bulletOption->Move();
}

bool CUIBulletComponent::ifCorrupted() const {
    return bulletOption->isCorrupted();
}

void CUIBulletComponent::setCorrupted() {
    bulletOption->setCorrupted();
}

const SDL_Rect & CUIBulletComponent::getDestRect() const {
    return dRect;
}

int CUIBulletComponent::getDamage() const {
    return bulletOption->getDamage();
}

CUIBulletComponent::~CUIBulletComponent() {
    delete bulletOption;
}

