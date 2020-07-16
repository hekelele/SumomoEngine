//=============================================================================
//
// Sample Project [main.cpp]
// Author : Hekelele
//
//=============================================================================
#include <windows.h>
#include <math.h>
#include "main.h"
#include "scripts.h"
#include <iostream>
using namespace std;

//*****************************************************************************
// Macro
//*****************************************************************************
#define	CLASS_NAME		"Physics Simulation"		// Name of Window Class
#define WINDOW_NAME		"Sample Project"		    // Name of Window

#define	WINDOW_POS_X	(200)			// Window Coordination X of Upper-Left Corner
#define	WINDOW_POS_Y	(200)			// Window Coordination Y of Upper-Left Corner
#define	SCREEN_WIDTH	(800)			// Window Width
#define	SCREEN_HEIGHT	(600)			// Window Height

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

RenderingManager renderManager;
PhysicsManager phyManager;

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
		WS_OVERLAPPEDWINDOW,	// Window Style
		WINDOW_POS_X,			// Window position X
		WINDOW_POS_Y,			// Window position Y
		SCREEN_WIDTH,			// Window Width
		SCREEN_HEIGHT,			// Window Height
		NULL,					// Parent Window
		// Menu Handler and Sub Window
		NULL,
		hInstance,				// Application Instance Handler
		NULL);					// Window Data

	initGame();
	
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

	//endGame();
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
	HDC hMemDC;
	PAINTSTRUCT ps;
	HBITMAP hBitmap;
	HBITMAP hPreBmp;
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
		cxclient = LOWORD(lParam);
		cyclient = HIWORD(lParam);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		hMemDC = CreateCompatibleDC(hDC);
		hBitmap = CreateCompatibleBitmap(hDC, renderManager.width, renderManager.height);
		hPreBmp = (HBITMAP)SelectObject(hMemDC, hBitmap);

		if (running) {
			renderManager.Draw(hMemDC);
		}


		SetStretchBltMode(hDC,HALFTONE);
		StretchBlt(hDC, 0, 0, cxclient, cyclient, hMemDC, 0, 0, 800, 600, SRCCOPY);

		SelectObject(hMemDC, hPreBmp);
		DeleteObject(hBitmap);
		DeleteDC(hMemDC);
		EndPaint(hWnd, &ps);
		break;

	case WM_ERASEBKGND:
		return TRUE;

	case WM_TIMER:
		t++;
		InvalidateRect(hWnd, NULL, TRUE);

		if (running) {
			phyManager.Update();
			// GameObject(s) Update
			for (unsigned int i = 0; i < GameObjectList.size(); i++) {
				GameObjectList[i]->Update();
			}
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
