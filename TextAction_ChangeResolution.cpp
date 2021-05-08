#include "TextAction_ChangeResolution.hpp"

TextAction_ChangeResolution::TextAction_ChangeResolution(TextTemplate* owner) : TextAction(owner), m_setup(nullptr) {

}

void TextAction_ChangeResolution::SetSetup(Setup* setup) {
	m_setup = setup;
}

void TextAction_ChangeResolution::RunAction() {
	Log("RUN ACTION!");
}

TextAction_ChangeResolution::~TextAction_ChangeResolution() {}