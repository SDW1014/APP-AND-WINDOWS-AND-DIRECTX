#include "myPlayScene.h"
#include "myGameObject.h"
#include "myPlayer.h"
#include "myTransform.h"
#include "mySpriteRenderer.h"
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
		
		
		//for (size_t i = 0; i < 100; i++)
		//{
		//	GameObject* obj = new GameObject();
		//	obj->SetPosition(rand() % 1600, rand() 900);
		//	AddGameObject(obj);
		//}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>(); // AddComponent<Transform>()는 Transform 컴포넌트를 생성하고 Player 객체에 추가합니다.
			tr->SetPos(800, 450); // Transform 컴포넌트의 위치 설정
			tr->SetName(L"TR"); // Transform 컴포넌트의 이름 설정

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>(); // AddComponent<SpriteRenderer>()는 SpriteRenderer 컴포넌트를 생성하고 Player 객체에 추가합니다.
			sr->SetName(L"SR"); // SpriteRenderer 컴포넌트의 이름 설정

			AddGameObject(pl);
		}
		
		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(300, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(100, 650);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}