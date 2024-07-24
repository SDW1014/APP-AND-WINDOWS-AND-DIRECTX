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
		/// @brief 카메라와 게임 오브젝트를 초기화합니다.
		
		// 메인 카메라 생성
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.f, 442.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		/// @brief 플레이어 생성 및 초기화
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		
		graphics::Texture* TheCat = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", TheCat, Vector2::Zero, Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
		animator->CreateAnimation(L"CatRightMove", TheCat, Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
		animator->CreateAnimation(L"CatBackMove", TheCat, Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
		animator->CreateAnimation(L"CatLeftMove", TheCat, Vector2(0.f, 96.f), Vector2(32.f, 32.f), Vector2::Zero, 4, 0.5f);
		animator->PlayAnimation(L"CatFrontMove", true);

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
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mPlayer->GetComponent<Animator>()->PlayAnimation(L"CatRightMove", true);
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			mPlayer->GetComponent<Animator>()->PlayAnimation(L"CatLeftMove", true);
		}
		else if (Input::GetKeyDown(eKeyCode::Up))
		{
			mPlayer->GetComponent<Animator>()->PlayAnimation(L"CatFrontMove", true);
		}
		else if (Input::GetKeyDown(eKeyCode::Down))
		{
			mPlayer->GetComponent<Animator>()->PlayAnimation(L"CatBackMove", true);
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