#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Square
{
private:
    float sq_side;

public:
    Square();
    Square(float sq_side);
    ~Square();

    void setSide(float sq_side);
    float getSide();
    float getSquare();

    friend ostream &operator<<(ostream &output, Square &sq);
    Square operator+(Square &test1);
    Square operator++(int test2);
    Square operator++();
};

Square::Square()
{
    sq_side = 0;
}

Square::Square(float i)
{
    sq_side = i;
}

Square::~Square(){}

void Square::setSide(float i)
{
    sq_side = i;
}

float Square::getSide()
{
    return sq_side;
}

float Square::getSquare()
{
    return pow(sq_side,2);
}

ostream &operator<<(ostream &output, Square &sq)
{
    output << "\nSide\t" << sq.sq_side << "\nSquare\t" << sq.getSquare();
    return output;
}

Square Square::operator+(Square &test1)
{
    Square duplo;
    float newSquare = test1.getSquare() + getSquare();
    duplo.setSide(pow(newSquare, 0.5));
    return duplo;
}

Square Square::operator++()
{
    sq_side++;
    return *this;
}

Square Square::operator++(int test2)
{
    Square duplo = *this;
    sq_side++;
    return duplo;
}

int main()
{
    Square a(3);
    Square b(5);
    Square c = (a + b);

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    Square d = ++a;
    cout << d << "\n";
}