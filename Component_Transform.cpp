#include "Component_Transform.hpp"

Component_Transform::Component_Transform(Object* owner) :
	Component(owner), m_position(0.f, 0.f) {

	Log("Called Component Transform Constructor");

}

void Component_Transform::SetPosition(float x, float y) {
	
	m_position.x = x;
	m_position.y = y;

}

void Component_Transform::SetPosition(const sf::Vector2f& pos) {
	m_position = pos;
}

void Component_Transform::AddPosition(float x, float y) {
	m_position.x += x;
	m_position.y += y;
}

void Component_Transform::AddPosition(sf::Vector2f pos) {
	m_position += pos;
}

void Component_Transform::SetX(float x) {
	m_position.x = x;
}

void Component_Transform::SetY(float y) {
	m_position.y = y;
}

void Component_Transform::AddX(float x) {
	m_position.x += x;
}

void Component_Transform::AddY(float y) {
	m_position.y += y;
}

const sf::Vector2f& Component_Transform::GetPosition() const {
	return m_position;
}