#include "myPlayer.h"
#include "myInput.h"
#include "myTransform.h"
#include "myTime.h"

namespace MyApp
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		// 2024-07-22
		// if (Input::GetKey(eKeyCode::Right))
		// {
		// 	Transform* tr = GetComponent<Transform>();
		// 	Vector2 pos = tr->GetPosition();
		// 	pos.x += 100.0f * Time::DeltaTime();
		// 	tr->SetPosition(pos);
		// }
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}