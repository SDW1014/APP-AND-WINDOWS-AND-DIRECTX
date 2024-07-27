#include "myPlayScene.h"
#include "myGameObject.h"
#include "myPlayer.h"
#include "myTransform.h"
#include "mySpriteRenderer.h"
#include "myInput.h"
#include "myTitleScene.h"
#include "mySceneManager.h"
#include "myObject.h"
#include "myTexture.h"
#include "myResources.h"
#include "myPlayerScript.h"
#include "myCamera.h"
#include "myRenderer.h"
#include "myAnimator.h"
#include "myCatPlayerScript.h"
#include "myRogueScript.h"

namespace MyApp
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		/// @brief 카메라와 게임 오브젝트를 초기화합니다.
		
		// 메인 카메라 생성
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.f, 442.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		/// @brief 플레이어 생성 및 초기화
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);

		Animator* animator = mPlayer->AddComponent<Animator>();
        graphics::Texture* rogueTexture = Resources::Find<graphics::Texture>(L"Rogue");

        animator->CreateAnimation(L"RogueRightStandMove1", rogueTexture, Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::Zero, 10, 0.2f);
		animator->CreateAnimation(L"RogueRightStandMove2", rogueTexture, Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::Zero, 10, 0.2f);
		animator->CreateReverseAnimation(L"RogueLeftStandMove1", rogueTexture, Vector2(0.f, 32.f * 10.f), Vector2(32.f, 32.f), Vector2::Zero, 10, 0.2f);
		animator->CreateAnimation(L"RogueRightMove", rogueTexture, Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::Zero, 10, 0.2f);
		animator->CreateReverseAnimation(L"RogueLeftMove", rogueTexture, Vector2(0.f, 32.f * 12.f), Vector2(32.f, 32.f), Vector2::Zero, 10, 0.2f);
        animator->PlayAnimation(L"RogueLeftStandMove1", true);

		mPlayer->AddComponent<RogueScript>();
		
		

		/// @brief 배경 생성 및 초기화
		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRenderer* bgRenderer = bg->AddComponent<SpriteRenderer>();
		bgRenderer->SetSize(Vector2(3.0f, 3.0f));
		bgRenderer->SetTexture(Resources::Find<graphics::Texture>(L"Map"));
		
		// 게임 오브젝트 생성 후 초기화 호출
		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
	}
}