#include <iostream>
#include <fstream>
using namespace std;
class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t_____________________________________\n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t              AVON DHABA             \n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t_____________________________________\n";
    cout << "\t\t\t\t                                     \n";

    cout << "\t\t\t\t\t| 1) Administrator |\n";
    cout << "\t\t\t\t\t|                  |\n";
    cout << "\t\t\t\t\t| 2)   Buyer       |\n";
    cout << "\t\t\t\t\t|                  |\n";
    cout << "\t\t\t\t\t| 3)   Exit        |\n";
    cout << "\t\t\t\t\t|                  |\n";
    cout << "\t\t\t\t\t Please select! ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please login \n";
        cout << "\t\t\t Enter email - \n";
        cin >> email;
        cout << "\t\t\t Password  -    \n";
        cin >> password;
        if (email == "t.sahil@iitg.ac.in" && password == "123456789")
        {
            administrator();
        }

        else
        {
            cout << "Invalid Email/Password";
        }
        break;
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select form the given options :)";
    }
    }
    goto m;
}
void shopping::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t administrator menu";
    cout << "\n\t\t\t|__________1)Add the product________|";
    cout << "\n\t\t\t|                                    ";
    cout << "\n\t\t\t|__________2)Modify the product_____|";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|__________3)Delete the product_____|";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|__________4) Back to Main menu_____|";

    cout << "\n\n\t Please Enter Your choice ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid Choice!";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t  Buyer          \n";
    cout << "\t\t\t __________________________\n";
    cout << "                       \n";
    cout << "\t\t\t 1) Buy Product  \n";
    cout << "                       \n";
    cout << "\t\t\t 2) Go Back      \n";
    cout << "                       \n";
    cout << "\t\t\t  Enter Your Choice -";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "Invalid choice!!";
    }
    goto m;
}
void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t Add new Product";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout << "\n\n Name of the product ";
    cin >> pname;
    cout << "\n\n\t Pice of the product";
    cin >> price;
    cout << "\n\n\t Discount on product ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << "  " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;

        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << "  " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record inserted!!";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t Modify the record";
    cout << "\n\t\t\t Product code:";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesn't exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\tProduct new code:";
                cin >> c;
                cout << "\n\t\t Name of the product:";
                cin >> n;
                cout << "\n\t\t Price";
                cin >> p;
                cout << "\n\t\t Discount";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found sorry!!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code:";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File does't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_____________________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n|_____________________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{

    fstream data;
    int arrc[100]; // array of codes;
    int arrq[100]; // array of quantity;
    char choice;   // choice variable;
    int c = 0;     // counter variable;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";

    list();
    cout << "\n__________________________________________________________\n";
    cout << "\n|                                                         \n";
    cout << "\n             PLEASE PLACE THE ORDER                       \n";
    cout << "\n|                                                         \n";
    cout << "\n__________________________________________________________\n";

    do
    {
    m:
        cout << "\n\n Enter product code :";
        cin >> arrc[c];
        cout << "\n\n Enter the product quantity : ";
        cin >> arrq[c];
        c++;
        for (int i = 0; i < c; i++)
        {
            if (arrc[c] == arrc[i])
            {
                cout << "\n\n Duplicate product code. Please try again! ";
                goto m;
            }
        }

        cout << "\n\n Do you want to buy another product? if yes then press y else no";
        cin >> choice;
    } while (choice == 'y');

    cout << "\n\n\t\t\t ___________________________RECEIPT___________________________\n";
    cout << "\nProduct No\tProd.name \t\t  quantity\t\t Price\t\tAmount\t\t Amount with discount\n";

    for (int i = 0; i <= c; i++)
    {
        data.open("database.txt", ios::in);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == arrc[i])
            {
                amount = price * arrq[i];
                dis = amount - (amount * dis / 100);
                total += dis;
                cout << "\n"
                     << pcode << "\t\t" << pname << "\t\t\t" << arrq[i] << "\t\t\t" << price << "\t\t\t" << amount << "\t\t" << dis;
            }
            data >> pcode >> pname >> price >> dis;
        }
         data.close();

    }
   
    cout << "\n\n___________________________";
    cout << "\n Total Amount: " << total;
}

int main()
{
    shopping avon;
    avon.menu();
}