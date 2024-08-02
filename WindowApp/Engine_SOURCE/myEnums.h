#pragma once


namespace MyApp::enums
{
	/**
	 * @brief 게임에서 사용되는 컴포넌트 타입을 정의합니다.
	 */
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End
	};

	/**
	 * @brief 게임에서 사용되는 레이어 타입을 정의합니다.
	 */
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

	/**
	 * @brief 게임에서 사용되는 리소스 타입을 정의합니다.
	 */
	enum class eResourceType
	{
		Texture,    // 텍스처 리소스
		AudioClip,  // 오디오 클립 리소스
		Animation,  // 애니메이션 리소스
		Prefab,     // 프리팹 리소스
		End,        // 리소스 종료
	};

}