// gwes-sample2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "gwes-sample2.h"

#include <windows.h>

HINSTANCE g_hInst = NULL;     // Handle to the application instance
HWND g_hwndMain = NULL;       // Handle to the application main window
TCHAR g_szTitle[80] = TEXT ("Main Window"),    
                              // Application main window name
      g_szClassName[80] = TEXT ("Main window class");  
                              // Main window class name
                
/***********************************************************************

FUNCTION: 
  WndProc

PURPOSE: 
  The callback function for the main window. It processes messages that
  are sent to the main window.

***********************************************************************/
LRESULT CALLBACK WndProc (HWND hwnd, UINT umsg, WPARAM wParam, 
                          LPARAM lParam)
{
  switch (umsg)
  {
    // Add cases such as WM_CREATE, WM_COMMAND, WM_PAINT if you don't 
    // want to pass these messages along for default processing.

    case WM_CLOSE:
      DestroyWindow (hwnd);
      return 0;

    case WM_DESTROY:
      PostQuitMessage (0);
      return 0;
  }

  return DefWindowProc (hwnd, umsg, wParam, lParam);
}

/***********************************************************************

FUNCTION: 
  InitInstance

PURPOSE: 
  Create and display the main window.

***********************************************************************/
BOOL InitInstance (HINSTANCE hInstance, int iCmdShow)
{

  g_hInst = hInstance;
  
  g_hwndMain = CreateWindow (
                  g_szClassName,  // Registered class name         
                  g_szTitle,      // Application window name
                  WS_OVERLAPPED,  // Window style
                  CW_USEDEFAULT,  // Horizontal position of the window
                  CW_USEDEFAULT,  // Vertical position of the window
                  CW_USEDEFAULT,  // Window width
                  CW_USEDEFAULT,  // Window height
                  NULL,           // Handle to the parent window
                  NULL,           // Handle to the menu the identifier
                  hInstance,      // Handle to the application instance
                  NULL);          // Pointer to the window-creation data

  // If it failed to create the window, return FALSE.
  if (!g_hwndMain)
    return FALSE;

  ShowWindow (g_hwndMain, iCmdShow);
  UpdateWindow (g_hwndMain);
  return TRUE;
}

/***********************************************************************

FUNCTION: 
  InitApplication

PURPOSE:
  Declare the window class structure, assign values to the window class
  structure members, and register the window class.

***********************************************************************/
BOOL InitApplication (HINSTANCE hInstance)
{
  WNDCLASS wndclass;

  wndclass.style = CS_HREDRAW | CS_VREDRAW;
  wndclass.lpfnWndProc = (WNDPROC)WndProc;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.hIcon = NULL;
  wndclass.hInstance = hInstance;
  wndclass.hCursor = NULL;
  wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
  wndclass.lpszMenuName = NULL;
  wndclass.lpszClassName = g_szClassName;
  
  return RegisterClass (&wndclass);
}


VOID DrawRandomObjects (HWND hwnd)
{
  HDC hDC;                  // Handle to the display device context 
  RECT rect;                // A RECT structure that contains the 
                            // window's client area coordinates
  POINT pt[4];              // Four dimensional POINT structure array
  HBRUSH hBrush,            // Handle to the new brush object 
         hOldBrush;         // Handle to the old brush object 
  TCHAR szDebug[80];        // A debug message string

  int x1, y1, x2, y2, x3, y3, x4, y4, 
                            // The coordinates of four points
      iRed, iGreen, iBlue,  // Indicate the Red, Green, Blue component
                            // color of the brush
      iObject;              // An integer indicates the type of objects

  // Retrieve the handle to the display device context.
  if (!(hDC = GetDC (hwnd)))
    return;

  // Retrieves the coordinates of a window's client area. 
  GetClientRect (hwnd, &rect);

  // Avoid divide by zero errors when the window is small.
  if (rect.right == 0) 
    rect.right++;
  if (rect.bottom == 0) 
    rect.bottom++;

  // Generate three random numbers.
  iRed = rand() % 255;
  iGreen = rand() % 255;
  iBlue = rand() % 255;

  // Create a solid brush object and select it into the device context.
  hBrush = CreateSolidBrush (RGB(iRed, iGreen, iBlue));

    hOldBrush = static_cast<HBRUSH>(SelectObject(hDC, static_cast<HGDIOBJ>(hBrush)));
    if (hOldBrush)
  {
    // Randomly generates four points.
    x1 = rand() % rect.right;
    y1 = rand() % rect.bottom;
    x2 = rand() % rect.right;
    y2 = rand() % rect.bottom;
    x3 = rand() % rect.right;
    y3 = rand() % rect.bottom;
    x4 = rand() % rect.right;
    y4 = rand() % rect.bottom;

    // Randomly generate an integer to indicate the type of objects.
    iObject = rand() % 4;

    switch (iObject)
    {
      case 0:
        wsprintf (szDebug, TEXT("Rectangle(%d ,%d, %d, %d)\n"), 
                  x1, y1, x2, y2);

        // Draws a rectangle.
        Rectangle (hDC, x1, y1, x2, y2);

        break;

      case 1:
        wsprintf (szDebug, TEXT("Ellipse(%d, %d, %d, %d)\n"), 
                  x1, y1, x2, y2);

        // Draws an ellipse.
        Ellipse (hDC, x1, y1, x2, y2);

        break;

      case 2:
        wsprintf (szDebug, TEXT("RoundRect (%d, %d, %d, %d, %d, %d)\n"),
                  x1, y1, x2, y2, x3, y3);

        // Draws a rectangle with rounded corners. 
        RoundRect (hDC, x1, y1, x2, y2, x3, y3);

        break;

      case 3:
        pt[0].x = x1;
        pt[0].y = y1;
        pt[1].x = x2;
        pt[1].y = y2;
        pt[2].x = x3;
        pt[2].y = y3;
        pt[3].x = x4;
        pt[3].y = y4;

        wsprintf (szDebug, 
                  TEXT("Chord(%d, %d, %d, %d, %d, %d, %d, %d)\n"),
                  x1, y1, x2, y2, x3, y3, x4, y4);

        // Draws a polygon.
        Polygon(hDC, pt, 4);

        break;

      default:
        break;
    }

    // Select the old brush into the device context.
    SelectObject (hDC, hOldBrush);

    // Delete the brush object and free all resources associated with it.
    DeleteObject (hBrush);
  }

  ReleaseDC (hwnd, hDC);
  return;
}

