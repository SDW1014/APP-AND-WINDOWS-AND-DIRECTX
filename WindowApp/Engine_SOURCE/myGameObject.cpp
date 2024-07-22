#include "myGameObject.h"
#include "myInput.h"
#include "myTime.h"
#include "myTransform.h"

namespace MyApp
{
	// GameObject 클래스의 생성자
	GameObject::GameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::Script);
		initializeTransform();
	}

	// GameObject 클래스의 소멸자
	GameObject::~GameObject()
	{
		// 모든 컴포넌트를 삭제하고 메모리를 해제합니다.
		for (Component* comp : mComponents)
		{
			delete comp; // 컴포넌트 삭제
			comp = nullptr; // 포인터를 nullptr로 설정하여 안전하게 만듭니다.
		}
	}

	// GameObject를 초기화하는 메서드
	void GameObject::Initialize()
	{
		// 모든 컴포넌트를 초기화합니다.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize(); // 각 컴포넌트의 Initialize 메서드를 호출합니다.
		}
	}

	// 매 프레임마다 GameObject를 업데이트하는 메서드
	void GameObject::Update()
	{
		// 모든 컴포넌트를 업데이트합니다.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Update(); // 각 컴포넌트의 Update 메서드를 호출합니다.
		}
	}

	// 모든 업데이트가 끝난 후 호출되는 메서드
	void GameObject::LateUpdate()
	{
		// 모든 컴포넌트를 후처리 업데이트합니다.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->LateUpdate(); // 각 컴포넌트의 LateUpdate 메서드를 호출합니다.
		}
	}

	// GameObject를 렌더링하는 메서드
	void GameObject::Render(HDC hdc)
	{
		// 모든 컴포넌트를 렌더링합니다.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Render(hdc); // 각 컴포넌트의 Render 메서드를 호출합니다.
		}
	}
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}