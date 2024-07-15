#include "myPlayScene_2.h"
#include "myGameObject.h"
#include "myPlayer.h"
#include "myTransform.h"
#include "mySpriteRenderer.h"

namespace MyApp
{
    PlayScene_2::PlayScene_2()
    {
    }

    PlayScene_2::~PlayScene_2()
    {
    }

    void PlayScene_2::Initialize()
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

    void PlayScene_2::Update()
    {
        Scene::Update();
    }

    void PlayScene_2::LateUpdate()
    {
        Scene::LateUpdate();
    }

    void PlayScene_2::Render(HDC hdc)
    {
        Scene::Render(hdc);
        Ellipse(hdc, 0, 0, 100, 100);
    }
}