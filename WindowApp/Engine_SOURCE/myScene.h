#pragma once
#include "myEntity.h" // 엔티티 클래스
#include "myGameObject.h" // 게임 오브젝트 클래스
#include "myLayer.h" // 레이어 클래스

namespace MyApp
{
	// Scene 클래스 정의
	class Scene : public Entity
	{
	public:
		// 생성자
		Scene();
		// 소멸자
		~Scene();

		// 초기화 함수
		virtual void Initialize();
		// 업데이트 함수
		virtual void Update();
		// 늦은 업데이트 함수
		virtual void LateUpdate();
		// 렌더링 함수
		virtual void Render(HDC hdc);

		// 씬 진입 시 호출
		virtual void OnEnter();
		// 씬 퇴장 시 호출
		virtual void OnExit();

		// 게임 오브젝트 추가 함수
		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		
		// 레이어 가져오는 함수
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		// 레이어 생성 함수
		void createLayers();

	private:
		// 레이어 벡터
		std::vector<Layer*> mLayers;
	};
}
