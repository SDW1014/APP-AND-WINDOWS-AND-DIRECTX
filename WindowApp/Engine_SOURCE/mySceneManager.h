#pragma once
#include "myScene.h"

// MyApp 네임스페이스 안에 SceneManager 클래스를 정의합니다.
namespace MyApp
{
	class SceneManager
	{
	public:
		// T 클래스의 인스턴스를 생성하여 씬으로 등록하는 함수입니다.
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
		// 이름으로 씬을 로드하는 함수입니다.
		static Scene* LoadScene(const std::wstring& name);
		// 현재 활성화된 씬을 반환하는 함수입니다.
		static Scene* GetActiveScene() { return mActiveScene; }

		// SceneManager를 초기화하는 함수입니다.
		static void Initialize();
		// SceneManager를 업데이트하는 함수입니다.
		static void Update();
		// SceneManager를 늦게 업데이트하는 함수입니다.
		static void LateUpdate();
		// SceneManager를 렌더링하는 함수입니다.
		static void Render(HDC hdc);

	private:
		// 씬 이름과 씬 포인터를 저장하는 맵입니다.
		static std::map<std::wstring, Scene*> mScene;
		// 현재 활성화된 씬을 가리키는 포인터입니다.
		static Scene* mActiveScene;
	};
}
