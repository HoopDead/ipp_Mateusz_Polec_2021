#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine() : m_scenes(0), m_currentScene(0), m_insertedSceneID(0) {
	Log("Called Scene State Machine Constructor");
}

void SceneStateMachine::Update(float deltaTime) {

	if (m_currentScene) {
		m_currentScene->Update(deltaTime);
	}
}

void SceneStateMachine::ProcessInput() {
	if (m_currentScene) {
		m_currentScene->ProcessInput();
	}
}

void SceneStateMachine::LateUpdate(float deltaTime) {

	if (m_currentScene) {
		m_currentScene->LateUpdate(deltaTime);
	}
}

void SceneStateMachine::Draw(Window& window) {

	if (m_currentScene) {
		m_currentScene->Draw(window);
	}

}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene) {

	auto inserted = m_scenes.insert(std::make_pair(m_insertedSceneID, scene));

	 m_insertedSceneID++;

	inserted.first->second->OnCreate();

	return m_insertedSceneID - 1;


}

void SceneStateMachine::SwitchTo(unsigned int id) {
	
	auto it = m_scenes.find(id);
	if (it != m_scenes.end()) {
		if (m_currentScene) {
			m_currentScene->OnDeactivate();
		}
	}

	m_currentScene = it->second;
	m_currentScene->OnActivate();

}

void SceneStateMachine::Remove(unsigned int id) {

	auto it = m_scenes.find(id);
	if (it != m_scenes.end()) {
		if (m_currentScene == it->second) {
			m_currentScene = nullptr;
		}
	}

	it->second->OnDestroy();

	m_scenes.erase(it);

}

SceneStateMachine::~SceneStateMachine() {
	Log("Called Scene State Machine Destructor");
}
