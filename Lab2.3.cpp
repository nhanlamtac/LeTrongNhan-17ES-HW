#include <iostream>
#include <conio.h>

using namespace std;
const int MAX=1000;
class Vector
{
private:
    int n;
    float *data;
public:
    Vector(){n = 10;}

    Vector(int n)
    {

        this->n= n;
        float Data[MAX];
        for ( int i=0; i <= n; i++)
        {
            cout << "Nhap gia tri ";
            cin >> Data[i] ;
            *data = Data[i];
        }
    }
    ~Vector(){}
    int Capacity();
    void clear();
    bool contains(float elem);
    int indexOf(float elem);
    int lastIndexOf(float elem);
    bool isEmpty();
    float toArray();
    void display();
};

int Vector::Capacity()
{
    return n;
}

//Vector Vector(int n, float *a)
//{
//    for (int i = 0, i <= n, i++)
//    {
//        cout <<
//    }
//}

void Vector::clear()
{
    float data[n] = {*data};
    for (int i = 0; i <= n; i++)
    {
        data[i]=0;
    }
}

bool Vector::contains(float elem)
{
    float Data[n] = {*data};
    int c = 0;
    for ( int i = 0; i<=n; i++)
    {
        if (Data[i]== elem)
            c = c + 1;

    }
    if (c>0) return true;
    else return false;

}

int Vector::indexOf(float elem)
{
    float Data[n] = {*data};
    int i=0;
    if (contains(elem))
    {
        while (i<=n)
        {
            if (Data[i]==elem)
                break;
            else i++;
        }
    }
    return i;
}

int lastIndexOf(float elem)
{
    float Data[n] = {*data};
    int i=0;
    int c=0;
    if (contains(elem))
    {
        while (i <=n)
        {
            if(data[i]==elem)
            {
                c = i;
            }
            else i++;
        }
    }
    return c;
}

bool Vector::isEmpty()
{
    if (n<=0) return true;
}

void Vector::display()
{
    float Data[n] =  {*data};
    for (int i=0; i<=n; i++)
        cout << data[i] << "  ";
}

int main()
{
    Vector A;
    cout << A.Capacity();
    A.Vector(4);
    A.isEmpty();
    A.indexOf(5);
    A.lastIndexOf(2);
    A.display();
    A.clear();
    A.display();

    return 0;
}
