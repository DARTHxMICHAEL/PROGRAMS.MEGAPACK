
#include <emmintrin.h>
#include <omp.h> //OpenMP
#include <cstdio> //czas
#include <ctime> //czas
#include <windows.h>
#include <windowsx.h>
#include <string>
#include <fstream> //zapis-zrodlo
#include <iostream>
#include <intrin.h>  //obsluga __cpuid
#include <commctrl.h> //Common controls
#include "BENCH-SOURCE.h" //BENCH-SOURCECODE
#include "resource.h"
using namespace std;;


LPSTR MojaNazwaKlasy = "Klasa Okienka";                       
MSG Komunikat;                                       //ZMIENNE GLOBLANE!  
//---------------------  

bool Przycisk = false;

/*extern*/ int res=0;

HWND g_hButtonSTART; 
HWND g_hButtonSAVE; 
HWND g_hButtonEXIT; 
HWND g_hButtonWEB; 
HWND g_hButtonTR;

HWND g_hSPEC1;
HWND g_hSPEC2;
HWND g_hSPEC3;
HWND g_hSPEC4;
HWND g_hSPEC5;
HWND g_hSPEC6;
HWND g_hSPEC7;
HWND g_hSPEC8;

HWND g_hSTTEXT1;
HWND g_hSTTEXTSCR;
HWND g_hSTTEXTOZDB;

HWND g_hTODEL; //!

HWND g_hProgressBar;
HWND g_hProgressBar2;


//BITMAPA
HBITMAP hbmObraz =( HBITMAP ) LoadImage( NULL, "C:\\Users\\USER\\Pictures\\C++\\Untitled-1.ico", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );



    //*CPU_INFO*//  



int CPUCORE;
int  RAMTOTA;

void CPU(){	

int CPUInfo[4] = {-1};
        unsigned   nExIds, i =  0;
        char CPUBrandString[0x40];
        // Get the information associated with each extended ID.
        __cpuid(CPUInfo, 0x80000000);
        nExIds = CPUInfo[0];
        for (i=0x80000000; i<=nExIds; ++i)
        {
            __cpuid(CPUInfo, i);
            // Interpret CPU brand string
            if  (i == 0x80000002)
                memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
            else if  (i == 0x80000003)
                memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
            else if  (i == 0x80000004)
                memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
        }
        //string includes manufacturer, model and clockspeed
    CPUBrandString;


        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
     CPUCORE = sysInfo.dwNumberOfProcessors;
    

        MEMORYSTATUSEX statex;
        statex.dwLength = sizeof (statex);
        GlobalMemoryStatusEx(&statex);
     RAMTOTA = (statex.ullTotalPhys/1024)/1024;
       
       
       
wchar_t buffer[256];
wsprintfW(buffer, L"%d", CPUCORE);  //TRANSFORMACJA int na LPCSTRW
  
wchar_t bufferr[256];
wsprintfW(bufferr, L"%d", RAMTOTA);
//MessageBoxW(g_hSPEC3, bufferr, bufferr, MB_OK);  
  


       SetWindowText( g_hSPEC1, CPUBrandString );
       
       SetWindowTextW( g_hSPEC2, buffer);
       
       SetWindowTextW( g_hSPEC3, bufferr);
	}





//--------------------- 

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
 
//STRUKTURA OKNA    
WNDCLASSEX wc;	

wc.cbSize = sizeof( WNDCLASSEX );
wc.style = CS_DBLCLKS;
wc.lpfnWndProc = WndProc; //WSK.DO PROCEDURY OBSLUGUJACEJ OKNO
static HFONT s_hFont = NULL;
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = hInstance;
wc.hCursor = LoadCursor( NULL, IDC_ARROW );
wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 0 );
wc.lpszMenuName = NULL;  //NAZWA IDENTYFIKUJACA MENU
wc.lpszClassName = MojaNazwaKlasy;
//wc.hIcon = (HICON) LoadImage( NULL, "res\\Untitled-1.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE |  LR_SHARED ); //IKONA 
wc.hIcon  = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
wc.hIconSm  = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0); 
//wc.hIconSm = (HICON) LoadImage( NULL, "res\\Untitled-1.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE |  LR_SHARED ); 

	
//JESLI REJSETRACJA OKNA SIE NIE POWIEDZIE	
if( !RegisterClassEx( & wc ) )
{
    MessageBox( NULL, "ERROR(reg)", "CX BENCH",MB_ICONEXCLAMATION | MB_OK );
    return 1;
}	



//TWORZENIE OKNA	
HWND hwnd;

hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, MojaNazwaKlasy, "CX BENCH v1.01", 
WS_SYSMENU, //ZWYKLE STYL OKNA
CW_USEDEFAULT, 
CW_USEDEFAULT, 
623, 
394, 
NULL, //UCHWYT DO OKNA RODZIDZIELSKIEGO-NADRZEDNEGO
NULL, //UCHWYT DO MENU
hInstance, 
NULL );


if( hwnd == NULL )
{
    MessageBox( NULL, "ERROR(cr)", "CX BENCH", MB_ICONEXCLAMATION );
    return 1;
}	
	
//RYSOWANIE OKNA	
ShowWindow( hwnd, nCmdShow );
UpdateWindow( hwnd );	

//----------------------------------------------------------------------------------

//HFONT hNormalFontt =( HFONT ) GetStockObject( DEFAULT_GUI_FONT ); //POBRANIE DOBREJ CZCIONKI 

HFONT hNormalFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));
                
HFONT hNormalFontt = CreateFont(19,0,0,0,FF_MODERN,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));                

HFONT hNormalFonttt = CreateFont(20,0,0,0,FF_MODERN,TRUE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));   
                
HFONT hNormalFontttt = CreateFont(18,0,0,0,FF_MODERN,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));   
 
 
 
g_hButtonSTART = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "START", WS_CHILD | WS_VISIBLE,
0, 250, 205, 113, hwnd, NULL, hInstance, NULL );
SendMessage( g_hButtonSTART, WM_SETFONT,( WPARAM ) hNormalFont, 0 );

g_hButtonSAVE = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "SAVE", WS_CHILD | WS_VISIBLE,
205, 250, 205, 113, hwnd, NULL, hInstance, NULL );
SendMessage( g_hButtonSAVE, WM_SETFONT,( WPARAM ) hNormalFont, 0 );

g_hButtonEXIT = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "EXIT", WS_CHILD | WS_VISIBLE,
410, 250, 205, 113, hwnd, NULL, hInstance, NULL );
SendMessage( g_hButtonEXIT, WM_SETFONT,( WPARAM ) hNormalFont, 0 );

g_hButtonWEB = CreateWindowEx( 0, "BUTTON", "More informations", WS_CHILD | WS_VISIBLE |
SS_CENTER, 230, 195, 120, 20, hwnd, NULL, hInstance, NULL );
SendMessage( g_hButtonWEB, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );

g_hButtonTR = CreateWindowEx( 0, "BUTTON", "Triple precision", WS_CHILD | WS_VISIBLE |
SS_CENTER, 445, 176, 120, 30, hwnd, NULL, hInstance, NULL );
SendMessage( g_hButtonTR, WM_SETFONT,( WPARAM ) hNormalFontttt, 0 );



g_hSPEC1 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
SS_LEFT, 50, 120, 300, 20, hwnd, NULL, hInstance, NULL );
//CPU(); 
SendMessage( g_hSPEC1, WM_SETFONT,( WPARAM ) hNormalFontt, 0 ); //UST.DOBREJ CZCIONKI

g_hSPEC2 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |  //COR.
SS_LEFT, 150, 145, 200, 20, hwnd, NULL, hInstance, NULL );
//CPU(); 
SendMessage( g_hSPEC2, WM_SETFONT,( WPARAM ) hNormalFontt, 0 );

g_hSPEC3 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |   //MEM.
SS_CENTER, 195, 170, 51, 20, hwnd, NULL, hInstance, NULL );
CPU();
SendMessage( g_hSPEC3, WM_SETFONT,( WPARAM ) hNormalFontt, 0 );

g_hSPEC4 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
SS_LEFT, 50, 195, 175, 20, hwnd, NULL, hInstance, NULL );
SetWindowText( g_hSPEC4, "CX BENCH v1.01 |2017.02|");
SendMessage( g_hSPEC4, WM_SETFONT,( WPARAM ) hNormalFontt, 0 );

g_hSPEC6 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |  //CO.
SS_LEFT, 50, 145, 95, 20, hwnd, NULL, hInstance, NULL );
SetWindowText( g_hSPEC6, "Logical cores:"); 
SendMessage( g_hSPEC6, WM_SETFONT,( WPARAM ) hNormalFontt, 0 );

g_hSPEC7 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |   //ME.
SS_LEFT, 50, 170, 150, 20, hwnd, NULL, hInstance, NULL );
SetWindowText( g_hSPEC7, "Total system memory:");
SendMessage( g_hSPEC7, WM_SETFONT,( WPARAM ) hNormalFontt, 0 );

