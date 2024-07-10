// title : Window APP 프로그램에 대한 진입점을 정의합니다.
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
    // 매개 변수 경고 표시 제거
    UNREFERENCED_PARAMETER(hPrevInstance);  
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);         // 각각의 인수 : hInstance : 인스턴스 핸들, IDS_APP_TITLE : "WindowAPP_1" 문자열을 가져온다, szTitle : "WindowAPP_1" 문자열을 저장할 변수, MAX_LOADSTRING : 문자열의 최대 길이
    LoadStringW(hInstance, IDC_WINDOWAPP1, szWindowClass, MAX_LOADSTRING);  // 각각의 인수 : hInstance : 인스턴스 핸들, IDC_WINDOWAPP1 : "WindowAPP_1" 문자열을 가져온다, szWindowClass : "WindowAPP_1" 문자열을 저장할 변수, MAX_LOADSTRING : 문자열의 최대 길이
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화
    {
        return FALSE; 
    }

    // 가속기 테이블을 로드
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWAPP1)); // 각각의 인수 : hInstance : 인스턴스 핸들, MAKEINTRESOURCE(IDC_WINDOWAPP1) : 가속기 테이블을 가져온다.

    // 메시지 루프를 실행
    MSG msg;

    // 기본 메시지 루프
    // GetMessage(&msg, nullptr, 0, 0)
    // 프로세스에서 발생한 메세지를 메시지 큐에서 가져오는 함수 
    // 메시지 큐에 메시지가 없으면 대기한다.

    // PeakMessage : 메시지 큐에 메시지가 없어도 바로 리턴한다.
    // 리턴 값이 true인 경우 메시지가 있고 false인 경우 메세지가 없다고 가르쳐준다.
    
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
			{
				break;
			}
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 메세지가 없을 경우는 이곳에서 처리가 된다. 
            // 특히 게임 로직이 들어가면 된다.
        }
    }

    return (int) msg.wParam;
}
// main 함수 끝 =============================================================


