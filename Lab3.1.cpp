#include <iostream>
#include <conio.h>

using namespace std;

class Real
{
private:
    float value;
public:
    Real(float v)
    {
        value = v;
    }
    Real operator+(Real&A)
    {
        float total = value + A.value;
        return total;
    }
    void display()
    {
        cout << value << endl;
    }
};

int main()
{
    Real A(6.5);
    Real B(3.5);
    Real C = A + B;
    C.display();
    getch();
    return 0;
}
