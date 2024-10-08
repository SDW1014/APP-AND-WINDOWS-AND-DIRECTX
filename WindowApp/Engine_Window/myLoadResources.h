#pragma once
#include "..\\Engine_SOURCE\\myResources.h"
#include "..\\Engine_SOURCE\\myTexture.h"

namespace MyApp
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}

// 2024-07-22에 카메라와 크기 조정 기능을 구분하기 위한 스크립트를 만들 예정이다. 
// 유니티를 사용해보면 스크립트의 개념을 이해할 수 있을 것이다. 