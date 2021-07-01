#include "CResult.h"

void CResult::cleanFile (const std::string & path) {
    std::ofstream ofs;
    ofs.open(path, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

bool is_digits(const std::string & str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

void CResult::fetchResultsFromFile() {
    std::multimap<int, std::pair<std::string, std::pair <int,int>>> rawData;
    std::ifstream is;
    std::string path = "examples/Records.txt";
    is.open(path);

    if (!is.is_open()) {
        return;
    }

    std::string bufferString;

    while (getline(is, bufferString)) {
        std::stringstream ss(bufferString);
        std::string bufferNickname, bufferPlayerScore, bufferEnemyScore;
        getline(ss, bufferNickname, ':');
        getline(ss, bufferPlayerScore, ':');
        getline(ss, bufferEnemyScore, ':');
        if (is.bad()) {
            is.close();
            return;
        }
        if (!is_digits(bufferPlayerScore) || !is_digits(bufferEnemyScore) || bufferNickname.size() > 10 || bufferNickname.empty() || bufferPlayerScore.size() > 3 || bufferEnemyScore.size() > 3 || bufferEnemyScore.empty() || bufferPlayerScore.empty()) {
            is.close();
            cleanFile(path);
            return;
        }
        if (std::stoi(bufferPlayerScore) > 3 || std::stoi(bufferPlayerScore) < 0 || std::stoi(bufferEnemyScore) > 3 || std::stoi(bufferEnemyScore) < 0) {
            is.close();
            cleanFile(path);
            return;
        }
        rawData.insert(std::make_pair(std::stoi(bufferPlayerScore)- std::stoi(bufferEnemyScore), std::make_pair(bufferNickname, std::make_pair(std::stoi(bufferPlayerScore), std::stoi(bufferEnemyScore)))));
    }

    is.close();
    scoreboard = rawData;
    successfullyFetched = true;
}

void CResult::updateFile() {
    std::string path = "examples/Records.txt";
    cleanFile(path);
    std::ofstream os;
    os.open(path);

    if (!os.is_open()) {
        return;
    }

    std::multimap<int, std::pair<std::string, std::pair <int,int>>>::iterator iterator;
    iterator = scoreboard.begin();

    while (true){
        os << iterator->second.first << ":" << iterator->second.second.first << ":" << iterator->second.second.second;
        iterator++;
        if (os.bad()) {
            os.close();
            return;
        }
        if (iterator == scoreboard.end()) {
            break;
        } else {
            os << std::endl;
        }
    }

    successfullyFetched = true;
    os.close();
}

int CResult::getPlayerScore() const {
    return playerScore;
}

void CResult::setPlayerScore(int score) {
    playerScore = score;
}

int CResult::getEnemyScore() const {
    return enemyScore;
}

void CResult::setEnemyScore(int score) {
    enemyScore = score;
}

bool CResult::isSuccessfullyFetched() const {
    return successfullyFetched;
}

void CResult::resetFetchFlag() {
    successfullyFetched = false;
}

void CResult::appendScoreboard(std::pair<int, std::pair<std::string, std::pair<int,int>>> result) {
    scoreboard.insert(result);
}

std::multimap<int, std::pair<std::string, std::pair<int,int>>> CResult::getScoreboard() const {
    return scoreboard;
}

CResult::CResult() = default;
