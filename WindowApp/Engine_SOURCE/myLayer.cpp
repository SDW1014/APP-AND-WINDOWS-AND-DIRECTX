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
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
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
			GameObject::eState state = gameObj->GetActive();
			if (state == GameObject::eState::Paused
				|| state == GameObject::eState::Dead)
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
			GameObject::eState state = gameObj->GetActive();
			if (state == GameObject::eState::Paused
				|| state == GameObject::eState::Dead)
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
			GameObject::eState state = gameObj->GetActive();
			if (state == GameObject::eState::Paused
				|| state == GameObject::eState::Dead)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (GameObjectIter iter = mGameObjects.begin()
			; iter != mGameObjects.end()
			; )
		{
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}