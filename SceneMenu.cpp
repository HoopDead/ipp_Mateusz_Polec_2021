#include "SceneMenu.hpp"

SceneMenu::SceneMenu(Window& window) : m_window(window) {
	Log("Called Scene Menu Constructor");
}

void SceneMenu::OnCreate() {
	Log("Called Scene Menu OnCreate Method");

	std::shared_ptr<ButtonObject> buttonTest = std::make_shared<ButtonObject>(); //Move to class member?


}

void SceneMenu::OnDestroy() {

}

void SceneMenu::ProcessInput() {

}

void SceneMenu::Update(float deltaTime) {

}

void SceneMenu::LateUpdate(float deltaTime) {

}

void SceneMenu::Draw(Window& window) {

}


SceneMenu::~SceneMenu() {
	Log("Called Scene Menu Destructor");
}