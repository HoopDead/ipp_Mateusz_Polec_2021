#include "Component_MapCollision.hpp"

Component_MapCollision::Component_MapCollision(Object* owner) : Component(owner) {
	Log("Called Component_MapCollision Constructor!");
}

void Component_MapCollision::Awake() {
	m_boxCollider = owner->GetComponent<Component_BoxCollider>();
	m_velocity = owner->GetComponent<Component_Velocity>();
	m_animation = owner->GetComponent<Component_Animation>();
	m_transform = owner->GetComponent<Component_Transform>();
}

void Component_MapCollision::SetLayer(tmx::ObjectGroup objectGroup) {
	for (auto& obj : objectGroup.getObjects()) {
		tmx::FloatRect rect = obj.getAABB();
		m_boundPoints.push_back(sf::FloatRect(rect.left, rect.top, rect.width, rect.height));
	}
}

void Component_MapCollision::Update(float deltaTime) {
	for (auto& obj : m_boundPoints) {
		const sf::Vector2f& vel = m_velocity->Get();
		const sf::Vector2f playerPos = owner->transform->GetPosition();
		m_boxCollider->SetPosition();
		if (obj.intersects(m_boxCollider->GetColliderBox())) {


			const sf::Vector2f objPosition = { obj.left, obj.top };
			const sf::Vector2f objCenter = { obj.left + (obj.width / 2), obj.top + (obj.height / 2) };

			// All of those addition/subtraction operations are here to avoid colliding with two perpendicular walls.
			// So solution is like that - we simply increase size of left and right wall, and slightly decrease up and down wall, to user wont intersect
			// with two of them in the same time.

			const sf::FloatRect leftWall(objPosition.x, objPosition.y - TWO_POWER_OF_TWO, 1, obj.height + TWO_POWER_OF_THREE);
			const sf::FloatRect rightWall(objPosition.x + obj.width, objPosition.y - TWO_POWER_OF_TWO, 1, obj.height + TWO_POWER_OF_THREE);
			const sf::FloatRect upWall(objPosition.x + TWO_POWER_OF_TWO, objPosition.y, obj.width - TWO_POWER_OF_THREE, 1);
			const sf::FloatRect downWall(objPosition.x + TWO_POWER_OF_TWO, objPosition.y + obj.height, obj.width - TWO_POWER_OF_THREE, 1);


			if (leftWall.intersects(m_boxCollider->GetColliderBox())) {
				m_transform->SetPosition(objCenter.x - (obj.width / 2) - 32.f, playerPos.y);
				Log("Left Wall");
			}

			if (rightWall.intersects(m_boxCollider->GetColliderBox())) {
				m_transform->SetPosition(objCenter.x + (obj.width / 2), playerPos.y);
				Log("Right Wall");
			}

			if (upWall.intersects(m_boxCollider->GetColliderBox())) {
				m_transform->SetPosition(playerPos.x, objCenter.y - (obj.height/ 2) - 32.f);
				Log("Up Wall");
			}

			if (downWall.intersects(m_boxCollider->GetColliderBox())) {
				m_transform->SetPosition(playerPos.x, objCenter.y + (obj.height / 2));
				Log("Down Wall");
			}
		}
	}
}

Component_MapCollision::~Component_MapCollision() {
	Log("Called Component_MapCollision Destructor!");
}