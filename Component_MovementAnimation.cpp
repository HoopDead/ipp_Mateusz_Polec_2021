#include "Component_MovementAnimation.hpp"

Component_MovementAnimation::Component_MovementAnimation(Object* owner) : Component(owner), m_velocity(nullptr), m_animation(nullptr) {
	Log("Called Component Movement Animation Constructor");
}

void Component_MovementAnimation::Awake() {
	m_velocity = owner->GetComponent<Component_Velocity>();
	m_animation = owner->GetComponent<Component_Animation>();
}

void Component_MovementAnimation::Update(float deltaTime) {
	const sf::Vector2f& currentVelocity = m_velocity->Get();

	if (currentVelocity.x != 0.f || currentVelocity.y != 0.f) {
		m_animation->SetAnimationState(AnimationState::Walk);

		float absVelocityX = fabs(currentVelocity.x);
		float absVelocityY = fabs(currentVelocity.y);

		if (absVelocityX > absVelocityY) {
			if (currentVelocity.x < 0.f) {
				m_animation->SetAnimationDirection(FacingDirection::Left);
			}
			else {
				m_animation->SetAnimationDirection(FacingDirection::Right);
			}
		}
		else {
			if (currentVelocity.y < 0.f) {
				m_animation->SetAnimationDirection(FacingDirection::Up);
			}
			else {
				m_animation->SetAnimationDirection(FacingDirection::Down);
			}
		}
	}
	else {
		m_animation->SetAnimationState(AnimationState::Idle);
	}
}

Component_MovementAnimation::~Component_MovementAnimation() {
	Log("Called Component Movement Animation Destructor");
}