#pragma once

#include "Logs.hpp"
#include "SFML/Graphics.hpp"


/*
* RESOLUTIONS:
* 1024x576,
* 1280x720,
* 1360x765,
* 1366x768,
* 1440x810,
* 1536x864,
* 1920x1080
*/

class Setup {
public:
	Setup();

	void LoadDeviceInfo();

	void SetupGameOptions();

	sf::Vector2u GetResolution() const;

	~Setup();
private:
	sf::Vector2u m_resolution;
};