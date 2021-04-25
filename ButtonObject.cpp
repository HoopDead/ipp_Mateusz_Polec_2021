#include "ButtonObject.hpp"

ButtonObject::ButtonObject() {
    Log("Called Object Constructor");
}

void ButtonObject::Awake()
{
    for (int i = m_buttons.size() - 1; i >= 0; i--)
    {
        m_buttons[i]->Awake();
    }
}

void ButtonObject::Start()
{
    for (int i = m_buttons.size() - 1; i >= 0; i--)
    {
        m_buttons[i]->Start();
    }
}

void ButtonObject::Update(float timeDelta)
{
    for (int i = m_buttons.size() - 1; i >= 0; i--)
    {
        m_buttons[i]->Update(timeDelta);
    }
}

void ButtonObject::LateUpdate(float timeDelta)
{
    for (int i = m_buttons.size() - 1; i >= 0; i--)
    {
        m_buttons[i]->LateUpdate(timeDelta);
    }
}

void ButtonObject::Draw(Window& window)
{
    for (int i = m_buttons.size() - 1; i >= 0; i--)
    {
        m_buttons[i]->Draw(window);
    }
}
