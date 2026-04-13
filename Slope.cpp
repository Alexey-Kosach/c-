#include "Slope.h"
#include <sstream>
#include <stdexcept>

using namespace std;

Slope::Slope(double value, const Piquet& start, const Piquet& end)
    : value(value), start(start), end(end)
{
}

Slope::Slope(const Slope& other)
    : value(other.value), start(other.start), end(other.end)
{
}

Slope::Slope(Slope&& other) noexcept
{
    value = other.value;
    start = std::move(other.start);
    end = std::move(other.end);

    other.value = 0.0;
}

Slope& Slope::operator=(const Slope& other)
{
    if (this != &other)
    {
        value = other.value;
        start = other.start;
        end = other.end;
    }
    return *this;
}

Slope& Slope::operator=(Slope&& other) noexcept
{
    if (this != &other)
    {
        value = other.value;
        start = std::move(other.start);
        end = std::move(other.end);

        other.value = 0.0;
    }
    return *this;
}

double Slope::getValue() const { return value; }
Piquet Slope::getStart() const { return start; }
Piquet Slope::getEnd() const { return end; }

void Slope::setValue(double value)
{
    if (value < 0 || value > 50)
        throw invalid_argument("”клон должен быть от 0 до 50 промилле");
    this->value = value;
}

void Slope::setStart(const Piquet& start) { this->start = start; }
void Slope::setEnd(const Piquet& end) { this->end = end; }

bool Slope::isValid() const
{
    return (value >= 0 && value <= 50);
}

string Slope::toString() const
{
    stringstream ss;
    ss << "”клон: " << value << "Й, от " << start << " до " << end;
    return ss.str();
}

void Slope::readFromStream(istream& is)
{
    cout << "¬ведите значение уклона (0-50 промилле): ";
    is >> value;
    while (!isValid())
    {
        cout << "ќшибка! ”клон должен быть от 0 до 50. ѕовторите ввод: ";
        is >> value;
    }

    cout << "¬ведите начало уклона:" << endl;
    is >> start;

    cout << "¬ведите конец уклона:" << endl;
    is >> end;

    if (start > end)
    {
        swap(start, end);
        cout << "Ќачало и конец были автоматически переставлены" << endl;
    }
}

bool Slope::operator==(const Slope& other) const
{
    return (abs(value - other.value) < numeric_limits<double>::epsilon()) &&
        (start == other.start) && (end == other.end);
}