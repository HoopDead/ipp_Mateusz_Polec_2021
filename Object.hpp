#pragma once

#include <vector>
#include "Window.hpp"
#include "Component.hpp"

class Object {
public:

    /*
    * Awake method
    * Called when Object is created
    * @Param: -
    * @Return: -
    */
	void Awake();

    /*
    * Start method
    * Called just after Awake method to initialse variables
    * @Param: -
    * @Return: -
    */
	void Start();

    /*
    * Update method
    * Used to Update the Objects
    * @Param: float deltaTime - time between each frame
    * @Return: -
    */
	void Update(float deltaTime);

    /*
    * LateUpdate method
    * Used after Update method to do more aggravating operations
    * @Param: float deltaTime - time between each frame
    */
	void LateUpdate(float deltaTime);

    /*
    * Draw method
    * Used to draw the Objects
    */
	void Draw(Window& window);

    /*
    * Template AddCompontent 
    * Take any kind of class compontent shared pointer compontent to add it to vector of compontents
    * @Param: -
    * @Return: Copy of shared pointer of Compontent
    * OR
    * @Return: new Component that was just created
    */
    template <typename T> std::shared_ptr<T> AddComponent() // 1
    {
        //Check, if class based to template is derivered from Compontent
        static_assert(std::is_base_of<Component, T>::value,
            "T must derive from Component");

            //Check, if any Compontent of this type exstsis in vector
            for (auto& exisitingComponent : m_components)
            {

                //Security for now to prevent adding two components twice
                if (std::dynamic_pointer_cast<T>(exisitingComponent))
                {
                    return std::dynamic_pointer_cast<T>(exisitingComponent); // 2
                }
            }

        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        m_components.push_back(newComponent);

        return newComponent;
    };

    /*
    * Template GetCompontent
    * Returns the compontent that we want to reach
    * @Param: -
    * @Return: Copy of shared pointer of Compontent that we want to get
    * OR
    * @Return: nullptr, if Component of this type does not exists.
    */
    template <typename T> std::shared_ptr<T> GetComponent()
    {
        static_assert(std::is_base_of<Component, T>::value,
            "T must derive from Component");

            for (auto& exisitingComponent : m_components)
            {
                if (std::dynamic_pointer_cast<T>(exisitingComponent))
                {
                    return std::dynamic_pointer_cast<T>(exisitingComponent);
                }
            }

        return nullptr;
    };

private:
    std::vector<std::shared_ptr<Component>> m_components;
};