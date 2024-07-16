#pragma once
#include "..\\Engine_SOURCE\\myScene.h"
namespace MyApp
{
	// PlayScene 클래스는 Scene 클래스를 상속합니다.
	class PlayScene : public Scene
	{
	public:
		// 생성자와 소멸자를 정의합니다.
		PlayScene();
		~PlayScene();

		// Scene 클래스의 가상 함수를 재정의합니다.
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		// OnEnter와 OnExit 함수를 재정의합니다.
		void OnEnter() override;
		void OnExit()  override;

	private:
		// Player 클래스의 포인터를 멤버 변수로 선언합니다.
		class Player* bg;
	};
}