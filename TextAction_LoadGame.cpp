#include "TextAction_LoadGame.hpp"

TextAction_LoadGame::TextAction_LoadGame(TextTemplate* owner) : TextAction(owner) {
	Log("Called TextAction_LoadGame Constructor");
}

void TextAction_LoadGame::SetSceneStateMachine(SceneStateMachine* sceneStateMachine) {
	m_sceneStateMachine = sceneStateMachine;
}

void TextAction_LoadGame::RunAction() {
	m_sceneStateMachine->SwitchTo(1);

}

TextAction_LoadGame::~TextAction_LoadGame() {
	Log("Called TextAction_LoadGame Destructor");
}