#include "myGameObject.h"
#include "myInput.h"
#include "myTime.h"
#include "myTransform.h"

namespace MyApp::object
{
	void Destory(GameObject* gameObject)
	{
			if (gameObject != nullptr)
				gameObject->death();
	}
}

namespace MyApp
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
	}

		//SceneManager::GetInst().Update();
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}


	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}
