#include "myLayer.h"


namespace MyApp
{
	// 생성자
	Layer::Layer()
		: mGameObjects{}
	{

	}
	// 소멸자
	Layer::~Layer()
	{

	}

	// 초기화 함수
	void Layer::Initialize()
	{
		for (GameObject* gameObj: mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}

	// 업데이트 함수
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}
	// 늦은 업데이트 함수
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}
	// 렌더링 함수
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(hdc);
		}
	}

	// 게임 오브젝트 추가 함수
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}