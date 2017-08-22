
#include <windows.h>
#include <string>
#include <iostream>
#include "resource.h"
#include <tchar.h> //KONWERSJA
//using namespace std;;


LPSTR MojaNazwaKlasy = "Klasa Okienka";                       
MSG Komunikat;                                       //ZMIENNE GLOBLANE!  
//---------------------  

HWND g_hBUTTONPON;
HWND g_hBUTTONWT;
HWND g_hBUTTONSR;
HWND g_hBUTTONCZW;
HWND g_hBUTTONPT;
HWND g_hBUTTONexit;
HWND g_BUWIEZ;
HWND g_BULCE;
HWND g_BUTRAS;
HWND g_hBUTTGO;

HWND g_hTEXT1;
HWND g_hTEXT2;

HWND g_hTEXT5;
HWND g_hTEXT6;
HWND g_hTEXT7; //S||W||T||H
HWND g_hTEXT8;

HWND g_hTEXT10;
HWND g_hTEXT11;
HWND g_hTEXT12;
HWND g_hTEXT13;
HWND g_hTEXT14;
HWND g_hTEXT15; //DNTYG

HWND g_hTEXT20; HWND g_hTEXT28;
HWND g_hTEXT21; HWND g_hTEXT29;
HWND g_hTEXT22; HWND g_hTEXT30;
HWND g_hTEXT23; HWND g_hTEXT31;
HWND g_hTEXT24; HWND g_hTEXT32;
HWND g_hTEXT25; HWND g_hTEXT33;
HWND g_hTEXT26; HWND g_hTEXT34;
HWND g_hTEXT27; HWND g_hTEXT35;
HWND g_hTEXT37; HWND g_hTEXT36;
HWND g_hTEXT38; HWND g_hTEXT39;
HWND g_hTEXT40; HWND g_hTEXT41;
HWND g_hTEXT42; HWND g_hTEXT43;

HFONT hNormalFonttt;
HFONT hNormalFontttt;
HFONT hNormalFonttttt;

int dzt=0;
int act=0;

HWND g_hText;
HWND g_hText2;
HWND g_hText3;
HWND g_hText4;

int mink; int WWM; int WPROC; int PP; int fre=1440; //czas
int minuty2; int minuty; int dztt;




   
//--------------------- 

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
 
//STRUKTURA OKNA    
WNDCLASSEX wc;	

wc.cbSize = sizeof( WNDCLASSEX );
wc.style = 0;
wc.lpfnWndProc = WndProc; //WSK.DO PROCEDURY OBSLUGUJACEJ OKNO
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = hInstance;
wc.hCursor = LoadCursor( NULL, IDC_ARROW );
wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 0 );
wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MYMENU);  //NAZWA IDENTYFIKUJACA MENU!
wc.lpszClassName = MojaNazwaKlasy;
wc.hIcon  = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
wc.hIconSm  = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 32, 32, 0);
	
//JESLI REJSETRACJA OKNA SIE NIE POWIEDZIE	
if( !RegisterClassEx( & wc ) )
{
    MessageBox( NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",MB_ICONEXCLAMATION | MB_OK );
    return 1;
}	



//TWORZENIE OKNA	
HWND hwnd; 
//HMENU hMenu = LoadMenu( hInstance, MAKEINTRESOURCE( 200 ) ); //MENU

hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, MojaNazwaKlasy, "WEEK TIMER", 
WS_SYSMENU, //ZWYKLE STYL OKNA
CW_USEDEFAULT, 
CW_USEDEFAULT, 
690, 
409, 
NULL, //UCHWYT DO OKNA RODZIDZIELSKIEGO-NADRZEDNEGO
NULL, //UCHWYT DO MENU
hInstance, 
NULL );


if( hwnd == NULL )
{
    MessageBox( NULL, "Okno odmówi³o przyjœcia na œwiat!", "Oh Shit!", MB_ICONEXCLAMATION );
    return 1;
}	
	
//RYSOWANIE OKNA	
ShowWindow( hwnd, nCmdShow );
UpdateWindow( hwnd );	

//----------------------------------------------------------------------------------



HFONT hNormalFonttt = CreateFont(20,0,0,0,FF_MODERN,TRUE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));   

HFONT hNormalFontttt = CreateFont(20,0,0,0,FF_MODERN,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));  

HFONT hNormalFonttttt = CreateFont(23,0,0,0,FF_MODERN,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));  	
				
