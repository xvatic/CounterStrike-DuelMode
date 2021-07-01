#include "CUIGameManager.h"


void CUIGameManager::fetchMap (SDL_Renderer* renderer) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 30; j++) {
            switch (rawMap[i][j]) {
                case '1':
                    mapTiles.push_back(new CUITile(CCoords(1,j,i), renderer, CUITile::BRICK, loadedTextureBrick, loadedTexturePowerUp, loadedTextureHeart));
                    break;
                case '2':
                    mapTiles.push_back(new CUITile(CCoords(1,j,i), renderer, CUITile::TREE, loadedTextureTree, loadedTexturePowerUp, loadedTextureHeart));
                    break;
                case '0':
                    mapTiles.push_back(new CUITile(CCoords(1,j,i), renderer, CUITile::SPACE, loadedTextureStone, loadedTexturePowerUp, loadedTextureHeart));
                    break;
            }
        }
    }
}

bool CUIGameManager::initialize(SDL_Renderer* renderer) {
    SDL_Surface * buffer = IMG_Load("assets/sprites/Brick.png");
    if(!buffer) {
        return false;
    }
    loadedTextureBrick = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/Tree.png");
    if(!buffer) {
        return false;
    }
    loadedTextureTree = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/Stone.png");
    if(!buffer) {
        return false;
    }
    loadedTextureStone = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/Heart.png");
    if(!buffer) {
        return false;
    }
    loadedTextureHeart = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/Knife.png");
    if(!buffer) {
        return false;
    }
    loadedTextureMelee = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/Bullet.png");
    if(!buffer) {
        return false;
    }
    loadedTextureRanged = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/Powerup.png");
    if(!buffer) {
        return false;
    }
    loadedTexturePowerUp = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/QuitButton.png");
    if(!buffer) {
        return false;
    }
    loadedTextureLeaveButton = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);
    buffer = IMG_Load("assets/sprites/PlayerSprites.png");
    if(!buffer) {
        return false;
    }
    playerSprites = SDL_CreateTextureFromSurface(renderer, buffer);
    SDL_FreeSurface(buffer);

    playerLabel = new CUIText({255,255,255,255}, nickname, 20);
    playerLabel->setCoords(CCoords(1,5,5));
    enemyLabel = new CUIText({255,255,255,255}, "Enemy", 20);
    enemyLabel->setCoords(CCoords(1,1120,5));
    heartPlayer = new CImageView(CCoords(1,0,0), renderer, loadedTextureHeart);
    heartPlayer->setCoords(CCoords(1,160,0));
    heartPlayer->setSize(CCoords(1, 40, 40));
    heartPlayer->setSourceSize(CCoords(1,640,640));
    heartEnemy = new CImageView(CCoords(1,0,0), renderer, loadedTextureHeart);
    heartEnemy->setCoords(CCoords(1,978,0));
    heartEnemy->setSize(CCoords(1, 40, 40));
    heartEnemy->setSourceSize(CCoords(1,640,640));
    playerHPLabel = new CUIText({255,255,255,255}, "", 20);
    playerHPLabel->setCoords(CCoords(1,200,5));
    enemyHPLabel = new CUIText({255,255,255,255}, "", 20);
    enemyHPLabel->setCoords(CCoords(1,1020,5));
    scoreLabel = new CUIText({255,255,255,255}, "", 20);
    scoreLabel->setCoords(CCoords(1,550,5));
    player = new CUIPlayerComponent(renderer, CUIPlayerComponent::PLAYER, playerSprites, loadedTextureMelee, loadedTextureRanged);
    enemy = new CUIPlayerComponent(renderer, CUIPlayerComponent::ENEMY, playerSprites, loadedTextureMelee, loadedTextureRanged);
    std::string path;
    switch (selectedMap) {
        case DUST:
            path = "assets/maps/de_dust2.txt";
            break;
        case INFERNO:
            path = "assets/maps/de_inferno.txt";
            break;
        case NUKE:
            path = "assets/maps/de_nuke.txt";
            break;
    }
    std::ifstream input;
    input.open(path);
    for( std::string line; getline( input, line ); ) {
        rawMap.push_back(line);
    }
    if (input.bad() || rawMap.size() != 19) {
        input.close();
        return false;
    }

    input.close();

    for (int i = 0; i < 19; i++) {
        if (rawMap[i].size() != 30)
            return false;
        for (int j = 0; j < 30; j++) {
            switch (rawMap[i][j]) {
                case '1':
                    mapTiles.push_back(new CUITile(CCoords(1,j,i), renderer, CUITile::BRICK, loadedTextureBrick, loadedTexturePowerUp, loadedTextureHeart));
                    break;
                case '2':
                    mapTiles.push_back(new CUITile(CCoords(1,j,i), renderer, CUITile::TREE, loadedTextureTree, loadedTexturePowerUp, loadedTextureHeart));
                    break;
                case '0':
                    mapTiles.push_back(new CUITile(CCoords(1,j,i), renderer, CUITile::SPACE, loadedTextureStone, loadedTexturePowerUp, loadedTextureHeart));
                    break;
                default:
                    return false;
                    break;
            }
        }
    }



    return true;
}

