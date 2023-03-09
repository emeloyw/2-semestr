#include "Labirint.h"
const int nL = 32;
const int nC = 32;
	UINT map[nL] = {
					0b1101'1111'1111'1111'1111'1111'1111'1111,//1
					0b1101'1111'1110'1111'1100'0111'1111'1111,//2
					0b1100'1111'0000'1111'1001'1111'1111'1111,//3
					0b1110'0111'0101'1111'0011'1111'1111'1111,//4
					0b1000'0010'0100'0111'0111'1111'1111'1111,//5
					0b1011'1000'1111'0000'0111'1111'1111'1111,//6
					0b1011'1110'0011'1111'1111'1111'1111'1111,//7
					0b1111'1111'1001'1111'1111'1111'0011'1111,//8
					0b1111'1111'0000'1111'1111'1110'0001'1111,//9
					0b1111'1110'0110'0111'1111'1100'1100'1111,//10
					0b1111'1100'1111'0011'1111'1001'1110'0111,//11
					0b1111'1001'1111'1000'0000'0011'1111'0011,//12
					0b1111'1011'1111'1111'1111'1111'1111'1011,//13
					0b1111'1011'1111'1111'1111'1111'1111'1011,//14
					0b1111'1011'1111'1111'1111'1111'1111'1011,//15
					0b1111'1011'1110'0111'1111'1110'0111'1011,//16
					0b1111'1011'1110'0111'1111'1110'0111'1011,//17
					0b1111'1011'1111'1111'0000'0111'1111'1011,//18
					0b1111'1011'1111'1011'1000'1110'1111'1011,//19
					0b1111'1011'1111'1000'1101'1000'1111'1011,//20
					0b1111'1000'1111'1110'0000'0011'1110'0011,//21
					0b1111'1110'0011'1111'1111'1111'1000'1111,//22
					0b1111'1111'1000'1111'1111'1110'0011'1111,//23
					0b1111'1111'1110'0000'0000'0000'1111'1111,//24
					0b1111'1100'0111'1101'1111'1011'1111'1111,//25
					0b1111'0001'0001'1100'0000'0011'1111'1111,//26
					0b1111'0111'0100'0001'1111'1011'1000'0111,//27
					0b1100'0111'0111'1100'0000'0011'1011'1111,//28
					0b1111'1111'0111'1111'1111'1111'1000'1111,//29
					0b1111'1111'0000'0110'0011'1000'0010'0001,//30
					0b1111'1111'1111'0000'1000'0011'1111'1100,//31
					0b1111'1111'1111'1111'1111'1111'1111'1111 }, * nMov = 0;//32
	UINT bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;	// маска для стены
	
	int nSRow = 0, nSCol = 2;
	int	nERow = 30, nECol = 31;
	int	nRow=nSRow, nCol=nSCol;
	ЦВЕТА nCLRB = CL_BLACK, nColorBugB=CL_LIGHT_PURPLE;
	COLORS nCLRT = CL_LIGHT_WHITE,nCLRE=CL_CYAN,nCLRS=CL_LIGHT_RED;
	int LabirintMenu() {
		UCHAR ch = 0;
		do {
			CLEAR;
			cout << "   Меню Лабиринта\n";
			cout<<"0 - Лабиринт\n";
			cout << "Для выхода из программы нажмите клавишу ESC";
			ch = _getch();
			switch (ch) {
			case'0': Labirint();  break;
			}
		} while (ch != 27);
		return 0;
	}

	int Moving(int pnRow, int pnCol) {
		SetColor(CL_LIGHT_RED);
		SetCursor(pnRow, pnCol * 2);
		int nRes = 0;
		cout << "  ";
		nMov[pnRow] |= bit >> pnCol;
		if ((pnRow == nERow) && (pnCol == nECol)) return 99;

		if (pnRow - 1 >= 0) {																	//можно ли шагнуть вверх	
			if (!(map[pnRow - 1] & (bit >> pnCol)) && !(nMov[pnRow - 1] & (bit >> pnCol))) {
				nRes = Moving(pnRow - 1, pnCol);
				if (nRes) return nRes;

			}
		}
		if (pnCol - 1 >= 0) {																	//можно ли шагать влево
			if (!(map[pnRow] & (bit >> (pnCol - 1))) && !(nMov[pnRow] & (bit >> (pnCol - 1)))) {
				nRes = Moving(pnRow, pnCol - 1);
				if (nRes) return nRes;
			}
		}
		if (pnCol + 1 <= nC) {
			if (!(map[pnRow] & (bit >> (pnCol + 1))) && !(nMov[pnRow] & (bit >> (pnCol + 1)))) {
				nRes = Moving(pnRow, pnCol + 1);
				if (nRes) return nRes;
			}
		}
		if (pnRow + 1 <= nL) {
			if (!(map[pnRow + 1] & (bit >> pnCol)) && !(nMov[pnRow + 1] & (bit >> pnCol))) {
					nRes = Moving(pnRow + 1, pnCol);
				if (nRes) return nRes;
			}
		}
		SetCursor(pnRow, pnCol*2);
		SetColor(nCLRB);
		cout << "  ";
		return 0;
	}

	int Labirint() {

		CONSOLE_CURSOR_INFO cci;										//отключение мигания курсора
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
		cci.bVisible = false;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

		CLEAR; SetCursor(0, 0);
		UCHAR ch = 27;
		for (int i = 0; i < nL; i++)
		{
			for (int j = 0; j < nC; j++)
			{
				if ((bit >> j) & map[i])
				{
					SetColor(nCLRT);
					cout << "00";
				}
				else {
					if ((i == nRow) && (j == nCol)) {
						SetColor(nColorBugB);
						cout << "ЖЖ";
					}
					else {
						SetColor(nCLRB);
						cout << "  ";
					}
				}
			}
			cout << endl;
		}

		do {


			SetCursor(nRow, nCol * 2);
			if (nRow != nSRow || nCol != nSCol) { SetCursor(nSRow, nSCol * 2); SetColor(nCLRS); cout << "  "; }
			if (nRow != nERow || nCol != nECol) { SetCursor(nERow, nECol * 2); SetColor(nCLRE); cout << "  "; }

			SetCursor(nRow, nCol * 2);
			if (nRow == nSRow && nCol == nSCol)SetColor(nCLRS, nColorBugB);
			else if (nRow == nERow && nCol == nECol)SetColor(CL_LIGHT_CYAN, nColorBugB); else SetColor(nColorBugB);
			cout << "ЖЖ";
			ch = _getch();
			SetColor(CL_BLACK);
			SetCursor(nRow, nCol * 2);
			cout << "  ";
			switch (ch)
			{
			case 0:
			case 224: {
				ch = _getch();
				switch (ch) {
				case 63: 
					nMov = new UINT[nL];
					memset(nMov, 0, (sizeof(UINT) * nL));
					Moving(nRow, nCol);
					delete[] nMov;
					break;
				case 72:	if ((nRow == 0) || (map[nRow - 1] & (bit >> nCol))) Beep(900, 300); else nRow--; break;			//вверх	   
				case 75:	if ((nCol == 0) || (map[nRow] & (bit >> (nCol - 1)))) Beep(900, 300); else nCol--; break;			//влево	   
				case 77:	if ((nCol + 1 == nC) || (map[nRow] & (bit >> (nCol + 1)))) Beep(900, 300); else nCol++; break;		//вправо			
				case 80:	if ((nRow + 1 == nL) || (map[nRow + 1] & (bit >> nCol))) Beep(900, 300); else nRow++; break;		//вниз				   	  

				}
			}
			}
		} while (!((nRow == nERow) && (nCol == nECol)) && (ch != ESC));

		SetCursor(nL + 3, 0);
		SetColor(CL_BLACK, CL_LIGHT_WHITE);

		if (ch == ESC) {
			cout << "\n\nАварийный выход.\n";
		}
		else {
			cout << "\n\nЛабиринт пройден. <3\n";
		}
		PAUSE;

		return 0;

		
	}
