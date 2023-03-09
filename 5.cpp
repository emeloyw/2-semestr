#include "Header.h"
int FirstSem() {
    setlocale(LC_ALL, "Russian");
    UCHAR ch = 0;

    do { 
        CLEAR;
        cout << "   Меню первого семестра" << endl;
        cout << "0 - Сведения программисте\n";
        cout << "1 - Задание 2.1 Вычисления с выбором формул" << endl;
        cout << "2 - Задание 2.2. Анализ данных и принятие решения" << endl;
        cout << "3 - Задание 3.1 Обработка одномерных массивов(типовая)" << endl;
        cout << "4 - Задание 3.2 Обработка одномерных массивов: с ветвлением алгоритма" << endl;
        cout << "5 - Задание 4. Обработка матриц" << endl;
        cout << "6 - Задание 5. Маска";
        cout << "\n\nДля выхода нажмите клавишу ESC\n" << endl;

        ch = _getch();
        switch (ch) {
        case '1':
            lab2_1();
            break;
        case '2':
            lab2_2();
            break;
        case '3':
            lab3_1();
            break;
        case '4':
            lab3_2();
            break;
        case '5':
            lab4();
            break;
        case '0':
            Creator();
            break;
        case '6':
            Maska();
            break;
        }
    } while (ch != 27);

    return 0;
}

