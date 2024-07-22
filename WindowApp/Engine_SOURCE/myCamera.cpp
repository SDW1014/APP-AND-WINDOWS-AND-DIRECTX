#include "myCamera.h"
#include "myGameObject.h"
#include "myTransform.h"
#include "myApplication.h"

extern MyApp::Application application;

namespace MyApp
{
    Camera::Camera()
        : Component(enums::eComponentType::Camera)
        , mDistance(Vector2::Zero)
        , mResolution(Vector2::Zero)
        , mLookPostion(Vector2::Zero)
        , mTarget(nullptr)
    {
    }

    Camera::~Camera()
    {
    }

    void Camera::Initialize()
    {
        mResolution.x = application.GetWidth();
        mResolution.y = application.GetHeight();
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
