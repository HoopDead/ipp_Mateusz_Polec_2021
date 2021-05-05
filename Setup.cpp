#include "Setup.hpp"

Setup::Setup() {
	Log("Called Setup Constructor!");
}

void Setup::LoadDeviceInfo() {

	m_resolution.x = sf::VideoMode::getDesktopMode().width;
	m_resolution.y = sf::VideoMode::getDesktopMode().height;
	Log("Load Device Info Method set");
	
}

void Setup::SetupGameOptions() {

}

sf::Vector2u Setup::GetResolution() const {
	return m_resolution;
}

Setup::~Setup() {
	Log("Called Setup Destructor!");
}