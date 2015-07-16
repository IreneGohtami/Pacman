#include "header.h"

#include "templates.h"

// Needs one of the following #includes, to include the class definition

#include "GameMain.h"

#define BASE_SCREEN_WIDTH 800
#define BASE_SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{
#if defined(_MSC_VER)
#ifdef _MEMORYLEAKDEBUG
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );
	//_CrtSetBreakAlloc(51);
#endif
#endif

	int iResult;

	{
		GameMain oMain;

		char buf[1024];
		sprintf( buf, "WELCOME TO PACMAN WORLD!!! : Size %d x %d", BASE_SCREEN_WIDTH, BASE_SCREEN_HEIGHT );
		iResult = oMain.Initialise( buf, BASE_SCREEN_WIDTH, BASE_SCREEN_HEIGHT, "font/Cornerstone Regular.ttf", 24 );
		iResult = oMain.MainLoop();
		oMain.Deinitialise();

	}

#if defined(_MSC_VER)
#ifdef _MEMORYLEAKDEBUG
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );
	_CrtDumpMemoryLeaks();
#endif
#endif

	return iResult;
}
