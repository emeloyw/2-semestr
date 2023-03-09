#include"Kontrolnya.h"


int KontrolnyaMenu() {
	UCHAR ch = 0;
	do {
		system("cls");
		cout << "   Меню контрольных\n";
		cout << "0-Сведения о программисте\n";
		cout << "I - информация по заданиям контрольных";
		cout << "1 - 1-я контрольная\n";
		cout << "L - 2-я контрольна\n";
		cout << "K - 3-я контрольна";
		cout << "\n\nДля выхода изнажмите клавишу ESC\n";

		ch = _getch();

		switch (ch) {
		case '0': Creator();  break;
		//case'i':case'I':case'Ш':case'ш': Info(); break;
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
	cout << "Введите значениe J:\n";
	cin >> J;
	do { // Исключение некорректного значения A
		cout << "\nВведите ненулевое значение Q:\n";
		cin >> Q;
		if (Q <= 0)
			cout << "\nQ не может принимать значение 0!\n";
	} while (Q <= 0);
	do { // Исключение некорректного значения A
		cout << "\nВведите ненулевое значение Р:\n";
		cin >> P;
		if (P <= 0)
			cout << "\nР не может принимать значение 0!\n";
	} while (P <= 0);
	x = P + ((Q - (2.58 * J)) / (P * Q));
	cout <<"\n\nРезультаты:\nx = "<< x << endl;
	N = (sqrt(abs(x + 0.5)) * (pow(sin(abs(x)), 2)));
	cout <<"\nN = "<< N << endl << "\n\n\n\n";
	PAUSE;
}

void Kontr2() {
	int r1, r2, r3;

	//if(r1==)


}
