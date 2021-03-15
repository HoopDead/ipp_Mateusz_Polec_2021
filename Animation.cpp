#include "Animation.hpp"


Animation::Animation() : m_frames(0), m_currentFrameIndex(0), m_currentFrameTime(0.f)
{

}

void Animation::AddFrame(int textureID, int x, int y, int width, int height, float frameTime)
{
    FrameData data;
    data.id = textureID;
    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.displayTimeSeconds = frameTime;

    m_frames.push_back(data);
}

const FrameData* Animation::GetCurrentFrame() const
{
    if (m_frames.size() > 0)
    {
        return &m_frames[m_currentFrameIndex];
    }

    return nullptr;
}

bool Animation::UpdateFrame(float deltaTime)
{
    if (m_frames.size() > 0)
    {
        m_currentFrameTime += deltaTime;

        if (m_currentFrameTime >= m_frames[m_currentFrameIndex].displayTimeSeconds)
        {
            m_currentFrameTime = 0.f;
            IncrementFrame();
            return true;
        }
    }

    return false;
}

void Animation::IncrementFrame()
{
    if (m_currentFrameIndex == (m_frames.size() - 1))
    {
        m_currentFrameIndex = 0;
    }
    else
    {
        m_currentFrameIndex++;
    }
}

void Animation::Reset()
{
    m_currentFrameIndex = 0;
}
