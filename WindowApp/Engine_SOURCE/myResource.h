#pragma once
#include "myEntity.h"
namespace MyApp
{
    /**
     * @brief 리소스를 나타내는 클래스입니다.
     * 이 클래스는 Entity를 상속받습니다.
     */
    class Resource : public Entity
    {
    public:
        /**
         * @brief 생성자
         * @param type 리소스의 타입
         * @param path 리소스의 경로
         */
        Resource(enums::eResourceType type, const std::wstring& path)
            : mType(type), mPath(path) {}
        /**
         * @brief 소멸자
         */
        virtual ~Resource() {}

        /**
         * @brief 리소스의 타입을 반환합니다.
         * @return 리소스의 타입
         */
        enums::eResourceType GetType() const { return mType; }
        /**
         * @brief 리소스의 경로를 반환합니다.
         * @return 리소스의 경로
         */
        const std::wstring& GetPath() const { return mPath; }

    private:
        enums::eResourceType mType;             // 리소스 타입
        std::wstring mPath;                     // 리소스 경로
    };
}

// 게임에서 사용되는 다양한 데이터 종류를 정의하는 클래스입니다.
// 예를 들어 이미지, 사운드, 저장된 게임 플레이 데이터(HDD, 클라우드 저장 포함) 등이 있습니다.
// 이러한 모든 데이터를 리소스라고 간주할 수 있습니다.
