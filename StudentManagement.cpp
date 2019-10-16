#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Student
{
private:
    int id;
    string name;
    float aver;
public:
    Student()
    {
        id = 0;
        aver = 0;
        name = "  ";
    }
    Student ( int i, string n, float a)
    {
        id = i;
        name = n;
        aver = a;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    float getAver()
    {
        return aver;
    }
};

class StudentManagement
{
public:
    Student student();
    list <Student> List;

    StudentManagement()
    {
        int choice;
        while (true)
        {
            cout << "*-CHUONG TRINH QUAN LY SINH VIEN-*" << endl;
            cout << "*- Chuc nang chinh chuong trinh -*" << endl;
            cout << "   1. Nhap danh sach sinh vien    " << endl;
            cout << "   2. Xem danh sach sinh vien     " << endl;
            cout << "   3. Sap xep sinh vien tang dan diem trung binh    "<< endl;
            cout << "   4. Tim kiem sinh vien " << endl;
            cout << "   5, Thoat"    << endl;
            cout << "   --------------------------     " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                this->input();
                break;
            case 2:
                this->view();
                break;
            case 3:
                this->sorter();
                break;
            case 4:
                this->searcher();
                break;
            default:
                cout << "Cam on da su dung chuong trinh" << endl;
                return;
            }
        }
    }

void input()
{
    int sv;
    int i= 0;
    int id;
    float aver;
    string name;
    cout << "Nhap so luong sinh vien:  ";
    cin >> sv;
    while (i < sv)
    {
        cout << "Nhap thong tin cho sinh vien thu " << i+1 << endl;
        cout << "Nhap ten: ";
        cin >> name;
        cout << "Nhap id: ";
        cin >> id;
        cout << "Nhap diem trung binh: ";
        cin >> aver;
        Student st(id,name,aver);
        List.push_back(st);
        i++;
    }
    cout << "---------------\n\n" << endl;
}

void view()
{
    list<Student> viewList = List;
    cout << "Thong tin danh sach sinh vien:  " << endl;
    while (!viewList.empty())
    {
        Student stu = viewList.front();
        cout << "ID= " << stu.getId() << ", ten: " << stu.getName() << ", diem trung binh: " << stu.getAver() << endl;
        viewList.pop_front();
    }
    cout << "\n\n";
}

void sorter()
{
    float aver[List.size()];
    int id[List.size()];
    string name[List.size()];
    float taver;
    int tid;
    int i=0;
    string tname;
    list <Student> unsortList = List;
    while (!unsortList.empty())
    {
        Student st = unsortList.front();
        aver[i] = st.getAver();
        id[i] = st.getId();
        name[i] = st.getName();
        unsortList.pop_front();
        i++;
    }
    for (int i = 0; i< List.size()-1; i++)
    {
        for (int j = i + 1; j < List.size(); j++)
        {
            if (aver[i] > aver[j])
            {
                taver = aver[i];
                aver[i] = aver[j];
                aver[j] = taver;
                tid = id[i];
                id[i] = id[j];
                id[j] = tid;
                tname = name[i];
                name[i] = name[j];
                name[j] = tname;
            }
        }
    }
    cout << "Danh sach sinh vien sau khi sap xep: " << endl;
    for (int n = 0; n < List.size(); n++)
    {
        cout << "ID= "<< id[n] << ", ten: " << name[n] << ", diem trung binh: " << aver[n] << endl;
    }
    cout << "\n\n";
}

void searcher()
{
    string name;
    list <Student> searchlist= List;
    cout << "Nhap ten sinh vien can tim: ";
    cin >> name;
    while (!searchlist.empty())
    {
        Student stu = searchlist.front();
        if (stu.getName()==name)
        {
            cout << "Thong tin sinh vien can tim: " << endl;
            cout << "ID= " << stu.getId() << ", ten: " << stu.getName() << ", diem trung binh: " << stu.getAver() << endl;
        }
        searchlist.pop_front();
    }
    cout << "\n\n";
}

};



int main()
{
    StudentManagement();
    return 0;
}