HFONT hNormalF = CreateFont(18,0,0,0,FF_MODERN,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));			



g_hBUTTONPON = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "MON", WS_CHILD | WS_VISIBLE,
15, 15, 70, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONPON, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hBUTTONWT = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "TH", WS_CHILD | WS_VISIBLE,
90, 15, 70, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONWT, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hBUTTONSR = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "WE", WS_CHILD | WS_VISIBLE,
165, 15, 70, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONSR, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hBUTTONCZW = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "THU", WS_CHILD | WS_VISIBLE,
240, 15, 70, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONCZW, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hBUTTONPT = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "FR", WS_CHILD | WS_VISIBLE,
315, 15, 70, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONPT, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hBUTTONexit = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "EXIT.", WS_CHILD | WS_VISIBLE,
595, 307, 70, 40, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONexit, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_BUWIEZ = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "SCHOOL", WS_CHILD | WS_VISIBLE,
35, 145, 120, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONexit, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_BULCE = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "HOMEWORK", WS_CHILD | WS_VISIBLE,
55, 185, 120, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONexit, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_BUTRAS = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "TRANSPORT", WS_CHILD | WS_VISIBLE,
75, 225, 120, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTONexit, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_hBUTTGO = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "GO!", WS_CHILD | WS_VISIBLE,
370, 295, 70, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hBUTTGO, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );



