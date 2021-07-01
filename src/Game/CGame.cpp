#include "CGame.h"


CGame::CGame() = default;

void CGame::setTerminationFlag(bool value) {
    isTerminationRequired = value;
}

bool CGame::ifTerminationRequired() const {
    return isTerminationRequired;
}

bool CGame::ifSuccessfullyInitialized() const {
    return screenManager.ifLibsWereSuccessfullyInitialized();
}

std::string CGame::getMusic() const {
    return settings.getMusic();
}

void CGame::setMusic(const std::string & music) {
    settings.setMusic(music);
}

std::string CGame::getNickname() const {
    return settings.getNickname();
}

void CGame::setNickname(const std::string & nickname) {
    settings.setNickname(nickname);
}

CSettings::Map CGame::getSelectedMap() const {
    return settings.getSelectedMap();
}

void CGame::setMap(CSettings::Map map) {
    settings.setMap(map);
}

void CGame::executeManager(CUIManager * manager) {
    screenManager.execute("Counter Strike",CCoords(1,1200,800), manager);
}

void CGame::closeWindow() {
    screenManager.closeWindow();
}

void CGame::fetchResultsFromFile() {
    result.fetchResultsFromFile();
}

void CGame::updateFile() {
    result.updateFile();
}

int CGame::getPlayerScore() const {
    return result.getPlayerScore();
}

void CGame::setPlayerScore(int score) {
    result.setPlayerScore(score);
}

int CGame::getEnemyScore() const {
    return result.getEnemyScore();
}

void CGame::setEnemyScore(int score) {
    result.setEnemyScore(score);
}

bool CGame::isSuccessfullyFetched() const {
    return result.isSuccessfullyFetched();
}

void CGame::resetFetchFlag() {
    result.resetFetchFlag();
}

void CGame::appendScoreboard(std::pair<int, std::pair<std::string, std::pair<int,int>>> result) {
    this->result.appendScoreboard(result);
}

std::multimap<int, std::pair<std::string, std::pair<int,int>>> CGame::getScoreboard() const {
    return result.getScoreboard();
}