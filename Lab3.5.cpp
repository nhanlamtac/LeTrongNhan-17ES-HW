#include <iostream>
#include <conio.h>

using namespace std;

class Fraction
{
private:
    int numerator;
    int dinominator;
public:
    Fraction(int n, int d)
    {
        numerator = n;
        dinominator = d;
    }
    Fraction (const Fraction&A)
    {
        numerator = A.numerator;
        dinominator = A.dinominator;
    }
    Fraction operator+(Fraction&A)
    {
        Fraction B(0,1);
        B.numerator = numerator*A.dinominator + A.numerator*dinominator;
        B.dinominator = dinominator * A.dinominator;
        return B;
    }
    Fraction operator-(Fraction&A)
    {
        Fraction B(0,1);
        B.numerator = numerator*A.dinominator - dinominator*A.numerator;
        B.dinominator = dinominator*A.dinominator;
        return B;
    }
    bool operator==(Fraction&A)
    {
        int n = 1;
        int c = 0;
        if (dinominator >= A.dinominator)
        {
            while (n <= dinominator/A.dinominator )
            {
                if (A.dinominator*n == dinominator && A.numerator*n == numerator)
                {
                    c = 1;
                    break;
                }
                else
                    n++;
            }
        }
        else
        {
            while (n <= A.dinominator/dinominator )
            {
                if (dinominator*n == A.dinominator && numerator*n == A.numerator)
                {
                    c = 1;
                    break;
                }
                else
                    n++;
            }
        }
        if (c!=0)
            return true;
        else
            return false;

    }

    Fraction operator*(Fraction&A)
    {
        Fraction B(0,1);
        B.dinominator = dinominator*A.dinominator;
        B.numerator = numerator * A.numerator;
        return B;
    }

    void display()
    {
        cout << numerator << "/" << dinominator << endl;

    }

};
int main()
{
    Fraction A(1,2);
    Fraction B(1,3);
    Fraction C(3,6);
    Fraction D = A + B;
    cout << "A + B = ";
    D.display();
    Fraction E = A - B;
    cout << "A - B = ";
    E.display();
    Fraction F = A * B;
    cout << "A * B = ";
    F.display();
    if (A==B)
        cout << "A equal B" << endl;
    else
        cout << "A not equal B" << endl;
    if (A==C)
        cout << "A equal C";
    else
        cout << "A not equal C";
    return 0;
}
