#include "ButtonCollection.hpp"

ButtonCollection::ButtonCollection() {
	Log("Called Button Collection Constructor");
}

void ButtonCollection::Add(std::shared_ptr<ButtonObject> buttonObject) {
	m_newObjects.push_back(buttonObject);
}

void ButtonCollection::Update(float deltaTime) {

	for (const auto& btnObject : m_objects) {
		btnObject->Update(deltaTime);
	}
}

void ButtonCollection::LateUpdate(float deltaTime) {
	for (const auto& btnObject : m_objects) {
		btnObject->LateUpdate(deltaTime);
	}
}

void ButtonCollection::Draw(Window& window) {
	for (const auto& btnObject : m_objects) {
		btnObject->Draw(window);
	}
}

void ButtonCollection::ProcessNewObjects() {
	if (m_newObjects.size() > 0) {

		for (const auto& btnObject : m_newObjects) {
			btnObject->Awake();
		}

		m_objects.assign(m_newObjects.begin(), m_newObjects.end());

		m_objects.clear();

	}
}

ButtonCollection::~ButtonCollection() {
	Log("Called Button Collection Destructor");
}