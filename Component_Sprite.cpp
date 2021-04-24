#include "Component_Sprite.hpp"

Component_Sprite::Component_Sprite(Object* owner) : Component(owner), m_currentTextureID(-1)
{
    Log("Called Component_Sprite Constructor");
}

void Component_Sprite::Load(const std::string& filePath)
{
    if (m_allocator) {
        int textureID = m_allocator->Add(filePath);
        
        if (textureID >= 0 && textureID != m_currentTextureID) {
            m_currentTextureID = textureID;
            std::shared_ptr<sf::Texture> texture = m_allocator->Get(textureID);
            m_sprite.setTexture(*texture);
        }
    }
}

void Component_Sprite::Load(int id) {
    if (id >= 0 && id != m_currentTextureID) {
        m_currentTextureID = id;
        std::shared_ptr<sf::Texture> texture = m_allocator->Get(id);
        m_sprite.setTexture(*texture);
    }
}

void Component_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator) {
    m_allocator = allocator;
}

void Component_Sprite::LateUpdate(float deltaTime) {
    m_sprite.setPosition(owner->transform->GetPosition());
}

void Component_Sprite::SetTextureRect(int x, int y, int width, int height) {
    m_sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void Component_Sprite::SetTextureRect(const sf::IntRect& rect) {
    m_sprite.setTextureRect(rect);
}

void Component_Sprite::Draw(Window& window) {
    window.Draw(m_sprite);
}

const sf::Sprite Component_Sprite::GetSprite() const {
    return m_sprite;
}


Component_Sprite::~Component_Sprite() {
    Log("Called Component_Sprite Destructor");
}