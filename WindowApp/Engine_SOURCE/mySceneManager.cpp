#include "mySceneManager.h"

namespace MyApp
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	// 씬을 로드하는 함수입니다.
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

	// SceneManager를 초기화하는 함수입니다.
	void SceneManager::Initialize()
	{
	}

	// SceneManager를 업데이트하는 함수입니다.
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	// SceneManager를 늦게 업데이트하는 함수입니다.
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	// SceneManager를 렌더링하는 함수입니다.
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}