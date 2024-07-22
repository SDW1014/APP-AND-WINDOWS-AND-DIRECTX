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
		Script,
		Camera,
		End
	};

	/**
	 * @brief 게임에서 사용되는 레이어 타입을 정의합니다.
	 */
	enum class eLayerType
	{
		None,		// 아무것도 없는 상태
		BackGround, // 배경 레이어
		//Tree 		// 나무 레이어
		//character // 캐릭터 레이어
		Player,		// 플레이어 레이어
		Max = 16,	// 최대 레이어 수
	};

	/**
	 * @brief 게임에서 사용되는 리소스 타입을 정의합니다.
	 */
	enum class eResourceType
	{
		Texture,    // 텍스처 리소스
		AudioClip,  // 오디오 클립 리소스
		Prefab,     // 프리팹 리소스
		End,        // 리소스 종료
	};

}