#pragma once
#include "CommonInclude.h"

namespace MyApp
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void setPosition(float x, float y);
		float GetpositionX();
		float GetpositionY();


	private:
		// 게임 오브젝트의 좌표
		float mX;
		float mY;
	};
}


