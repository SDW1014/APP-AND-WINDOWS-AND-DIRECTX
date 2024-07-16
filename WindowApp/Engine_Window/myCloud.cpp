#include "myCloud.h"
#include "myInput.h"
#include "myTransform.h"
#include "myTime.h"

namespace MyApp
{
    void Cloud::Initialize()
    {
        GameObject::Initialize();
        // 여기에 필요한 초기화 로직을 구현하세요.
    }

    void Cloud::Update()
    {
        GameObject::Update();
        Transform* transform = GetComponent<Transform>();
        if (transform)
        {
            // 클라우드의 이동 속도는 30에서 70 사이의 값으로 랜덤하게 설정
            float speed = 30.0f + static_cast<float>(rand() % 41);
            float newX = transform->GetPosition().x + speed * MyApp::Time::DeltaTime();
            if (newX > 1600)
            {
                newX = 0; // 오른쪽 끝에 도달하면 왼쪽으로 되돌아감
                // 상하 좌표를 900 사이의 값으로 랜덤하게 설정
                float newY = static_cast<float>(rand() % 900);
                transform->SetPosition(Vector2(newX, newY));
            }
            else
            {
                // 상하 좌표를 조금씩 왔다갔다 하도록 설정
                float newY = transform->GetPosition().y + (static_cast<float>(rand() % 21) - 10) * MyApp::Time::DeltaTime();
                transform->SetPosition(Vector2(newX, newY));
            }
        }
    }

    void Cloud::LateUpdate()
    {
        GameObject::LateUpdate();
        // 여기에 필요한 늦은 업데이트 로직을 구현하세요.
    }

    void Cloud::Render(HDC hdc)
    {
        GameObject::Render(hdc);
        // 여기에 필요한 렌더링 로직을 구현하세요.
    }
}