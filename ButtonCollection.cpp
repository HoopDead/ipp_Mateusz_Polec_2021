#include "ButtonCollection.hpp"

ButtonCollection::ButtonCollection() {
	Log("Called ButtonCollection Constructor");
}

ButtonCollection::~ButtonCollection() {
	Log("Called Object Collection Destructor");
}

void ButtonCollection::Add(std::shared_ptr<ButtonObject> object) {
	m_ButtonNewObjects.push_back(object);
}

void ButtonCollection::Update(float deltaTime) {
	for (const auto& o : m_ButtonObjects) {
		o->Update(deltaTime);
	}
}

void ButtonCollection::LateUpdate(float deltaTime) {
	for (const auto& o : m_ButtonObjects) {
		o->LateUpdate(deltaTime);
	}
}

void ButtonCollection::Draw(Window& window) {
	for (const auto& o : m_ButtonObjects) {
		o->Draw(window);
	}
}

void ButtonCollection::ProcessNewObjects() {
	if (m_ButtonNewObjects.size() > 0) {

		for (const auto& o : m_ButtonNewObjects) {
			o->Awake();
		}

		for (const auto& o : m_ButtonNewObjects) {
			o->Start();
		}

		m_ButtonObjects.assign(m_ButtonNewObjects.begin(), m_ButtonNewObjects.end());

		m_ButtonNewObjects.clear();
	}
}
