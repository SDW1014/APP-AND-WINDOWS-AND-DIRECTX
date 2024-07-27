#include "myRogueScript.h"
#include "myInput.h"
#include "myTransform.h"
#include "myTime.h"
#include "myGameObject.h"
#include "myAnimator.h"

namespace MyApp
{
	RogueScript::RogueScript()
		: mSpeed(Vector2(0.0f, 0.0f))
		, mIsRight(true)
	{
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
		UpdateAnimationBasedOnDirection();
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

	void RogueScript::UpdateAnimationBasedOnDirection()
	{
		Vector2 direction = mSpeed; // 현재 속도를 방향 벡터로 사용
		Animator* at = GetOwner()->GetComponent<Animator>();
		float length = sqrt(direction.x * direction.x + direction.y * direction.y); // 벡터의 길이 계산

		if (length > 0.0f) // 길이가 0보다 클 경우에만 단위 벡터로 변환
		{
			direction.x /= length; // x 성분을 단위 벡터로 변환
			direction.y /= length; // y 성분을 단위 벡터로 변환
		}

		float angle = atan2(direction.y, direction.x) * (180.0f / 3.14159265f); // 각도 계산

		if (length > 5.0f) {
			if (angle > -45.0f && angle < 45.0f) // 오른쪽
			{
				// 오른쪽 애니메이션 재생
				at->PlayAnimation(L"RogueRightMove", true);
				setIsRight(true);
			}
			else if (angle >= 135.0f || angle < -135.0f) // 왼쪽
			{
				// 왼쪽 애니메이션 재생
				at->PlayAnimation(L"RogueLeftMove", true);
				setIsRight(false);
			}
		} else {
			if (isRight()) // 오른쪽 스탠드
			{
				at->PlayAnimation(L"RogueRightStandMove1", true);
			}
			else // 왼쪽 스탠드
			{
				at->PlayAnimation(L"RogueLeftStandMove1", true);
			}
		}
	}
}
