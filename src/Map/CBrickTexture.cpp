#include "CBrickTexture.h"

bool CBrickTexture::ifDestroyable() const {
    return false;
}

bool CBrickTexture::ifCollide() const {
    return true;
}

CBrickTexture::~CBrickTexture() {
}
