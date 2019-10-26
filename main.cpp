#include <iostream>
#include <list>

using namespace std;

class Person
{
private:
    string name;

public:
    Person()
    {
        name = "  ";
    }
    Person(string n)
    {
        this ->name = n;
    }
    string getName()
    {
        return name;
    }

};

class Student: public Person
{
private:
    float gpa;
    int id;
public:
    Student():Person()
    {
        id = 0;
        gpa = 0;
    }
    Student(int i,string name, float gp):Person(name)
    {
        this->id  = i;
        this->gpa = gp;

    }
    int getId()
    {
        return id;
    }
    float getGPA()
    {
        return gpa;
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
            cout << "*-STUDENT MANAGEMENT APPLICATION-*" << endl;
            cout << "*- Main function of the program -*" << endl;
            cout << "   1. Add a student    " << endl;
            cout << "   2. Edit student by id     " << endl;
            cout << "   3. Delete student by id     " << endl;
            cout << "   4. Sort student by GPA    "<< endl;
            cout << "   5. Sort student by name " << endl;
            cout << "   6. Show student"    << endl;
            cout << "   0. Exit        "    << endl;
            cout << "   --------------------------     " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                this->input();
                break;
            case 2:
                this->edit();
                break;
            case 3:
                this->Delete();
                break;
            case 4:
                this->sortbyGPA();
                break;
            case 5:
                this->sortbyName();
                break;
            case 6:
                this->view();
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
        float gpa;
        string name;
        cout << "Quantity of student to add  ";
        cin >> sv;
        while (i < sv)
        {
            cout << "Enter ifo for student number: " << i+1 << endl;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter id: ";
            cin >> id;
            cout << "Enter gpa: ";
            cin >> gpa;
            Student st(id,name,gpa);
            List.push_back(st);
            i++;
        }
        cout << "---------------\n\n" << endl;
    }

    void view()
    {
        list<Student> viewList = List;
        cout << "The list of student  " << endl;
        while (!viewList.empty())
        {
            Student stu = viewList.front();
            cout << "ID= " << stu.getId() << ", ten: " << stu.getName() << ", diem trung binh: " << stu.getGPA();
            float gpa = stu.getGPA();
            if(gpa>=2)
                cout << "   is Qualified" << endl;
            else
                cout << "   is fail"<< endl;
            viewList.pop_front();
        }
        cout << "\n--------------------------\n";
    }

    void edit()
    {
        int id;
        string nn;
        float ngpa;
        Student st = List.front();
        cout << "Enter the id need to edit:  ";
        cin >> id;
        cout << "Enter new name: ";
        cin >> nn;
        cout << "Enter new gpa: ";
        cin >> ngpa;
        Student nst(id,nn,ngpa);
        list<Student> cList;
        while((!List.empty())&&(st.getId()!=id))
        {
            cList.push_front(st);
            List.pop_front();
        }
        while(!cList.empty())
        {
            Student kst = cList.front();
            List.push_front(kst);
        }
//        List.merge(cList);
        List.push_front(nst);
    }

    void Delete()
    {
        int id;
        Student st = List.front();
        int pl = 0;
        cout << "Enter the id need to delete: ";
        cin >> id;
        list<Student> cList;
        while((!List.empty())&&(st.getId()!=id))
        {
            cList.push_front(st);
            List.pop_front();
        }
        while(!cList.empty())
        {
            Student kst = cList.front();
            List.push_front(kst);
        }
//        List.merge(cList);
    }
    void sortbyGPA()
    {
        float gpa[List.size()];
        int id[List.size()];
        string name[List.size()];
        float tgpa;
        int tid;
        int i=0;
        string tname;
        list <Student> unsortList = List;
        list <Student> sortedList;
        while (!unsortList.empty())
        {
            Student st = unsortList.front();
            gpa[i] = st.getGPA();
            id[i] = st.getId();
            name[i] = st.getName();
            unsortList.pop_front();
            i++;
        }
        for (int i = 0; i< List.size()-1; i++)
        {
            for (int j = i + 1; j < List.size(); j++)
            {
                if (gpa[i] > gpa[j])
                {
                    tgpa = gpa[i];
                    gpa[i] = gpa[j];
                    gpa[j] = tgpa;
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
            cout << "ID: " << id[n] << ", name: " << name[n] << ", gpa= " << gpa[n] << endl;
        }

        cout << "\n------------------------------\n";
    }

    void sortbyName()
    {
        float gpa[List.size()];
        int id[List.size()];
        string name[List.size()];
        string tname;
        float tgpa;
        int tid;
        int i=0;
        list <Student> unsortList = List;
        list <Student> sortedList;
        while (!unsortList.empty())
        {
            Student st = unsortList.front();
            gpa[i] = st.getGPA();
            id[i] = st.getId();
            name[i] = st.getName();
            unsortList.pop_front();
            i++;
        }
        for (int i = 0; i< List.size()-1; i++)
        {
            for (int j = i + 1; j < List.size(); j++)
            {
                if (name[i] > name[j])
                {
                    tname = name[i];
                    name[i] = name[j];
                    name[j] = tname;
                    tid = id[i];
                    id[i] = id[j];
                    id[j] = tid;
                    tgpa = gpa[i];
                    gpa[i] = gpa[j];
                    gpa[j] = tgpa;
                }
            }
        }
        cout << "Danh sach sinh vien sau khi sap xep: " << endl;
        for (int n = 0; n < List.size(); n++)
        {
            cout << "ID: " << id[n] << ", name: " << name[n] << ", gpa= " << gpa[n] << endl;
        }
        cout << "\n------------------------------\n";
    }
};


int main()
{
    StudentManagement();
    return 0;
}
