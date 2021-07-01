#include "CSettings.h"


std::string CSettings::getMusic() const {
    return music;
}

void CSettings::setMusic(const std::string & music) {
    this->music = music;
}

std::string CSettings::getNickname() const {
    return nickname;
}

void CSettings::setNickname(const std::string & nickname) {
    this->nickname = nickname;
}

CSettings::Map CSettings::getSelectedMap() const {
    return selectedMap;
}

void CSettings::setMap(CSettings::Map map) {
    selectedMap = map;
}