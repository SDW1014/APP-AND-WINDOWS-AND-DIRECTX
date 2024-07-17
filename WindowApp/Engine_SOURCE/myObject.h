#pragma once
#include "myComponent.h"
#include "myGameObject.h"
#include "myLayer.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myTransform.h"


namespace MyApp::object
{
	// 템플릿 함수 Instantiate는 T라는 임시 타입으로 정의된 객체를 생성합니다.
	// 이 함수는 MyApp::enums::eLayerType 타입의 파라미터를 하나 받습니다.
	// 이 함수는 T 타입의 포인터를 반환합니다.
	// 이 함수는 T 타입의 객체를 생성하고, 현재 활성화된 씬의 지정된 레이어에 추가합니다.
	template <typename T>
	static T* Instantiate(MyApp::enums::eLayerType type)
	{
		// T 타입의 새로운 객체를 생성합니다.
		T* gameObject = new T();
		// 현재 활성화된 씬을 가져옵니다.
		Scene* activeScene = SceneManager::GetActiveScene();
		// 지정된 타입의 레이어를 가져옵니다.
		Layer* layer = activeScene->GetLayer(type);
		// 생성된 객체를 레이어에 추가합니다.
		layer->AddGameObject(gameObject);

		// 생성된 객체의 포인터를 반환합니다.
		return gameObject;
	}

	// 템플릿 함수 Instantiate는 T라는 임시 타입으로 정의된 객체를 생성합니다.
	// 이 함수는 MyApp::enums::eLayerType 타입의 파라미터와 math::Vector2 타입의 position 파라미터를 받습니다.
	// 이 함수는 T 타입의 포인터를 반환합니다.
	// 이 함수는 T 타입의 객체를 생성하고, 현재 활성화된 씬의 지정된 레이어에 추가합니다.
	// 또한, 생성된 객체의 위치를 지정된 position으로 설정합니다.
	template <typename T>
	static T* Instantiate(MyApp::enums::eLayerType type, math::Vector2 position)
	{
		// T 타입의 새로운 객체를 생성합니다.
		T* gameObject = new T();
		// 현재 활성화된 씬을 가져옵니다.
		Scene* activeScene = SceneManager::GetActiveScene();
		// 지정된 타입의 레이어를 가져옵니다.
		Layer* layer = activeScene->GetLayer(type);
		// 생성된 객체를 레이어에 추가합니다.
		layer->AddGameObject(gameObject);

		// 생성된 객체의 Transform 컴포넌트를 가져옵니다.
		Transform* tr = gameObject->GetComponent<Transform>();
		// 생성된 객체의 위치를 지정된 position으로 설정합니다.
		tr->SetPosition(position);

		// 생성된 객체의 포인터를 반환합니다.
		return gameObject;
	}
}