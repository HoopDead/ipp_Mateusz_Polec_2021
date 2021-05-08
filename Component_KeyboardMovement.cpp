#include "Component_KeyboardMovement.hpp"

Component_KeyboardMovement::Component_KeyboardMovement(Object* owner)
	: Component(owner), m_moveSpeed(200), m_input(nullptr) {
	Log("Called Component Keyboard Movement Constructor");
}

void Component_KeyboardMovement::Awake() {
	m_velocity = owner->GetComponent<Component_Velocity>();
}


void Component_KeyboardMovement::SetInput(std::shared_ptr<Input> input) {
	m_input = input;
}

void Component_KeyboardMovement::SetMovementSpeed(int moveSpeed) {
	m_moveSpeed = moveSpeed;
}

void Component_KeyboardMovement::Update(float deltaTime) {
	if (m_input == nullptr) {
		return;
	}

	float xMove = 0.f;
	if (m_input->IsKeyPressed(Input::Key::Left)) {
		xMove = -m_moveSpeed;
	}
	else if (m_input->IsKeyPressed(Input::Key::Right)) {
		xMove = m_moveSpeed;
	}

	float yMove = 0.f;
	if (m_input->IsKeyPressed(Input::Key::Up)) {
		yMove = -m_moveSpeed;
	}
	else if (m_input->IsKeyPressed(Input::Key::Down)) {
		yMove = m_moveSpeed;
	}

		m_velocity->Set(xMove, yMove);
}

Component_KeyboardMovement::~Component_KeyboardMovement() {
	Log("Called Compontent Keyboard Movement Destructor");
}