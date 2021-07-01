#include "CUIPlayerComponent.h"


CUIPlayerComponent::CUIPlayerComponent (SDL_Renderer * renderer, Side s, SDL_Texture * sprites, SDL_Texture * knifeSprites, SDL_Texture * bullet) {
    this->texture = sprites;
    this->textureBullet = bullet;
    this->textureKnife = knifeSprites;
    sRect.w = 100;
    sRect.h = 100;
    collisionRect.w = 20;
    collisionRect.h = 20;
    if (s == PLAYER) {
        playerOptions = new CPersonPlayer();
    } else {
        spriteColumn = 400;
        playerOptions = new CEnemyPlayer();
    }
    playerOptions->setDefaultCoords();
    dRect.x = playerOptions->getCoords().x - 25;
    dRect.y = playerOptions->getCoords().y - 25;
}


void CUIPlayerComponent::setCoords(CCoords coords) {
    dRect.x = coords.x;
    dRect.y = coords.y;
}

void CUIPlayerComponent::draw(SDL_Renderer * renderer) {
    sRect.y = (100 * (playerOptions->getCoords().direction - 1));
    sRect.x = (100 * playerOptions->getStep());
    sRect.x += spriteColumn;

    dRect.x = playerOptions->getCoords().x - 25;
    dRect.y = playerOptions->getCoords().y - 25;
    dRect.h = 50;
    dRect.w = 50;

    collisionRect.x = (playerOptions->getCoords().x - 10);
    collisionRect.y = (playerOptions->getCoords().y - 10);
    SDL_RenderCopy(renderer, texture, &sRect, &dRect);
}

void CUIPlayerComponent::checkHit(std::vector<std::unique_ptr<CUIBulletComponent>> & shots) {
    int counter = 0;
    for (auto & bullet : shots) {

        if (SDL_HasIntersection(&bullet->getDestRect(), &collisionRect)) {
            playerOptions->Damage(bullet->getDamage());
            shots.erase(shots.begin() + counter);
            break;
        }
        counter++;
    }
}


