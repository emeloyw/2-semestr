#include"Recursion.h"

stRecursion RecData;
void RecMenu() {
	UCHAR ch = 0;
	do {
		system("cls");
		cout << "   Меню Рекурсии\n";
		cout << "0 - Рекурсия Таблица\n";
		//cout << "I - информация по заданиям контрольных";
		//cout << "1 - 1-я контрольная\n";
		//cout << "L - 2-я контрольна\n";
		//cout << "K - 3-я контрольна";
		cout << "\n\nДля выхода изнажмите клавишу ESC\n";

		ch = _getch();

		switch (ch) {
		case '0': RecTable();  break;
			//case'i':case'I':case'Ш':case'ш': Info(); break;
		//case '1': Kontr1(); break;
		//case '2': Kontr2(); break;
			//case '3': Kontr3(); break;
		}
	} while (ch != 27);
}

double NextRec(double xxx, int n, double An, double nSum) {
	An = (n == 1) ? An * xxx * xxx / n : An * (n - 1) * xxx * xxx / n;
	nSum = nSum + An;
	RecData.setRec[n].nIdSet = n;
	RecData.setRec[n].nValue1 = An;
	RecData.setRec[n].nValue2 = nSum;

	
	if (n < 10) return NextRec(xxx, n + 1, An, nSum);
	return nSum;
}
void RecTable() {
	CLEAR;
	SetColor(CL_BLACK, CL_LIGHT_BLUE);
		cout << "Расчет рекурентного соотоношения в последовательности\n" << "из 20 членов, с последующим суммированием\n";

		SetColor(0, CL_LIGHT_WHITE);
		double x;
		cout << "Введите начальное значение х="; cin >> x;

		RecData.SetCount(20);
		double y = NextRec(x, 1, 1, 0);

		printf("\nВывести конечные значения у=%f,\tпри a=%4, ", y, x);
		SetColor(CL_BLACK, CL_YELLOW);
		cout << "№пп\t член ряда\tнакопленное значение" << endl;
		for (int i = 0; i < RecData.nCount; i++) {
			cout << setw(4) << RecData.setRec[i].nIdSet << setw(10) << RecData.setRec[i].nValue1
				<< setw(10) << RecData.setRec[i].nValue2;
		}
}
