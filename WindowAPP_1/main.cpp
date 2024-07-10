﻿// title : Window APP 프로그램에 대한 진입점을 정의합니다.
// explanation : 이 프로젝트는 Window전용 APP을 생성하는 것의 기본이 되는 프로젝트이다.
// author : SDW
// date : 2024-07-10

#include "framework.h"        // 프레임워크 헤더파일을 포함한다. 프레임워크란? :  
#include "WindowAPP_1.h" 	  // WindowAPP_1 헤더파일을 포함한다.

#define MAX_LOADSTRING 100    // 문자열의 최대 길이를 정의한다.

// 전역 변수 ==================================================================
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
// 전역 변수 끝 ===============================================================

// 전역 함수 ==================================================================
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);   // 창 클래스를 등록한다.
BOOL                InitInstance(HINSTANCE, int);           // 인스턴스 핸들을 저장하고 주 창을 만든다.  
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);    // 주 창의 메시지를 처리한다.
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);      // 정보 대화 상자의 메시지 처리기이다.
// 전역 함수 끝 ===============================================================

// main 함수 시작 =============================================================
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);  // 사용되지 않는 매개 변수를 표시한다.
    UNREFERENCED_PARAMETER(lpCmdLine);	    // 사용되지 않는 매개 변수를 표시한다.

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // LoadStringW를 사용하는 이유는? 
    // LoadStringW 함수는 리소스 문자열을 로드하는 함수이다. 리소스 문자열은 리소스 파일에 저장되어 있으며, 리소스 파일은 리소스 편집기를 사용하여 만들 수 있다.
    // 무슨 이유 때문에? : 리소스 문자열을 사용하면 프로그램의 다국어 지원이 쉬워진다. 리소스 문자열을 사용하면 프로그램의 다국어 지원이 쉬워진다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);         // 각각의 인수 : hInstance : 인스턴스 핸들, IDS_APP_TITLE : "WindowAPP_1" 문자열을 가져온다, szTitle : "WindowAPP_1" 문자열을 저장할 변수, MAX_LOADSTRING : 문자열의 최대 길이
    LoadStringW(hInstance, IDC_WINDOWAPP1, szWindowClass, MAX_LOADSTRING);  // 각각의 인수 : hInstance : 인스턴스 핸들, IDC_WINDOWAPP1 : "WindowAPP_1" 문자열을 가져온다, szWindowClass : "WindowAPP_1" 문자열을 저장할 변수, MAX_LOADSTRING : 문자열의 최대 길이
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow)) // InitInstance() 함수가 성공적으로 실행되면 TRUE를 반환하고, 실패하면 FALSE를 반환한다.
    {
        return FALSE; 
    }

    // 가속기 테이블을 로드한다.
    // [SDW 질문] 가속기 테이블이란?
    // [대답] 가속기 테이블은 키보드의 단축키를 지정하는 테이블이다. 가속기 테이블을 사용하면 메뉴나 버튼을 클릭하지 않고도 키보드로 명령을 실행할 수 있다.
    // [SDW 질문] 어떤 원리지?
    // [대답] 가속기 테이블은 메뉴나 버튼의 ID와 단축키를 연결하는 방식으로 동작한다. 가속기 테이블은 가속기 키와 명령 ID를 연결하는 방식으로 동작한다.
    // [SDW 질문] 쉽게 메티포로 설명해줘 
    // [대답] 가속기 테이블은 키보드의 단축키를 지정하는 테이블이다. 가속기 테이블을 사용하면 메뉴나 버튼을 클릭하지 않고도 키보드로 명령을 실행할 수 있다.
    // [SDW 질문] 그니까 그런거네, 가속기 테이블 자체는 테이블인건데, 그 테이블에 맞는 단축키를 지정해서 뿌려준다 라는 개념? 맞아? : 네 맞아요.
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWAPP1)); // 각각의 인수 : hInstance : 인스턴스 핸들, MAKEINTRESOURCE(IDC_WINDOWAPP1) : 가속기 테이블을 가져온다.

    // 메시지 루프를 실행한다:
    // [SDW 질문] 메시지 루프란? 
    // [대답] 메시지 루프는 윈도우 프로그램이 메시지를 받아들이고 처리하는 루프이다. 메시지 루프는 GetMessage() 함수를 사용하여 메시지를 받아들이고, DispatchMessage() 함수를 사용하여 메시지를 처리한다.
    // [SDW 질문] 그니까 한마디로, 위의 테이블도 사용하는거지? 
    // [대답] 네 맞아요. 메시지 루프는 메시지를 받아들이고 처리하는 루프이다. 메시지 루프는 GetMessage() 함수를 사용하여 메시지를 받아들이고, DispatchMessage() 함수를 사용하여 메시지를 처리한다.
    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}
// main 함수 끝 =============================================================


// 전역 함수 정의 시작 =============================================================
//   함수: MyRegisterClass()
//   용도: 창 클래스를 등록합니다.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWAPP1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWAPP1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//   함수: InitInstance(HINSTANCE, int)
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//   주석:
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
// 
//  HWND hWnd : 윈도우 핸들, UINT message : 메시지, WPARAM wParam : 메시지의 부가정보, LPARAM lParam : 메시지의 부가정보
// 
//  용도: 주 창의 메시지를 처리합니다.
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// 전역 함수 정의 끝 =============================================================

// 프로그램 실행 순서 =============================================================
// 1. wWinMain() 함수가 실행된다.
// 2. MyRegisterClass() 함수가 실행된다.
// 3. InitInstance() 함수가 실행된다.
// 4. WndProc() 함수가 실행된다.
// 5. About() 함수가 실행된다.
// 6. 메시지 루프가 실행된다.
// 7. PostQuitMessage() 함수가 실행된다.
// 8. wWinMain() 함수가 종료된다.
// 프로그램 실행 순서 끝 =============================================================