#pragma once

#include <vector>
#include "Window.hpp"
#include "Component.hpp"

class Object {
public:

    //TODO: Documentation
	void Awake();

    //TODO: Documentation
	void Start();

    //TODO: Documentation
	void Update(float deltaTime);

    //TODO: Documentation
	void LateUpdate(float deltaTime);

    //TODO: Documentation
	void Draw(Window& window);

    //TODO: Documentation
    template <typename T> std::shared_ptr<T> AddComponent() // 1
    {

        static_assert(std::is_base_of<Component, T>::value,
            "T must derive from Component");

            for (auto& exisitingComponent : m_components)
            {
                if (std::dynamic_pointer_cast<T>(exisitingComponent))
                {
                    return std::dynamic_pointer_cast<T>(exisitingComponent); // 2
                }
            }

        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        m_components.push_back(newComponent);

        return newComponent;
    };

    //TODO: Documentation
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