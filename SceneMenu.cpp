#include "SceneMenu.hpp"

SceneMenu::SceneMenu(Window& window) : m_window(window) {
	Log("Called Scene Menu Constructor");
}

void SceneMenu::OnCreate() {
	Log("Called Scene Menu OnCreate Method");

	std::shared_ptr<TextTemplate> test = std::make_shared<TextTemplate>();

	test->Awake();
	test->SetText("abcdefg");
	test->SetPosition(300, 300);
	test->SetFontSize(24);
	test->SetColor(255, 255, 255);

	m_textCollection.Add(test);


	m_textCollection.Awake();

}

void SceneMenu::OnDestroy() {

}

void SceneMenu::ProcessInput() {

}

void SceneMenu::Update(float deltaTime) {
	m_textCollection.Update(deltaTime);

}

void SceneMenu::LateUpdate(float deltaTime) {

}

void SceneMenu::Draw(Window& window) {
	m_textCollection.Draw(window);

}


SceneMenu::~SceneMenu() {
	Log("Called Scene Menu Destructor");
}