#pragma once

#include "Component.hpp"
#include "Animation.hpp"
#include "Component_Sprite.hpp"
#include "Logs.hpp"

enum class AnimationState {
	None,
	Idle,
	Walk
};

class Component_Animation : public Component {
public:
	/*
	* Constructor of Component Animation class,
	* Initialise all values of this class
	* @Param: Object* owner - pointer to owner of this Compontent
	* @Return: -
	*/
	Component_Animation(Object* owner);

	/*
	* Awake Method overriden from Compontent class
	* Gets the pointer to sprite compontent
	* @Param: -
	* @Return: -
	*/
	void Awake() override;

	/*
	* Update Method overriden from Compontent class
	* Method to update current animation - updates the sprite with new texture
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime) override;

	/*
	* AddAnimation method
	* Add the new animation to collection of animations
	* @Param: AnimatioNState state - state of Animation we want assign
	* @Param: std::shared_ptr<Animation> animation - animation we want to assign to state
	*/
	void AddAnimation(AnimationState state,
		std::shared_ptr<Animation> animation);

	/*
	* SetAnimationState method
	* Set the current animation state
	* @Param: AnimationState state - state of animation
	* @Return: -
	*/
	void SetAnimationState(AnimationState state);

	/*
	* GetAnimationState method
	* Returns current animation state
	* @Param: -
	* @Return: immutable current animation state
	*/
	const AnimationState& GetAnimationState() const;

	/*
	* SetAnimationDirection method
	* Set direction that player is moving (Left/Right)
	* @Param: FacingDirection dir - direction that player is facing
	* @Return: -
	*/
	void SetAnimationDirection(FacingDirection dir);

private:
	std::shared_ptr<Component_Sprite> m_sprite;
	std::map<AnimationState, std::shared_ptr<Animation>> m_animations
	std::pair<AnimationState, std::shared_ptr<Animation>> m_currentAnimation;

};