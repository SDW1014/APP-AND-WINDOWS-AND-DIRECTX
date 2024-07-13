#pragma once
#include "mySceneManager.h"
#include "myScene.h"

namespace MyApp
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
	};
}

