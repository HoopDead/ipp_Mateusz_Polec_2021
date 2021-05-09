#include "ModalOptions.hpp"

ModalOptions::ModalOptions() : m_isActive(false) {}

void ModalOptions::Initialise(std::shared_ptr<Input> input, Setup* setup, Window* window) {
	m_input = input;
	m_setup = setup;
	m_window = window;
	m_modalRect.setSize(sf::Vector2f(500, 700));
	m_modalRect.setFillColor(sf::Color(13, 120, 186));

	ExitModalButton = std::make_shared<TextTemplate>(m_input);

	ExitModalButton->Awake();
	ExitModalButton->SetText("ZAMKNIJ OKNO");
	ExitModalButton->SetFontSize(24);
	ExitModalButton->SetColor(255, 255, 255);
	ExitModalButton->SetType(Type::MENU);
	auto ExitModalAction = ExitModalButton->AddAction<TextAction_ExitOptionsModal>();
	ExitModalAction->SetModal(this);

	ResolutionRawText = std::make_shared<TextTemplate>();

	ResolutionRawText->Awake();
	ResolutionRawText->SetText("ROZDZIELCZOSC");
	ResolutionRawText->SetFontSize(24);
	ResolutionRawText->SetColor(255, 255, 255);
	ResolutionRawText->SetType(Type::RAW);

	ResolutionText = std::make_shared<TextTemplate>(m_input);

	ResolutionText->Awake();
	ResolutionText->SetText(std::to_string(m_setup->GetResolution().width) + "x" + std::to_string(m_setup->GetResolution().height));
	ResolutionText->SetFontSize(20);
	ResolutionText->SetColor(255, 255, 255);
	ResolutionText->SetType(Type::MENU);
	auto ChangeResolutionAction = ResolutionText->AddAction<TextAction_ChangeResolution>();
	ChangeResolutionAction->SetSetup(m_setup);
	ChangeResolutionAction->SetWindow(m_window);

	VSyncRawText = std::make_shared<TextTemplate>();

	VSyncRawText->Awake();
	VSyncRawText->SetText("VSync");
	VSyncRawText->SetFontSize(24);
	VSyncRawText->SetColor(255, 255, 255);
	VSyncRawText->SetType(Type::RAW);

	VSyncText = std::make_shared<TextTemplate>(m_input);

	VSyncText->Awake();
	VSyncText->SetText("Wlaczony");
	VSyncText->SetFontSize(20);
	VSyncText->SetColor(255, 255, 255);
	VSyncText->SetType(Type::MENU);
	auto VSyncSwitch = VSyncText->AddAction<TextAction_VSyncSwitch>();
	VSyncSwitch->SetWindow(m_window);

	m_textCollection.Add(ExitModalButton);
	m_textCollection.Add(ResolutionRawText);
	m_textCollection.Add(ResolutionText);
	m_textCollection.Add(VSyncRawText);
	m_textCollection.Add(VSyncText);
}

void ModalOptions::Update(float deltaTime) {
	if (m_isActive) {
		m_textCollection.Update(deltaTime);
	}
}

void ModalOptions::Draw(Window& window) {
	if (m_isActive) {
		LogAllOneLine("Modal width:", m_modalRect.getLocalBounds().width);
		m_modalRect.setPosition(window.GetCenter().x - m_modalRect.getLocalBounds().width / 2, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2);
		ExitModalButton->SetPosition(window.GetCenter().x - ExitModalButton->GetDimensions().x, window.GetCenter().y + m_modalRect.getLocalBounds().height / 2.3);
		ResolutionRawText->SetPosition(window.GetCenter().x - ResolutionRawText->GetDimensions().x, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2.3);
		ResolutionText->SetPosition(window.GetCenter().x - ResolutionText->GetDimensions().x, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2.6);
		VSyncRawText->SetPosition(window.GetCenter().x - VSyncRawText->GetDimensions().x, window.GetCenter().y - m_modalRect.getLocalBounds().height / 3.1);
		VSyncText->SetPosition(window.GetCenter().x - VSyncText->GetDimensions().x, window.GetCenter().y - m_modalRect.getLocalBounds().height / 3.6);
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