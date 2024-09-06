#pragma once
#include "..\\Engine_SOURCE\\myScene.h"

namespace MyApp
{
    // TitleScene 클래스: Scene을 상속받는 타이틀 씬 클래스
    class TitleScene : public Scene
    {
    public:
        // 생성자
        TitleScene();
        // 소멸자
        ~TitleScene();

        // 초기화 함수
        void Initialize() override;
        // 업데이트 함수
        void Update() override;
        // 늦은 업데이트 함수
        void LateUpdate() override;
        // 렌더링 함수
        void Render(HDC hdc) override;

        void OnEnter() override;
		void OnExit() override;

    private:

    };
}