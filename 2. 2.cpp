#include <iostream>
#include "../2. 2/Piquet.h"
#include "../2. 2/Slope.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

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

    cout << "\n=== Тестирование класса Уклон ===" << endl;
    Slope s1(25, Piquet(10, 0), Piquet(20, 0));
    cout << "s1: " << s1 << endl;

    Slope s2;
    cout << "\nВведите уклон (ручной ввод):" << endl;
    s2.readFromStream(cin);
    cout << "Введенный уклон: " << s2 << endl;

    cout << "\n=== Демонстрация полиморфизма ===" << endl;
    Constraint* constraint = new Slope(15, Piquet(5, 0), Piquet(15, 0));
    cout << "Через указатель на базовый класс: " << *constraint << endl;
    delete constraint;

    return 0;
}