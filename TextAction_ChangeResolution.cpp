#include "TextAction_ChangeResolution.hpp"

TextAction_ChangeResolution::TextAction_ChangeResolution(TextTemplate* owner) : TextAction(owner) {

}

void TextAction_ChangeResolution::SetSetup(Setup* setup) {
	m_setup = setup;
	m_actualResolution = m_setup->GetResolution();
}

void TextAction_ChangeResolution::SetWindow(Window* window) {
	m_window = window;
}

void TextAction_ChangeResolution::RunAction() {
	m_actualResolutionIndex++;

	if (m_actualResolutionIndex >= m_resolutions.size()) {
		m_actualResolutionIndex = 0;
	}

	m_actualResolution = m_resolutions[m_actualResolutionIndex];
	m_setup->SetResolution(m_actualResolution);

	m_window->ResizeToResolution();

	

	owner->SetText(std::to_string(m_actualResolution.width) + "x" + std::to_string(m_actualResolution.height));
}

TextAction_ChangeResolution::~TextAction_ChangeResolution() {}