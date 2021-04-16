#include "Component_Camera.hpp"

Component_Camera::Component_Camera(Object* owner) : Component(owner) {
	Log("Called Component Camera Constructor");
}

void Component_Camera::Awake() {

}

void Component_Camera::LateUpdate(float deltaTime) {
	if (m_window) {
		sf::View view = m_window->GetView();

		const sf::Vector2u screenDimension = { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };

		const sf::Vector2f& playerPos = owner->transform->GetPosition();

		view.reset(sf::FloatRect(0, 0, screenDimension.x, screenDimension.y));
			
		view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));

		sf::Vector2f position(screenDimension.x / 2, screenDimension.y / 2);


		if (playerPos.x + 32 > screenDimension.x / 2) {
			position.x = playerPos.x + 32;
		}
		else {
			position.x = screenDimension.x / 2;
		}

		if (playerPos.y + 32 > screenDimension.y / 2) {
			position.y = playerPos.y + 32;
		}
		else {
			position.y = screenDimension.y / 2;
		}

		if (playerPos.x + 32 > MAP_SIZE_X - (screenDimension.x / 2)) {
			position.x = MAP_SIZE_X - (screenDimension.x / 2);
		}
		if (playerPos.y + 32 > MAP_SIZE_Y - (screenDimension.y / 2)) {
			position.y = MAP_SIZE_Y - (screenDimension.y / 2);
		}

		view.setCenter(position);

		m_window->SetView(view);
	}
}

void Component_Camera::SetWindow(Window* window) {
	m_window = window;
}

Component_Camera::~Component_Camera() {
	Log("Called Component Camera Destructor");
}