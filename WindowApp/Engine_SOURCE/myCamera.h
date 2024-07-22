#pragma once
#include "myComponent.h"

namespace MyApp
{
    using namespace MyApp::math;
    class Camera : public Component
    {
    public:
        Vector2 CaluatePostion(Vector2 pos) {return pos - mDistance;};

        Camera();
        ~Camera();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

    private:
        // std::vector<GameObject*> mGameObjects;
        class GameObject* mTarget;
        Vector2 mDistance;
        Vector2 mResolution;
        Vector2 mLookPostion;
    };
}

// 카메라는 물체를 바라보는 관점에서 
// 세상의 중심이 된다. 
// 게임 내에서 카메라가 상승하면, 
// 물체는 아래로 내려가야 한다. 
// 따라서 세상의 중심은 카메라이다.

