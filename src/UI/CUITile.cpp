#include "CUITile.h"


CUITile::CUITile(CCoords coords, SDL_Renderer * renderer, Texture t, SDL_Texture * textureSprite, SDL_Texture * texturePowerUp, SDL_Texture * textureHeal): sRect{0,0, 281, 281}, dRect{coords.x*40,coords.y*40 + 40, 40, 40} {
    texture = textureSprite;
    this->textureHeal = textureHeal;
    this->texturePowerUp = texturePowerUp;

    switch (t) {
        case SPACE:
            textureProperties = new CSpaceTexture();
            break;
        case TREE:
            textureProperties = new CTreeTexture();
            break;
        case BRICK:
            textureProperties = new CBrickTexture();
            break;
    }

}

void CUITile::setCoords(CCoords coords) {
    dRect.x = coords.x;
    dRect.y = coords.y;
}

void CUITile::draw(SDL_Renderer * renderer) const {
    SDL_RenderCopy(renderer, texture, &sRect, &dRect);
}

void CUITile::destroy(std::vector<std::unique_ptr<CImageView>> & bonuses, SDL_Renderer * renderer) {
    SDL_Surface * surface = IMG_Load("assets/sprites/Stone.png");
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    delete textureProperties;
    textureProperties = new CSpaceTexture();
    int chance = rand() % 100;

    if (chance > 50 && chance <= 75) {
        bonuses.push_back(std::make_unique<CImageView>(CCoords(1,0,0), renderer, texturePowerUp));
        bonuses[bonuses.size() - 1]->setBonusType(CImageView::POWERUP);
        bonuses[bonuses.size() - 1]->setSourceSize(CCoords(1,556,556));
        bonuses[bonuses.size() - 1]->setCoords(CCoords(1,dRect.x, dRect.y));
        bonuses[bonuses.size() - 1]->setSize(CCoords(1,30, 30));
    } else if (chance > 75) {
        bonuses.push_back(std::make_unique<CImageView>(CCoords(1,0,0), renderer, textureHeal));
        bonuses[bonuses.size() - 1]->setBonusType(CImageView::HEAL);
        bonuses[bonuses.size() - 1]->setSourceSize(CCoords(1,640,640));
        bonuses[bonuses.size() - 1]->setCoords(CCoords(1,dRect.x, dRect.y));
        bonuses[bonuses.size() - 1]->setSize(CCoords(1,30, 30));
    }

    SDL_FreeSurface(surface);
}

bool CUITile::ifCollide() const {
    return textureProperties->ifCollide();
}

bool CUITile::ifDestroyable() const {
    return textureProperties->ifDestroyable();
}

const SDL_Rect & CUITile::getDestRect() const {
    return dRect;
}

CUITile::~CUITile() {
    delete textureProperties;
}
