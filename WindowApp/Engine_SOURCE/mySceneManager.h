#pragma once
#include "mySceneManager.h"
#include "myScene.h"

namespace MyApp
{
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));
		}

		SceneManager();
		~SceneManager();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		//static std::vector<Scene*> mScenes;
		static std::map<const std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

