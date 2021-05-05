#pragma once

#include "TextAction.hpp"
#include "TextTemplate.hpp"
#include "Logs.hpp"
#include "ModalOptions.hpp"

class TextAction_Options : public TextAction {

public:
	TextAction_Options(TextTemplate* owner);

	void SetModal(ModalOptions* modal);

	void RunAction() override;

	~TextAction_Options();

private:

	ModalOptions* m_modal;

};