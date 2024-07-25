#include "myCatPlayerScript.h"
#include "myInput.h"
#include "myTransform.h"
#include "myTime.h"
#include "myGameObject.h"
#include "myAnimator.h"
#include "myResources.h"
#include "myTexture.h"

namespace MyApp
{
    CatPlayerScript::CatPlayerScript()
    {
    }

    CatPlayerScript::~CatPlayerScript()
    {
    }

    void CatPlayerScript::Initialize()
    {
    }

    void CatPlayerScript::Update()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
		Animator* at = GetOwner()->GetComponent<Animator>();
        Vector2 pos = tr->GetPosition();

		// if (Input::GetKey(eKeyCode::Right))
		// {
		// 	pos.x += 100.0f * Time::DeltaTime();
        //     at->PlayAnimation(L"CatRightMove", true);
		// }
        // if (Input::GetKey(eKeyCode::Left))
		// {
		// 	pos.x -= 100.0f * Time::DeltaTime();
        //     at->PlayAnimation(L"CatLeftMove", true);
		// }
		// if (Input::GetKey(eKeyCode::Up))
		// {
		// 	pos.y += 100.0f * Time::DeltaTime();
        //     at->PlayAnimation(L"CatFrontMove", true);
		// }
		// if (Input::GetKey(eKeyCode::Down))
		// {
		// 	pos.y -= 100.0f * Time::DeltaTime();
        //     at->PlayAnimation(L"CatBackMove", true);
            
		// }
		tr->SetPosition(pos);
    }

    void CatPlayerScript::LateUpdate()
    {
    }

    void CatPlayerScript::Render(HDC hdc)
    {
    }
}
