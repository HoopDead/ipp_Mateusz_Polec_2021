#pragma once

#include <vector>
#include "Logs.hpp"

struct FrameData {
	//Handles the texture id
	int id;

	//Handles the x position of sprite in texture
	int x;

	//Handles the y position of sprite in texture
	int y;

	// Width of sprite
	int width;

	// Height of sprite
	int height;

	// How long we have to display the frame
	float displayTimeSeconds;
};

class Animation {
public:
	/*
	* Constructor of Animation class
	* Initialise the all private values of this class
	* @Param: -
	* @Return: -
	*/
	Animation();

	/*
	* AddFrame method
	* Push new frame to m_frames vector
	* @Param: int texutreID - ID of texture
	* @Param: int x - x position of sprite in texture
	* @Param: int y - y position of sprite in texture
	* @Param: int width - width of sprite
	* @Param: int height - height of sprite
	* @Param: float frameTime - how long we have to display the frame
	* @Return: -
	*/
	void AddFrame(int textureID, int x, int y,
		int width, int height, float frameTime);

	/*
	* FrameData method
	* Return pointer to frame that is displayed or nullptr
	* @Param: -
	* @Return: pointer to current fremt
	* OR
	* @Return: nullptr
	*/
	const FrameData* GetCurrentFrame() const;

	/*
	* UpdateFrame method
	* Check if it is time to transition to the next frame
	* @Param: deltaTime - time between each frame
	* @Return: True if it is time to transition
	* OR
	* @Return: False if it is not time to transition
	*/
	bool UpdateFrame(float deltaTime);

	/*
	* Reset Method
	* Reset animation to initial state
	* @Param: -
	* @Return: -
	*/
	void Reset();

private:
	/*
	* IncrementFrame method
	* increments the frame index by 1
	* @Param: -
	* @Return: -
	*/
	void IncrementFrame();

	std::vector<FrameData> m_frames;

	int m_currentFrameIndex;

	float m_currentFrameTime;
};