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
		{
			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			
			sr->ImageLoad(L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\CloudOcean.png");


			AddGameObject(bg);
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