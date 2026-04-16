#include "Constraint.h"
#include "Slope.h"

using namespace std;

Constraint& Constraint::operator=(const Constraint& other)
{
    if (this != &other)
    {
        // Базовый класс не имеет данных
        // Для наследников этот оператор нужно переопределять
    }
    return *this;
}

Constraint& Constraint::operator=(Constraint&& other) noexcept
{
    if (this != &other)
    {
        // Базовый класс не имеет данных
        // Для наследников этот оператор нужно переопределять
    }
    return *this;
}

Constraint* Constraint::readFromStdIn()
{
    cout << "Выберите тип ограничения (13 - Уклон): ";
    int type;
    cin >> type;

    if (type == 13 || type == 1)
    {
        Slope* slope = new Slope();
        slope->readFromStream(cin);
        return slope;
    }
    return nullptr;
}

ostream& operator<<(ostream& os, const Constraint& c)
{
    os << c.toString();
    return os;
}