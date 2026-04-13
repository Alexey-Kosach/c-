#pragma once
#include <iostream>
#include <string>
#include "Piquet.h"

using namespace std;

class Constraint
{
public:
    virtual ~Constraint() = default;

    virtual string toString() const = 0;
    virtual void readFromStream(istream& is) = 0;

    static Constraint* readFromStdIn();

    Constraint& operator=(const Constraint& other);
    Constraint& operator=(Constraint&& other) noexcept;

    friend ostream& operator<<(ostream& os, const Constraint& c);
};