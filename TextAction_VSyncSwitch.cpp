#include "TextAction_VSyncSwitch.hpp"

TextAction_VSyncSwitch::TextAction_VSyncSwitch(TextTemplate* owner) : TextAction(owner) {

}
void TextAction_VSyncSwitch::SetWindow(Window* window) {
	m_window = window;
}

void TextAction_VSyncSwitch::RunAction() {

	if (m_VSyncState) {
		owner->SetText("Wylaczony");
		m_VSyncState = false;
		m_window->VSyncSwitch(m_VSyncState);
	}
	else if (!m_VSyncState) {
		owner->SetText("Wlaczony");
		m_VSyncState = true;
		m_window->VSyncSwitch(m_VSyncState);
	}
}

TextAction_VSyncSwitch::~TextAction_VSyncSwitch() {}