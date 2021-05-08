#include "ModalOptions.hpp"

ModalOptions::ModalOptions() : m_isActive(false) {}

void ModalOptions::Initialise(std::shared_ptr<Input> input, Setup* setup) {
	m_input = input;
	m_setup = setup;
	m_modalRect.setSize(sf::Vector2f(500, 700));
	m_modalRect.setFillColor(sf::Color(13, 120, 186));

	ExitModalButton = std::make_shared<TextTemplate>(m_input);

	ExitModalButton->Awake();
	ExitModalButton->SetText("CLOSE OPTIONS");
	ExitModalButton->SetFontSize(24);
	ExitModalButton->SetColor(255, 255, 255);
	ExitModalButton->SetType(Type::MENU);
	auto ExitModalAction = ExitModalButton->AddAction<TextAction_ExitOptionsModal>();
	ExitModalAction->SetModal(this);

	ResolutionRawText = std::make_shared<TextTemplate>();

	ResolutionRawText->Awake();
	ResolutionRawText->SetText("RESOLUTION");
	ResolutionRawText->SetFontSize(24);
	ResolutionRawText->SetColor(255, 255, 255);
	ResolutionRawText->SetType(Type::RAW);

	ResolutionText = std::make_shared<TextTemplate>(m_input);

	ResolutionText->Awake();
	ResolutionText->SetText(std::to_string(m_setup->GetResolution().x) + "x" + std::to_string(m_setup->GetResolution().y));
	ResolutionText->SetFontSize(20);
	ResolutionText->SetColor(255, 255, 255);
	ResolutionText->SetType(Type::MENU);



	m_textCollection.Add(ExitModalButton);
	m_textCollection.Add(ResolutionRawText);
	m_textCollection.Add(ResolutionText);
}

void ModalOptions::Update(float deltaTime) {
	if (m_isActive) {
		m_textCollection.Update(deltaTime);
	}
}

void ModalOptions::Draw(Window& window) {
	if (m_isActive) {
		m_modalRect.setPosition(window.GetCenter().x - m_modalRect.getLocalBounds().width / 2, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2);
		ExitModalButton->SetPosition(window.GetCenter().x - ExitModalButton->GetDimensions().x, window.GetCenter().y + m_modalRect.getLocalBounds().height / 2.3);
		ResolutionRawText->SetPosition(window.GetCenter().x - ResolutionRawText->GetDimensions().x, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2.3);
		ResolutionText->SetPosition(window.GetCenter().x - ResolutionText->GetDimensions().x, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2.6);
		window.Draw(m_modalRect);
		m_textCollection.Draw(window);
	}
}

void ModalOptions::Activate() {
	m_isActive = true;
}

void ModalOptions::Deactivate() {
	m_isActive = false;
}

bool ModalOptions::IsActive() const {
	return m_isActive;
}


ModalOptions::~ModalOptions() {}