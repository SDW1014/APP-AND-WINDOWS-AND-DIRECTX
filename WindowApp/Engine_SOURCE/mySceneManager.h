#pragma once
#include "myScene.h"

// MyApp 네임스페이스 안에 SceneManager 클래스를 정의합니다.
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
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}
		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();


	//	static SceneManager& GetInst()
	//	{
	//		static SceneManager sceneManager;
	//		return sceneManager;
	//	}

	//private:
	//	SceneManager();
	//	~SceneManager();

	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};

	//static SceneManager sceneManager;
}
