#include "Header.h"
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"������� ������ �� ���������� \"���������� ����������������\" �������� ��������� �������");
	UCHAR ch = 0;
	do {
		system("cls");
		cout << "   ���� ���������\n";
		cout << "0-�������� � ������������\n";
		cout << "1 - ��������� ������� ��������\n";
		cout << "L - ��������\n";
		cout << "R - ��������";
		cout << "K - ����������� ������(������� 36)";
		cout << "\n\n��� ������ ��������� ������� ESC\n";

		ch = _getch();

		switch (ch) {
		case '0': Creator();  break;
		case '1': FirstSem();  break;
		case 'L': case'l': case (UCHAR)'�': case (UCHAR)'�':LabirintMenu();
		case'K':case'k':case(UCHAR)'�':case(UCHAR)'�':KontrolnyaMenu();
		case'r':case'R':case(UCHAR)'�':case(UCHAR)'�':RecMenu(); break;
		}
	} while (ch != 27);
	return 0;
}