// Arithmetic_Bench.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>		 
#include <windows.h>
#include <Commdlg.h>	 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>	
#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono;
#include "Arithmetic_Bench.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	
	
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_ARITHMETIC_BENCH, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ARITHMETIC_BENCH));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Free char array
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
BOOL Free_Array_char(char s[], int size)
{
	int j;
	for(j=0; j < size; j++)
	{
		s[j] = '\0';
	}
	return TRUE;
}	
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// measure CPU counts per seconds
// return the time of one count in nano-second
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
double OneCount_nano()
{
	LARGE_INTEGER freq;
	UINT64  Ufreq ;		
	int int_freq = 0; 	
	double OneCount = 0.0;		
	char  AT[100];	 // to store time
	
	if(QueryPerformanceFrequency(&freq)==FALSE)   //freq in [counts per second]
					MessageBox(NULL, "freq problem", NULL, NULL); 
	
	
	Ufreq = freq.QuadPart;
	Free_Array_char(AT, 100);
	sprintf_s(AT,"%d",Ufreq); 
	int_freq   = atoi(AT) ;
	OneCount  = 1000000000.0 /double(int_freq);   // in nano seconds 	
	return OneCount;
}
void test_Add()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = 100.123 + 25.666 ;
		i--;
		a = 0.0;
	}  
	return;
}
void test_Sub()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = 100.123 - 25.666 ;
		i--;
		a = 0.0;
	}  
	return;	 	
}
void test_Multiply()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = 100.123 * 25.666 ;
		i--;
		a = 0.0;
	}  
	return;
}
void test_Div()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = 100.123 / 25.666 ;
		i--;
		a = 0.0;
	}  
	return;
}
void test_sqrt()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = sqrt(0.456)  ;
		i--;
		a = 0.0;
	}  
	return;	 	
}
void test_atan()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = atan(0.456)  ;
		i--;
		a = 0.0;
	}  
	return;
}
void test_sin()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = sin(0.456)  ;
		i--;
		a = 0.0;
	}  
	return;
}
void test_cos()
{
	int i =	 1000;
	long double a = 0.0 ;
	while (i > 0)
	{
		a = cos(0.456)  ;
		i--;
		a = 0.0;
	}  
	return;
}

