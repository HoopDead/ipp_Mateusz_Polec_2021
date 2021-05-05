#pragma once


#include "TextAction.hpp"
#include "ModalOptions.hpp"

class ModalOptions;

class TextAction_ExitOptionsModal : public TextAction {

public:

	TextAction_ExitOptionsModal(TextTemplate* owner);

	void RunAction() override;

	void SetModal(ModalOptions* modal);

	~TextAction_ExitOptionsModal();

private:

	ModalOptions* m_modal;

};