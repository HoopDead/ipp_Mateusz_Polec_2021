#pragma once

#include "TextAction.hpp"
#include "TextTemplate.hpp"
#include "Logs.hpp"
#include "Setup.hpp"

class TextAction_ChangeResolution : public TextAction {

public:
	TextAction_ChangeResolution(TextTemplate* owner);

	void SetSetup(Setup* setup);

	void RunAction() override;

	~TextAction_ChangeResolution();

private:

	Setup* m_setup;

};