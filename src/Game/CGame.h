#pragma once

#include "CSettings.h"
#include "CResult.h"
#include "../UI/CUIScreenHandler.h"

/**
* @brief Class represents the object that contains all needed tools
*/
class CGame {

    bool isTerminationRequired = false;
    CSettings settings;
    CUIScreenHandler screenManager;
    CResult result;

public:

    /**
	 * @brief Method set the termination flag to true value
	 */
    void setTerminationFlag(bool value);

    /**
	 * @brief Method tell if the termination flag was set
	 */
    bool ifTerminationRequired() const;

    /**
	 * @brief Method tell if the termination flag was set
	 */
    bool ifSuccessfullyInitialized() const;

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
    CSettings::Map getSelectedMap() const;

    /**
     * @brief Method set the passed map
     */
    void setMap(CSettings::Map map);

    /**
	 * @brief Method run the manager in screen handling tool
     * @param[in] manager the passed UI manager(form)
	 */
    void executeManager(CUIManager * manager);

    /**
	 * @brief Method close the screen
     * @note Need to fetch data from UI components and then to close the form correctly
	 */
    void closeWindow();

    /**
     * @brief Method give the person's score
     */
    int getPlayerScore() const;

    /**
     * @brief Method set the person's score
     */
    void setPlayerScore(int score);

    /**
     * @brief Method give the AI's score
     */
    int getEnemyScore() const;

    /**
     * @brief Method set the AI's score
     */
    void setEnemyScore(int score);

    /**
     * @brief Method tell if any type of fetching was conducted successfully
     */
    bool isSuccessfullyFetched() const;

    /**
     * @brief Method reset the fetch flag to false value
     */
    void resetFetchFlag();

    /**
	 * @brief Method fetches scores from file
	 */
    void fetchResultsFromFile();

    /**
	 * @brief Method updates file with scores
	 */
    void updateFile();

    /**
	 * @brief Method add a score to scoreboard
	 */
    void appendScoreboard(std::pair<int, std::pair<std::string, std::pair<int,int>>> result);

    /**
	 * @brief Method give the scoreboard
	 */
    std::multimap<int, std::pair<std::string, std::pair<int,int>>> getScoreboard() const;

    /**
	 * @brief Default constructor
	 */
    CGame();
};
