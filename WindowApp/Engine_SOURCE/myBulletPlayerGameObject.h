#pragma once

#include "myGameObject.h"

namespace MyApp
{
	typedef void (*voidFUnction)();

	class BulletPlayerGameObject : public GameObject
	{
	public:
		BulletPlayerGameObject();
		~BulletPlayerGameObject();

		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetShotFunction(voidFUnction funcPtr) { mShotFunction = funcPtr; }
	private:
		voidFUnction mShotFunction;
		
	};
}

