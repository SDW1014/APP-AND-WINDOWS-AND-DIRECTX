#pragma once
#include "..\\Engine_SOURCE\\mySceneManager.h"

#include "myPlayScene.h"
#include "myTitleScene.h"



namespace MyApp
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		// SceneManager::CreateScene<EndScene>(L"EndScene");
		

		SceneManager::LoadScene(L"PlayScene");
	}
}
