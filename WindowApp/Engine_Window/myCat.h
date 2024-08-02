#pragma once
#include "..\\Engine_SOURCE\\myGameObject.h"

namespace MyApp
{

	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}