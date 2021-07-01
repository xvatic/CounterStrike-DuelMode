#include "CImageView.h"


CImageView::CImageView(CCoords coords, SDL_Renderer * renderer, SDL_Texture * texture): sRect{coords.x,coords.y, 400, 250}, dRect{coords.x,coords.y, 400, 250} {
    this->texture = texture;
}

void CImageView::setCoords(CCoords coords) {
    dRect.x = coords.x;
    dRect.y = coords.y;
}

void CImageView::setSize(CCoords coords) {
    dRect.w = coords.x;
    dRect.h = coords.y;
}
void CImageView::setSourceCoords(CCoords coords) {
    sRect.x = coords.x;
    sRect.y = coords.y;
}

void CImageView::setSourceSize(CCoords coords) {
    sRect.w = coords.x;
    sRect.h = coords.y;
}

void CImageView::draw(SDL_Renderer * renderer) const {
    SDL_RenderCopy(renderer, texture, &sRect, &dRect);
}

void CImageView::setBonusType(CImageView::BonusType bt) {
    selectedBonusType = bt;
}

const SDL_Rect & CImageView::getDestRect() const {
    return dRect;
}

CImageView::BonusType CImageView::getBonusType() const {
    return selectedBonusType;
}

CImageView::~CImageView() {

}
