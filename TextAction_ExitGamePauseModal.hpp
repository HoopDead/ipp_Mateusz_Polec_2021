#pragma once

#include "TextAction.hpp"
#include "ModalGamePause.hpp"

class ModalGamePause;

class TextAction_ExitGamePauseModal : public TextAction {

public:

	TextAction_ExitGamePauseModal(TextTemplate* owner);

	void RunAction() override;

	void SetModal(ModalGamePause* modal);

	~TextAction_ExitGamePauseModal();

private:

	ModalGamePause* m_modal;

};