VOID BitmapDemo (HWND hwnd)
{
  
  HDC hDC,                  // Handle to the display device context 
      hDCMem;               // Handle to the memory device context
  HBITMAP hBitmap,          // Handle to the new bitmap
          hOldBitmap;       // Handle to the old bitmap
  static int iCoordinate[200][4];  
  int i, j,                
      iXSrc, iYSrc,         // x and y coordinates of the source 
                            // Rectangle's upper-left corner
      iXDest, iYDest,       // x and y coordinates of the destination 
                            // Rectangle's upper-left corner
      iWidth, iHeight;      // Width and height of the bitmap

  // Retrieve the handle to a display device context for the client 
  // area of the window (hwnd). 
  if (!(hDC = GetDC (hwnd)))
    return;

  // Create a memory device context compatible with the device. 
  hDCMem = CreateCompatibleDC (hDC);

  // Retrieve the width and height of windows display elements.
  iWidth = GetSystemMetrics (SM_CXSCREEN) / 10;
  iHeight = GetSystemMetrics (SM_CYSCREEN) / 10;

  // Create a bitmap compatible with the device associated with the 
  // device context.
  hBitmap = CreateCompatibleBitmap (hDC, iWidth, iHeight);

  // Select the new bitmap object into the memory device context. 
  hOldBitmap = static_cast<HBITMAP>(SelectObject(hDCMem, hBitmap));

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 200; j++)
    {
      if (i == 0)
      {
        iCoordinate[j][0] = iXDest = iWidth * (rand () % 10);
        iCoordinate[j][1] = iYDest = iHeight * (rand () % 10);
        iCoordinate[j][2] = iXSrc = iWidth * (rand () % 10);
        iCoordinate[j][3] = iYSrc = iHeight * (rand () % 10);
      }
      else
      {
        iXDest = iCoordinate[200 - 1 - j][0];
        iYDest = iCoordinate[200 - 1 - j][1];
        iXSrc = iCoordinate[200 - 1 - j][2];
        iYSrc = iCoordinate[200 - 1 - j][3];
      }

      // Transfer pixels from the source rectangle to the destination
      // rectangle.
      BitBlt (hDCMem, 0, 0, iWidth, iHeight, hDC,  iXDest, iYDest, 
              SRCCOPY);
      BitBlt (hDC,  iXDest, iYDest, iWidth, iHeight, hDC,  iXSrc, iYSrc,
              SRCCOPY);
    }
  }

  // Select the old bitmap back into the device context.
  SelectObject (hDC, hOldBitmap);

  // Delete the bitmap object and free all resources associated with it. 
  DeleteObject (hBitmap);

  // Delete the memory device context and the display device context.
  DeleteDC (hDCMem);
  ReleaseDC (hwnd, hDC);

  return;  
}


/***********************************************************************

FUNCTION: 
  WinMain

PURPOSE: 
  The WinMain function of the application. It is called by the system as
  the initial entry point for this Windows CE-based application.

***********************************************************************/
int WINAPI WinMain (
               HINSTANCE hInstance,     // Handle to the current instance
               HINSTANCE hPrevInstance, // Handle to the previous instance
               LPWSTR lpCmdLine,        // Pointer to the command line
               int iCmdShow)            // Shows the state of the window
{
  MSG msg;                             // Message structure
  HACCEL hAccel;                       // Handle of the accelerator 
                                      // table
    

// Use this code to prevent your application from starting twice
// assuming that your application has not changed its window text
if (FindWindow(g_szClassName, g_szTitle)){
   SetForegroundWindow(FindWindow(g_szClassName, g_szTitle));
   return FALSE;
}
  

  if (!hPrevInstance)
  {
    if (!InitApplication (hInstance))
      return FALSE; 
  }

  if (!InitInstance (hInstance, iCmdShow))
    return FALSE;
  
  // Insert code here to load the accelerator table.
  // hAccel = LoadAccelerators (...);
  
  while (GetMessage (&msg, NULL, 0, 0))
  {
    if (!TranslateAccelerator (
                    g_hwndMain,     // Handle to the destination window
                    hAccel,         // Handle to the accelerator table
                    &msg))          // Address of the message data
    {
      TranslateMessage (&msg);
      DispatchMessage (&msg);
    }

      BitmapDemo(g_hwndMain);
  }
  return msg.wParam;
}

