#include "CButton.h"

CButton::CButton(CCoords coords, SDL_Renderer * renderer, SDL_Texture * texture): sRect{coords.x,coords.y, 175, 65}, dRect{coords.x,coords.y, 175, 65} {
    this->texture = texture;
    selected = false;
}


void CButton::setCoords(CCoords coords) {
    dRect.x = coords.x;
    dRect.y = coords.y;
}

void CButton::draw(SDL_Renderer * renderer) const {
    SDL_RenderCopy(renderer, texture, &sRect, &dRect);
}

bool CButton::isSelected() const {
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

CButton::~CButton() {
}

