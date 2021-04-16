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
	Log("Layer set!");
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

			const sf::FloatRect leftWall(objPosition.x, objPosition.y, 1, obj.height);
			const sf::FloatRect rightWall(objPosition.x + obj.width, objPosition.y, 1, obj.height);
			const sf::FloatRect upWall(objPosition.x, objPosition.y, obj.width, 1);
			const sf::FloatRect downWall(objPosition.x, objPosition.y + obj.height, obj.width, 1);

			if (leftWall.intersects(m_boxCollider->GetColliderBox())) {
				Log("Left Wall Coll");
				m_velocity->Set(0, 0);
				m_transform->SetPosition(objCenter.x - (obj.width / 2) - 32.f, playerPos.y);
			}

			if (rightWall.intersects(m_boxCollider->GetColliderBox())) {
				Log("Right Wall Coll");
				m_velocity->Set(0, 0);
				m_transform->SetPosition(objCenter.x + (obj.width / 2), playerPos.y);
			}

			if (upWall.intersects(m_boxCollider->GetColliderBox())) {
				Log("Up Wall Coll");
				m_velocity->Set(0, 0);
				m_transform->SetPosition(playerPos.x, objCenter.y - (obj.height/ 2) - 32.f);
			}

			if (downWall.intersects(m_boxCollider->GetColliderBox())) {
				Log("Down Wall Coll");
				m_velocity->Set(0, 0);
				m_transform->SetPosition(playerPos.x, objCenter.y + (obj.height / 2));
			}
		}
	}
}

Component_MapCollision::~Component_MapCollision() {
	Log("Called Component_MapCollision Destructor!");
}