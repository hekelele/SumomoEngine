//=============================================================================
//
// Sample Project [main.cpp]
// Author : Hekelele
//
//=============================================================================
#include <windows.h>
#include <math.h>
#include "SumomoGame.h"
#include "SpriteGame.h"
#include <iostream>
using namespace std;
using namespace Sumomo;

#include <Gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

//*****************************************************************************
// Macro
//*****************************************************************************
#define	CLASS_NAME		"Sprite Render"		// Name of Window Class
#define WINDOW_NAME		"Sample Project2"		    // Name of Window

#define	WINDOW_POS_X	(200)			// Window Coordination X of Upper-Left Corner
#define	WINDOW_POS_Y	(200)			// Window Coordination Y of Upper-Left Corner
#define	SCREEN_WIDTH	(800+16)			// Window Width
#define	SCREEN_HEIGHT	(600+39)			// Window Height

#define	ID_TIMER		(120)			// Timer ID
#define	TIMER_INTERVAL	(1000 / 60)		// Timer Interval
#define PI				(3.141592)


//*****************************************************************************
// Prototype
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//*****************************************************************************
// Global Variables:
//*****************************************************************************

SumomoGame* myGame;
void myPaint(HDC hDC, int xx, int yy);


//=============================================================================
// Main Function
//=============================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;		// Window Handler
	MSG msg;		// Message Structure

	WNDCLASSEX wcex =							// Message Construct
	{
		sizeof(WNDCLASSEX),						// cbSize Size of WNDCLASSEX Construct
		CS_HREDRAW | CS_VREDRAW,				// style  Window Style
		WndProc,								// lpfnWndProc  Address of Window Process
		0,										// cbClsExtra  0
		0,										// cbWndExtra  0
		hInstance,								// hInstance  Instance of WinMain()
		LoadIcon(NULL,IDI_APPLICATION),			// hIcon Icon
		LoadCursor(NULL, IDC_ARROW),			// hCursor  Cursor
		(HBRUSH)GetStockObject(GRAY_BRUSH),		// hbrBackground  Background Color
		NULL,									// lpszMenuName Menu
		CLASS_NAME,								// lpszClassName Name of Window Class
		NULL									// hIconSm Icon Small
	};

	// Register Window Class
	RegisterClassEx(&wcex);

	// Create Window
	hWnd = CreateWindow(
		CLASS_NAME,				// Register Class Name
		WINDOW_NAME,			// Window Name
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX &~WS_THICKFRAME,
		// Window Style
		WINDOW_POS_X,			// Window position X
		WINDOW_POS_Y,			// Window position Y
		SCREEN_WIDTH,			// Window Width
		SCREEN_HEIGHT,			// Window Height
		NULL,					// Parent Window
		// Menu Handler and Sub Window
		NULL,
		hInstance,				// Application Instance Handler
		NULL);					// Window Data
	myGame = (SumomoGame*)(new SpriteGame(hInstance, 800, 600));
	myGame->initGame();

	// Show Window
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Message Loop
	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		// Translate Message and Dispatch
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	myGame->endGame();
	delete(myGame);

	// Unregister Window Class
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}


//=============================================================================
// Process
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	static int t = 0;
	static int cxclient = 800;
	static int cyclient = 600;

	switch (uMsg)
	{
	case WM_CREATE:
		// Initialize Window
		SetTimer(hWnd, ID_TIMER, TIMER_INTERVAL, NULL);		// WM_TIMER Message
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		KillTimer(hWnd, 1);
		break;
	case WM_SIZE:
	case WM_SIZING:
		cxclient = LOWORD(lParam);
		cyclient = HIWORD(lParam);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		myPaint(hDC, cxclient, cyclient);
		EndPaint(hWnd, &ps);
		break;

	case WM_ERASEBKGND:
		return TRUE;

	case WM_TIMER:
		t++;
		InvalidateRect(hWnd, NULL, TRUE);

		if (myGame->isRunning()) {
			phyManager.Update();
			myGame->updateTimer(t);
			myGame->updateGame();
		}
		break;


	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		}
		break;

	case WM_COMMAND:
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void myPaint(HDC hDC, int xx, int yy) {
	Bitmap bmp(800, 600);

	Graphics bmpGraphics(&bmp);
	bmpGraphics.SetSmoothingMode(SmoothingModeAntiAlias);


	if (myGame->isRunning()) {
		renderManager.Draw(&bmpGraphics);
	}


	//Graphics graphics(hDC);
	//graphics.DrawImage(&bmp, 0, 0, xx, yy);

	Graphics graphics(hDC);
	/*Important! Create a CacheBitmap object for quick drawing*/
	CachedBitmap cachedBmp(&bmp, &graphics);
	graphics.DrawCachedBitmap(&cachedBmp, 0, 0);
}