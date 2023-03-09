#include "MyFunction.h"
#include "Header.h"

void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x00F)));
}

void SetColor(int pnColor) {
	SetColor(pnColor, pnColor);
}

void SetCursor(short int pnRow, short int pnCol) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position{pnCol,pnRow};
	SetConsoleCursorPosition(hStdOut, position);
	
}
