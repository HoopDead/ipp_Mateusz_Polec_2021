#include "Setup.hpp"

Setup::Setup() {
	Log("Called Setup Constructor!");
}

void Setup::LoadDeviceInfo() {

	m_resolution.width = sf::VideoMode::getDesktopMode().width;
	m_resolution.height = sf::VideoMode::getDesktopMode().height;
	Log("Load Device Info Method set");
	
}

void Setup::SetupGameOptions() {

}

void Setup::SetResolution(unsigned int x, unsigned int y) {
	m_resolution.width = x;
	m_resolution.height = y;
}

void Setup::SetResolution(sf::VideoMode resolution) {
	m_resolution = resolution;
}

sf::VideoMode Setup::GetResolution() const {
	return m_resolution;
}

Setup::~Setup() {
	Log("Called Setup Destructor!");
}