#include "mySceneManager.h"

namespace MyApp
{
	// SceneManager 클래스의 정적 멤버 변수 mScene을 초기화합니다. 이 맵은 씬 이름과 씬 포인터를 저장합니다.
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	// SceneManager 클래스의 정적 멤버 변수 mActiveScene을 초기화합니다. 이 변수는 현재 활성화된 씬을 가리킵니다.
	Scene* SceneManager::mActiveScene = nullptr;
	
	// 씬을 로드하는 함수입니다.
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		// 현재 활성화된 씬이 있다면, OnExit 함수를 호출하여 씬을 비활성화합니다.
		if (mActiveScene)
			mActiveScene->OnExit();

		// mScene 맵에서 이름으로 씬을 찾습니다.
		std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);

		// 찾는 씬이 없다면 nullptr를 반환합니다.
		if (iter == mScene.end())
			return nullptr;

		// 찾은 씬을 활성화된 씬으로 설정하고 OnEnter 함수를 호출합니다.
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		// 활성화된 씬을 반환합니다.
		return iter->second;
	}

	// SceneManager를 초기화하는 함수입니다.
	void SceneManager::Initialize()
	{
	}
	// SceneManager를 업데이트하는 함수입니다.
	void SceneManager::Update()
	{
		// 활성화된 씬이 있다면, Update 함수를 호출합니다.
		mActiveScene->Update();
	}
	// SceneManager를 늦게 업데이트하는 함수입니다.
	void SceneManager::LateUpdate()
	{
		// 활성화된 씬이 있다면, LateUpdate 함수를 호출합니다.
		mActiveScene->LateUpdate();
	}
	// SceneManager를 렌더링하는 함수입니다.
	void SceneManager::Render(HDC hdc)
	{
		// 활성화된 씬이 있다면, Render 함수를 호출합니다.
		mActiveScene->Render(hdc);
	}
}