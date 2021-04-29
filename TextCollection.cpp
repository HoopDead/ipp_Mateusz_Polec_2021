#include "TextCollection.hpp"

TextCollection::TextCollection() {

}

void TextCollection::Awake() {
	for (const auto& t : m_texts) {
		t->Awake();
	}
}

void TextCollection::Update(float deltaTime) {
	for (const auto& t : m_texts) {
		t->Update(deltaTime);
	}
}


void TextCollection::Draw(Window& window) {

	for (const auto& t : m_texts) {
		t->Draw(window);
	}

}

void TextCollection::Add(std::shared_ptr<TextTemplate> text) {
	m_texts.push_back(text);
}

TextCollection::~TextCollection() {

}