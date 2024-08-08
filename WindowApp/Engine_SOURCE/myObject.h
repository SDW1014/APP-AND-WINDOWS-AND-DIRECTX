#pragma once
#include "myComponent.h"
#include "myGameObject.h"
#include "myLayer.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myTransform.h"


namespace MyApp::object
{
	template <typename T>
	static T* Instantiate(MyApp::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(MyApp::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destory(GameObject* obj)
	{
		obj->Death();
	}
}