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
    Real operator-(Real&A)
    {
        float rs = value - A.value;
        return rs;
    }
    Real operator*(Real&A)
    {
        float rs = value*A.value;
        return rs;
    }
    Real operator/(Real&A)
    {
        if (A.value!=0)
        {
            float res = value/A.value;
            return res;
        }

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
    Real D = A - B;
    Real E = A * B;
    Real F = A / B;
    C.display();
    D.display();
    E.display();
    F.display();
    getch();
    return 0;
}
