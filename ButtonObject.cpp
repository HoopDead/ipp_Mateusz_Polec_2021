#include "ButtonObject.hpp"

ButtonObject::ButtonObject() {
	Log("Called Button Object Constructor");
}

void ButtonObject::Awake() {
	for (const auto& btn : m_buttons) {
		btn->Awake();
	}
}

void ButtonObject::Update(float deltaTime) {
	for (const auto& btn : m_buttons) {
		btn->Update(deltaTime);
	}
}

void ButtonObject::LateUpdate(float deltaTime) {
	for (const auto& btn : m_buttons) {
		btn->LateUpdate(deltaTime);
	}
}

void ButtonObject::Draw(Window& window) {
	for (const auto& btn : m_buttons) {
		btn->Draw(window);
	}
}

ButtonObject::~ButtonObject() {
	Log("Called Button Object Destructor");
}