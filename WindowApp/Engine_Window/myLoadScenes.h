#pragma once
#include "..\\Engine_SOURCE\\mySceneManager.h"

#include "myPlayScene.h"
#include "myPlayScene_2.h"



namespace MyApp
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		// SceneManager::CreateScene<EndScene>(L"EndScene");
		// SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene_2>(L"PlayScene_2");

		SceneManager::LoadScene(L"PlayScene_2");
	}
}
