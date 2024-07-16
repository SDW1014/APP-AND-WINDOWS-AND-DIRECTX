#pragma once
#include "myEntity.h" // Entity 클래스를 포함합니다.
#include "CommonInclude.h" // 공통 포함 파일을 포함합니다.
#include "myGameObject.h" // GameObject 클래스를 포함합니다.

namespace MyApp
{
	// Layer 클래스는 Entity를 상속받습니다. 레이어를 나타내는 클래스입니다.
	class Layer : public Entity
	{
	public:
		// Layer 클래스의 생성자입니다.
		Layer();
		// Layer 클래스의 소멸자입니다.
		~Layer();

		// Layer를 초기화하는 함수입니다.
		virtual void Initialize();
		// Layer를 업데이트하는 함수입니다.
		virtual void Update();
		// Layer의 늦은 업데이트를 처리하는 함수입니다.
		virtual void LateUpdate();
		// Layer를 렌더링하는 함수입니다.
		virtual void Render(HDC hdc);

		// Layer에 게임 오브젝트를 추가하는 함수입니다.
		void AddGameObject(GameObject* gameObject);

	private:
		// Layer의 타입을 나타내는 변수입니다. (현재 사용하지 않음)
		//eLayerType mType;
		// Layer에 속한 게임 오브젝트들을 저장하는 벡터입니다.
		std::vector<GameObject*> mGameObjects;
	};
}