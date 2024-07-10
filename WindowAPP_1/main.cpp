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
// [SDW 질문] APIENTRY란 뭔가요?
// [대답] APIENTRY는 API 함수를 선언하는 매크로이다. API 함수는 외부에서 호출할 수 있는 함수를 의미한다. API 함수는 외부에서 호출할 수 있는 함수를 의미한다.
// [SDW 질문] 이 매크로를 사용함으로서 어떤 변화를 알 수 있나요? 
// [대답] APIENTRY 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다. APIENTRY 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다.
// [SDW 질문] 그니까 WINAPI를 자동으로 사용하기 위해서 APIENTY를 사용하는건가요? 
// [대답] 네 맞아요. APIENTRY 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다. APIENTRY 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다.
// [SDW 질문] 그럼 WINAPI는 무엇인가요?
// [대답] WINAPI는 API 함수를 선언하는 매크로이다. WINAPI 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다. WINAPI 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다.
// [SDW 질문] WINAPI 어떤 이점을 가져와서 그것을 사용하는것인지가 궁굼합니다.
// [대답] WINAPI 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다. WINAPI 매크로를 사용하면 API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다.
// [SDW 질문] 그니까 네임스페이스 같은건가요? 
// [대답] 네 맞아요. API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다. API 함수를 선언할 때 WINAPI 매크로를 사용하지 않아도 된다.
// [SDW 질문] HINSTANCE는 뭔가요? 
// [대답] HINSTANCE는 인스턴스 핸들을 의미한다. 인스턴스 핸들은 프로그램의 인스턴스를 식별하는 값이다. 인스턴스 핸들은 프로그램의 인스턴스를 식별하는 값이다.
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // 매개 변수 경고 표시 제거
    // [SDW 질문] 왜 사용되지 않음을 표시하나요? 
    // [대답] 사용되지 않는 매개 변수를 표시하는 이유는 컴파일러에게 경고를 표시하지 않도록 하기 위해서이다. 사용되지 않는 매개 변수를 표시하는 이유는 컴파일러에게 경고를 표시하지 않도록 하기 위해서이다.
    // [SDW 질문] 그럼 왜 경고를 표시하지 않도록 하는건가요?
    // [대답] 경고를 표시하지 않도록 하는 이유는 경고가 너무 많이 표시되면 중요한 경고를 놓칠 수 있기 때문이다. 경고를 표시하지 않도록 하는 이유는 경고가 너무 많이 표시되면 중요한 경고를 놓칠 수 있기 때문이다.
    // [SDW 질문] 그럼 경고를 놓치면 어떤일이 일어나나요?
    // [대답] 경고를 놓치면 프로그램이 오작동할 수 있기 때문에 경고를 놓치지 않도록 주의해야 한다. 경고를 놓치면 프로그램이 오작동할 수 있기 때문에 경고를 놓치지 않도록 주의해야 한다.
    // [SDW 질문] 굳이 나와도 상관없는 경고다 그러므로 지우는거다 라고 이해하면 될까요? 
    // [대답] 네 맞아요. 사용되지 않는 매개 변수를 표시하는 이유는 컴파일러에게 경고를 표시하지 않도록 하기 위해서이다. 사용되지 않는 매개 변수를 표시하는 이유는 컴파일러에게 경고를 표시하지 않도록 하기 위해서이다.
    UNREFERENCED_PARAMETER(hPrevInstance);  
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // LoadStringW를 사용하는 이유는? 
    // LoadStringW 함수는 리소스 문자열을 로드하는 함수이다. 리소스 문자열은 리소스 파일에 저장되어 있으며, 리소스 파일은 리소스 편집기를 사용하여 만들 수 있다.
    // 무슨 이유 때문에? : 리소스 문자열을 사용하면 프로그램의 다국어 지원이 쉬워진다. 리소스 문자열을 사용하면 프로그램의 다국어 지원이 쉬워진다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);         // 각각의 인수 : hInstance : 인스턴스 핸들, IDS_APP_TITLE : "WindowAPP_1" 문자열을 가져온다, szTitle : "WindowAPP_1" 문자열을 저장할 변수, MAX_LOADSTRING : 문자열의 최대 길이
    LoadStringW(hInstance, IDC_WINDOWAPP1, szWindowClass, MAX_LOADSTRING);  // 각각의 인수 : hInstance : 인스턴스 핸들, IDC_WINDOWAPP1 : "WindowAPP_1" 문자열을 가져온다, szWindowClass : "WindowAPP_1" 문자열을 저장할 변수, MAX_LOADSTRING : 문자열의 최대 길이
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화
    // [SDW 질문] 에플리케이션이란 뭔가요? 
    // [대답] 애플리케이션은 사용자가 사용하는 프로그램을 의미한다. 애플리케이션은 사용자가 사용하는 프로그램을 의미한다.
    // [SDW 질문] 그럼 window에서의 어플리케이션과의 관계는 어떤건가요? 
    // [대답] 윈도우에서의 애플리케이션은 사용자가 사용하는 프로그램을 의미한다. 윈도우에서의 애플리케이션은 사용자가 사용하는 프로그램을 의미한다.
    if (!InitInstance (hInstance, nCmdShow)) // InitInstance() 함수가 성공적으로 실행되면 TRUE를 반환하고, 실패하면 FALSE를 반환한다.
    {
        return FALSE; 
    }

    // 가속기 테이블을 로드
    // [SDW 질문] 가속기 테이블이란?
    // [대답] 가속기 테이블은 키보드의 단축키를 지정하는 테이블이다. 가속기 테이블을 사용하면 메뉴나 버튼을 클릭하지 않고도 키보드로 명령을 실행할 수 있다.
    // [SDW 질문] 어떤 원리지?
    // [대답] 가속기 테이블은 메뉴나 버튼의 ID와 단축키를 연결하는 방식으로 동작한다. 가속기 테이블은 가속기 키와 명령 ID를 연결하는 방식으로 동작한다.
    // [SDW 질문] 쉽게 메티포로 설명해줘 
    // [대답] 가속기 테이블은 키보드의 단축키를 지정하는 테이블이다. 가속기 테이블을 사용하면 메뉴나 버튼을 클릭하지 않고도 키보드로 명령을 실행할 수 있다.
    // [SDW 질문] 그니까 그런거네, 가속기 테이블 자체는 테이블인건데, 그 테이블에 맞는 단축키를 지정해서 뿌려준다 라는 개념? 맞아? : 네 맞아요.
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWAPP1)); // 각각의 인수 : hInstance : 인스턴스 핸들, MAKEINTRESOURCE(IDC_WINDOWAPP1) : 가속기 테이블을 가져온다.

    // 메시지 루프를 실행
    // [SDW 질문] 메시지 루프란? 
    // [대답] 메시지 루프는 윈도우 프로그램이 메시지를 받아들이고 처리하는 루프이다. 메시지 루프는 GetMessage() 함수를 사용하여 메시지를 받아들이고, DispatchMessage() 함수를 사용하여 메시지를 처리한다.
    // [SDW 질문] 그니까 한마디로, 위의 테이블도 사용하는거지? 
    // [대답] 네 맞아요. 메시지 루프는 메시지를 받아들이고 처리하는 루프이다. 메시지 루프는 GetMessage() 함수를 사용하여 메시지를 받아들이고, DispatchMessage() 함수를 사용하여 메시지를 처리한다.
    MSG msg;

    // 기본 메시지 루프
    // [SDW 질문] GetMessage() 함수는 무슨 역할을 하는 함수인가요?
    // [대답] GetMessage() 함수는 메시지 큐에서 메시지를 가져오는 함수이다. GetMessage() 함수는 메시지 큐에서 메시지를 가져오는 함수이다.
    // [SDW 질문] 그러면 이건, 실시간 용은 아닌거지? 
    // [대답] 네 맞아요. GetMessage() 함수는 메시지 큐에서 메시지를 가져오는 함수이다. GetMessage() 함수는 메시지 큐에서 메시지를 가져오는 함수이다.
    // [SDW 질문] 그럼 인제 실시간 반응형으로 만들려면 어떻게 해야할까? 
    // [대답] 실시간 반응형으로 만들려면 PeekMessage() 함수를 사용하면 된다. PeekMessage() 함수는 메시지 큐에서 메시지를 가져오는 함수이다.
    // [SDW 질문] 보통 게임은 PeekMessage()를 사용해야지? 
    // [대답] 네 맞아요. 게임은 PeekMessage() 함수를 사용하여 메시지를 처리한다. PeekMessage() 함수는 메시지 큐에서 메시지를 가져오는 함수이다.
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
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));    // 0, 0, 255의 색상을 가지는 브러쉬를 생성한다.

            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // 올드 브러쉬를 선택한다.

            SelectObject(hdc, brush);                           // 브러쉬를 선택한다.

            Rectangle(hdc, 100, 100, 200, 200);                 // 100, 100의 위치서 200, 200 위치의 사각형을 그린다.

            (HBRUSH)SelectObject(hdc, oldBrush);                // 올드 브러쉬를 선택한다.

            Ellipse(hdc, 200, 200, 300 , 300);                  // 100, 100의 위치서 200, 200 위치의 원을 그린다.

			DeleteObject(brush);                                // 브러쉬를 삭제한다.
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