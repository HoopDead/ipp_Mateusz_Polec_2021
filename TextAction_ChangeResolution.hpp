#pragma once

#include "TextAction.hpp"
#include "TextTemplate.hpp"
#include "Logs.hpp"
#include "TextCollection.hpp"
#include "Setup.hpp"


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


class TextAction_ChangeResolution : public TextAction {

public:
	TextAction_ChangeResolution(TextTemplate* owner);

	void RunAction() override;

	void SetSetup(Setup* setup);

	void SetWindow(Window* window);

	~TextAction_ChangeResolution();

private:

	Setup* m_setup;
	std::vector<sf::VideoMode> m_resolutions = sf::VideoMode::getFullscreenModes();
	sf::VideoMode m_actualResolution;
	int m_actualResolutionIndex = 0;
	Window* m_window;

};