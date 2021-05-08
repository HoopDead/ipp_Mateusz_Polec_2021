#include "SceneGame.hpp"

SceneGame::SceneGame(ResourceAllocator<sf::Texture>& textureAllocator, Window& window, std::shared_ptr<Input> input) :
	m_textureAllocator(textureAllocator), m_window(window), m_input(input) {
	Log("Called Scene Game Constructor");
}

void SceneGame::OnCreate() {

    //Map Loading Section
    m_mapRenderer = std::make_shared<MapRenderer>();
    m_mapRenderer->Awake();

    CreatePlayer();

}

void SceneGame::OnDestroy() {}

void SceneGame::ProcessInput() {
	m_input->Update();
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
    m_mapRenderer->DrawLayersBelow(window);
	m_objects.Draw(window);
    m_mapRenderer->DrawLayersAbove(window);

}

void SceneGame::CreatePlayer() {

    //Player loader section
    std::shared_ptr<Object> player = std::make_shared<Object>(); //Move to class member?

    auto sprite = player->AddComponent<Component_Sprite>();
    sprite->SetTextureAllocator(&m_textureAllocator);

    auto movement = player->AddComponent<Component_KeyboardMovement>();
    movement->SetInput(m_input);

    auto transform = player->AddComponent<Component_Transform>();

    auto collision = player->AddComponent<Component_MapCollision>();
    collision->SetLayer(m_mapRenderer->GetCollisionLayer());


    auto animation = player->AddComponent<Component_Animation>();

    int playerTextureID = m_textureAllocator.Add("Graphics/sprites/ShibaInu.png");

    const int frameWidth = 32;
    const int frameHeight = 32;

    const int downYFramePos = 0;
    const int upYFramePos = 32;
    const int rightYFramePos = 64;
    const int leftYFramePos = 96;


    /*===================
        IDLE ANIMATIONS
    =====================*/
    std::map<FacingDirection, std::shared_ptr<Animation>> idleAnimations;

    std::shared_ptr<Animation> idleDownAnimation = std::make_shared<Animation>();
    idleDownAnimation->AddFrame(playerTextureID, 0, downYFramePos, frameWidth, frameHeight, 0.f);
    idleAnimations.insert(std::make_pair(FacingDirection::Down, idleDownAnimation));

    std::shared_ptr<Animation> idleUpAnimation = std::make_shared<Animation>();
    idleUpAnimation->AddFrame(playerTextureID, 0, upYFramePos, frameWidth, frameHeight, 0.f);
    idleAnimations.insert(std::make_pair(FacingDirection::Up, idleUpAnimation));

    std::shared_ptr<Animation> idleRightAnimation = std::make_shared<Animation>();
    idleRightAnimation->AddFrame(playerTextureID, 0, rightYFramePos, frameWidth, frameHeight, 0.f);
    idleAnimations.insert(std::make_pair(FacingDirection::Right, idleRightAnimation));

    std::shared_ptr<Animation> idleLeftAnimation = std::make_shared<Animation>();
    idleLeftAnimation->AddFrame(playerTextureID, 0, leftYFramePos, frameWidth, frameHeight, 0.f);
    idleAnimations.insert(std::make_pair(FacingDirection::Left, idleLeftAnimation));


    animation->AddAnimation(AnimationState::Idle, idleAnimations);

    /*===================
        WALK ANIMATIONS
    =====================*/
    const int walkingFrameCount = 9;
    const float delayBetweenWalkingFramesSecs = 0.1f;

    std::map<FacingDirection, std::shared_ptr<Animation>> walkingAnimations;

    std::shared_ptr<Animation> walkDownAnimation = std::make_shared<Animation>();
    for (int i = 0; i < walkingFrameCount; i++)
    {
        walkDownAnimation->AddFrame(playerTextureID, i * frameWidth, downYFramePos, frameWidth, frameHeight, delayBetweenWalkingFramesSecs);
    }
    walkingAnimations.insert(std::make_pair(FacingDirection::Down, walkDownAnimation));

    std::shared_ptr<Animation> walkUpAnimation = std::make_shared<Animation>();
    for (int i = 0; i < walkingFrameCount; i++)
    {
        walkUpAnimation->AddFrame(playerTextureID, i * frameWidth, upYFramePos, frameWidth, frameHeight, delayBetweenWalkingFramesSecs);
    }
    walkingAnimations.insert(std::make_pair(FacingDirection::Up, walkUpAnimation));

    std::shared_ptr<Animation> walkRightAnimation = std::make_shared<Animation>();
    for (int i = 0; i < walkingFrameCount; i++)
    {
        walkRightAnimation->AddFrame(playerTextureID, i * frameWidth, rightYFramePos, frameWidth, frameHeight, delayBetweenWalkingFramesSecs);
    }
    walkingAnimations.insert(std::make_pair(FacingDirection::Right, walkRightAnimation));

    std::shared_ptr<Animation> walkLeftAnimation = std::make_shared<Animation>();
    for (int i = 0; i < walkingFrameCount; i++)
    {
        walkLeftAnimation->AddFrame(playerTextureID, i * frameWidth, leftYFramePos, frameWidth, frameHeight, delayBetweenWalkingFramesSecs);
    }
    walkingAnimations.insert(std::make_pair(FacingDirection::Left, walkLeftAnimation));



    animation->AddAnimation(AnimationState::Walk, walkingAnimations);


    auto boxCollider = player->AddComponent<Component_BoxCollider>();
    boxCollider->SetCollidable(sf::FloatRect(0, 0, 32, 32));

    auto camera = player->AddComponent<Component_Camera>();
    camera->SetWindow(&m_window);

    player->AddComponent<Component_Velocity>();
    player->AddComponent<Component_MovementAnimation>();

    m_objects.Add(player);

}

SceneGame::~SceneGame() {
	Log("Called Scene Game Destructor");
}