// 전역 함수 정의 시작 =============================================================
//   함수: MyRegisterClass()
//   용도: 창 클래스를 등록
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    // 창 클래스 구조체를 초기화한다.
    WNDCLASSEXW wcex;

    // 창 클래스 구조체를 초기화한다.
    // [SDW 질문] 왜 사이즈를 초기화할까? 
    // [대답] 사이즈를 초기화하는 이유는 구조체의 크기를 설정하기 위해서이다. 사이즈를 초기화하는 이유는 구조체의 크기를 설정하기 위해서이다.
    // [SDW 질문] 왜 이런 특수한 함수를 사용해서 초기화를 할까? 
    // [대답] 특수한 함수를 사용하여 초기화하는 이유는 구조체의 크기를 설정하기 위해서이다. 특수한 함수를 사용하여 초기화하는 이유는 구조체의 크기를 설정하기 위해서이다.
    // [SDW 질문] 그럼 왜 구조체의 크기를 설정해야 하는건가요?
    // [대답] 구조체의 크기를 설정하는 이유는 구조체의 크기를 설정하기 위해서이다. 구조체의 크기를 설정하는 이유는 구조체의 크기를 설정하기 위해서이다.
    // [SDW 질문] 그니까 왜 구조체를 근본적을 ㅗ그렇게 사이즈를 미리 정해놔야 하냐는거임 안하면 어떻게됨? 
    // [대답] 구조체의 크기를 설정하지 않으면 구조체의 크기가 잘못 계산될 수 있기 때문에 구조체의 크기를 설정해야 한다. 구조체의 크기를 설정하지 않으면 구조체의 크기가 잘못 계산될 수 있기 때문에 구조체의 크기를 설정해야 한다.
    // [SDW 질문] 그니까 잘봐봐 int A 이렇게하면 그냥 다들 정수형이구나 알잖아 그래서 거기다가 범위를 넘지 않는 선에서 값을 넣는거고 근데 이부분에서는 사이즈까지 조정한다 이부분이 이상하다는거야 뭘위해서? 
    // [대답] 구조체의 크기를 설정하는 이유는 구조체의 크기를 설정하기 위해서이다. 구조체의 크기를 설정하는 이유는 구조체의 크기를 설정하기 위해서이다.
    // [SDW 질문] 그렇다면 sizeof가 필요하다는건 운영체제 특히 16비트 32비트 64비트와 같이 유동적인 데이터 유형에 대해서 대응한다 라고 생각하면 되는거야? 
    // ***[대답] 네 맞아요. 구조체의 크기를 설정하는 이유는 구조체의 크기를 설정하기 위해서이다. 구조체의 크기를 설정하는 이유는 구조체의 크기를 설정하기 위해서이다.***
    // 내가봐도 똑똑한 질문이었다 크으
    wcex.cbSize = sizeof(WNDCLASSEX);

    // 창 클래스 구조체를 초기화한다.
    // [SDW 질문] style은 어떤건가요 설정을 하면 어떻게 변하는지에 대해서도 간단하게 소개해주세요.
    // [대답] style은 창의 스타일을 설정하는 값이다. CS_HREDRAW는 창의 너비가 변경될 때 창을 다시 그리는 스타일이다. CS_VREDRAW는 창의 높이가 변경될 때 창을 다시 그리는 스타일이다.
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    // [SDW 질문] lpfnWndProc는 무엇인가요?
    // [대답] lpfnWndProc는 창의 메시지 처리 함수의 주소를 설정하는 값이다. lpfnWndProc는 창의 메시지 처리 함수의 주소를 설정하는 값이다.
    // [SDW 질문] 그니까 창의 메시지 처리 함수의 주소를 설정한다는건 그곳의 있는 함수를 사용한다는 뜻이지? 
    // [대답] 네 맞아요. lpfnWndProc는 창의 메시지 처리 함수의 주소를 설정하는 값이다. lpfnWndProc는 창의 메시지 처리 함수의 주소를 설정하는 값이다.
    wcex.lpfnWndProc    = WndProc;
    // [SDW 질문] cbClsExtra는 무엇인가요?
    // [대답] cbClsExtra는 클래스의 여분 바이트 수를 설정하는 값이다. cbClsExtra는 클래스의 여분 바이트 수를 설정하는 값이다.
    wcex.cbClsExtra     = 0;
    // [SDW 질문] cbWndExtra는 무엇인가요?
    // [대답] cbWndExtra는 창의 여분 바이트 수를 설정하는 값이다. cbWndExtra는 창의 여분 바이트 수를 설정하는 값이다.
    wcex.cbWndExtra     = 0;
    // [SDW 질문] hInstance는 무엇인가요?
    // [대답] hInstance는 인스턴스 핸들을 설정하는 값이다. hInstance는 인스턴스 핸들을 설정하는 값이다.
    wcex.hInstance      = hInstance;
    // [SDW 질문] hIcon는 무엇인가요?
    // [대답] hIcon는 아이콘 핸들을 설정하는 값이다. hIcon는 아이콘 핸들을 설정하는 값이다.
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWAPP1));
    // [SDW 질문] hCursor는 무엇인가요?
    // [대답] hCursor는 커서 핸들을 설정하는 값이다. hCursor는 커서 핸들을 설정하는 값이다.
    // [SDW 질문] 커서는 무엇이고 핸들은 무엇인가요? 
    // [대답] 커서는 마우스 포인터를 의미하고, 핸들은 커서를 식별하는 값이다. 커서는 마우스 포인터를 의미하고, 핸들은 커서를 식별하는 값이다.
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    // [SDW 질문] hbrBackground는 무엇인가요?
    // [대답] hbrBackground는 배경색을 설정하는 값이다. hbrBackground는 배경색을 설정하는 값이다.
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    // [SDW 질문] lpszMenuName은 무엇인가요?
    // [대답] lpszMenuName은 메뉴 이름을 설정하는 값이다. lpszMenuName은 메뉴 이름을 설정하는 값이다.
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWAPP1);
    // [SDW 질문] lpszClassName은 무엇인가요?
    // [대답] lpszClassName은 클래스 이름을 설정하는 값이다. lpszClassName은 클래스 이름을 설정하는 값이다.
    wcex.lpszClassName  = szWindowClass;
    // [SDW 질문] hIconSm은 무엇인가요?
    // [대답] hIconSm은 작은 아이콘 핸들을 설정하는 값이다. hIconSm은 작은 아이콘 핸들을 설정하는 값이다.
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

            // 위치 등은 hwnd를 통해서 사용이 가능하다.

            // DC란 화명네 출력에 필요한 모든 정보를 가지는 데이터 구조체이다. 
            // GDI모듈에 의해서 관리된다. 
            // 어떤 폰트를 사용할건가? , 어떤 선의 굵기를 정해줄건가 어떤 색상으로 그려줄건가 등...
            // 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업을 진행할 수 있다. 

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            // 그리기 코드 시작 =============================================================
            HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));    // 파란 색상을 가지는 브러쉬를 생성한다.

            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush); // 올드 브러쉬를 선택한다.
            // [SWD 질문] 반환을 이전의 브러쉬를 가져오나보지? 
            // [대답] 네 맞아요. 이전의 브러쉬를 가져오기 위해서 올드 브러쉬를 선택한다.

            SelectObject(hdc, blueBrush);                           // 파란 브러쉬를 선택한다.

            Rectangle(hdc, 100, 100, 200, 200);                     // 100, 100의 위치서 200, 200 위치의 사각형을 그린다.

            (HBRUSH)SelectObject(hdc, oldBrush);                    // 올드 브러쉬를 선택한다.

            HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));   // 빨간 색상을 가지는 펜을 생성한다.

            HPEN oldPen = (HPEN)SelectObject(hdc, redPen);          // 올드 펜을 선택한다.

            Ellipse(hdc, 200, 200, 300 , 300);                      // 100, 100의 위치서 200, 200 위치의 원을 그린다.

            SelectObject(hdc, oldPen);                              // 올드 펜을 선택한다.

            DeleteObject(redPen);                                   // 빨간 펜을 삭제한다.

			DeleteObject(blueBrush);                                // 파란 브러쉬를 삭제한다.

            // 기본으로 자주사용 되는 GDI오브젝트를 미리 DC안에 만들어 두었다. 
            // 그 오브젝트들을 스톡 오브젝트라고 한다. 
            // BALCK_BRUSH : 검은색 브러쉬
            // WHITE_BRUSH : 흰색 브러쉬
            // GRAY_BRUSH : 회색 브러쉬
            // LTGRAY_BRUSH : 밝은 회색 브러쉬 등 이러한 것들이 있다.

            // 스톡오브젝트를 사용해 봅시다. 

            HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);  // 회색 브러쉬를 가져온다.

            HBRUSH oldBrush2 = (HBRUSH)SelectObject(hdc, grayBrush);// 올드 브러쉬를 선택한다.

            Rectangle(hdc, 400, 400, 500, 500);                     // 300, 300의 위치서 400, 400 위치의 사각형을 그린다.

            SelectObject(hdc, oldBrush2);                           // 올드 브러쉬를 선택한다.

            DeleteObject(grayBrush);                                // 회색 브러쉬를 삭제한다.

            // 그리기 코드 끝 =============================================================
            
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