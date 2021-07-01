#include "CUIText.h"


void CUIText::setCoords(CCoords coords) {
    dRect.x = coords.x;
    dRect.y = coords.y;
}

CUIText::CUIText(SDL_Color color, const std::string & message, int textSize) {
    this->font = TTF_OpenFont("assets/fonts/Font.ttf", textSize);
    this->color = color;
    this->message = message;
}

void CUIText::draw(SDL_Renderer * renderer) {
    auto textSurface = TTF_RenderText_Solid(font, message.c_str(), color);
    auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_QueryTexture(textTexture, nullptr, nullptr, &dRect.w, &dRect.h);
    SDL_RenderCopy(renderer, textTexture, nullptr, &dRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

std::string CUIText::getText() const{
    return message;
}

void CUIText::setText(const std::string & text) {
    message = text;
}

void CUIText::append(const std::string & text) {
    message += text;
}

void CUIText::erase() {
    message.pop_back();
}

CUIText::~CUIText() {
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

