#include "Piquet.h"
#include <sstream>
#include <iomanip>

using namespace std;

Piquet::Piquet(int number, double shift, bool isStandard)
    : number(number), shift(shift), isStandard(isStandard)
{
}

Piquet::Piquet(const Piquet& other)
    : number(other.number), shift(other.shift), isStandard(other.isStandard)
{
}

Piquet::Piquet(Piquet&& other) noexcept
{
    number = other.number;
    shift = other.shift;
    isStandard = other.isStandard;

    other.number = 0;
    other.shift = 0.0;
    other.isStandard = true;
}

Piquet& Piquet::operator=(const Piquet& other)
{
    if (this != &other)
    {
        number = other.number;
        shift = other.shift;
        isStandard = other.isStandard;
    }
    return *this;
}

Piquet& Piquet::operator=(Piquet&& other) noexcept
{
    if (this != &other)
    {
        number = other.number;
        shift = other.shift;
        isStandard = other.isStandard;

        other.number = 0;
        other.shift = 0.0;
        other.isStandard = true;
    }
    return *this;
}

int Piquet::getNumber() const { return number; }
double Piquet::getShift() const { return shift; }
bool Piquet::getIsStandard() const { return isStandard; }

double Piquet::toMeters() const
{
    return number * 100.0 + shift;
}

bool Piquet::operator==(const Piquet& other) const
{
    return (number == other.number) &&
        (abs(shift - other.shift) < numeric_limits<double>::epsilon()) &&
        (isStandard == other.isStandard);
}

bool Piquet::operator!=(const Piquet& other) const
{
    return !(*this == other);
}

bool Piquet::operator<(const Piquet& other) const
{
    return toMeters() < other.toMeters();
}

bool Piquet::operator>(const Piquet& other) const
{
    return toMeters() > other.toMeters();
}

bool Piquet::operator<=(const Piquet& other) const
{
    return toMeters() <= other.toMeters();
}

bool Piquet::operator>=(const Piquet& other) const
{
    return toMeters() >= other.toMeters();
}

string Piquet::toString() const
{
    stringstream ss;
    if (number >= 0)
    {
        ss << "ПК " << number << "+" << fixed << setprecision(2) << shift;
    }
    else
    {
        ss << "ПК 0" << abs(number) << "+" << fixed << setprecision(2) << shift;
    }
    return ss.str();
}

ostream& operator<<(ostream& os, const Piquet& p)
{
    os << p.toString();
    return os;
}

istream& operator>>(istream& is, Piquet& p)
{
    cout << "Введите номер пикета (целое): ";
    is >> p.number;
    cout << "Введите смещение (метры): ";
    is >> p.shift;
    cout << "Стандартный? (1 - да, 0 - нет): ";
    int standard;
    is >> standard;
    p.isStandard = (standard == 1);
    return is;
}