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
		// 2024-07-22 카메라와 게임 오브젝트를 초기화합니다.
		
		// 메인 카메라 생성
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.f, 442.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		

		// 플레이어 생성 및 초기화
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		// SpriteRenderer* playerRenderer = mPlayer->AddComponent<SpriteRenderer>();
		// playerRenderer->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();
		// playerRenderer->SetTexture(Resources::Find<graphics::Texture>(L"Cat"));
		graphics::Texture* packman = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", packman, Vector2::Zero, Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
		animator->PlayAnimation(L"CatFrontMove", true);

		// 배경 생성 및 초기화
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
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}