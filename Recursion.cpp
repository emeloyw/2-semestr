#include"Recursion.h"

stRecursion RecData;
void RecMenu() {
	UCHAR ch = 0;
	do {
		system("cls");
		cout << "   ���� ��������\n";
		cout << "0 - �������� �������\n";
		//cout << "I - ���������� �� �������� �����������";
		//cout << "1 - 1-� �����������\n";
		//cout << "L - 2-� ����������\n";
		//cout << "K - 3-� ����������";
		cout << "\n\n��� ������ ��������� ������� ESC\n";

		ch = _getch();

		switch (ch) {
		case '0': RecTable();  break;
			//case'i':case'I':case'�':case'�': Info(); break;
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
		cout << "������ ������������ ������������ � ������������������\n" << "�� 20 ������, � ����������� �������������\n";

		SetColor(0, CL_LIGHT_WHITE);
		double x;
		cout << "������� ��������� �������� �="; cin >> x;

		RecData.SetCount(20);
		double y = NextRec(x, 1, 1, 0);

		printf("\n������� �������� �������� �=%f,\t��� a=%4, ", y, x);
		SetColor(CL_BLACK, CL_YELLOW);
		cout << "���\t ���� ����\t����������� ��������" << endl;
		for (int i = 0; i < RecData.nCount; i++) {
			cout << setw(4) << RecData.setRec[i].nIdSet << setw(10) << RecData.setRec[i].nValue1
				<< setw(10) << RecData.setRec[i].nValue2;
		}
}