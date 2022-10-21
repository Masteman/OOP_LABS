#include <iostream>
#include <math.h>

class Figure2D {
public:
		virtual float getResult() = 0;
		virtual void print() = 0;
};

class Equil_Triangle : public Figure2D {
private:
		float _side_a;
public:
		Equil_Triangle(float side_a)
		{
				_side_a = side_a;
		}
		Equil_Triangle() : Equil_Triangle(0) {}
		float getResult() override
		{
				return (sqrt(3) * pow(_side_a, 2)) / 4;
		}
		void setSide_A(float side_a)
		{
				_side_a = side_a;
		}
		void print() override
		{
				std::cout << "Equil_Triangle: Side_A: " << _side_a << "\n\t\t\t\tResult: " << getResult() << std::endl;
		}
};

class Triangle : public Figure2D {
private:
		float _side_a;
		float _height;
public:
		Triangle(float side_a, float height)
		{
				_side_a = side_a;
				_height = height;
		}
		Triangle() : Triangle(0, 0) {}
		float getResult() override
		{
				return 0.5 * _side_a * _height;
		}
		void setSide_A(float side_a)
		{
				_side_a = side_a;
		}
		void setHeight(float height)
		{
				_height = height;
		}
		void print() override
		{
				std::cout << "\n\t  Triangle: Side_A: " << _side_a << "\n\t\t\t\tHeight: " << _height << "\n\t\t\t\tResult: " << getResult() << std::endl;
		}
};

class Trapeze : public Figure2D {
private:
		float _side_a;
    float _side_b;
    float _height;
public:
		Trapeze(float side_a, float side_b, float height)
		{
				_side_a = side_a;
        _side_b = side_b;
        _height = height;
		}
		Trapeze() : Trapeze(0, 0, 0) {}
		float getResult() override
		{
				return 0.5 * (_side_a + _side_b)  * _height;
		}
		void setSide_A(float side_a)
		{
				_side_a = side_a;
		}
    void setSide_B(float side_b)
		{
				_side_b = side_b;
		}
    void setHeight(float height)
		{
				_height = height;
		}
		void print() override
		{
				std::cout << "\n\t   Trapeze: Side_A: " << _side_a << "\n\t\t\t\tSide_B: " << _side_b << "\n\t\t\t\tHeight: " << _height<< "\n\t\t\t\tResult: " << getResult() << std::endl;
		}
};

int main()
{
		Figure2D *shapes[3];
		shapes[0] = new Equil_Triangle(2);
		shapes[1] = new Triangle(2, 4);
		shapes[2] = new Trapeze(2, 4, 8);
		for (int i = 0; i < 3; i++)
		{
				shapes[i]->print();
		}
}