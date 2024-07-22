#include "myCamera.h"
#include "myGameObject.h"
#include "myTransform.h"

namespace MyApp
{
    Camera::Camera()
        : Component(enums::eComponentType::Camera)
        , mDistance(Vector2::Zero)
        , mResolution(Vector2(1600.0f, 900.0f))
        , mLookPostion(Vector2::Zero)
    {
    }

    Camera::~Camera()
    {
    }

    void Camera::Initialize()
    {
    }

    void Camera::Update()
    {
        if(mTarget)
        {
            Transform* tr = mTarget->GetComponent<Transform>();
            mLookPostion = tr->GetPosition();
        }

        Transform* cameraTr = GetOwner()->GetComponent<Transform>();
        mLookPostion = cameraTr->GetPosition();
        
        mDistance = mLookPostion - (mResolution / 2.0f);
    }

    void Camera::LateUpdate()
    {

    }

    void Camera::Render(HDC hdc)
    {
    }
}
