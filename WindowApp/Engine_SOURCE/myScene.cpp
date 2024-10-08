#include "myScene.h"

namespace MyApp
{
	// Scene 생성자
	Scene::Scene()
		: mLayers{}
	{
		// 모든 레이어를 생성합니다.
		createLayers();
	}
	// Scene 소멸자
	Scene::~Scene()
	{
		for ( Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}
	// Scene 초기화 함수
	void Scene::Initialize()
	{
		// 모든 레이어를 초기화합니다.
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}
	// Scene 업데이트 함수
	void Scene::Update()
	{
		// 모든 레이어를 업데이트합니다.
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}
	// Scene 늦은 업데이트 함수
	void Scene::LateUpdate()
	{
		// 모든 레이어의 늦은 업데이트를 호출합니다.
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}
	// Scene 렌더링 함수
	void Scene::Render(HDC hdc)
	{
		// 모든 레이어를 렌더링합니다.
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(hdc);
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	// 씬이 활성화될 때 호출되는 함수
	void Scene::OnEnter()
	{

	}

	// 씬이 비활성화될 때 호출되는 함수
	void Scene::OnExit()
	{

	}
}