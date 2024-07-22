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
		// 2024-07-22 카메라를 만들어 보자 
		// There is Main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.f, 442.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		

		//게임오브젝트 만들기전에 리소스들 전부 Load해두면 좋다.
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));

		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"PackMan");
		sr->SetTexture(packmanTexture);

		//게임오브젝트 만들기전에 리소스들 전부 Load해두면 좋다.
		GameObject* bg = object::Instantiate<Player>(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);
		
		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
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