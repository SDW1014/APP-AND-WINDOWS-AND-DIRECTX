#pragma once
#include "..\\Engine_SOURCE\\myScript.h"

namespace MyApp
{
    class CatPlayerScript : public Script
    {
    public:
        CatPlayerScript();
        ~CatPlayerScript();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;
    private:
    };
}
