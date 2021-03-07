#include "Component_Sprite.hpp"

Component_Sprite::Component_Sprite(Object* owner) : Component(owner) {
    Log("Called Component_Sprite Constructor");
}

void Component_Sprite::Load(const std::string& filePath)
{
    m_texture.loadFromFile(filePath);
    m_sprite.setTexture(m_texture);
}

void Component_Sprite::Draw(Window& window)
{
    window.Draw(m_sprite);
}

Component_Sprite::~Component_Sprite() {
    Log("Called Component_Sprite Destructor");
}