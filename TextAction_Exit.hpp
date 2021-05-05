#pragma once

#include "TextAction.hpp"
#include "TextTemplate.hpp"
#include "Logs.hpp"


class TextAction_Exit : public TextAction {

public:
	TextAction_Exit(TextTemplate* owner);
	 
	void RunAction() override;

	void SetWindow(Window* window);



	~TextAction_Exit();

private:

	Window* m_window;

};