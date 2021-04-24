#include "Component_BoxCollider.hpp"

Component_BoxCollider::Component_BoxCollider(Object* owner) : Component(owner) {
	Log("Called Component_BoxCollider Constructor");
}

void Component_BoxCollider::SetCollidable(const sf::FloatRect& rect) {
	m_AABB = rect;
}

const sf::FloatRect& Component_BoxCollider::GetColliderBox() const {
	return m_AABB;
}

void Component_BoxCollider::SetPosition() {
	const sf::Vector2f pos = owner->transform->GetPosition();
	m_AABB.left = pos.x;
	m_AABB.top = pos.y;
}

void Component_BoxCollider::Draw(Window& window) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(m_AABB.height, m_AABB.width));
	rectangle.setPosition(m_AABB.left, m_AABB.top);
	window.Draw(rectangle);
}

Component_BoxCollider::~Component_BoxCollider() {
	Log("Called Component_BoxCollider Destructor");
}