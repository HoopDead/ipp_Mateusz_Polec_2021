#include "TextAction_Options.hpp"

TextAction_Options::TextAction_Options(TextTemplate* owner) : TextAction(owner) {
	Log("Called TextAxtion exit");
}

void TextAction_Options::SetModal(ModalOptions* modal) {
	m_modal = modal;
}

void TextAction_Options::RunAction() {
	
	if (m_modal->IsActive()) {
		m_modal->Deactivate();
	}
	else {
		m_modal->Activate();
	}
}

TextAction_Options::~TextAction_Options() {
	Log("Called TextAction_Exit Destructor");
}