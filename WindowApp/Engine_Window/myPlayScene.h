#pragma once
#include "..\\Engine_SOURCE\\myScene.h"
namespace MyApp
{
	// PlayScene 클래스는 Scene 클래스를 상속합니다.
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

	private:
		class Player* mPlayer;
	};
}