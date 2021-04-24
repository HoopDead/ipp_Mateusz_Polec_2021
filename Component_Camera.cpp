#include "Component_Camera.hpp"

Component_Camera::Component_Camera(Object* owner) : Component(owner) {
	Log("Called Component Camera Constructor");
}

void Component_Camera::SetWindow(Window* window) {
	m_window = window;
}


void Component_Camera::Awake() {

	m_view = m_window->GetView();

}

void Component_Camera::LateUpdate(float deltaTime) {
	if (m_window) {

		const sf::Vector2u screenDimension = { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };

		const sf::Vector2f& playerPos = owner->transform->GetPosition();

		m_view.reset(sf::FloatRect(0, 0, screenDimension.x, screenDimension.y));
			
		m_view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
		m_view.zoom(0.5f);

		/*
		* Everything is divded by four, because the view is zoomed by two. So we have to keep the track of screen dimension like it's also zoomed.
		*/

		sf::Vector2f position(screenDimension.x / 4, screenDimension.y / 4);


		if (playerPos.x + SPRITE_SIZE > screenDimension.x / 4) {
			position.x = playerPos.x + SPRITE_SIZE;
		}
		else {
			position.x = screenDimension.x / 4;
		}

		if (playerPos.y + SPRITE_SIZE > screenDimension.y / 4) {
			position.y = playerPos.y + SPRITE_SIZE;
		}
		else {
			position.y = screenDimension.y / 4;
		}

		if (playerPos.x + SPRITE_SIZE > MAP_SIZE_X - (screenDimension.x / 4)) {
			position.x = MAP_SIZE_X - (screenDimension.x / 4);
		}
		if (playerPos.y + SPRITE_SIZE > MAP_SIZE_Y - (screenDimension.y / 4)) {
			position.y = MAP_SIZE_Y - (screenDimension.y / 4);
		}

		m_view.setCenter(position);


		m_window->SetView(m_view);
	}
}

Component_Camera::~Component_Camera() {
	Log("Called Component Camera Destructor");
}