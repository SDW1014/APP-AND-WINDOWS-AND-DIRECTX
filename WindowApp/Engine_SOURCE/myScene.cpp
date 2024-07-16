#include "myScene.h"

namespace MyApp
{
	// Scene 생성자
	Scene::Scene()
		: mLayers{}
	{
		// 모든 레이어를 생성합니다.
		CreateLayers();
	}
	// Scene 소멸자
	Scene::~Scene()
	{
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

	// 특정 레이어에 게임 오브젝트를 추가하는 함수
	void Scene::AddGameObject(GameObject* gameObj, const eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	// 모든 레이어를 생성하는 함수
	void Scene::CreateLayers()
	{
		// 모든 레이어 타입에 맞게 벡터의 크기를 조정합니다.
		mLayers.resize((UINT)eLayerType::Max);
		// 각 레이어를 생성합니다.
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
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