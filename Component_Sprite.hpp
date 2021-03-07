#pragma once

#include "Component.hpp"
#include "Logs.hpp"

class Component_Sprite : public Component
{
public:

    /*
    * Constructor of Compontent Sprite object
    * Used to set *Object* as Owner of new Compontent
    * @Param: Object* owner - Pointer to Object, that is owner of this Compontent 
    * @Return: -
    */
    Component_Sprite(Object* owner);

    /*
    * Destructor of Compontent Sprite Object
    * Created only for test purposes
    */
    ~Component_Sprite();

    /*
    * Load method
    * Load method allows the Owner of Compontent to load texture & sprite
    * @Param: const std::string& filePath - file path to sprite that we want to load
    * @Return: -
    */
    void Load(const std::string& filePath);

    /*
    * Draw method - overriden from Compontent class
    * Will draw the Sprite, that is loaded
    * @Param: Window& window - reference to window class
    * @Return: -
    */
    void Draw(Window& window) override;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
