#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

/**
* @brief Class represent a tool to get and update settings
*/
class CSettings {

    std::string music;
    std::string nickname;

public:
    enum Map {INFERNO, DUST, NUKE};

private:
    Map selectedMap = INFERNO;

public:
    /**
     * @brief Method give the music, that was chosen
     */
    std::string getMusic() const;

    /**
     * @brief Method set the passed music
     */
    void setMusic(const std::string & music);

    /**
     * @brief Method give the chosen nickname
     */
    std::string getNickname() const;

    /**
     * @brief Method set the passed nickname
     */
    void setNickname(const std::string & nickname);

    /**
     * @brief Method give the chosen map
     */
    Map getSelectedMap() const;

    /**
     * @brief Method set the passed map
     */
    void setMap(Map map);

};