void Arith_Speed()
{	 	
	double time_1 =  0.0;  // start time
	double time_2 =  0.0;	// end time
	double t_Mul = 0.0 ; 
	double t_Div = 0.0 ;
	double t_Add = 0.0 ;
	double t_Sub = 0.0 ;
	double t_sqrt = 0.0 ;
	double t_atan = 0.0 ;
	double t_cos = 0.0 ;
	double t_sin = 0.0 ;
	double OneCount = 0.0 ;

	int Count_Mul = 0; 
	int Count_Div = 0;
	int Count_Add = 0;
	int Count_Sub = 0;
	int Count_sqrt = 0 ;
	int Count_atan = 0 ;
	int Count_cos = 0;
	int Count_sin = 0;
	ofstream fn;

	OneCount = OneCount_nano();
	
	LARGE_INTEGER StartingTime, EndingTime, Elapsednanoseconds;
	LARGE_INTEGER Frequency;   	
	
	QueryPerformanceFrequency(&Frequency);	// counts 
	// Test Multiply
	QueryPerformanceCounter(&StartingTime);	// counts per second
	// Activity to be timed
		test_Multiply() ; 
	QueryPerformanceCounter(&EndingTime);
	//ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart; 	
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles	
	Count_Mul = int(Elapsednanoseconds.QuadPart);
	// We now have the elapsed number of ticks, along with the
	// number of ticks-per-second. We use these values
	// to convert to the number of elapsed microseconds.
	// To guard against loss-of-precision, we convert
	// to microseconds *before* dividing by ticks-per-second.
	//

	//ElapsedMicroseconds.QuadPart *= 1000000;	 // microseconds
	//ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_Mul = double(Elapsednanoseconds.QuadPart);	
	
	// Test Add
	QueryPerformanceCounter(&StartingTime);	 
		test_Add() ;
	QueryPerformanceCounter(&EndingTime);
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles
	Count_Add = int(Elapsednanoseconds.QuadPart);
	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_Add = double(Elapsednanoseconds.QuadPart);

	// Test Substraction
	QueryPerformanceCounter(&StartingTime);	
		test_Sub() ;
	QueryPerformanceCounter(&EndingTime);
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles
	Count_Sub = int(Elapsednanoseconds.QuadPart);
	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_Sub = double(Elapsednanoseconds.QuadPart);

	// Test Division
	QueryPerformanceCounter(&StartingTime); 
		test_Div();
	QueryPerformanceCounter(&EndingTime);
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles
	Count_Div = int(Elapsednanoseconds.QuadPart);
	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_Div = double(Elapsednanoseconds.QuadPart);
	
	// Test Square-root
	QueryPerformanceCounter(&StartingTime);
		test_sqrt() ;
	QueryPerformanceCounter(&EndingTime);
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles
	Count_sqrt = int(Elapsednanoseconds.QuadPart);
	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_sqrt = double(Elapsednanoseconds.QuadPart);
	
	// Test atan
	QueryPerformanceCounter(&StartingTime); 
		test_atan() ;
	QueryPerformanceCounter(&EndingTime);
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles
	Count_atan = int(Elapsednanoseconds.QuadPart);
	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_atan = double(Elapsednanoseconds.QuadPart);

	// Test sin
	QueryPerformanceCounter(&StartingTime);  
		test_sin() ;
	QueryPerformanceCounter(&EndingTime);
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles
	Count_sin = int(Elapsednanoseconds.QuadPart);
	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_sin = double(Elapsednanoseconds.QuadPart);
	
	// Test cos
	QueryPerformanceCounter(&StartingTime);
		test_cos() ;
	QueryPerformanceCounter(&EndingTime);
	Elapsednanoseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;	  // in cycles
	Count_cos = int(Elapsednanoseconds.QuadPart);
	Elapsednanoseconds.QuadPart *= 1000000000;		// nanoseconds
	Elapsednanoseconds.QuadPart /= Frequency.QuadPart;
	t_cos = double(Elapsednanoseconds.QuadPart);
	

	// write output to file
	fn.open(MATH_SPEED,ios::out); // open new file 
	fn << std::fixed << std::setprecision(18) ;
	fn << "********************************************************************\n";
	fn << "              Math speed test  (Feb 2020)  \n\n"; 	
	fn << "********************************************************************\n";
	fn << "              QueryPerformance function  \n\n"; 	
	fn << "********************************************************************\n"; 
	fn << "OneCount equals   " << OneCount <<"  nano seconds" << endl ;
	fn << "frequency equals  " << (1000000000.0 /OneCount) <<"  Cycles per second" << endl ;	  
	fn << "********************************************************************\n";
	fn << "processing time of 1000 operations of multiply  is " << t_Mul <<"  nano seconds" << endl ;
	fn << "processing time of 1000 operations of division  is " << t_Div <<"  nano seconds" << endl ;
	fn << "processing time of 1000 operations of addition  is " << t_Add <<"  nano seconds" << endl ;
	fn << "processing time of 1000 operations of substract is " << t_Sub <<"  nano seconds" << endl ;
	fn << "processing time of 1000 operations of SQRT      is " << t_sqrt<<"  nano seconds" << endl ;
	fn << "processing time of 1000 operations of atan      is " << t_atan<<"  nano seconds" << endl ;
	fn << "processing time of 1000 operations of cos       is " << t_cos <<"  nano seconds" << endl ;
	fn << "processing time of 1000 operations of sin       is " << t_sin <<"  nano seconds" << endl ;
	fn << "*******************************************************************\n";
	fn << "Count_Mul multiply   is " << Count_Mul <<"  Cycles" << endl ;
	fn << "Count_Div division   is " << Count_Div <<"  Cycles" << endl ;
	fn << "Count_Sub addition   is " << Count_Add <<"  Cycles" << endl ;
	fn << "Count_Add substract  is " << Count_Sub <<"  Cycles" << endl ;
	fn << "Count_sqr SQRT       is " << Count_sqrt <<"  Cycles" << endl ;
	fn << "Count_ata atan       is " << Count_atan <<"  Cycles" << endl ;
	fn << "Count_sin cos        is " << Count_cos <<"  Cycles" << endl ;
	fn << "Count_cos sin        is " << Count_sin <<"  Cycles" << endl ;
	fn << "********************************************************************\n";
	
	fn << endl	;	 	
	//fn << "Elapsednanoseconds " << double(Elapsednanoseconds.QuadPart) << endl ; 
	fn << "Frequency " << double(Frequency.QuadPart) << endl ;  
	
	fn.close();
	
	//Free_Array_char(AT, 100);
	//tt = (time_2 - time_1) * OneCount/1000000.0;  //time in milli seconds
	//sprintf_s(AT, "%f", tt );
	//MessageBox(NULL, AT, " tt time in milli sseconds", NULL); 
	return ;
}
void Arith_Speed_Clock()
{		
	clock_t t_Mul  ; 
	clock_t t_Div  ;
	clock_t t_Add  ;
	clock_t t_Sub  ;
	clock_t t_sqrt ;
	clock_t t_atan ;
	clock_t t_cos  ;
	clock_t t_sin  ;

	double Count_Mul = 0; 
	double Count_Div = 0;
	double Count_Add = 0;
	double Count_Sub = 0;
	double Count_sqrt = 0 ;
	double Count_atan = 0 ;
	double Count_cos = 0;
	double Count_sin = 0;
	ofstream fn;	
	
	clock_t start;
   	
	start = clock();
		test_Multiply() ; 		
	t_Mul = clock() - start;   // clock cycles
	Count_Mul =  t_Mul/ (double)CLOCKS_PER_SEC;  // seconds);
	
	// Test Add
	start = clock(); 
		test_Add() ;
	t_Add = clock() - start;   // clock cycles
	Count_Add = t_Add/ (double)CLOCKS_PER_SEC;  // seconds); 	

	// Test Substraction
	start = clock();	
		test_Sub() ;   
	t_Sub = clock() - start;   // clock cycles
	Count_Sub = t_Mul/ (double)CLOCKS_PER_SEC;  // seconds);

	// Test Division
	start = clock();
		test_Div();		 
	t_Div = clock() - start;   // clock cycles
	Count_Div = t_Div/ (double)CLOCKS_PER_SEC;  // seconds);
	
	// Test Square-root
	start = clock();
		test_sqrt() ;	 
	t_sqrt = clock() - start;   // clock cycles
	Count_sqrt = t_Mul/ (double)CLOCKS_PER_SEC;  // seconds);

	// Test atan
	start = clock(); 
		test_atan() ; 
	t_atan = clock() - start;   // clock cycles
	Count_atan = t_atan/ (double)CLOCKS_PER_SEC;  // seconds);

	// Test sin
	start = clock();  
		test_sin() ;			  	
	t_sin = clock() - start;   // clock cycles
	Count_sin = t_sin/ (double)CLOCKS_PER_SEC;  // seconds);

	// Test cos
	start = clock();
		test_cos() ; 
	t_cos = clock() - start;   // clock cycles
	Count_cos = t_cos/ (double)CLOCKS_PER_SEC;  // seconds);

	// write output to file
	fn.open(MATH_SPEED,ios::app); // append file 
	fn << std::fixed << std::setprecision(18) ;
	fn << "********************************************************************\n";
	fn << "              Clock function)  \n\n"; 	
	fn << "********************************************************************\n"; 
	fn << "multiply  is " << t_Mul <<"  cycles" << endl ;
	fn << "division  is " << t_Div <<"  cycles" << endl ;
	fn << "addition  is " << t_Add <<"  cycles" << endl ;
	fn << "substract is " << t_Sub <<"  cycles" << endl ;
	fn << "SQRT      is " << t_sqrt<<"  cycles" << endl ;
	fn << "atan      is " << t_atan<<"  cycles" << endl ;
	fn << "cos       is " << t_cos <<"  cycles" << endl ;
	fn << "sin       is " << t_sin <<"  cycles" << endl ;
	fn << "********************************************************************\n";
	fn << "Count_Mul multiply   is " << Count_Mul <<" seconds" << endl ;
	fn << "Count_Div division   is " << Count_Div <<" seconds" << endl ;
	fn << "Count_Sub addition   is " << Count_Add <<" seconds" << endl ;
	fn << "Count_Add substract  is " << Count_Sub <<" seconds" << endl ;
	fn << "Count_sqr SQRT       is " << Count_sqrt <<"seconds" << endl ;
	fn << "Count_ata atan       is " << Count_atan <<"seconds" << endl ;
	fn << "Count_sin cos        is " << Count_cos <<" seconds" << endl ;
	fn << "Count_cos sin        is " << Count_sin <<" seconds" << endl ;
	fn << "********************************************************************\n";
	
	fn << "CLOCKS_PER_SEC        is " << (double)CLOCKS_PER_SEC << endl ;
	
	fn << endl	;	 	
	fn.close(); 
	return ;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ARITHMETIC_BENCH));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_ARITHMETIC_BENCH);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_Bench:
			Arith_Speed();
			//Arith_Speed_Clock();
			//MessageBox(NULL, "Done", "Done",MB_OK | MB_ICONINFORMATION);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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
