#include "Component_KeyboardMovement.hpp"
#include "Object.hpp"

Component_KeyboardMovement::Component_KeyboardMovement(Object* owner)
	: Component(owner), m_moveSpeed(200), m_input(nullptr) {
	Log("Called Component Keyboard Movement Constructor");
}

void Component_KeyboardMovement::Awake() {
	m_animation = owner->GetComponent<Component_Animation>();
}


void Component_KeyboardMovement::SetInput(Input* input) {
	m_input = input;
}

void Component_KeyboardMovement::SetMovementSpeed(int moveSpeed) {
	m_moveSpeed = moveSpeed;
}

void Component_KeyboardMovement::Update(float deltaTime) {

	if (m_input == nullptr) {
		return;
	}

	int xMove = 0;

	if (m_input->IsKeyPressed(Input::Key::Left)) {
		xMove = -m_moveSpeed;
	}
	else if (m_input->IsKeyPressed(Input::Key::Right)) {
		xMove = m_moveSpeed;
	}

	int yMove = 0;
	if (m_input->IsKeyPressed(Input::Key::Up)) {
		yMove = -m_moveSpeed;
	}
	else if (m_input->IsKeyPressed(Input::Key::Down)) {
		yMove = m_moveSpeed;
	}

	float xFrameMove = xMove * deltaTime;
	float yFrameMove = yMove * deltaTime;

	owner->transform->AddPosition(xFrameMove, yFrameMove);

	if (xMove == 0 && yMove == 0) {
		m_animation->SetAnimationState(AnimationState::Idle);
	}
	else {
		m_animation->SetAnimationState(AnimationState::Walk);
	}

	if (abs(xMove) > abs(yMove)) {
		if (xMove < 0) {
			m_animation->SetAnimationDirection(FacingDirection::Left);
		}
		else {
			m_animation->SetAnimationDirection(FacingDirection::Right);
		}
	}
	else {
		if (yMove < 0) {
			m_animation->SetAnimationDirection(FacingDirection::Up);
		}
		else {
			m_animation->SetAnimationDirection(FacingDirection::Down);
		}
	}

}

Component_KeyboardMovement::~Component_KeyboardMovement() {
	Log("Called Compontent Keyboard Movement Destructor");
}