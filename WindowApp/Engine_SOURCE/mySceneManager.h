#pragma once
#include "myScene.h"

// MyApp 네임스페이스 안에 SceneManager 클래스를 정의합니다.
namespace MyApp
{
	// SceneManager 클래스를 정의합니다.
	class SceneManager
	{
	public:
		// 템플릿을 사용하여 Scene을 생성하는 CreateScene 함수를 정의합니다.
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			// T 타입의 scene을 생성합니다.
			T* scene = new T();
			// scene의 이름을 설정합니다.
			scene->SetName(name);
			// mActiveScene을 scene으로 설정합니다.
			mActiveScene = scene;
			// scene을 초기화합니다.
			scene->Initialize();

			// mScene에 scene을 삽입합니다.
			mScene.insert(std::make_pair(name, scene)));

			// scene을 반환합니다.
			return scene;
		}

		// Scene을 로드하는 LoadScene 함수를 정의합니다.
		static Scene* LoadScene(const std::wstring& name);
		// 활성 Scene을 가져오는 GetActiveScene 함수를 정의합니다.
		static Scene* GetActiveScene() { return mActiveScene; }

		// SceneManager를 초기화하는 Initialize 함수를 정의합니다.
		static void Initialize();
		// SceneManager를 업데이트하는 Update 함수를 정의합니다.
		static void Update();
		// SceneManager를 늦게 업데이트하는 LateUpdate 함수를 정의합니다.
		static void LateUpdate();
		// SceneManager를 렌더링하는 Render 함수를 정의합니다.
		static void Render(HDC hdc);

	private:
		// mScene을 정의합니다.
		static std::map<std::wstring, Scene*> mScene;
		// mActiveScene을 정의합니다.
		static Scene* mActiveScene;
	};
}
