#include <iostream>

using namespace std;

class DynamicArray
{
private:
    int *array;
    int length;

public:
    DynamicArray(int length);
    ~DynamicArray();
    void output();
    friend void filter(DynamicArray &cl_obj);
};

DynamicArray::DynamicArray(int value)
{
    length = value;
    array = new int[length];
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            array[i] = i + 4.1;
        }
        else
        {
            array[i] = i - 1;
        }
    }
}

DynamicArray::~DynamicArray()
{
    delete[] array;
}

void DynamicArray::output()
{   cout << "\n";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void filter(DynamicArray &cl_obj)
{ 
    int sum = 0;
    for (int i = 0; i < cl_obj.length; i++)
    {
        if (cl_obj.array[i] %2 == 0)
        {
            cout << cl_obj.array[i] << " ";
            sum += cl_obj.array[i]; 
        }
    }
    cout << "\nSum = " << sum << "\n\n";
}

int main()
{
    DynamicArray a(15);
    a.output();
    filter(a);

    return (0);
}