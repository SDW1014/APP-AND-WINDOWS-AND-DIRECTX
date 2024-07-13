#include "myBulletGameObject.h"
#include "myTime.h"

namespace MyApp
{
	BulletGameObject::BulletGameObject()
		: GameObject()
		, mShow(false)
	{
	}
	BulletGameObject::~BulletGameObject()
	{
	}
	void BulletGameObject::Update()
	{
		static const float speed = 1000.0f;
		if(mShow)
			this->setPosition(this->GetpositionX(), this->GetpositionY() - speed * Time::DeltaTime());
		if(this->GetpositionY() < -100.0f)
			mShow = false;
	}
	void BulletGameObject::Render(HDC hdc)
	{
		if(mShow)
			Ellipse(hdc, 100 + this->GetpositionX(), 100 + this->GetpositionY(), 200 + this->GetpositionX(), 200 + this->GetpositionY());
	}
	void BulletGameObject::OnShow(float x, float y)
	{
		this->setPosition(x, y);
		SetShow();
	}
}
