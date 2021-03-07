#pragma once

#include "Component.hpp"
#include "Logs.hpp"

class Component_Sprite : public Component
{
public:

    //TODO: Documentation
    Component_Sprite(Object* owner);

    //TODO: Documentation
    ~Component_Sprite();

    //TODO: Documentation
    void Load(const std::string& filePath);

    //TODO: Documentation
    void Draw(Window& window) override;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
