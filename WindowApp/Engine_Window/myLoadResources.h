#pragma once
#include "..\\Engine_SOURCE\\myResources.h"
#include "..\\Engine_SOURCE\\myTexture.h"

namespace MyApp
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Resources\\CloudOcean.png");
	}
}