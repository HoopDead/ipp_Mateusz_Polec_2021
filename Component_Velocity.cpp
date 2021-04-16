#include "Component_Velocity.hpp"

Component_Velocity::Component_Velocity(Object* owner) : Component(owner), m_maxVelocity(300.f, 300.f) {
	Log("Called Compontent Velocity Constructor");
}

void Component_Velocity::Update(float deltaTime) {
	owner->transform->AddPosition(m_velocity * deltaTime);
}

void Component_Velocity::Set(const sf::Vector2f& velocity) {
	m_velocity = velocity;
	ClampVelocity();
}

void Component_Velocity::Set(float x, float y) {
	m_velocity.x = x;
	m_velocity.y = y;

	ClampVelocity();
}

const sf::Vector2f& Component_Velocity::Get() const {
	return m_velocity;
}

void Component_Velocity::ClampVelocity() {
	if (fabs(m_velocity.x) > m_maxVelocity.x) {
		if (m_velocity.x > 0.f) {
			m_velocity.x = m_maxVelocity.x;
		}
		else {
			m_velocity.x = -m_maxVelocity.x;
		}
	}

	if (fabs(m_velocity.y) > m_maxVelocity.y) {
		if (m_velocity.y > 0.f) {
			m_velocity.y = m_maxVelocity.y;
		}
		else {
			m_velocity.y = -m_maxVelocity.y;
		}
	}
}

Component_Velocity::~Component_Velocity() {
	Log("Called Compontent Velocity Destructor");
}