void CUIPlayerComponent::update(SDL_Event e, const Uint8 * keystates, std::vector<CUITile*> &tiles, std::vector<std::unique_ptr<CImageView>> & bonuses, std::vector<std::unique_ptr<CUIBulletComponent>> & shots) {
    int runningDirection = 0;

    if (keystates[SDL_SCANCODE_W] && !keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_D]) {
        playerOptions->fetchMoves(3, enemyCoords);
    } else if (keystates[SDL_SCANCODE_W] && keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_D]) {
        playerOptions->fetchMoves(8, enemyCoords);
    } else if (keystates[SDL_SCANCODE_W] && !keystates[SDL_SCANCODE_A] && keystates[SDL_SCANCODE_D]) {
        playerOptions->fetchMoves(6, enemyCoords);
    } else if (!keystates[SDL_SCANCODE_W] && !keystates[SDL_SCANCODE_S] && keystates[SDL_SCANCODE_D]) {
        playerOptions->fetchMoves(1, enemyCoords);
    } else if (!keystates[SDL_SCANCODE_A] && keystates[SDL_SCANCODE_S] && keystates[SDL_SCANCODE_D]) {
        playerOptions->fetchMoves(7, enemyCoords);
    } else if (!keystates[SDL_SCANCODE_A] && keystates[SDL_SCANCODE_S] && !keystates[SDL_SCANCODE_D]) {
        playerOptions->fetchMoves(4, enemyCoords);
    } else if (keystates[SDL_SCANCODE_S] && keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_D]) {
        playerOptions->fetchMoves(5, enemyCoords);
    } else if (!keystates[SDL_SCANCODE_S] && keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_W]) {
        playerOptions->fetchMoves(2, enemyCoords);
    } else {
        playerOptions->fetchMoves(0, enemyCoords);
    }

    runningDirection = playerOptions->getCoords().direction;

    if (playerOptions->meleeShot(keystates)) {
        shots.push_back(std::make_unique<CUIBulletComponent>(CUIBulletComponent::MELEE, textureKnife));
        shots[shots.size() - 1]->setCoords(CCoords(0, dRect.x, dRect.y));
    }
    if (playerOptions->rangedShot(keystates)) {
        shots.push_back(std::make_unique<CUIBulletComponent>(CUIBulletComponent::RANGED, textureBullet));
        shots[shots.size() - 1]->setCoords(playerOptions->getCoords());
    }

    collisionRect.x = (playerOptions->getCoords().x - 10);
    collisionRect.y = (playerOptions->getCoords().y - 10);

    if (runningDirection == 0) {
        return;
    }

    std::vector<int> collidedTiles;
    int counter = 0;
    for (CUITile * tile : tiles) {
        if (tile->ifCollide()) {
            if (SDL_HasIntersection(&tile->getDestRect(), &collisionRect)) {
                collidedTiles.push_back(counter);
            }
        }

        counter++;
    }

    counter = 0;
    for (auto & bonus : bonuses) {
        if (SDL_HasIntersection(&bonus->getDestRect(), &collisionRect)) {
            if (bonus->getBonusType() == CImageView::HEAL) {
                playerOptions->Heal(50);
            } else {
                playerOptions->boost();
            }
            bonuses.erase(bonuses.begin() + counter);
            break;
        }
        counter++;
    }

    if (collidedTiles.empty()) {
        return;
    }

    switch (runningDirection) {
        case 1:
            playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x - 10);
            break;
        case 2:
            playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x + 40 + 10);
            break;
        case 3:
            playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y + 40 + 10);
            break;
        case 4:
            playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y - 10);
            break;
        case 7:
            switch (collidedTiles.size()) {
                case 1:
                    if((tiles[collidedTiles[0]]->getDestRect().x - playerOptions->getCoords().x) < (tiles[collidedTiles[0]]->getDestRect().y - playerOptions->getCoords().y)) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y - 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x - 10);
                    }
                    break;
                case 2:
                    if((tiles[collidedTiles[0]]->getDestRect().x <= (playerOptions->getCoords().x - 6)) && (tiles[collidedTiles[0]]->getDestRect().x + 40 >= (playerOptions->getCoords().x - 6)) || (tiles[collidedTiles[1]]->getDestRect().x <= (playerOptions->getCoords().x - 6)) && (tiles[collidedTiles[1]]->getDestRect().x + 40 >= (playerOptions->getCoords().x - 6))) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y - 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x - 10);
                    }
                    break;
                case 3:
                    playerOptions->setY(tiles[collidedTiles[1]]->getDestRect().y - 10);
                    playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x - 10);
                    break;
            }
            break;
        case 8:
            switch (collidedTiles.size()) {
                case 1:
                    if((playerOptions->getCoords().x - tiles[collidedTiles[0]]->getDestRect().x) < (playerOptions->getCoords().y - tiles[collidedTiles[0]]->getDestRect().y)) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y + 40 + 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x + 40 + 10);
                    }
                    break;
                case 2:
                    if((tiles[collidedTiles[0]]->getDestRect().x <= (playerOptions->getCoords().x - 6)) && (tiles[collidedTiles[0]]->getDestRect().x + 40 >= (playerOptions->getCoords().x - 6)) || (tiles[collidedTiles[1]]->getDestRect().x <= (playerOptions->getCoords().x - 6)) && (tiles[collidedTiles[1]]->getDestRect().x + 40 >= (playerOptions->getCoords().x - 6))) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y + 40 + 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x + 40 + 10);
                    }
                    break;
                case 3:
                    playerOptions->setY(tiles[collidedTiles[1]]->getDestRect().y +40 + 10);
                    playerOptions->setX(tiles[collidedTiles[2]]->getDestRect().x + 40 + 10);
                    break;
            }
            break;
        case 5:
            switch (collidedTiles.size()) {
                case 1:
                    if(((playerOptions->getCoords().x) - (tiles[collidedTiles[0]]->getDestRect().x + 20)) < ((tiles[collidedTiles[0]]->getDestRect().y + 20) - (playerOptions->getCoords().y))) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y - 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x + 40 + 10);
                    }
                    break;
                case 2:
                    if((tiles[collidedTiles[0]]->getDestRect().x <= (playerOptions->getCoords().x)) && (tiles[collidedTiles[0]]->getDestRect().x + 40 >= (playerOptions->getCoords().x)) || (tiles[collidedTiles[1]]->getDestRect().x <= (playerOptions->getCoords().x)) && (tiles[collidedTiles[1]]->getDestRect().x + 40 >= (playerOptions->getCoords().x))) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y - 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x + 40 + 10);
                    }
                    break;
                case 3:
                    playerOptions->setY(tiles[collidedTiles[2]]->getDestRect().y - 10);
                    playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x + 40 + 10);
                    break;
            }
            break;
        case 6:
            switch (collidedTiles.size()) {
                case 1:
                    if(((tiles[collidedTiles[0]]->getDestRect().x + 20) - (playerOptions->getCoords().x)) < ((playerOptions->getCoords().y) - (tiles[collidedTiles[0]]->getDestRect().y + 20))) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y + 40 + 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x - 10);
                    }
                    break;
                case 2:
                    if((tiles[collidedTiles[0]]->getDestRect().x <= (playerOptions->getCoords().x)) && (tiles[collidedTiles[0]]->getDestRect().x + 40 >= (playerOptions->getCoords().x)) || (tiles[collidedTiles[1]]->getDestRect().x <= (playerOptions->getCoords().x)) && (tiles[collidedTiles[1]]->getDestRect().x + 40 >= (playerOptions->getCoords().x))) {
                        playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y + 40 + 10);
                    } else {
                        playerOptions->setX(tiles[collidedTiles[0]]->getDestRect().x - 10);
                    }
                    break;
                case 3:
                    playerOptions->setY(tiles[collidedTiles[0]]->getDestRect().y + 40 + 10);
                    playerOptions->setX(tiles[collidedTiles[2]]->getDestRect().x - 10);
                    break;
            }
            break;
    }
}

int CUIPlayerComponent::getScore() {
    return playerOptions->getScore();
}

void CUIPlayerComponent::addScore() {
    playerOptions->addScore();
}

int CUIPlayerComponent::getHealth() {
    return playerOptions->getHealth();
}

void CUIPlayerComponent::refresh() {
    playerOptions->refresh();
    playerOptions->setDefaultCoords();
}

void CUIPlayerComponent::setEnemyCoords(CCoords coords) {
    enemyCoords = coords;
}

CCoords CUIPlayerComponent::getCoords() {
    return playerOptions->getCoords();
}

SDL_Rect CUIPlayerComponent::getDestRect() {
    return dRect;
}

CUIPlayerComponent::~CUIPlayerComponent() {
    delete playerOptions;
}

