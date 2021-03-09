#include "Component_Sprite.hpp"

Component_Sprite::Component_Sprite(Object* owner) : Component(owner) {
    Log("Called Component_Sprite Constructor");
}

void Component_Sprite::Load(const std::string& filePath)
{
    if (m_allocator) {
        int textureID = m_allocator->Add(filePath);

        if (textureID >= 0) {
            std::shared_ptr<sf::Texture> texture = m_allocator->Get(textureID);
            m_sprite.setTexture(*texture);
        }
    }
}

void Component_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator) {
    m_allocator = allocator;
}

void Component_Sprite::Load(int id) {
    if (id >= 0) {
        std::shared_ptr<sf::Texture> texture = m_allocator->Get(id);
        m_sprite.setTexture(*texture);
    }
}

void Component_Sprite::Draw(Window& window)
{
    window.Draw(m_sprite);
}

void Component_Sprite::LateUpdate(float deltaTime) {
    m_sprite.setPosition(owner->transform->GetPosition());
}

Component_Sprite::~Component_Sprite() {
    Log("Called Component_Sprite Destructor");
}