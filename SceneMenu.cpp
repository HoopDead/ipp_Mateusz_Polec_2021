#include "SceneMenu.hpp"

SceneMenu::SceneMenu(Window& window, SceneStateMachine* sceneStateMachine, std::shared_ptr<Input> input, Setup* setup) 
	: m_window(window), 
	m_sceneStateMachine(sceneStateMachine),
	m_input(input),
	m_setup(setup) {
	Log("Called Scene Menu Constructor");
}

void SceneMenu::OnCreate() {
	Log("Called Scene Menu OnCreate Method");


	//NEW GAME BUTTON
	NewGameButton = std::make_shared<TextTemplate>(m_input);

	NewGameButton->Awake();
	NewGameButton->SetText("NOWA GRA");
	NewGameButton->SetFontSize(32);
	NewGameButton->SetColor(255, 255, 255);
	NewGameButton->SetType(Type::MENU);


	//LOAD GAME BUTTON
	LoadGameButton = std::make_shared<TextTemplate>(m_input);

	LoadGameButton->Awake();
	LoadGameButton->SetText("WCZYTAJ GRE");
	LoadGameButton->SetFontSize(32);
	LoadGameButton->SetColor(255, 255, 255);
	LoadGameButton->SetType(Type::MENU);
	auto LoadGameAction = LoadGameButton->AddAction<TextAction_LoadGame>();
	LoadGameAction->SetSceneStateMachine(m_sceneStateMachine);

	//OPTIONS BUTTON
	OptionsGameButton = std::make_shared<TextTemplate>(m_input);

	OptionsGameButton->Awake();
	OptionsGameButton->SetText("OPCJE");
	OptionsGameButton->SetFontSize(32);
	OptionsGameButton->SetColor(255, 255, 255);
	OptionsGameButton->SetType(Type::MENU);
	auto OptionsModalAction = OptionsGameButton->AddAction<TextAction_Options>();
	OptionsModalAction->SetModal(&m_modalOptions);

	//EXIT BUTTON
	ExitGameButton = std::make_shared<TextTemplate>(m_input);

	ExitGameButton->Awake();
	ExitGameButton->SetText("WYJDZ Z GRY");
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

	m_modalOptions.Initialise(m_input, m_setup, &m_window);

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
	NewGameButton->SetPosition(m_window.GetCenter() - NewGameButton->GetDimensions());
	LoadGameButton->SetPosition(m_window.GetCenter().x - LoadGameButton->GetDimensions().x, m_window.GetCenter().y - LoadGameButton->GetDimensions().y + 75);
	OptionsGameButton->SetPosition(m_window.GetCenter().x - OptionsGameButton->GetDimensions().x, m_window.GetCenter().y - OptionsGameButton->GetDimensions().y + 150);
	ExitGameButton->SetPosition(m_window.GetCenter().x - ExitGameButton->GetDimensions().x, m_window.GetCenter().y - ExitGameButton->GetDimensions().y + 225);
	m_textCollection.Draw(window);
	m_modalOptions.Draw(window);

}


SceneMenu::~SceneMenu() {
	Log("Called Scene Menu Destructor");
}