#include <iostream>
#include <conio.h>

using namespace std;

class Cube
{
    private: double size=10;
    public: Cube(double val)
    {
        if (val>0)
            size=val;
    };
    double GetSize(double val)
    {
        if (val>0)
        {
            size=val;
            return size;
        }
    }
    double volume()
    {
        return size*size*size;
    }
    void details()
    {
        cout << "\nDetails of the cube\n";
        cout << "Width " << size << endl;
        cout << "Length " << size << endl;
        cout << "Height " << size << endl;
        cout << "Volume " << volume() << endl;
    }
};

int main()
{
    Cube cube1(4);
    Cube cube2(3);
    Cube cube3(-2);
    cube1.details();
    cube2.details();
    cube3.details();
    return 0;
}
