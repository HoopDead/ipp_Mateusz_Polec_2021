#include "Object.hpp"

Object::Object() {
    m_transform = AddComponent<Component_Transform>();
}

void Object::Awake()
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->Awake();
    }
}

void Object::Start()
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->Start();
    }
}

void Object::Update(float timeDelta)
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->Update(timeDelta);
    }
}

void Object::LateUpdate(float timeDelta)
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->LateUpdate(timeDelta);
    }
}

void Object::Draw(Window& window)
{
    for (int i = m_components.size() - 1; i >= 0; i--)
    {
        m_components[i]->Draw(window);
    }
}