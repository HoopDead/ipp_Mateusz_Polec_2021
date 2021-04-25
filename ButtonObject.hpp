#pragma once

#include <vector>
#include "Window.hpp"
#include "Button.hpp"

class ButtonObject {
public:

public:

    //TODO: Documentation
    ButtonObject();

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
    template <typename T> std::shared_ptr<T> AddButton() // 1
    {
        static_assert(std::is_base_of<Button, T>::value,
            "T must derive from Button");

        for (auto& existingButton : m_buttons)
        {

            if (std::dynamic_pointer_cast<T>(existingButton))
            {
                return std::dynamic_pointer_cast<T>(existingButton); // 2
            }
        }

        std::shared_ptr<T> newButton = std::make_shared<T>(this);
        m_buttons.push_back(newButton);

        return newButton;
    };
    
    //TODO: Documentation
    template <typename T> std::shared_ptr<T> GetButton()
    {
        static_assert(std::is_base_of<Button, T>::value,
            "T must derive from Button");

        for (auto& existingButton : m_buttons)
        {
            if (std::dynamic_pointer_cast<T>(existingButton))
            {
                return std::dynamic_pointer_cast<T>(existingButton);
            }
        }

        return nullptr;
    };


private:
    std::vector<std::shared_ptr<Button>> m_buttons;
};