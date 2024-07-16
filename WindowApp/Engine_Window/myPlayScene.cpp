#include "myPlayScene.h"
#include "myGameObject.h"
#include "myPlayer.h"
#include "myTransform.h"
#include "mySpriteRenderer.h"
#include "myInput.h"
#include "myTitleScene.h"
#include "mySceneManager.h"
#include "myObject.h"

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
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"E:\\AR50\\YamYam_Engine\\Resources\\CloudOcean.png");

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();
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
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPos(Vector2(0, 0));
	}
}