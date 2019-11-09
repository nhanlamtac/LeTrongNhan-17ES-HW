#include <iostream>
#include <list>

using namespace std;

class Customer;
void Start();
class Goods;
class Market;
class StoreManage;
list<StoreManage> List;
class Goods
{
private:
    float price;
    string good;
    int quantity;
public:
    Goods()
    {
        price = 0;
        good = "  ";
    }
    Goods(string good, float price)
    {
        this->good=good;
        this->price=price;
    }
    Goods(string good, float price, int quantity)
    {
        this->good=good;
        this->price=price;
        this->quantity=quantity;
    }
    float getPrice()
    {
        return price;
    }
    string getGood()
    {
        return good;
    }
    int getQuantity()
    {
        return quantity;
    }
    virtual double calPrice(int q, float p)
    {
        return 0;
    }
};

class StoreManage:public Goods
{
private:
    int ID;
    string owner;
public:
    StoreManage(int ID, string owner, string good, float price):Goods(good,price)
    {
        this->ID= ID;
        this->owner=owner;
    }
    StoreManage():Goods()
    {
        ID  = 0;
        owner="  ";
    }
    int getID()
    {
        return ID;
    }
    string getOwner()
    {
        return owner;
    }

};

class Market
{
public:
    StoreManage storeManage();
    Goods goods();

    Market()
    {
        int choice;
        while (true)
        {
            cout << "*-MarketManagement-*" << endl;
            cout << "*- Main function of the program -*" << endl;
            cout << "   1. Add a store    " << endl;
            cout << "   2. Delete store by id     " << endl;
            cout << "   3. Show store"    << endl;
            cout << "   4. Go to the other interface.";
            cout << "   0. Exit        "    << endl;
            cout << "   --------------------------     " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                this->input();
                break;
            case 2:
                this->Delete();
                break;
            case 3:
                this->view();
                break;
            case 4:
                Start();
                return;
            default:
                cout << "Cam on da su dung chuong trinh" << endl;
                return;
            }
        }
    }


    void input()
    {
        int st;
        int i= 1;
        int id;
        float price;
        string good;
        string owner;
        cout << "Quantity of store to add  ";
        cin >> st;
        while (i <= st)
        {
            cout << "Enter info for store number: " << i << endl;
            cout << "Enter good: ";
            cin >> good;
            cout << "Enter id: ";
            cin >> id;
            cout << "Enter owner: ";
            cin >> owner;
            cout << "Enter price: ";
            cin >> price;
            StoreManage st(id,owner,good,price);
            List.push_back(st);
            i++;
        }
        cout << "---------------\n\n" << endl;
    }

    void view()
    {
        list<StoreManage> viewList = List;
        cout << "The list of store  " << endl;
        while (!viewList.empty())
        {
            StoreManage st = viewList.front();
            cout << "Store ID: "<< st.getID() << " is owned by: " << st.getOwner() << " selling " << st.getGood() << " at price " << st.getPrice() << endl;
            viewList.pop_front();
        }
        cout << "\n--------------------------\n";
    }

    void Delete()
    {
        int ID;
        cout << "Enter id to delete the store: ";
        cin >> ID;
        for (int i = 0; i<=100; i++)
        {
            StoreManage st = List.front();
            List.pop_front();
            if (st.getID()==ID)
            {
                break;
            }
            else
                List.push_back(st);
        }
    }
};

class Customer:public Market, Goods
{
public:
    StoreManage storeManage();
    Goods goods();

    list<Goods> ListOfGoods;
    Customer()
    {
        int choic;
        while (true)
        {
            cout << "*-Customer Usage-*" << endl;
            cout << "*- Main function of the program -*" << endl;
            cout << "   1. View store and good and price    " << endl;
            cout << "   2. Adding goods to buy.     " << endl;
            cout << "   3. Remove goods."    << endl;
            cout << "   4. Pay." << endl;
            cout << "   5. Changing interface." << endl;
            cout << "   0. Exit        "    << endl;
            cout << "   --------------------------     " << endl;
            cin >> choic;
            switch (choic)
            {
            case 1:
                this->view();
                break;
            case 2:
                this->AddGood();
                break;
            case 3:
                this->RemoveGood();
                break;
            case 4:
                this->Pay();
                break;
            case 5:
                Start();
                return;
            default:
                cout << "Cam on da su dung chuong trinh" << endl;
                return;
            }
        }
    }
    void AddGood()
    {
        string good;
        int quan;
        float price;
        cout << "Enter good name: ";
        cin >> good;
        list<StoreManage> viewList=List;
        while(!viewList.empty())
        {
            StoreManage st = viewList.front();
            if (st.getGood()==good)
            {
                cout << "Your good price is: " << st.getPrice() << endl;
                break;
            }
            else
                viewList.pop_front();
        }
        StoreManage stm = viewList.front();
        price = stm.getPrice();
        cout << "Your good cost :" << price << " dollars. Please enter quantity: ";
        cin >> quan;
        Goods goods(good, price, quan);
        ListOfGoods.push_front(goods);
    }

    void RemoveGood()
    {
        cout << "Im too lazy to define this function...\n" ;
    }
    double calPrice(int q, float p)
    {
        return q*p ;
    }
    void Pay()
    {
        double totPrice = 0;
        list<Goods> PayList = ListOfGoods;
        while(!PayList.empty())
        {
            Goods gs = PayList.front();
            totPrice+=calPrice(gs.getQuantity(),gs.getPrice());
            PayList.pop_front();
        }
        cout << "You have to pay: " << totPrice << " dollars.\n\n";
    }
//    friend class Market;
};
void Start()
{
    int choi;
    while(true)
    {
        cout << "This is my midterm project\n";
        cout << "1. For market manager:\n";
        cout << "2. For customer:\n";
        cout << "Choose the interface to use:  ";
        cin >> choi;
        switch(choi)
        {
        case 1:
            Market();
            break;
        case 2:
            Customer();
            break;
        default:
            return;
        }
    }

}
int main()
{
    Start();
    return 0;
}
