#include "TextAction_ExitGamePauseModal.hpp"

TextAction_ExitGamePauseModal::TextAction_ExitGamePauseModal(TextTemplate* owner) : TextAction(owner) {}

void TextAction_ExitGamePauseModal::RunAction() {

	if (m_modal->IsActive()) {
		m_modal->Deactivate();
	}

}

void TextAction_ExitGamePauseModal::SetModal(ModalGamePause* modal) {
	m_modal = modal;
}

TextAction_ExitGamePauseModal::~TextAction_ExitGamePauseModal() {}