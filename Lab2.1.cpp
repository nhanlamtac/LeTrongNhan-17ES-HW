/* Production of a Complex number and a Real number: m(a+jb)=ma + jmb
Create a friend function of both classes (Real and Complex) to perform this operation
*/
#include <iostream>
#include <conio.h>

using namespace std;

class Complex;
class Real
{
private:
 float value;
public:
 Real(float v=0)
 {
 value=v;
 }
 void display()
 {
 cout<<value;
 }
 friend Complex &prod(Real &A, Complex &B);
};
class Complex
{
private:
 float real, image;
public:
 Complex(float a=0, float b=0)
 {
 real=a;
 image=b;
 }
 void display()
 {
 cout<<real<<" + j*"<<image;
 }
 friend Complex &prod(Real &A, Complex &B);
};
//Define the production function of a Real and a Complex
Complex &prod(Real &A, Complex &B)
{
Complex C;
C.real=A.value*B.real;
C.image=A.value*B.image;
return C;
}
main()
{
Real A(6);
Complex B(5, 4);
A.display();
cout<<"*(";
B.display();
cout<<")= ";
Complex C= prod(A,B);
C.display();
getch();
}
