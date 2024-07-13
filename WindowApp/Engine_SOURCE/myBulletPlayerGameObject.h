#pragma once

#include "myGameObject.h"
#include <functional>

namespace MyApp
{
	using voidFunction = std::function<void()>;

	class BulletPlayerGameObject : public GameObject
	{
	public:
		BulletPlayerGameObject();
		~BulletPlayerGameObject();

		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetShotFunction(voidFunction funcPtr) { mShotFunction = funcPtr; }
	private:
		voidFunction mShotFunction;
	};
}

