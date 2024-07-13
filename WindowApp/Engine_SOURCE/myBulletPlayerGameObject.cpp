#include "myBulletPlayerGameObject.h"
#include "myInput.h"
#include "myTime.h"

namespace MyApp
{
	BulletPlayerGameObject::BulletPlayerGameObject()
		: GameObject(),
		mShotFunction(nullptr)
	{
	}

	BulletPlayerGameObject::~BulletPlayerGameObject()
	{
	}

	void BulletPlayerGameObject::Update()
	{
		const int speed = 100.0f;
		GameObject::Update();

		if (Input::GetKey(eKeyCode::X))
		{
			if(mShotFunction != nullptr)
			{
				mShotFunction();
			}
		}
	}

	void BulletPlayerGameObject::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
