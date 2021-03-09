#include "Component_KeyboardMovement.hpp"
#include "Object.hpp"

Component_KeyboardMovement::Component_KeyboardMovement(Object* owner)
	: Component(owner), m_moveSpeed(100), m_input(nullptr) {
	Log("Called Component Keyboard Movement Constructor");
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

}

Component_KeyboardMovement::~Component_KeyboardMovement() {
	Log("Called Compontent Keyboard Movement Destructor");
}