#include <iostream>
#include <Windows.h>
#include "../2. 2/Piquet.h"
#include "../2. 2/Slope.h"

using namespace std;

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    // Настройка консоли для правильного отображения русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "=== Тестирование класса Пикет ===" << endl;
    Piquet p1(12, 28.37, true);    ///< Положительный пикет
    Piquet p2(0, 15.5, true);      ///< Нулевой пикет
    Piquet p3(-12, 28.37, true);   ///< Отрицательный пикет

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
    p5 = p4;  ///< Оператор копирования
    cout << "p5 после копирования из p4: " << p5 << endl;

    Piquet p6;
    p6 = std::move(p4);  ///< Оператор перемещения
    cout << "p6 после перемещения из p4: " << p6 << endl;
    cout << "p4 после перемещения (сброшен): " << p4 << endl;

    cout << "\n=== Тестирование класса Уклон ===" << endl;
    Slope s1(25, Piquet(10, 0), Piquet(20, 0));
    cout << "s1: " << s1 << endl;

    cout << "\n=== Демонстрация копирования и перемещения уклона ===" << endl;
    Slope s2;
    s2 = s1;  ///< Копирование уклона
    cout << "s2 после копирования из s1: " << s2 << endl;

    Slope s3;
    s3 = std::move(s1);  ///< Перемещение уклона
    cout << "s3 после перемещения из s1: " << s3 << endl;
    cout << "s1 после перемещения (сброшен): " << s1 << endl;

    cout << "\n=== Ручной ввод уклона ===" << endl;
    Slope s4;
    s4.readFromStream(cin);  ///< Чтение уклона из потока
    cout << "Введенный уклон: " << s4 << endl;

    cout << "\n=== Демонстрация полиморфизма ===" << endl;
    Slope s5(15, Piquet(5, 0), Piquet(15, 0));
    cout << "Объект класса Slope: " << s5 << endl;

    cout << endl;
    system("pause");
    return 0;
}
