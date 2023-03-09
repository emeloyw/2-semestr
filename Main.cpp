#include "Header.h"
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"Учебный проект по дисциплине \"Технология программирования\" Студента Тупицыной Наталии");
	UCHAR ch = 0;
	do {
		system("cls");
		cout << "   Меню программы\n";
		cout << "0-Сведения о программисте\n";
		cout << "1 - Программы первого семестра\n";
		cout << "L - Лабиринт\n";
		cout << "R - Рекурсия";
		cout << "K - Контрольные работы(Вариант 36)";
		cout << "\n\nДля выхода изнажмите клавишу ESC\n";

		ch = _getch();

		switch (ch) {
		case '0': Creator();  break;
		case '1': FirstSem();  break;
		case 'L': case'l': case (UCHAR)'д': case (UCHAR)'Д':LabirintMenu();
		case'K':case'k':case(UCHAR)'Л':case(UCHAR)'л':KontrolnyaMenu();
		case'r':case'R':case(UCHAR)'к':case(UCHAR)'К':RecMenu(); break;
		}
	} while (ch != 27);
	return 0;
}
