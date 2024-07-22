#pragma once
#include "myEntity.h"

namespace MyApp
{
	class GameObject; // 전방 선언: GameObject 클래스가 존재함을 알림

	// Component 클래스는 게임 객체의 컴포넌트로서 다양한 기능을 수행할 수 있도록 설계된 기본 클래스입니다.
	class Component : public Entity
	{
	public:
		// 생성자
		Component(enums::eComponentType type);
		
		// 소멸자
		~Component();

		// 컴포넌트를 초기화하는 가상 메서드
		virtual void Initialize();

		// 매 프레임마다 호출되는 가상 메서드
		virtual void Update();

		// 모든 업데이트가 끝난 후 호출되는 가상 메서드
		virtual void LateUpdate();

		// 객체를 렌더링하는 가상 메서드
		virtual void Render(HDC hdc);

		// 소유자(GameObject)를 설정하는 메서드
		void SetOwner(GameObject* owner) { mOwner = owner; }

		// 소유자(GameObject)를 반환하는 메서드
		GameObject* GetOwner() { return mOwner; }

		// 컴포넌트의 타입을 반환하는 메서드
		enums::eComponentType GetType() { return mType; }
	private:
		GameObject* mOwner; // 이 컴포넌트를 소유하는 게임 객체
		enums::eComponentType mType; // 컴포넌트의 타입
	};
}