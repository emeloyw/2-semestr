#include"Kontrolnya.h"


int KontrolnyaMenu() {
	UCHAR ch = 0;
	do {
		system("cls");
		cout << "   ���� �����������\n";
		cout << "0-�������� � ������������\n";
		cout << "I - ���������� �� �������� �����������";
		cout << "1 - 1-� �����������\n";
		cout << "L - 2-� ����������\n";
		cout << "K - 3-� ����������";
		cout << "\n\n��� ������ ��������� ������� ESC\n";

		ch = _getch();

		switch (ch) {
		case '0': Creator();  break;
		//case'i':case'I':case'�':case'�': Info(); break;
		case '1': Kontr1(); break;
		case '2': Kontr2(); break;
		//case '3': Kontr3(); break;
		}
	} while (ch != 27);
	return 0;
}



void Kontr1() {
	CLEAR;
	double P, Q, J, x, N;
	cout << "������� �������e J:\n";
	cin >> J;
	do { // ���������� ������������� �������� A
		cout << "\n������� ��������� �������� Q:\n";
		cin >> Q;
		if (Q <= 0)
			cout << "\nQ �� ����� ��������� �������� 0!\n";
	} while (Q <= 0);
	do { // ���������� ������������� �������� A
		cout << "\n������� ��������� �������� �:\n";
		cin >> P;
		if (P <= 0)
			cout << "\n� �� ����� ��������� �������� 0!\n";
	} while (P <= 0);
	x = P + ((Q - (2.58 * J)) / (P * Q));
	cout <<"\n\n����������:\nx = "<< x << endl;
	N = (sqrt(abs(x + 0.5)) * (pow(sin(abs(x)), 2)));
	cout <<"\nN = "<< N << endl << "\n\n\n\n";
	PAUSE;
}

void Kontr2() {
	int r1, r2, r3;

	//if(r1==)


}

