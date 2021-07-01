#include "CCheckBox.h"


CCheckBox::CCheckBox(CCoords coords, SDL_Renderer * renderer, SDL_Texture * uncheckedTexture, SDL_Texture * checkedTexture): sRect{coords.x,coords.y, 768, 768}, dRect{coords.x,coords.y, 75, 75} {
    textureChecked = checkedTexture;
    textureUnchecked = uncheckedTexture;
    selected = false;
}


void CCheckBox::setCoords(CCoords coords) {
    dRect.x = coords.x;
    dRect.y = coords.y;
}

void CCheckBox::draw(SDL_Renderer * renderer) const{
    if (selected) {
        SDL_RenderCopy(renderer, textureChecked, &sRect, &dRect);
    } else {
        SDL_RenderCopy(renderer, textureUnchecked, &sRect, &dRect);
    }
}

bool CCheckBox::isCovered() const {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX,&mouseY);

    if (mouseX >= dRect.x && mouseX < (dRect.x + dRect.w))
    {
        if (mouseY >= dRect.y && mouseY < (dRect.y + dRect.h))
        {
            return true;
        }
    }

    return false;
}

void CCheckBox::select() {
    selected = true;
}

void CCheckBox::unselect() {
    selected = false;
}

bool CCheckBox::isSelected() const {
    return selected;
}

CCheckBox::~CCheckBox() {
}
