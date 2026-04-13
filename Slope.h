#pragma once
#include "Constraint.h"

using namespace std;

class Slope : public Constraint
{
private:
    double value;
    Piquet start;
    Piquet end;

public:
    Slope(double value = 0.0, const Piquet& start = Piquet(), const Piquet& end = Piquet());
    Slope(const Slope& other);
    ~Slope() = default;
    Slope(Slope&& other) noexcept;

    Slope& operator=(const Slope& other);
    Slope& operator=(Slope&& other) noexcept;

    double getValue() const;
    Piquet getStart() const;
    Piquet getEnd() const;

    void setValue(const double value);
    void setStart(const Piquet& start);
    void setEnd(const Piquet& end);

    bool isValid() const;

    string toString() const override;
    void readFromStream(istream& is) override;

    bool operator==(const Slope& other) const;
};
