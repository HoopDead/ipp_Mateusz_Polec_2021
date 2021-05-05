#include "SceneMenu.hpp"

SceneMenu::SceneMenu(Window& window) : m_window(window) {
	Log("Called Scene Menu Constructor");
}

void SceneMenu::OnCreate() {
	Log("Called Scene Menu OnCreate Method");


	//NEW GAME BUTTON
	std::shared_ptr<TextTemplate> NewGameButton = std::make_shared<TextTemplate>();

	NewGameButton->Awake();
	NewGameButton->SetText("NEW GAME");
	NewGameButton->SetPosition(300, 300);
	NewGameButton->SetFontSize(32);
	NewGameButton->SetColor(255, 255, 255);
	NewGameButton->SetType(Type::MENU);


	//LOAD GAME BUTTON
	std::shared_ptr<TextTemplate> LoadGameButton = std::make_shared<TextTemplate>();

	LoadGameButton->Awake();
	LoadGameButton->SetText("LOAD GAME");
	LoadGameButton->SetPosition(300, 375);
	LoadGameButton->SetFontSize(32);
	LoadGameButton->SetColor(255, 255, 255);
	LoadGameButton->SetType(Type::MENU);

	//OPTIONS BUTTON
	std::shared_ptr<TextTemplate> OptionsGameButton = std::make_shared<TextTemplate>();

	OptionsGameButton->Awake();
	OptionsGameButton->SetText("OPTIONS");
	OptionsGameButton->SetPosition(300, 450);
	OptionsGameButton->SetFontSize(32);
	OptionsGameButton->SetColor(255, 255, 255);
	OptionsGameButton->SetType(Type::MENU);

	//EXIT BUTTON
	std::shared_ptr<TextTemplate> ExitGameButton = std::make_shared<TextTemplate>();

	ExitGameButton->Awake();
	ExitGameButton->SetText("EXIT GAME");
	ExitGameButton->SetPosition(300, 525);
	ExitGameButton->SetFontSize(32);
	ExitGameButton->SetColor(255, 255, 255);
	ExitGameButton->SetType(Type::MENU);
	auto ExitAction = ExitGameButton->AddAction<TextAction_Exit>();
	ExitAction->SetWindow(&m_window);

	m_textCollection.Add(NewGameButton);
	m_textCollection.Add(LoadGameButton);
	m_textCollection.Add(OptionsGameButton);
	m_textCollection.Add(ExitGameButton);


	m_textCollection.Awake();

}

void SceneMenu::OnDestroy() {
	Log("Destroy!");

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