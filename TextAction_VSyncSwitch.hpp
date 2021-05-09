#pragma once

#include "TextAction.hpp"
#include "TextTemplate.hpp"
#include "Logs.hpp"
#include "Setup.hpp"



class TextAction_VSyncSwitch : public TextAction {

public:
	TextAction_VSyncSwitch(TextTemplate* owner);

	void RunAction() override;

	void SetWindow(Window* window);

	~TextAction_VSyncSwitch();

private:

	bool m_VSyncState = true;
	Window* m_window;

};