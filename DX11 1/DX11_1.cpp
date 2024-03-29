﻿#include <windows.h>
#include <iostream>
#include <d3d11.h>



int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow )
{
	const wchar_t className = *"test";
	//const auto className = LPCWSTR("Test");
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName	 = nullptr;
	wc.lpszClassName = &className;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);


	const wchar_t windowName = *"hello world";
	HWND WindowHandle = CreateWindowEx(
		0, &className, &windowName,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);
	ShowWindow(WindowHandle, SW_SHOW);
	while (true);
	return 0;
}