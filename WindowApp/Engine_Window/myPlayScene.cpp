#include "myPlayScene.h"
#include "myGameObject.h"
#include "myPlayer.h"
#include "myTransform.h"
#include "mySpriteRenderer.h"
#include "myInput.h"
#include "myTitleScene.h"
#include "mySceneManager.h"
#include "myObject.h"
#include "myTime.h"

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
		// Player 클래스의 인스턴스를 생성하고, 배경 레이어에 위치 (100.0f, 100.0f)로 배치
		bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(0.0f, 0.0f));

		// bg에 SpriteRenderer 컴포넌트 추가
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		// sr의 ImageLoad 함수를 호출하여 이미지 로드
		sr->ImageLoad(L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\sky.jpg");

		// 클라우드 클래스의 인스턴스를 4~10개 생성하고, 중간 레이어에 위치 (1600과 900 사이의 랜덤한 위치)로 배치
		for (int i = 0; i < 4 + rand() % 7; i++) // 4~10개의 클라우드를 생성
		{
			Cloud* cloud = object::Instantiate<Cloud>(enums::eLayerType::Middle, Vector2(rand() % 1600, rand() % 900));

			// cloud에 SpriteRenderer 컴포넌트 추가
			SpriteRenderer* cloudSr = cloud->AddComponent<SpriteRenderer>();

			// cloudSr의 ImageLoad 함수를 호출하여 이미지 로드
			cloudSr->ImageLoad(L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\Cloud2.png");
		}

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