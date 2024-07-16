#pragma once
#include "..\\Engine_SOURCE\\myGameObject.h"

namespace MyApp
{
	class Cloud : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		// 여기에 필요한 멤버 변수를 선언하세요.
	};
}
