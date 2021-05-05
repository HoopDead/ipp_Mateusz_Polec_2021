#include "SceneMenu.hpp"

SceneMenu::SceneMenu(Window& window, SceneStateMachine* sceneStateMachine) : m_window(window), m_sceneStateMachine(sceneStateMachine) {
	Log("Called Scene Menu Constructor");
}

void SceneMenu::OnCreate() {
	Log("Called Scene Menu OnCreate Method");


	//NEW GAME BUTTON
	std::shared_ptr<TextTemplate> NewGameButton = std::make_shared<TextTemplate>();

	NewGameButton->Awake();
	NewGameButton->SetText("NEW GAME");
	NewGameButton->SetPosition(m_window.GetCenter() - NewGameButton->GetDimensions());
	NewGameButton->SetFontSize(32);
	NewGameButton->SetColor(255, 255, 255);
	NewGameButton->SetType(Type::MENU);


	//LOAD GAME BUTTON
	std::shared_ptr<TextTemplate> LoadGameButton = std::make_shared<TextTemplate>();

	LoadGameButton->Awake();
	LoadGameButton->SetText("LOAD GAME");
	LoadGameButton->SetPosition(m_window.GetCenter().x - LoadGameButton->GetDimensions().x, m_window.GetCenter().y - LoadGameButton->GetDimensions().y + 75);
	LoadGameButton->SetFontSize(32);
	LoadGameButton->SetColor(255, 255, 255);
	LoadGameButton->SetType(Type::MENU);
	auto LoadGameAction = LoadGameButton->AddAction<TextAction_LoadGame>();
	LoadGameAction->SetSceneStateMachine(m_sceneStateMachine);

	//OPTIONS BUTTON
	std::shared_ptr<TextTemplate> OptionsGameButton = std::make_shared<TextTemplate>();

	OptionsGameButton->Awake();
	OptionsGameButton->SetText("OPTIONS");
	OptionsGameButton->SetPosition(m_window.GetCenter().x - OptionsGameButton->GetDimensions().x, m_window.GetCenter().y - OptionsGameButton->GetDimensions().y + 150);
	OptionsGameButton->SetFontSize(32);
	OptionsGameButton->SetColor(255, 255, 255);
	OptionsGameButton->SetType(Type::MENU);
	auto OptionsModalAction = OptionsGameButton->AddAction<TextAction_Options>();
	OptionsModalAction->SetModal(&m_modalOptions);

	//EXIT BUTTON
	std::shared_ptr<TextTemplate> ExitGameButton = std::make_shared<TextTemplate>();

	ExitGameButton->Awake();
	ExitGameButton->SetText("EXIT GAME");
	ExitGameButton->SetPosition(m_window.GetCenter().x - ExitGameButton->GetDimensions().x, m_window.GetCenter().y - ExitGameButton->GetDimensions().y + 225);
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

	m_modalOptions.Initialise();

}

void SceneMenu::OnDestroy() {
	Log("Destroy!");

}

void SceneMenu::ProcessInput() {

}

void SceneMenu::Update(float deltaTime) {
	if (!m_modalOptions.IsActive()) {
		m_textCollection.Update(deltaTime);
	}
	else {
		m_modalOptions.Update(deltaTime);
	}

}

void SceneMenu::LateUpdate(float deltaTime) {

}

void SceneMenu::Draw(Window& window) {
	m_textCollection.Draw(window);
	m_modalOptions.Draw(window);

}


SceneMenu::~SceneMenu() {
	Log("Called Scene Menu Destructor");
}