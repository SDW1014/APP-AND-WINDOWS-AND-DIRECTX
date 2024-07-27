#include "myAnimator.h"

namespace MyApp {
    Animator::Animator() 
        : Component(enums::eComponentType::Animator) // 부모 클래스의 생성자 호출
        , mAnimations {}
        , mActiveAnimation(nullptr)
        , mbLoop(false)
    {
    }

    Animator::~Animator()
    {
        // 애니메이션 메모리 해제 로직 추가 필요
    }

    void Animator::Initialize()
    {
        // 애니메이션 초기화 로직 추가 필요
    }

    void Animator::Update()
    {
        if(mActiveAnimation)
        {
            mActiveAnimation->Update();
            if(mActiveAnimation->IsComplete() == true && mbLoop == true)
            {
                mActiveAnimation->Reset();   
            }
        }
    }

    void Animator::LateUpdate()
    {
        // 애니메이션 후처리 로직 추가 필요
    }

    void Animator::Render(HDC hdc)
    {
        if(mActiveAnimation)
            mActiveAnimation->Render(hdc);  
    }
    void Animator::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
    {
        Animation* animation = nullptr;
        animation = FindAnimation(name);
        if(animation != nullptr)
            return;
        
        animation = new Animation();
        animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
        
        animation->SetAnimator(this);
        
        mAnimations.insert(std::make_pair(name, animation));
    }
    void Animator::CreateReverseAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
    {
        Animation* animation = nullptr;
        animation = FindAnimation(name);
        if(animation != nullptr)
            return;
        
        animation = new Animation();
        animation->CreateReverseAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
        
        animation->SetAnimator(this);
        
        mAnimations.insert(std::make_pair(name, animation));
    }
    Animation* Animator::FindAnimation(const std::wstring& name)
    {
        auto iter = mAnimations.find(name);
        if(iter != mAnimations.end())
            return iter->second;
        return nullptr;
    }
    void Animator::PlayAnimation(const std::wstring& name, bool loop)
    {
        Animation* animation = FindAnimation(name);

        if(animation == nullptr || animation == mActiveAnimation)
            return;

        mActiveAnimation = animation;
        mActiveAnimation->Reset();
        mbLoop = loop;
    }
} // namespace MyApp
