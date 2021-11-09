// ShootingGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "framework.h"
#include "ShootingGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND hWnd;                                      // 현재 윈동우 핸들입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //프로그램 초기화 코드를 추가하시오.
    START_DEBUG_CONSOLE();              //디버그 콘솔창 시작하기
    cout<<"디버그 콘솔창 시작하기"<<endl;

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SHOOTINGGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;

    initGraphic(hWnd, 0, 0, WIDTH, HEIGHT);  //그래픽 초기화
    Time::init();                            //타이머 초기화

    //게임오브젝트..추가하기//
    ObjectManager::instantiate(new GameBG(0          ,          0)); //게임배경 추가
    ObjectManager::instantiate(new Player(WIDTH/2-34 , HEIGHT-150)); //플레이어 추가

    //적기 테스트하기//
    ObjectManager::instantiate(new Enemy(150, 300));

    //레이저 폭발 테스트하기
    //ObjectManager::instantiate(new LaserExp(100, 100));

    // 기본 메시지 루프입니다:
    while (true)
    {
        //PeekMessage로 윈도우메세지 가져오기
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) == TRUE)
        {
            //윈도우 처리 함수//
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            //무한루프..종료하기
            if (msg.message == WM_QUIT)
            {
                break;
            }
        }

        ////////////////////////////////////////////////

        //게임구동 함수//
        clear(255, 0, 0);
        Time::update();
        Input::update();

        ObjectManager::update();
        ObjectManager::checkCollision();
        ObjectManager::clearDeadObject();
        ObjectManager::draw();

        render();
    }

    STOP_DEBUG_CONSOLE();  //디버그 콘솔창 닫기
    exitGraphic();         //그래픽 종료하기
    ObjectManager::clear(); //매니저 목록에 추가된 객체 모두 삭제하기

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SHOOTINGGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   //윈도우 스타일 변수
    int style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

   //윈도우 크기 조정하기 : AdjustWindowRect
   RECT rt = {0,0, WIDTH, HEIGHT};

   AdjustWindowRect(&rt ,style , FALSE);
   
   //윈도우 가로/세롤 크기
   int width  = rt.right  - rt.left;
   int height = rt.bottom - rt.top;

   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, 
                        szTitle, 
                        style,
                        CW_USEDEFAULT, 
                        0, 
                        width, 
                        height, 
                        nullptr, 
                        nullptr, 
                        hInstance, 
                        nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            render();  //윈도우...출력하기
            
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
