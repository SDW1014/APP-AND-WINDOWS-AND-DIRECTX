#pragma once
#include "..\\Engine_SOURCE\\myResources.h"
#include "..\\Engine_SOURCE\\myTexture.h"

namespace MyApp
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"Cat", L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Rogue", L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources\\Rogue.bmp");
	}
}

// 2024-07-22에 카메라와 크기 조정 기능을 구분하기 위한 스크립트를 만들 예정이다. 
// 유니티를 사용해보면 스크립트의 개념을 이해할 수 있을 것이다. 