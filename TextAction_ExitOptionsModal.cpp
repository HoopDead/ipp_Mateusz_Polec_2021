#include "TextAction_ExitOptionsModal.hpp"

TextAction_ExitOptionsModal::TextAction_ExitOptionsModal(TextTemplate* owner) : TextAction(owner) {}

void TextAction_ExitOptionsModal::RunAction() {

	if (m_modal->IsActive()) {
		m_modal->Deactivate();
	}

}

void TextAction_ExitOptionsModal::SetModal(ModalOptions* modal) {
	m_modal = modal;
}

TextAction_ExitOptionsModal::~TextAction_ExitOptionsModal() {}