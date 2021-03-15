#include "SceneGame.hpp"

SceneGame::SceneGame(ResourceAllocator<sf::Texture>& textureAllocator) :
	m_textureAllocator(textureAllocator) {
	Log("Called Scene Game Constructor");
}

void SceneGame::OnCreate() {
    std::shared_ptr<Object> player = std::make_shared<Object>();

    auto sprite = player->AddComponent<Component_Sprite>();
    sprite->SetTextureAllocator(&m_textureAllocator);

    auto movement = player->AddComponent<Component_KeyboardMovement>();
    movement->SetInput(&input);

    auto animation = player->AddComponent<Component_Animation>();

    int vikingTextureID = m_textureAllocator.Add("Graphics/sprites/Viking.png");

    const int frameWidth = 165;
    const int frameHeight = 145;

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>();
    const float idleAnimFrameSeconds = 0.2f;
    idleAnimation->AddFrame(vikingTextureID, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    animation->AddAnimation(AnimationState::Idle, idleAnimation);

    m_objects.Add(player);
}

void SceneGame::OnDestroy() {}

void SceneGame::ProcessInput() {
	input.Update();
}

void SceneGame::Update(float deltaTime) {
	m_objects.ProcessRemoval();
	m_objects.ProcessNewObjects();
	m_objects.Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime) {
	m_objects.LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window) {
	m_objects.Draw(window);
}

SceneGame::~SceneGame() {
	Log("Called Scene Game Destructor");
}