#include "myLayer.h"


namespace MyApp
{
	// Layer 클래스의 생성자입니다. 초기화 리스트를 사용하여 mGameObjects 벡터를 초기화합니다.
	Layer::Layer()
		: mGameObjects{}
	{
		// 생성자 내부에서는 아무 작업도 수행하지 않습니다.
	}

	// Layer 클래스의 소멸자입니다. 소멸 시점에 필요한 리소스 해제를 수행합니다.
	Layer::~Layer()
	{
		// 소멸자 내부에서는 아무 작업도 수행하지 않습니다.
	}

	// Layer를 초기화하는 함수입니다. 모든 게임 오브젝트의 Initialize 함수를 호출합니다.
	void Layer::Initialize()
	{
		// mGameObjects 벡터에 저장된 모든 GameObject 포인터를 순회합니다.
		for (GameObject* gameObj: mGameObjects)
		{
			// nullptr인 경우를 제외하고 각 GameObject의 Initialize 함수를 호출합니다.
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}

	// Layer를 업데이트하는 함수입니다. 모든 게임 오브젝트의 Update 함수를 호출합니다.
	void Layer::Update()
	{
		// mGameObjects 벡터에 저장된 모든 GameObject 포인터를 순회합니다.
		for (GameObject* gameObj : mGameObjects)
		{
			// nullptr인 경우를 제외하고 각 GameObject의 Update 함수를 호출합니다.
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}

	// Layer의 늦은 업데이트를 처리하는 함수입니다. 모든 게임 오브젝트의 LateUpdate 함수를 호출합니다.
	void Layer::LateUpdate()
	{
		// mGameObjects 벡터에 저장된 모든 GameObject 포인터를 순회합니다.
		for (GameObject* gameObj : mGameObjects)
		{
			// nullptr인 경우를 제외하고 각 GameObject의 LateUpdate 함수를 호출합니다.
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}

	// Layer를 렌더링하는 함수입니다. 모든 게임 오브젝트의 Render 함수를 호출합니다.
	void Layer::Render(HDC hdc)
	{
		// mGameObjects 벡터에 저장된 모든 GameObject 포인터를 순회합니다.
		for (GameObject* gameObj : mGameObjects)
		{
			// nullptr인 경우를 제외하고 각 GameObject의 Render 함수를 호출합니다.
			if (gameObj == nullptr)
				continue;

			gameObj->Render(hdc);
		}
	}

	// Layer에 게임 오브젝트를 추가하는 함수입니다.
	void Layer::AddGameObject(GameObject* gameObject)
	{
		// 추가하려는 GameObject 포인터가 nullptr이면 아무것도 수행하지 않습니다.
		if (gameObject == nullptr)
			return;

		// GameObject 포인터를 mGameObjects 벡터에 추가합니다.
		mGameObjects.push_back(gameObject);
	}
}