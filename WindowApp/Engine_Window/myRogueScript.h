#pragma once
#include "..\\Engine_SOURCE\\myScript.h"

namespace MyApp
{
	class RogueScript : public Script
	{
		public:
			RogueScript();
			~RogueScript();

			virtual void Initialize() override;
			virtual void Update() override;
			virtual void LateUpdate() override;
			virtual void Render(HDC hdc) override;

			void speedDownUpdate();
			void UpdateAnimationBasedOnDirection();

			bool isRight() { return mIsRight; }
			void setIsRight(bool isRight) { mIsRight = isRight; }

		private:
			Vector2 mSpeed;
			bool mIsRight;
	};
}