g_hSPEC8 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |   //M.
SS_LEFT, 248, 170, 90, 20, hwnd, NULL, hInstance, NULL );
SetWindowText( g_hSPEC8, "mb");
SendMessage( g_hSPEC8, WM_SETFONT,( WPARAM ) hNormalFontt, 0 );



g_hSTTEXT1 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
SS_LEFT, 485, 103, 60, 20, hwnd, NULL, hInstance, NULL );
SetWindowText( g_hSTTEXT1, "Time|ms|:");
SendMessage( g_hSTTEXT1, WM_SETFONT,( WPARAM ) hNormalFontt, 0 );

g_hSTTEXTSCR  = CreateWindowEx( WS_EX_CLIENTEDGE, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
SS_CENTER, 454, 139, 80, 25, hwnd, NULL, hInstance, NULL );
SetWindowText( g_hSTTEXTSCR, "--- ms");
SendMessage( g_hSTTEXTSCR, WM_SETFONT,( WPARAM ) hNormalFonttt, 0 );

g_hSTTEXTOZDB = CreateWindowEx( WS_EX_CLIENTEDGE, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
SS_LEFT, 1, 1, 611, 5, hwnd, NULL, hInstance, NULL );
SetWindowText( g_hSTTEXTOZDB, "");
SendMessage( g_hSTTEXTOZDB, WM_SETFONT,( WPARAM ) hNormalFontt, 0 ); //OZDOBA

//g_hTODEL = CreateWindowEx( WS_EX_CLIENTEDGE, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
//SS_LEFT, 50, 35, 514, 30, hwnd, NULL, hInstance, NULL );  //TEMPLE



INITCOMMONCONTROLSEX icex;                         //PROGRESSBAR
icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
icex.dwICC = ICC_STANDARD_CLASSES;


g_hProgressBar = CreateWindowEx( 0, PROGRESS_CLASS, NULL, WS_CHILD | PBS_SMOOTH | WS_VISIBLE,
50, 35, 514, 33, hwnd,( HMENU ) 200, hInstance, NULL );

SendMessage( g_hProgressBar, PBM_SETRANGE, 0,( LPARAM ) MAKELONG( 0, 1400 ) ); //ZAKRES(0-65300)

SendMessage( g_hProgressBar, PBM_SETPOS,( WPARAM ) 0, 0 ); //POSTEP 

SendMessage( g_hProgressBar, PBM_SETSTEP,( WPARAM ) 1, 0 ); //WARTOSC PRZYROSTU

//SendMessage( g_hProgressBar, PBM_STEPIT, 0, 0 ); //PRZYROST O WCZ.UST.WART.

g_hProgressBar2 = CreateWindowEx( 0, PROGRESS_CLASS, NULL, WS_CHILD | PBS_SMOOTH | WS_VISIBLE,
50, 35, 30, 33, hwnd,( HMENU ) 200, hInstance, NULL );

