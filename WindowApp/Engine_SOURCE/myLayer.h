#pragma once
#include "myEntity.h"
#include "CommonInclude.h"
#include "myGameObject.h"

namespace MyApp
{
	// Layer 클래스: Entity를 상속받는 레이어 클래스
	class Layer : public Entity
	{
	public:
		// 생성자
		Layer();
		// 소멸자
		~Layer();

		// 초기화 함수
		virtual void Initialize();
		// 업데이트 함수
		virtual void Update();
		// 늦은 업데이트 함수
		virtual void LateUpdate();
		// 렌더링 함수
		virtual void Render(HDC hdc);

		// 게임 오브젝트 추가 함수
		void AddGameObject(GameObject* gameObject);

	private:
		// 레이어 타입
		//eLayerType mType;
		// 게임 오브젝트 벡터
		std::vector<GameObject*> mGameObjects;
	};
}