#pragma once
#include "..\\Engine_SOURCE\\myScript.h"

namespace MyApp
{
	class PlayerScript : public Script
	{
        public:
                PlayerScript();
                ~PlayerScript();

                virtual void Initialize() override;
                virtual void Update() override;
                virtual void LateUpdate() override;
                virtual void Render(HDC hdc) override;
        private:
	};
}

