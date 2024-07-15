#include "mySceneManager.h"

namespace MyApp
{
	// 씬 이름과 씬 객체를 저장하는 맵
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	
	// 현재 활성화된 씬을 가리키는 포인터
	Scene* SceneManager::mActiveScene = nullptr;
	
	// 씬 매니저 초기화 함수
	void SceneManager::Initialize()
	{
		// 현재는 비어있음
	}
	
	// 씬 매니저 업데이트 함수
	void SceneManager::Update()
	{
		// 활성화된 씬의 Update 함수 호출
		mActiveScene->Update();
	}
	
	// 씬 매니저 LateUpdate 함수 
	void SceneManager::LateUpdate()
	{
		// 활성화된 씬의 LateUpdate 함수 호출
		mActiveScene->LateUpdate();
	}
	
	// 씬 매니저 렌더링 함수
	void SceneManager::Render(HDC hdc)
	{
		// 활성화된 씬의 Render 함수 호출
		mActiveScene->Render(hdc);
	}
}