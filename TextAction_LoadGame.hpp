#pragma once

#include "TextAction.hpp"
#include "TextTemplate.hpp"
#include "Logs.hpp"
#include "SceneStateMachine.hpp"


class TextAction_LoadGame : public TextAction {

public:
	TextAction_LoadGame(TextTemplate* owner);

	void RunAction() override;

	void SetSceneStateMachine(SceneStateMachine* sceneStateMachine);



	~TextAction_LoadGame();

private:

	SceneStateMachine* m_sceneStateMachine;

};