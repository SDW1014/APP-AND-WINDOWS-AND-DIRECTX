#pragma once


namespace MyApp::enums
{
	enum class eComponentType
	{
		Transform,
		Colider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None, 
		BackGround,
		//Tree 
		//character
		Animal,
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,    // 텍스처 리소스
		AudioClip,  // 오디오 클립 리소스
		Animation,  // 애니메이션 리소스
		Prefab,     // 프리팹 리소스
		End,        // 리소스 종료
	};

}