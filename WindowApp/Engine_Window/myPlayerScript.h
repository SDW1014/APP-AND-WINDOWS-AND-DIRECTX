#pragma once
#include "..\\Engine_SOURCE\\myScript.h"

namespace MyApp
{
	class PlayerScript : public Script
	{
        public:
                enum class eState
                        {
                                SitDown,
                                Walk,
                                Sleep,
                                Attack,
                        };
                PlayerScript();
                ~PlayerScript();

                virtual void Initialize() override;
                virtual void Update() override;
                virtual void LateUpdate() override;
                virtual void Render(HDC hdc) override;

        private:
                void sitDown();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}

