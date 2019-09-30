#include <iostream>
#include <conio.h>

using namespace std;

const int MAXSIZE=1000;

class Matrix
{
private:
    int row;
    int col;
    float data[MAXSIZE][MAXSIZE];
public:
    Matrix()
    {
        cout << "Enter the number of rows: " ;
        cin >> row;
        cout << "Enter the number of columns: ";
        cin >> col;
        float data[row][col];
        for (int i = 0; i <= row; i++)
        {
            for (int k = 0; k <= col; k++)
            {
                cout << "Enter the value at row " << i << " column " << k;
                cin >> data[i][k];
            }
        }

    }
    Matrix (int M, int N)
    {
        row = N;
        col = M;
        float data[row][col];
        for (int i = 0; i <= row; i++)
        {
            for (int k = 0; k <= col; k++)
            {
                cout << "Enter the value at row " << i << " column " << k;
                cin >> data[i][k];
            }
        }
    }
//    Matrix(float arr[][]); // Create later
    void swap(int i, int j)
    {
        float temp[col];
        for (int t = 0; t <= col; t++)
        {
            temp[t] = data[i][t];
            data[i][t] = data[j][t];
            data[j][t] = temp[t];
        }
    }
    void swappos(int i, int j, int n, int m)
    {
        float temp;
        temp = data[i][j];
        data[i][j] = data[m][n];
        data[m][n] = temp;
    }

    Matrix transpose()
    {
        Matrix A(col, row);
        for (int m = 0, n = 0; m <= row, n <= col; m++, n++)
        {
            A.data[n][m] = data[row-m][col-n];
        }
        return A;
    }

    Matrix Add(Matrix B)
    {
        Matrix C(row, col);
        for (int i = 0, j = 0; i <= row, j <= col ; i++, j++ )
        {
            C.data[i][j] = B.data[i][j] + data[i][j];
        }
        return C;
    }

    Matrix Sub(Matrix B)
    {
        Matrix C(row, col);
        for (int i = 0, j = 0; i <= row, j <= col ; i++, j++ )
        {
            C.data[i][j] = data[i][j] - B.data[i][j];
        }
        return C;
    }

    bool equal(Matrix B)
    {
        int e = 0;
        for (int i = 0, j = 0; i <= row, j <= col ; i++, j++ )
        {
            if (data[i][j] != B.data[i][j]) e = e+1;
        }
        if (e > 0) return false;
        else return true;
    }

//    Matrix Prod(Matrix B)
//    {
//        if (col != B.row)
//            cout << "The production cant be producted. Error 404: cant find the error.";
//        else{
//            Matrix C(row, B.col)
//            for (int i = 0, j = 0; i <= row, j <= B.col ; i++, j++ )
//            {
//                C.data[i][j] =
//            }
//
//
//
//        }
//    }

};

int main()
{
    Matrix A(2, 2);
    Matrix B(2, 2);

    Matrix C = A.Add(B);
    Matrix D = A.Sub(B);
    Matrix E = A.transpose();

    cout << "Hello world!" << endl;
    return 0;
}
