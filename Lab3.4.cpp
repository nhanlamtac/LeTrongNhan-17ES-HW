#include <iostream>
#include <conio.h>

using namespace std;

class Complex
{
private:
    float real;
    float image;
public:
    Complex (float r, float i)
    {
        real = r;
        image = i;
    }

    Complex (const Complex&A)
    {
        real = A.real;
        image = A.image;
    }

    Complex operator+(Complex&A)
    {
        Complex C(0, 0);
        C.real = real + A.real;
        C.image = image + A.image;
        return C;
    }
    Complex operator-(Complex&A)
    {
        Complex C(0, 0);
        C.real = real - A.real;
        C.image = image - A.image;
        return C;
    }
    bool operator==(Complex&A)
    {
        if(real==A.real && image == A.image)
            return true;
        else return false;
    }
    Complex operator*(Complex&A)
    {
        Complex C(0, 0);
        C.real = real * A.real - image*A.image;
        C.image = real*A.image + image*A.real;
        return C;
    }
    void display()
    {
        cout << real << " + " << image << "i" << endl;
    }
};


int main()
{
    Complex A(3,1);
    Complex B(2,5);
    Complex C = A + B;
    cout << "A + B = ";
    C.display();
    Complex D = A - B;
    cout << "A - B = ";
    D.display();
    Complex E = A * B;
    cout << "A * B = ";
    E.display();
    if ( A==B)
        cout << "A equal B ";
    else
        cout << "A not equal B ";
    return 0;
}