bool CUIGameManager::draw(SDL_Renderer * renderer) {
    for (CUITile * tile : mapTiles) {
        tile->draw(renderer);
    }

    playerLabel->draw(renderer);
    enemyLabel->draw(renderer);
    heartPlayer->draw(renderer);
    playerHPLabel->draw(renderer);
    enemyHPLabel->draw(renderer);
    heartEnemy->draw(renderer);
    scoreLabel->draw(renderer);
    player->draw(renderer);

    for (auto & bonus : bonusesDropped) {
        bonus->draw(renderer);
    }

    for (int i = 0; i < (int)shotsPlayer.size(); i++) {
        if (shotsPlayer[i] == nullptr) {
            continue;
        }
        shotsPlayer[i]->update(CCoords(0,player->getDestRect().x, player->getDestRect().y));
        shotsPlayer[i]->draw(renderer);
    }

    for (int i = 0; i < (int)shotsEnemy.size(); i++) {
        if (shotsEnemy[i] == nullptr) {
            continue;
        }
        shotsEnemy[i]->update(CCoords(0,enemy->getDestRect().x, enemy->getDestRect().y));
        shotsEnemy[i]->draw(renderer);
    }


    playerHPLabel->setText(std::to_string(player->getHealth()));
    enemyHPLabel->setText(std::to_string(enemy->getHealth()));
    scoreLabel->setText(std::to_string(player->getScore()) + " : " + std::to_string(enemy->getScore()));
    enemy->draw(renderer);
    return false;
}

CUIGameManager::CUIGameManager(const std::string & nickname, Map m) {
    this->nickname = nickname;
    selectedMap = m;
}

void CUIGameManager::update(SDL_Event e,const Uint8 * keystates, SDL_Renderer * renderer) {
    player->update(e,keystates,mapTiles, bonusesDropped, shotsPlayer);
    enemy->setEnemyCoords(player->getCoords());
    scoreLabel->setText(std::to_string(player->getScore()) + " : " + std::to_string(enemy->getScore()));
}

void CUIGameManager::updateAutomatedObjects(SDL_Event e, const Uint8 * keystates, SDL_Renderer * renderer) {
    enemy->update(e, keystates, mapTiles, bonusesDropped, shotsEnemy);

    if (player->getHealth() <= 0 || enemy->getHealth() <=0) {
        if (player->getHealth() <= 0) {
            enemy->addScore();
        } else {
            player->addScore();
        }
        player->refresh();
        enemy->refresh();
        shotsPlayer.clear();
        shotsEnemy.clear();
        bonusesDropped.clear();
        for (CUITile *tile : mapTiles) {
            delete tile;
        }
        mapTiles.clear();
        fetchMap(renderer);
    }
    if (enemy->getScore() == 3 || player->getScore() == 3) {
        running = false;
    }

    for (int i = 0; i < (int)shotsPlayer.size(); i++) {
        for (auto& tile : mapTiles) {
            if (SDL_HasIntersection(&tile->getDestRect(), &shotsPlayer[i]->getDestRect())) {
                if (tile->ifCollide()) {
                    shotsPlayer[i]->setCorrupted();
                }
                if (tile->ifDestroyable()) {
                    tile->destroy(bonusesDropped, renderer);
                }
            }
        }
    }

    for (int i = 0; i < (int)shotsPlayer.size(); i++) {
        if (shotsPlayer[i]->ifCorrupted()) {
            shotsPlayer.erase(shotsPlayer.begin() + i);
            i--;
        }
    }
    enemy->checkHit(shotsPlayer);

    for (int i = 0; i < (int)shotsEnemy.size(); i++) {
        for (auto& tile : mapTiles) {
            if (SDL_HasIntersection(&tile->getDestRect(), &shotsEnemy[i]->getDestRect())) {
                if (tile->ifCollide()) {
                    shotsEnemy[i]->setCorrupted();
                }
                if (tile->ifDestroyable()) {
                    tile->destroy(bonusesDropped, renderer);
                }
            }
        }
    }


    for (int i = 0; i < (int)shotsEnemy.size(); i++) {
        if (shotsEnemy[i]->ifCorrupted()) {
            shotsEnemy.erase(shotsEnemy.begin() + i);
            i--;
        }
    }
    player->checkHit(shotsEnemy);
}

CUIGameManager::~CUIGameManager() {
    if (loadedTextureBrick != nullptr)
        SDL_DestroyTexture(loadedTextureBrick);
    if (loadedTextureTree != nullptr)
        SDL_DestroyTexture(loadedTextureTree);
    if (loadedTextureStone != nullptr)
        SDL_DestroyTexture(loadedTextureStone);
    if (loadedTextureHeart != nullptr)
        SDL_DestroyTexture(loadedTextureHeart);
    if (loadedTextureMelee != nullptr)
        SDL_DestroyTexture(loadedTextureMelee);
    if (loadedTextureRanged != nullptr)
        SDL_DestroyTexture(loadedTextureRanged);
    if (loadedTexturePowerUp != nullptr)
        SDL_DestroyTexture(loadedTexturePowerUp);
    if (loadedTextureLeaveButton != nullptr)
        SDL_DestroyTexture(loadedTextureLeaveButton);
    if (playerSprites != nullptr)
        SDL_DestroyTexture(playerSprites);

    delete scoreLabel;
    delete enemyLabel;
    delete playerLabel;
    delete playerHPLabel;
    delete enemyHPLabel;
    delete heartPlayer;
    delete heartEnemy;

    delete player;
    delete enemy;

    for (CUITile * tile : mapTiles) {
        delete tile;
    }
    mapTiles.clear();
    bonusesDropped.clear();
    shotsPlayer.clear();
}

int CUIGameManager::getEnemyScore() const {
    return enemy->getScore();
}

int CUIGameManager::getPlayerScore() const {
    return player->getScore();
}