g_hTEXT1 = CreateWindowEx( 0, "STATIC", "Activity type:", WS_CHILD | WS_VISIBLE |
SS_LEFT, 30, 90, 90, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT1, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hTEXT2 = CreateWindowEx( 0, "STATIC", "From:", WS_CHILD | WS_VISIBLE |
SS_LEFT, 35, 296, 40, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT2, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hTEXT2 = CreateWindowEx( 0, "STATIC", "to:", WS_CHILD | WS_VISIBLE |
SS_LEFT, 220, 296, 40, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT2, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

HWND g_hTEXT3 = CreateWindowEx( 0, "STATIC", ":", WS_CHILD | WS_VISIBLE |
SS_LEFT, 126, 296, 40, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT3, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_hTEXT3 = CreateWindowEx( 0, "STATIC", ":", WS_CHILD | WS_VISIBLE |
SS_LEFT, 291, 296, 40, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT3, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_hTEXT5 = CreateWindowEx( 0, "STATIC", "SCHOOL", WS_CHILD | WS_VISIBLE |  //TABELA
SS_LEFT, 360, 80, 50, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT5, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT6 = CreateWindowEx( 0, "STATIC", "HOMEWORK", WS_CHILD | WS_VISIBLE |
SS_LEFT, 430, 80, 70, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT6, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT7 = CreateWindowEx( 0, "STATIC", "TRANSPORT", WS_CHILD | WS_VISIBLE |
SS_LEFT, 520, 80, 70, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT7, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT8 = CreateWindowEx( 0, "STATIC", "FREE", WS_CHILD | WS_VISIBLE |
SS_LEFT, 610, 80, 70, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT8, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT10 = CreateWindowEx( 0, "STATIC", "MON", WS_CHILD | WS_VISIBLE |  //TABELA2
SS_RIGHT, 305, 110, 30, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT10, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT11 = CreateWindowEx( 0, "STATIC", "TH", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 305, 140, 30, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT11, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT12 = CreateWindowEx( 0, "STATIC", "WE", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 305, 170, 30, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT12, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT12 = CreateWindowEx( 0, "STATIC", "THU", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 305, 200, 30, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT12, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT12 = CreateWindowEx( 0, "STATIC", "FR", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 305, 230, 30, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT12, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT20 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  // 20P
SS_RIGHT, 360, 110, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT20, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT21 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 360, 140, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT21, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT23 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 360, 170, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT23, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT24 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 360, 200, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT24, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT25 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 360, 230, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT25, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT26 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  // 
SS_RIGHT, 430, 110, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT26, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT27 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 430, 140, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT27, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT29 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 430, 170, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT29, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT30 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 430, 200, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT30, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT31 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 430, 230, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT31, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT32 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  // 
SS_RIGHT, 520, 110, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT32, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT33 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 520, 140, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT33, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT35 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 520, 170, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT36, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT36 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 520, 200, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT36, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT37 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 520, 230, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT37, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT38 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  // 
SS_RIGHT, 610, 110, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT38, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT39 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 610, 140, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT39, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT41 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 610, 170, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT41, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT42 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 610, 200, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT42, WM_SETFONT,( WPARAM ) hNormalF, 0 );

g_hTEXT43 = CreateWindowEx( 0, "STATIC", "--", WS_CHILD | WS_VISIBLE |  
SS_RIGHT, 610, 230, 60, 20, hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hTEXT1, "g");
SendMessage( g_hTEXT43, WM_SETFONT,( WPARAM ) hNormalF, 0 );



g_hText = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 75, 290, 50, 35,
hwnd, NULL, hInstance, NULL );

SendMessage( g_hText, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_hText2 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 130, 290, 50, 35,
hwnd, NULL, hInstance, NULL );
//SetWindowText( g_hText2, Bufor);
SendMessage( g_hText2, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_hText3 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 240, 290, 50, 35,
hwnd, NULL, hInstance, NULL );
SendMessage( g_hText3, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_hText4 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 295, 290, 50, 35,
hwnd, NULL, hInstance, NULL );

SendMessage( g_hText4, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );



HWND g_hRAMKA = CreateWindowEx( 0, "BUTTON", "", WS_CHILD | WS_VISIBLE | BS_GROUPBOX ,
305, 98, 370, 154, hwnd, NULL, hInstance, NULL );





//----------------------------------------------------------------------------------

//PETLA KOMUNIKATOW-ZDARZEN!	
while( GetMessage( & Komunikat, NULL, 0, 0 ) )
{
    TranslateMessage( & Komunikat );
    DispatchMessage( & Komunikat );
}

return Komunikat.wParam;	
	
	
	return 0;
}



//OBSLUGA KOMUNIKATOW-ZDARZEN!
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
    case WM_CLOSE:
        DestroyWindow( hwnd );            //OBSLUGA ZAMKNIECIA OKNA
        break;
       
    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
       
    //----------------------------------------------------------------------------------   
       
        case WM_COMMAND:

     if(( HWND ) lParam == g_hBUTTONexit )  //EXIT
    DestroyWindow( hwnd );
       
       
     if(( HWND ) lParam == g_hBUTTONPON ) { dzt=1; fre=1440;
    SetWindowText( g_hBUTTONPON, ">MON<");	SetWindowText( g_hBUTTONWT, "TH"); SetWindowText( g_hBUTTONSR, "WE"); SetWindowText( g_hBUTTONCZW, "THU");  SetWindowText( g_hBUTTONPT, "FR");		
	 }
       
     if(( HWND ) lParam == g_hBUTTONWT ) {  dzt=2; fre=1440;
    SetWindowText( g_hBUTTONPON, "MON");	SetWindowText( g_hBUTTONWT, ">TH<"); SetWindowText( g_hBUTTONSR, "WE"); SetWindowText( g_hBUTTONCZW, "THU");  SetWindowText( g_hBUTTONPT, "FR");		
	
	 }  
       
	 if(( HWND ) lParam == g_hBUTTONSR ) {  dzt=3; fre=1440;
	SetWindowText( g_hBUTTONPON, "MON");	SetWindowText( g_hBUTTONWT, "TH"); SetWindowText( g_hBUTTONSR, ">WE<"); SetWindowText( g_hBUTTONCZW, "THU");  SetWindowText( g_hBUTTONPT, "FR");		
	
	 }  
       
     if(( HWND ) lParam == g_hBUTTONCZW ) {  dzt=4; fre=1440;
    SetWindowText( g_hBUTTONPON, "MON");	SetWindowText( g_hBUTTONWT, "TH"); SetWindowText( g_hBUTTONSR, "WE"); SetWindowText( g_hBUTTONCZW, ">THU<");  SetWindowText( g_hBUTTONPT, "FR");		
	
	 }
	    
     if(( HWND ) lParam == g_hBUTTONPT ) {  dzt=5; fre=1440;
    SetWindowText( g_hBUTTONPON, "MON");	SetWindowText( g_hBUTTONWT, "TH"); SetWindowText( g_hBUTTONSR, "WE"); SetWindowText( g_hBUTTONCZW, "THU");  SetWindowText( g_hBUTTONPT, ">FR<");		
	
	 }    
       
       
   if(( HWND ) lParam == g_BUWIEZ ) {SetWindowText( g_BUWIEZ, ">SCHOOL"); SetWindowText( g_BULCE, "HOMEWORK"); SetWindowText( g_BUTRAS, "TRANSPORT"); mink=0; act=1;}   
    if(( HWND ) lParam == g_BULCE )   {SetWindowText( g_BUWIEZ, "SCHOOL"); SetWindowText( g_BULCE, ">HOMEWORK"); SetWindowText( g_BUTRAS, "TRANSPORT"); mink=0; act=2;}   
       if(( HWND ) lParam == g_BUTRAS ) {SetWindowText( g_BUWIEZ, "SCHOOL"); SetWindowText( g_BULCE, "HOMEWORK"); SetWindowText( g_BUTRAS, ">TRANSPORT"); mink=0; act=3;}  
       
       
       
     
    if( LOWORD( wParam ) == ID_STUFF_GO ) {  //OBSLUGA MENU
    MessageBox( hwnd, "Our website don`t exist yet...", "Message", MB_ICONINFORMATION ); 

	/*
	DWORD dlugosc = GetWindowTextLength( g_hText );
LPSTR Bufor =( LPSTR ) GlobalAlloc( GPTR, dlugosc + 1 );
GetWindowText( g_hText, (LPSTR) Bufor, dlugosc + 1 );
SetWindowText( g_hText2, Bufor); SetWindowText( g_hText3, Bufor);
int Num = atoi(( char * ) Bufor ); */ }
    
    
    if( LOWORD( wParam ) == ID_FILE_EXIT ) {  
    DestroyWindow( hwnd ); }         //OBSLUGA ZAMKNIECIA OKNA - MENU 
       
    
	if( LOWORD( wParam ) == ID_STUFF_GOO ) {minuty=0;minuty2=0;PP=0;WWM=0;fre=1440;
	SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT21, "--"); SetWindowText(g_hTEXT2,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--");
	SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT43, "--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--");
	SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT43, "--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--");
	SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT43, "--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--");
	SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT43, "--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--"); SetWindowText(g_hTEXT20,"--");
	} 
	
	   
      if(( HWND ) lParam == g_hBUTTGO ) { 
      
      if(dzt==0||act==0) { mink=0;minuty=0;minuty2=0;PP=0;WWM=0;fre=1440; MessageBox( hwnd, "Wrong data!(F)", "Message", MB_ICONINFORMATION ); break; }
     	
	DWORD dlugosc = GetWindowTextLength( g_hText );
LPSTR Bufor =( LPSTR ) GlobalAlloc( GPTR, dlugosc + 1 );
GetWindowText( g_hText, (LPSTR) Bufor, dlugosc + 1 );
int num = atoi(( char * ) Bufor );
if(num>=24||num<0) {MessageBox( hwnd, "Wrong data!(D1)", "Message", MB_ICONINFORMATION ); break;}

	
	DWORD dlugoscc = GetWindowTextLength( g_hText2 );
LPSTR Buforr =( LPSTR ) GlobalAlloc( GPTR, dlugoscc + 1 );
GetWindowText( g_hText2, (LPSTR) Buforr, dlugoscc + 1 );
int num2 = atoi(( char * ) Buforr );
if(num2>=60||num2<0) {MessageBox( hwnd, "Wrong data!(D2)", "Message", MB_ICONINFORMATION ); break;} 


	DWORD dlugosccc = GetWindowTextLength( g_hText3 );
LPSTR Buforrr =( LPSTR ) GlobalAlloc( GPTR, dlugosccc + 1 );
GetWindowText( g_hText3, (LPSTR) Buforrr, dlugosccc + 1 );
int num3 = atoi(( char * ) Buforrr );
if(num3>=24||num3<0) {MessageBox( hwnd, "Wrong data!(D3)", "Message", MB_ICONINFORMATION ); break;} 


	DWORD dlugoscccc = GetWindowTextLength( g_hText4 );
LPSTR Buforrrr =( LPSTR ) GlobalAlloc( GPTR, dlugoscccc + 1 );
GetWindowText( g_hText4, (LPSTR) Buforrrr, dlugoscccc + 1 );
int num4 = atoi(( char * ) Buforrrr );
if(num4>=60||num4<0) {MessageBox( hwnd, "Wrong data!(D4)", "Message", MB_ICONINFORMATION ); break;} 
	
     	
    minuty = num*60 + num2; 
    minuty2 = num3*60 + num4;
	if(minuty2<minuty){MessageBox( hwnd, "Wrong data!(TL)", "Message", MB_ICONINFORMATION ); break;} 
	if(minuty2>minuty){ mink = mink + (minuty2 - minuty); PP = (mink/1440)*10 ; WWM = 1400-mink; fre = fre -mink;}
	
	if(PP<5) { WPROC = 2; }
	if(PP=5) { WPROC = 5; }
	if(PP=10) { WPROC = 10; }
	if(PP>10 && PP<20) { WPROC = 15; }
 	if(PP=20) { WPROC = 20; }
	if(PP>20 && PP<30) { WPROC = 25; }
	if(PP=30) { WPROC = 30; }
	if(PP>30 && PP<40) { WPROC = 35; }
	if(PP=40) { WPROC = 40; }
	if(PP>40 && PP<50) { WPROC = 45; }
	if(PP=50) { WPROC = 50; }
	if(PP>50 && PP<60) { WPROC = 55; }
	if(PP=60) { WPROC = 60; }
	if(PP>60 && PP<70) { WPROC = 65; }
	if(PP=70) { WPROC = 70; }
	if(PP>70 && PP<80) { WPROC = 75; }	
	if(PP=80) { WPROC = 80; }
	if(PP>80 && PP<90) { WPROC = 85; }	
	if(PP=90) { WPROC = 90; }
	if(PP>90 && PP<100) { WPROC = 95; }	
	if(PP=100) { WPROC = 100; }	
 
    wchar_t buffer[256];
   wsprintfW(buffer, L"%d", mink);  //TRANSFORMACJA int na wchar_t*
     	

TCHAR buf[100];
_stprintf(buf, _T("%d"), mink);
//MessageBox(hwnd, buf, "Testing", MB_OK); //TRANSFORMACJA int na LPCSTR

TCHAR buf2[100];
_stprintf(buf2, _T("%d"), WPROC); 

TCHAR buf3[100];
_stprintf(buf3, _T("%d"), fre); 

const size_t concatenated_size = 100;
char concatenated[concatenated_size];
snprintf(concatenated, concatenated_size, "%sm", buf); //LACZENIE 2THCAR


if(act==1) {
	if(dzt==1) { SetWindowText(g_hTEXT20,concatenated); SetWindowText(g_hTEXT38, buf3); }
	 if(dzt==2) { SetWindowText(g_hTEXT21,concatenated); SetWindowText(g_hTEXT39, buf3); }	 
	  if(dzt==3) { SetWindowText(g_hTEXT23,concatenated); SetWindowText(g_hTEXT41, buf3); }
	   if(dzt==4) { SetWindowText(g_hTEXT24,concatenated); SetWindowText(g_hTEXT42, buf3); }
		 if(dzt==5) { SetWindowText(g_hTEXT25,concatenated); SetWindowText(g_hTEXT43, buf3);  }}
if(act==2) {
	if(dzt==1) { SetWindowText(g_hTEXT26,concatenated); SetWindowText(g_hTEXT38, buf3); }
	 if(dzt==2) { SetWindowText(g_hTEXT27,concatenated); SetWindowText(g_hTEXT39, buf3); }	 
	  if(dzt==3) { SetWindowText(g_hTEXT29,concatenated); SetWindowText(g_hTEXT41, buf3); }
	   if(dzt==4) { SetWindowText(g_hTEXT30,concatenated); SetWindowText(g_hTEXT42, buf3); }
		 if(dzt==5) { SetWindowText(g_hTEXT31,concatenated); SetWindowText(g_hTEXT43, buf3);  }}
if(act==3) {
	if(dzt==1) { SetWindowText(g_hTEXT32,concatenated); SetWindowText(g_hTEXT38, buf3); }
	 if(dzt==2) { SetWindowText(g_hTEXT33,concatenated); SetWindowText(g_hTEXT39, buf3); }	 
	  if(dzt==3) { SetWindowText(g_hTEXT35,concatenated); SetWindowText(g_hTEXT41, buf3); }
	   if(dzt==4) { SetWindowText(g_hTEXT36,concatenated); SetWindowText(g_hTEXT42, buf3); }
		 if(dzt==5) { SetWindowText(g_hTEXT37,concatenated); SetWindowText(g_hTEXT43, buf3);  }}


    
} 
       
       
    //----------------------------------------------------------------------------------   
       
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }
   
    return 0;
}
