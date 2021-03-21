#include "Component_Animation.hpp"
#include "Object.hpp"

Component_Animation::Component_Animation(Object* owner) : Component(owner), m_currentAnimation(AnimationState::None, nullptr)
{

}

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

void Component_Animation::AddAnimation(AnimationState state, std::shared_ptr<Animation> animation)
{
    auto inserted = m_animations.insert(std::make_pair(state, animation));

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

    auto animation = m_animations.find(state);
    if (animation != m_animations.end())
    {
        m_currentAnimation.first = animation->first;
        m_currentAnimation.second = animation->second;

        m_currentAnimation.second->Reset();
    }
}

const AnimationState& Component_Animation::GetAnimationState() const
{
    return m_currentAnimation.first;
}

void Component_Animation::SetAnimationDirection(FacingDirection dir) {
    if (m_currentAnimation.first != AnimationState::None) {
        m_currentAnimation.second->SetDirection(dir);
    }
}