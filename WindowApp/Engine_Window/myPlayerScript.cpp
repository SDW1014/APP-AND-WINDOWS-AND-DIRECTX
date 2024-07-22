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
		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
        if (Input::GetKey(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void MyApp::PlayerScript::LateUpdate()
	{
	}

	void MyApp::PlayerScript::Render(HDC hdc)
	{
	}
}
