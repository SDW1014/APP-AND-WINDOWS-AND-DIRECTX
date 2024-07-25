#include "myRogueScript.h"
#include "myInput.h"
#include "myTransform.h"
#include "myTime.h"
#include "myGameObject.h"
#include "myAnimator.h"

namespace MyApp
{
	RogueScript::RogueScript()
	{
		mSpeed = Vector2(0.0f, 0.0f); // 초기 속도 설정
	}
	RogueScript::~RogueScript()
	{
	}
	void RogueScript::Initialize()
	{
	}
	void RogueScript::Update()
	{
		speedDownUpdate();
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Animator* at = GetOwner()->GetComponent<Animator>();
        Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			mSpeed.x += 5.0f; // 스피드를 더 빠르게 증가
			if (mSpeed.x > 100.0f) mSpeed.x = 100.0f; // 최대 100으로 제한
			// at->PlayAnimation(L"CatRightMove", true);
		}
        else if (Input::GetKey(eKeyCode::Left))
		{
			mSpeed.x -= 5.0f; // 스피드를 더 빠르게 감소
			if (mSpeed.x < -100.0f) mSpeed.x = -100.0f; // 최소 -100으로 제한
			// at->PlayAnimation(L"CatLeftMove", true);
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mSpeed.y += 5.0f; // 스피드를 더 빠르게 증가
			if (mSpeed.y > 100.0f) mSpeed.y = 100.0f; // 최대 100으로 제한
			// at->PlayAnimation(L"CatFrontMove", true);
		}
		else if (Input::GetKey(eKeyCode::Down))
		{
			mSpeed.y -= 5.0f; // 스피드를 더 빠르게 감소
			if (mSpeed.y < -100.0f) mSpeed.y = -100.0f; // 최소 -100으로 제한
			// at->PlayAnimation(L"CatBackMove", true);
		}
		pos.x += mSpeed.x * Time::DeltaTime(); // 시간에 따라 위치 업데이트
		pos.y += mSpeed.y * Time::DeltaTime(); // 시간에 따라 위치 업데이트

		tr->SetPosition(pos);
	}
	void RogueScript::LateUpdate()
	{
		
	}
	void RogueScript::Render(HDC hdc)
	{
	}
	void RogueScript::speedDownUpdate()
	{
		// 속도 감소 업데이트
		if (mSpeed.x > 0.0f) {
			mSpeed.x -= 2.0f; // 더 빠르게 감소
			if (mSpeed.x < 0.0f) mSpeed.x = 0.0f; // 0으로 설정
		} else if (mSpeed.x < 0.0f) {
			mSpeed.x += 2.0f; // 더 빠르게 증가
			if (mSpeed.x > 0.0f) mSpeed.x = 0.0f; // 0으로 설정
		}
		if (mSpeed.y > 0.0f) {
			mSpeed.y -= 2.0f; // 더 빠르게 감소
			if (mSpeed.y < 0.0f) mSpeed.y = 0.0f; // 0으로 설정
		} else if (mSpeed.y < 0.0f) {
			mSpeed.y += 2.0f; // 더 빠르게 증가
			if (mSpeed.y > 0.0f) mSpeed.y = 0.0f; // 0으로 설정
		}
	}
}
