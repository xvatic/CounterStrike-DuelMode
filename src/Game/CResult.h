#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include "CSettings.h"

/**
* @brief Class represents a tool to get and update scores
*/
class CResult {

    int playerScore;
    int enemyScore;
    bool successfullyFetched = false;
    std::multimap<int, std::pair<std::string, std::pair<int,int>>> scoreboard;

public:

    /**
	 * @brief Default constructor
	 */
    CResult();

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
	 * @brief Method that clean file
	 */
    static void cleanFile (const std::string & path);

    /**
	 * @brief Method fetches scores from file
	 */
    void fetchResultsFromFile();

    /**
	 * @brief Method add a score to scoreboard
	 */
    void appendScoreboard(std::pair<int, std::pair<std::string, std::pair<int,int>>> result);

    /**
	 * @brief Method give the scoreboard
	 */
    std::multimap<int, std::pair<std::string, std::pair<int,int>>> getScoreboard() const;

    /**
	 * @brief Method updates file with scores
	 */
    void updateFile();

};
