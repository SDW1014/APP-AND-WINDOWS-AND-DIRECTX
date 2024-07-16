#pragma once
#include "myScene.h"

namespace MyApp
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			// 이미 활성화된 씬이 있으면 종료 함수를 호출합니다.
			if (mActiveScene)
				mActiveScene->OnExit();
				
			std::map<const std::wstring, Scene*>::iterator iter = mScene.find(name);

			if (iter == mScene.end())
				return nullptr;

			mActiveScene = iter->second;
			// 시작 함수를 호출합니다.
			mActiveScene->OnEnter();

			return mActiveScene;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		//static std::vector<Scene*> mScenes;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

