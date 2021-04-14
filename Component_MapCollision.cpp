#include "Component_MapCollision.hpp"

Component_MapCollision::Component_MapCollision(Object* owner) : Component(owner) {
	Log("Called Component_MapCollision Constructor!");
}

void Component_MapCollision::SetLayer(tmx::ObjectGroup objectGroup) {
	Log("Layer set!");
	for (auto& obj : objectGroup.getObjects()) {
		tmx::FloatRect rect = obj.getAABB();
		m_boundPoints.push_back(sf::FloatRect(rect.left, rect.top, rect.width, rect.height));
	}
}

void Component_MapCollision::Update(float deltaTime) {
	for (auto& obj : m_boundPoints) {
		auto boxCollider = owner->GetComponent<Component_BoxCollider>();
		boxCollider->SetPosition();
		if (obj.intersects(boxCollider->GetColliderBox())) {
			std::cout << "Collision" << "\n";
		}
	}
}

Component_MapCollision::~Component_MapCollision() {
	Log("Called Component_MapCollision Destructor!");
}