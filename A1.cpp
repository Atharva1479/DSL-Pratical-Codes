#include <iostream>
using namespace std;
struct node
{
    long long int telenum;
    node *next;
};
struct anode
{
    long long int telnum;
    int flag;
};
class Hashing
{
    node *p[10];
    anode a[10];

public:
    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            p[i] = NULL;
            a[i].flag = 0;
        }
    }
    void insertDynamic(long long int num)
    {
        long long int key;
        key = num % 10;
        node *k = new node;
        k->telenum = num;
        k->next = NULL;
        if (p[key] == NULL)
        {
            p[key] = k;
        }
        else
        {
            node *t;
            t = p[key];
            while (t != NULL)
            {
                if (t->next == NULL)
                {
                    t->next = k;
                    break;
                }
                t = t->next;
            }
        }
        cout << "Element Inserted.." << endl;
    }
    void insertStatic(long long int num)
    {
        long long int key;
        key = num % 10;
        if (a[key].flag == 0)
        {
            a[key].telnum = num;
            a[key].flag = 1;
        }
        else
        {
            while (a[key].flag == 0)
            {
                key = key + 1;
                key = key % 10;
                if (a[key].flag == 0)
                {
                    a[key].telnum = num;
                    a[key].flag = 1;
                    break;
                }
            }
        }
        cout << "Element Inserted.." << endl;
    }
    void display()
    {
        int ch;
        node *q;
        do
        {
            cout << "Enter which List of Numbers you want to Display: " << endl;
            cout << "1) Linear Probing " << endl;
            cout << "2) Seperate Chaining " << endl;
            cout << "3) Exit " << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                for (int i = 0; i < 10; i++)
                {
                    if (a[i].flag == 0)
                    {
                        cout << "----------" << endl;
                    }
                    else
                    {
                        cout << a[i].telnum << endl;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < 10; i++)
                {
                    if (p[i] == NULL)
                    {
                        cout << "----------" << endl;
                    }
                    else
                    {
                        q = p[i];
                        while (q != NULL)
                        {
                            cout << q->telenum << "-->";
                            q = q->next;
                        }
                        cout << endl;
                    }
                }
                break;
            }
        } while (ch < 3);
    }
    void create()
    {
        int count;
        int ch;
        long long int tnum;
        do
        {
            cout << "Enter the Book in which you want to enter the numbers : " << endl;
            cout << "1) Linear Probing " << endl;
            cout << "2) Seperate Chaining " << endl;
            cout << "3) Exit " << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Enter the number of Telephone numbers to be entered(Max 10 numbers) : " << endl;
                cin >> count;
                for (int i = 0; i < count; i++)
                {
                    cout << "Enter " << i + 1 << " number: " << endl;
                    cin >> tnum;
                    insertStatic(tnum);
                }
                break;
            case 2:
                cout << "Enter the number of Telephone numbers to be entered : " << endl;
                cin >> count;
                for (int i = 0; i < count; i++)
                {
                    cout << "Enter " << i + 1 << " number: " << endl;
                    cin >> tnum;
                    insertDynamic(tnum);
                }
                break;
            }
        } while (ch < 3);
    }
    void search()
    {
        long long int tele;
        long long int key2;
        int ch;
        int c = 0;
        int check = 0;
        do
        {
            cout << "Enter the Book in which you want to search the phone numbers : " << endl;
            cout << "1) Linear Probing " << endl;
            cout << "2) Seperate Chaining " << endl;
            cout << "3) Exit " << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Enter the Telephone Number to search: " << endl;
                cin >> tele;
                key2 = tele % 10;
                if (a[key2].telnum == tele)
                {
                    cout << "Element Found.." << endl;
                }
                else
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if (a[i].telnum == tele)
                        {
                            c = 1;
                            break;
                        }
                    }
                    if (c == 1)
                    {
                        cout << "Element Found.." << endl;
                    }
                    else
                    {
                        cout << "Element not Found.." << endl;
                    }
                }
                break;
            case 2:
                cout << "Enter the Telephone Number to search: " << endl;
                cin >> tele;
                key2 = tele % 10;
                if (p[key2] == NULL)
                {
                    cout << "Element not Found.." << endl;
                }
                else
                {
                    node *v;
                    v = p[key2];
                    while (v != NULL)
                    {
                        if (v->telenum == tele)
                        {
                            check = 1;
                            break;
                        }
                        v = v->next;
                    }
                    if (check == 1)
                    {
                        cout << "Element Found.." << endl;
                    }
                    else
                    {
                        cout << "Element not Found.." << endl;
                    }
                }
                break;
            }
        } while (ch < 3);
    }
    void call()
    {
        int ch;
        do
        {
            cout << "Enter your choice: " << endl;
            cout << "1) Create " << endl;
            cout << "2) Display " << endl;
            cout << "3) Search " << endl;
            cout << "4) Exit " << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            }
        } while (ch < 4);
    }
};
int main()
{
    Hashing h;
    h.call();
}
