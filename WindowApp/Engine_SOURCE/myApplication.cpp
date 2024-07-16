#include "myApplication.h"
#include "myInput.h"
#include "myTime.h"
#include "mySceneManager.h"

namespace MyApp
{
    // 1. Application 생성자
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mWidth(0)
        , mHeight(0)
        , mBackHdc(nullptr)
        , mBackBitmap(nullptr)
    {
    }

    // 2. Application 소멸자
    Application::~Application()
    {
    }

    // 3. Initialize 함수
    void Application::Initialize(HWND hwnd, UINT width, UINT height)
    {
        // 3.1. 윈도우 설정 및 초기화
        adjustWindowRect(hwnd, width, height);
        createBuffer(width, height);
        initializeEtc();

        // 3.2. SceneManager 초기화
        SceneManager::Initialize();
    }

    // 4. Run 함수 (게임 루프)
    void Application::Run()
    {
        // 4.1. Update 함수 호출
        Update();
        // 4.2. LateUpdate 함수 호출
        LateUpdate();
        // 4.3. Render 함수 호출
        Render();
    }

    // 5. Update 함수
    void Application::Update()
    {
        // 5.1. 입력 업데이트
        Input::Update();
        // 5.2. 시간 업데이트
        Time::Update();

        // 5.3. SceneManager를 통한 현재 씬 업데이트
        SceneManager::Update();
    }

    // 6. LateUpdate 함수 (현재 비어있음)
    void Application::LateUpdate()
    {
        SceneManager::LateUpdate();
    }

    // 7. Render 함수
    void Application::Render()
    {
        // 7.1. 렌더링 시작
        clearRenderTarget();

        // 7.2. 시간 정보 렌더링
        Time::Render(mBackHdc);

        // 7.3. SceneManager를 통한 현재 씬 렌더링
        SceneManager::Render(mBackHdc);

        // 7.4. 더블 버퍼링을 위한 백버퍼 복사
        copyRenderTarget(mBackHdc, mHdc);
    }

    // 8. clearRenderTarget 함수
    void Application::clearRenderTarget()
    {
        Rectangle(mBackHdc, -1, -1, 1601, 901);
    }

    // 9. copyRenderTarget 함수
    void Application::copyRenderTarget(HDC source, HDC dest)
    {
        BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
    }

    // 10. adjustWindowRect 함수
    void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
    {
        mHwnd = hwnd;
        mHdc = GetDC(hwnd);

        RECT rect = { 0, 0, width, height };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        mWidth = rect.right - rect.left;
        mHeight = rect.bottom - rect.top;

        SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);

        ShowWindow(hwnd, true);
    }

    // 11. createBuffer 함수
    void Application::createBuffer(UINT width, UINT height)
    {
        mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
        mBackHdc = CreateCompatibleDC(mHdc);

        HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
        DeleteObject(oldBitmap);
    }

    // 12. initializeEtc 함수
    void Application::initializeEtc()
    {
        Input::Initialize();
        Time::Initialize();
    }
}

// 이 파일은 MyApp 네임스페이스 내에서 Application 클래스를 정의하고 구현합니다. 
// Application 클래스는 윈도우 애플리케이션의 초기화, 실행, 업데이트, 렌더링 등을 담당합니다. 
// 주요 함수로는 Initialize, Run, Update, LateUpdate, Render 등이 있으며, 
// 내부적으로 윈도우 설정, 버퍼 생성, 입력 및 시간 시스템 초기화 등을 수행합니다.