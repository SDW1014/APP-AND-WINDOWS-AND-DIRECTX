#include "mySceneManager.h"
#include "myInput.h"

namespace MyApp
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	
	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();

		if (Input::GetKeyDown(MyApp::eKeyCode::Q))
		{
			// 1번을 누른 경우의 코드
			SceneManager::LoadScene(L"PlayScene");
		}
		if (Input::GetKeyDown(MyApp::eKeyCode::W))
		{
			// 2번을 누른 경우의 코드
			SceneManager::LoadScene(L"PlayScene_2");
		}
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}