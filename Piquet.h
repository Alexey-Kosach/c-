#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

class Piquet
{
private:
    int number;
    double shift;
    bool isStandard;

public:
    Piquet(int number = 0, double shift = 0.0, bool isStandard = true);
    Piquet(const Piquet& other);
    ~Piquet() = default;
    Piquet(Piquet&& other) noexcept;

    Piquet& operator=(const Piquet& other);
    Piquet& operator=(Piquet&& other) noexcept;

    int getNumber() const;
    double getShift() const;
    bool getIsStandard() const;

    double toMeters() const;

    bool operator==(const Piquet& other) const;
    bool operator!=(const Piquet& other) const;
    bool operator<(const Piquet& other) const;
    bool operator>(const Piquet& other) const;
    bool operator<=(const Piquet& other) const;
    bool operator>=(const Piquet& other) const;

    friend ostream& operator<<(ostream& os, const Piquet& p);
    friend istream& operator>>(istream& is, Piquet& p);

    string toString() const;
};