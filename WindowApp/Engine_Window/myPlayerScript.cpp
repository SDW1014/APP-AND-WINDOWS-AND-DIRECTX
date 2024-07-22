#include "myPlayerScript.h"
#include "myInput.h"
#include "myTransform.h"
#include "myTime.h"
#include "myGameObject.h"

namespace MyApp
{
	MyApp::PlayerScript::PlayerScript()
	{
	}

	MyApp::PlayerScript::~PlayerScript()
	{
	}

	void MyApp::PlayerScript::Initialize()
	{
	}

	void MyApp::PlayerScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
        if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);
	}

	void MyApp::PlayerScript::LateUpdate()
	{
	}

	void MyApp::PlayerScript::Render(HDC hdc)
	{
	}
}
