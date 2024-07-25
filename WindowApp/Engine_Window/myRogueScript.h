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

		private:
			Vector2 mSpeed;
	};
}


