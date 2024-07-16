#include "myTitleScene.h"
#include "myInput.h"
#include "myPlayScene.h"
#include "mySceneManager.h"

namespace MyApp
{
	// 생성자
	TitleScene::TitleScene()
	{
	}
	// 소멸자
	TitleScene::~TitleScene()
	{
	}
	// 초기화 함수
	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}
	// 업데이트 함수
	void TitleScene::Update()
	{
		Scene::Update();
	}
	// 늦은 업데이트 함수
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		// 'N' 키가 눌렸을 때 PlayScene으로 전환
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	// 렌더링 함수
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}