SendMessage( g_hProgressBar2, PBM_SETRANGE, 0,( LPARAM ) MAKELONG( 0, 191 ) );
SendMessage( g_hProgressBar2, PBM_SETPOS,( WPARAM ) 0, 0 );
SendMessage( g_hProgressBar2, PBM_SETSTEP,( WPARAM ) 1, 0 );




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
       // GetModuleHandle(NULL)
       
       case WM_COMMAND:

     if(( HWND ) lParam == g_hButtonEXIT )  //EXIT
    DestroyWindow( hwnd );

     if(( HWND ) lParam == g_hButtonWEB )  //WEB
   ShellExecute(hwnd, "open", "https://github.com/DARTHxMICHAEL/", NULL, NULL, NULL);




	if(( HWND ) lParam == g_hButtonSAVE )  //ZAPIS
	if(res==1) {

   int duration;
   wchar_t buffert[256]; //WYNIKI
   
	
  OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "CXB-RESULT";

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW //ZAPISZ - OKNO
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if(GetSaveFileName(&ofn))
    {
      
	HWND hEdit;
	hEdit = (HWND)duration;
	
LPSTR Bufor;
DWORD dwRozmiar, dwZapisane;
HANDLE hPlik;

hPlik = CreateFile( "CXB-result.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL );
if( hPlik == INVALID_HANDLE_VALUE ) {
    MessageBox( NULL, "ERROR(CE1)", "CX BENCH v1.01", MB_ICONEXCLAMATION );
    //PostQuitMessage( 0 ); // Zakoñcz program
}

dwRozmiar = 256; //GetWindowTextLength( g_hSTTEXTSCR );
if( dwRozmiar == 0 ) {
    MessageBox( NULL, "ERROR(SI1)", "CX BENCH v1.01", MB_ICONEXCLAMATION );
    //PostQuitMessage( 0 ); // Zakoñcz program
}

Bufor =( LPSTR ) GlobalAlloc( GPTR, dwRozmiar + 1 );
if( Bufor == NULL ) {
    MessageBox( NULL, "ERROR(BU1)", "CX BENCH v1.01", MB_ICONEXCLAMATION );
    //PostQuitMessage( 0 ); // Zakoñcz program
}

GetWindowText( g_hSTTEXTSCR, Bufor, dwRozmiar ); // skopiuj do bufora tekst z jakiegoœ okna
Bufor[ dwRozmiar ] = 0; // dodaj zero na koñcu stringa 

if( !WriteFile( hPlik, Bufor, dwRozmiar, & dwZapisane, NULL ) ) {
    MessageBox( NULL, "ERROR(FTL)", "CX BENCH v1.01", MB_ICONEXCLAMATION );
    //PostQuitMessage( 0 ); // Zakoñcz program
}

GlobalFree( Bufor ); // Zwolnij bufor
CloseHandle( hPlik ); // Zamknij plik
MessageBox( hwnd, "Score has been saved.", "CX BENCH v1.01", MB_ICONINFORMATION );

 } } else {MessageBox( hwnd, "No score to save...", "CX BENCH v1.01", MB_ICONINFORMATION );}  




     
	if(( HWND ) lParam == g_hButtonSTART ) {   //*BENCH*//  

	res=1;	
 	int nt=0;
    int ntt=0;
    SetWindowText( g_hSTTEXTSCR,"--- ms");
    
 //BENCH-SOURCE.h
 
   while(ntt!=192){
   test_dp_mac_SSE(8,7000); 
   SendMessage( g_hProgressBar2, PBM_STEPIT, 0, 0 );
   ntt++;
   }
 
    std::clock_t start; //ZEGAR
    start = std::clock();

   while(nt!=1400){
   test_dp_mac_SSE(8,70000); 
   SendMessage( g_hProgressBar, PBM_STEPIT, 0, 0 );
   nt++;
   }
 
    int duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000.0;
    wchar_t buffert[256];
    wsprintfW(buffert, L"%d", duration);
 
   SetWindowTextW( g_hSTTEXTSCR, buffert); }
	
	
	

 
  	if(( HWND ) lParam == g_hButtonTR ) { //*TRIPLE PRECISION*//
  	
  	res=1;	
 	int nt=0;
    int ntt=0;
    SetWindowText( g_hSTTEXTSCR,"--- ms");
  	
  	while(ntt!=192){ //-1-
   test_dp_mac_SSE(8,7000); 
   SendMessage( g_hProgressBar2, PBM_STEPIT, 0, 0 );
   ntt++;
   }
  	
  	std::clock_t start; //ZEGAR
    start = std::clock();

   while(nt!=1400){
   test_dp_mac_SSE(8,70000); 
   SendMessage( g_hProgressBar, PBM_STEPIT, 0, 0 );
   nt++;
   }
  	
  	int duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000.0;
    wchar_t buffert[256];
    wsprintfW(buffert, L"%d", duration);
 
   SetWindowTextW( g_hSTTEXTSCR, buffert);
   
 nt=0; //-2-
    start = std::clock();
    
   while(nt!=1400){
   test_dp_mac_SSE(8,70000); 
   SendMessage( g_hProgressBar, PBM_STEPIT, 0, 0 );
   nt++;
   }
  	
  	int durationn = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000.0;
  	int score = (durationn+duration)/2;
    wchar_t buffertt[256];
    wsprintfW(buffertt, L"%d", durationn);
 
   SetWindowTextW( g_hSTTEXTSCR, buffertt);
  	 
 nt=0; //-3-
  start = std::clock();
  
   while(nt!=1400){
   test_dp_mac_SSE(8,70000); 
   SendMessage( g_hProgressBar, PBM_STEPIT, 0, 0 );
   nt++;
   }
  	
  	int durationnn = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000.0;
  	int scoree = (durationn+durationn+duration)/3;
    wchar_t bufferttt[256];
    wsprintfW(bufferttt, L"%d", scoree);
 
   SetWindowTextW( g_hSTTEXTSCR, bufferttt); } 
  	
  	
  	
    //----------------------------------------------------------------------------------   
       
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }
   
    return 0;
}
