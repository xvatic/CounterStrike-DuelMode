#pragma once

#include <SDL.h>
#include <string>

/**
* @brief Class represent template for UI scene manager
*/
class CUIManager {

public:

    /**
	 * @brief Method initialize all components
     * @param[in] renderer Renderer
	 */
    virtual bool initialize(SDL_Renderer* renderer) = 0;

    /**
	 * @brief Method draw all components
     * @param[in] renderer Renderer
	 */
    virtual bool draw(SDL_Renderer * renderer) = 0;

    /**
	 * @brief Method update all componnets
     * @param[in] e input events
     * @param[in] keystates keys conditions
     * @param[in] renderer Renderer
	 */
    virtual void update(SDL_Event e,const Uint8 * keystates, SDL_Renderer * renderer) = 0;

    /**
	 * @brief Method update all automated dynamic components(AI, bullets)
     * @param[in] e input events
     * @param[in] keystates keys conditions
     * @param[in] renderer Renderer
	 */
    virtual void updateAutomatedObjects(SDL_Event e,const Uint8 * keystates, SDL_Renderer * renderer) = 0;

    /**
	 * @brief Method tell if form is still active
	 */
    bool isRunning() {
        return running;
    }

    /**
	 * @brief Method stop the manager running(stop the main endless loop)
	 */
    void stop() {
        running = false;
    }

    /**
	 * @brief Method set the termination flag to true value
	 */
    void setTerminationFlag() {
        wasTerminated = true;
    }

    /**
	 * @brief Method give the termination flag
	 */
    bool getTerminationFlag() {
        return wasTerminated;
    }

    /**
	 * @brief Method give the chosen music
	 */
    std::string getMusic() const {
        return music;
    }

    /**
	 * @brief Method pass the music to manager
	 */
    void setMusic(std::string track) {
        music = track;
    }

    /**
	 * @brief Default virtual destructor
     * @note Should be virtual because of polymorfismus
	 */
    virtual ~CUIManager() {}

protected:
    bool running = true;
    bool wasTerminated = false;
    std::string music;
};
