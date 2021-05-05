#include "TextAction_Exit.hpp"

TextAction_Exit::TextAction_Exit(TextTemplate* owner) : TextAction(owner) {
	Log("Called TextAxtion exit");
}

void TextAction_Exit::SetWindow(Window* window) {
	m_window = window;
}

void TextAction_Exit::RunAction() {
	m_window->Exit();

}

TextAction_Exit::~TextAction_Exit() {
	Log("Called TextAction_Exit Destructor");
}