#include "Component_Animation.hpp"
#include "Object.hpp"

Component_Animation::Component_Animation(Object* owner) : Component(owner),
m_currentAnimation(AnimationState::None, nullptr), m_currentDirection(FacingDirection::Down) { }

void Component_Animation::Awake()
{
    m_sprite = owner->GetComponent<Component_Sprite>();
}

void Component_Animation::Update(float deltaTime)
{
    if (m_currentAnimation.first != AnimationState::None)
    {
        bool newFrame = m_currentAnimation.second->UpdateFrame(deltaTime);

        if (newFrame)
        {
            const FrameData* data = m_currentAnimation.second->GetCurrentFrame();
            m_sprite->Load(data->id);

            m_sprite->SetTextureRect(data->x, data->y, data->width, data->height);
        }
    }
}

void Component_Animation::AddAnimation(AnimationState state, AnimationList& animationList)
{
    m_animations.insert(std::make_pair(state, animationList));

    if (m_currentAnimation.first == AnimationState::None)
    {
        SetAnimationState(state);
    }
}

void Component_Animation::SetAnimationState(AnimationState state)
{
    if (m_currentAnimation.first == state)
    {
        return;
    }

    auto animationList = m_animations.find(state);
    if (animationList != m_animations.end())
    {
        auto animation = animationList->second.find(m_currentDirection);

        if (animation != animationList->second.end())
        {
            m_currentAnimation.first = animationList->first;
            m_currentAnimation.second = animation->second;
            m_currentAnimation.second->Reset();
        }
    }
}

const AnimationState& Component_Animation::GetAnimationState() const
{
    return m_currentAnimation.first;
}

void Component_Animation::SetAnimationDirection(FacingDirection dir)
{
    if (dir != m_currentDirection)
    {
        m_currentDirection = dir;

        auto animationList = m_animations.find(m_currentAnimation.first);
        if (animationList != m_animations.end())
        {
            auto animation = animationList->second.find(m_currentDirection);

            if (animation != animationList->second.end())
            {
                m_currentAnimation.second = animation->second;
                m_currentAnimation.second->Reset();
            }
        }
    }
}