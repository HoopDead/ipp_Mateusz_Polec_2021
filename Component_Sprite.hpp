#pragma once

#include "Component.hpp"
#include "Component_Transform.hpp"
#include "Object.hpp"
#include "Logs.hpp"
#include "ResourceAllocator.hpp"

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
    * Load method allows the Owner of Compontent to load texture & sprite. It also adds the Texture to resource allocator.
    * @Param: const std::string& filePath - file path to sprite that we want to load
    * @Return: -
    */
    void Load(const std::string& filePath);

    /*
    * Load method
    * Load method allows the Owner of Compontent to load texture & sprite. It also adds the Texture to resource allocator.
    * @Param: int id - id of resource we want to load
    * @Return: -
    */
    void Load(int id);

    /*
    * SetTextureAllocator method
    * Set the Resource Allocator for this Compontent
    * @Param: ResouerceAllocator<sf::Texture>* allocator - pointer to resource allocator we want to assign
    * @Return: -
    */
    void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

    /*
    * Draw method - overriden from Compontent class
    * Will draw the Sprite, that is loaded
    * @Param: Window& window - reference to window class
    * @Return: -
    */
    void Draw(Window& window) override;

    /*
    * LateUpdate method - overriden from Component class
    * Is called just after Update method to handle more challanging operations
    * @Param: float deltaTime - time between each frame
    * @Return: -
    */
    void LateUpdate(float deltaTime) override;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    ResourceAllocator<sf::Texture>* m_allocator;
};
