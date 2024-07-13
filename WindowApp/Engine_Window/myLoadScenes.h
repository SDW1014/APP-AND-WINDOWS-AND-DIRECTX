#pragma once
#include "mySceneManager.h"
#include "myPlayScene.h"

namespace MyApp
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		// SceneManager::CreateScene<EndScene>(L"EndScene");
		// SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}
