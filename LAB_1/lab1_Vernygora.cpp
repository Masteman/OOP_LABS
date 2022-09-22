#include <iostream>
using namespace std;

class Square
{
    float width; // private variables
    float length;
    float result;

public:
    Square();                          // Constructor without parameters
    Square(float width, float length); // Constructor with parameters
    ~Square();                         // Destructor

    void setLength(float length);
    void setWidth(float width);

    void calc();
    void getWidth();
    void getLength();
    void getSpace();
};

Square::Square()
{
    width = length = 0;
    cout << "Constructor without parameters\n"
         << endl;
}

Square::Square(float w, float l)
{
    width = w;
    length = l;
    result = 0;
    cout << "\nConstructor with parameters\t" << w << "\t" << l << endl;
}

Square::~Square()
{
    cout << "\nDestructor" << endl;
}

void Square::setLength(float l)
{
    length = l;
}

void Square::setWidth(float w)
{
    width = w;
}

void Square::calc()
{
    result = (width * length);
}

void Square::getWidth()
{
    cout << "Width\t" << width << endl;
}

void Square::getLength()
{
    cout << "Length\t" << length << endl;
}

void Square::getSpace()
{
    cout << "\nSpace\t" << result << endl;
}

int main()
{

    Square a;

    a.setLength(4);
    a.setWidth(4);

    a.calc();

    a.getLength();
    a.getWidth();
    a.getSpace();
}
