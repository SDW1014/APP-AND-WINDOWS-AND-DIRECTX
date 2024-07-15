#pragma once
#include "..\\Engine_SOURCE\\myScene.h"

namespace MyApp
{
    class PlayScene_2 : public Scene
    {
    public:
        PlayScene_2();
        ~PlayScene_2();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;
    };
}