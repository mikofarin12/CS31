//
//  main.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright � 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Cell.h"
#include "Board.h"
#include "NumberSet.h"
#include "Game.h"
using namespace cs31;
using namespace std;

void clearScreen();
void beep();

int main()
{
	using namespace cs31;
	using namespace std;

	// test code
	NumberSet ns(1, 2, 3, 4, 5, 6, 7, 8);

	assert(ns.notFound(0));
	assert(!ns.notFound(1));
	assert(!ns.notFound(2));
	assert(!ns.notFound(3));
	assert(!ns.notFound(4));
	assert(!ns.notFound(5));
	assert(!ns.notFound(6));
	assert(!ns.notFound(7));
	assert(!ns.notFound(8));
	assert(ns.notFound(9));

	Cell c;

	c.setValue(1);
	assert(c.getValue() == 1);
	assert(!c.isImmutable());
	c.setValue(2);
	c.setImmutable(true);
	assert(c.getValue() == 2);
	assert(c.isImmutable());

	// isValueOK does not check immutability
	assert(c.isValueOK(0, ns, ns, ns));
	assert(!c.isValueOK(1, ns, ns, ns));
	assert(!c.isValueOK(2, ns, ns, ns));
	assert(!c.isValueOK(3, ns, ns, ns));
	assert(!c.isValueOK(4, ns, ns, ns));
	assert(!c.isValueOK(5, ns, ns, ns));
	assert(!c.isValueOK(6, ns, ns, ns));
	assert(!c.isValueOK(7, ns, ns, ns));
	assert(!c.isValueOK(8, ns, ns, ns));
	assert(c.isValueOK(9, ns, ns, ns));

	// isOKToSetValue does check immutability
	assert(!c.isOKToSetValue(0, ns, ns, ns));
	assert(!c.isOKToSetValue(1, ns, ns, ns));
	assert(!c.isOKToSetValue(2, ns, ns, ns));
	assert(!c.isOKToSetValue(3, ns, ns, ns));
	assert(!c.isOKToSetValue(4, ns, ns, ns));
	assert(!c.isOKToSetValue(5, ns, ns, ns));
	assert(!c.isOKToSetValue(6, ns, ns, ns));
	assert(!c.isOKToSetValue(7, ns, ns, ns));
	assert(!c.isOKToSetValue(8, ns, ns, ns));
	assert(!c.isOKToSetValue(9, ns, ns, ns));

	Game g;
	g.cheat("123456789|.........|987321456|456987123|.........|312645978|.........|.........|.........");

	assert(g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
	assert(g.evaluate() == 36);
	assert(!g.completed());
	// all the cheated values are immutable
	assert(!g.acceptValue(0, 1, 1));
	assert(!g.acceptValue(7, 1, 1));
	assert(g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
	assert(g.evaluate() == 36);
	assert(!g.completed());

	Game g1;
	g1.cheat("5364678912|672195348|198342567|859761423|426853791|713924856|961537284|287419635|345286179");
	assert(g1.evaluate() == 100);
	assert(g1.completed());

	// all the cheated values are immutable
	assert(g1.acceptValue(0, 1, 1));
	assert(g1.acceptValue(7, 1, 1));
	assert(g1.evaluate() == 81);
	assert(g1.completed());
}


	cout << "all tests passed!" << endl;
	return(0);
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen and beep implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

void beep()
{
	cout << '\a' << endl;
}

#endif

#ifdef __APPLE__

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
	using namespace std;
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl;;
	}
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

void beep()
{
	// system( "/usr/bin/osascript -e  \"beep 1\"" );
	// printf("%c", 7);
	// system( "echo $'\\a'" );
	// NSBeep();
}

#endif

#if __unix__ // not Microsoft Visual C++, not Mac, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
	using namespace std;
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl;;
	}
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

void beep()
{
	cout << '\a' << endl;
}

#endif

