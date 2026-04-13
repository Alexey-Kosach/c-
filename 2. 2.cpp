#include <iostream>
#include <Windows.h>
#include "../2. 2/Piquet.h"
#include "../2. 2/Slope.h"

using namespace std;

int main()
{
    // Настройка консоли для правильного отображения русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Тестирование класса Пикет ===" << endl;
    Piquet p1(12, 28.37, true);
    Piquet p2(0, 15.5, true);
    Piquet p3(-12, 28.37, true);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;

    cout << "\n=== Сравнение пикетов ===" << endl;
    cout << "p1 < p2: " << (p1 < p2 ? "да" : "нет") << endl;
    cout << "p1 > p2: " << (p1 > p2 ? "да" : "нет") << endl;

    cout << "\n=== Демонстрация операторов присваивания ===" << endl;

    Piquet p4(5, 10.5, true);
    Piquet p5;
    cout << "p5 до присваивания: " << p5 << endl;
    p5 = p4;
    cout << "p5 после копирования из p4: " << p5 << endl;

    Piquet p6;
    p6 = std::move(p4);
    cout << "p6 после перемещения из p4: " << p6 << endl;
    cout << "p4 после перемещения (сброшен): " << p4 << endl;

    cout << "\n=== Тестирование класса Уклон ===" << endl;
    Slope s1(25, Piquet(10, 0), Piquet(20, 0));
    cout << "s1: " << s1 << endl;

    cout << "\n=== Демонстрация копирования и перемещения уклона ===" << endl;
    Slope s2;
    s2 = s1;
    cout << "s2 после копирования из s1: " << s2 << endl;

    Slope s3;
    s3 = std::move(s1);
    cout << "s3 после перемещения из s1: " << s3 << endl;
    cout << "s1 после перемещения (сброшен): " << s1 << endl;

    cout << "\n=== Демонстрация полиморфизма ===" << endl;
    Constraint* constraint = new Slope(15, Piquet(5, 0), Piquet(15, 0));
    cout << "Через указатель на базовый класс: " << *constraint << endl;
    delete constraint;

    cout << endl;
    system("pause");
    return 0;
}
