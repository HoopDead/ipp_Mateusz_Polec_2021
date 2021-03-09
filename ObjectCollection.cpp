#include "ObjectCollection.hpp"

ObjectCollection::ObjectCollection() {
	Log("Called Object Collection Constructor");
}

ObjectCollection::~ObjectCollection() {
	Log("Called Object Collection Destructor");
}

void ObjectCollection::Add(std::shared_ptr<Object> object) {
	m_newObjects.push_back(object);
}

void ObjectCollection::Update(float deltaTime) {
	for (const auto& o : m_objects) {
		o->Update(deltaTime);
	}
}

void ObjectCollection::LateUpdate(float deltaTime) {
	for (const auto& o : m_objects) {
		o->LateUpdate(deltaTime);
	}
}

void ObjectCollection::Draw(Window& window) {
	for (const auto& o : m_objects) {
		o->Draw(window);
	}
}

void ObjectCollection::ProcessNewObjects() {
	if (m_newObjects.size() > 0) {

		for (const auto& o : m_newObjects) {
			o->Awake();
		}

		for (const auto& o : m_newObjects) {
			o->Start();
		}

		m_objects.assign(m_newObjects.begin(), m_newObjects.end());

		m_newObjects.clear();
	}
}

void ObjectCollection::ProcessRemoval() {
	auto objIterator = m_objects.begin();

	while (objIterator != m_objects.end()) {
		auto obj = **objIterator;

		if (obj.IsQueuedForRemoval()) {
			objIterator = m_objects.erase(objIterator);
		}
		else {
			++objIterator;
		}

	}
}