#include "myPlayScene.h"
#include "myGameObject.h"
#include "myPlayer.h"
#include "myTransform.h"
#include "mySpriteRenderer.h"
#include "myInput.h"
#include "myTitleScene.h"
#include "mySceneManager.h"

namespace MyApp
{
	// 생성자와 소멸자
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}

	// 초기화 함수
	void PlayScene::Initialize()
	{
		// 플레이어 게임 오브젝트 생성 및 초기화
		bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\CloudOcean.png");

		AddGameObject(bg, eLayerType::BackGround);
	}

	// 업데이트 함수
	void PlayScene::Update()
	{
		Scene::Update();
	}

	// 늦은 업데이트 함수
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		// 'N' 키를 누르면 제목 씬으로 로드
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	// 렌더링 함수
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	// 씬 진입 함수
	void PlayScene::OnEnter()
	{
	}

	// 씬 퇴장 함수
	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}