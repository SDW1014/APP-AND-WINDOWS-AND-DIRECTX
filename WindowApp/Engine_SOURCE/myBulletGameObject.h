#pragma once
#include "myGameObject.h"

namespace MyApp
{
	class BulletGameObject : public GameObject
	{
	public:
		BulletGameObject();
		~BulletGameObject();

		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void OnShow(float x, float y);
		void SetShow() { mShow = true; }
		void OffShow() { mShow = false; }
		bool IsShow() { return mShow; }
	private:
		bool mShow;
	};
}

