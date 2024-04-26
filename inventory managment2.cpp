#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class product {
protected:
    int pcode;
    float price;
    float disc;
    string pname;
    
    public:
    virtual	void add();
    };
class shopping:public product{

public:
    void menu();
    void administor();
    void buyer();    
    void edit();
    void list();
    void receipt();
    void removefile();
};

void shopping::menu() {
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t ----------------- \n";
    cout << "\t\t\t\t                   \n";
    cout << "\t\t\t\t      SUPER MARKET MAIN MENU       \n";
    cout << "\t\t\t\t                 \n";
    cout << "\t\t\t\t-----------------\n";
    cout << "\t\t\t\t 1) Administrator \n";
    cout << "\t\t\t\t                \n";
    cout << "\t\t\t\t 2)  Buyer      \n";
    cout << "\t\t\t\t                \n";
    cout << "\t\t\t\t 3)  Exit       \n";
    cout << "\t\t\t\t                \n";
    cout << "Please select from above option to continue\n";
    cin >> choice;
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    menu();
	}
    switch (choice) {
        case 1:
            cout << "Enter your e-mail \n";
            cin >> email;
       
	
            cout << "Enter your password \n";
            cin >> password;
   	
            if (email == "admin" && password == "admin") {
                administor();
            } else {
                cout << "Invalid e-mail or password";
            }
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong entry please select from above options";
    }
    goto m;
}

void shopping::administor() {
m:
    int choice;
    cout << "\t\t\t------------  Administrator menu \t\t\t\t \n";
    cout << " 1) Add the product   \n";
    cout << " 2) Modify product    \n";
    cout << " 3) Delete product    \n";
    cout << " 4) Back to main menu \n";
    cout << "Please enter your choice \n";
    cin >> choice;
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            removefile();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Invalid choice";
    }
    goto m;
}

void shopping::buyer() {
m:
    int choice;
    cout << "\t\t\t   Buyer  \n";
    cout << "1) Buy product \n";
    cout << "2) Go back    \n";
    cin >> choice;
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    buyer()	;
	}
    switch (choice) {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "Invalid choice";
    }
    goto m;
}

void product::add() {
    fstream data;
    data.open("database.txt", ios::app);
    cout << "\t\t\t Add new product   \n";
    cout << "\t\t\t  Product code   \n";
    cin >> pcode;
    
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    add()	;
	}
	
    cout << "\t\t\t  Product name   \n";
    cin >> pname;
    
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    add()	;
	}
	
    cout << "\t\t\t  Product price   \n";
    cin >> price;
    
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    add();
	}
	
    cout << "\t\t\t  Discount on product   \n";
    cin >> disc;
    
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	add();
	}
	
    data << pcode << " " << pname << " " << price << " " << disc << endl;
    data.close();
    cout << " Record inserted ";
}

void shopping::edit() {
    fstream data, temp;
    int pkey;
    cout << "\n\t\t Modify the product \n";
    cout << "\t\tEnter product code:\t\t \n";
    cin >> pkey;
    
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    edit()	;
	}
	
    data.open("database.txt", ios::in);
    temp.open("temp.txt", ios::out);
    while (data >> pcode >> pname >> price >> disc) {
        if (pkey == pcode) {
            cout << "\t\t Product new code  :\n";
            cin >> pcode;
            	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    edit()	;
	}
	
            cout << "\t\t Enter name of product:\n";
            cin >> pname;
            
            	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    edit()	;
	}
	
            cout << "\t\t Price of product \n";
            cin >> price;
            
            	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    edit()	;
	}
	
            cout << "\t\t Enter discount on product\n";
            cin >> disc;
            
            	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    edit()	;
	}
	
        }
        temp << pcode << " " << pname << " " << price << " " << disc << endl;
    }
    data.close();
    temp.close();
    remove("database.txt");
    rename("temp.txt", "database.txt");
}

void shopping::removefile() {
    fstream data, temp;
    int pkey;
    cout << "\n\t\t  Delete product";
    cout << "\n Enter Product code \n";
    cin >> pkey;
    
    	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Select from above numbers only) \n";
	    removefile()	;
	}
	
    data.open("database.txt", ios::in);
    temp.open("temp.txt", ios::out);
    while (data >> pcode >> pname >> price >> disc) {
        if (pkey != pcode) {
            temp << pcode << " " << pname << " " << price << " " << disc << endl;
        } else {
            cout << "Product deleted successfully ";
        }
    }
    data.close();
    temp.close();
    remove("database.txt");
    rename("temp.txt", "database.txt");
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n                  \n";
    cout << "ProNo\tName\tPrice \n";
    cout << "\n                  \n";
    while (data >> pcode >> pname >> price >> disc) {
        cout << pcode << "\t" << pname << "\t" << price <<"\n";
    }
    data.close();
}

void shopping::receipt() {
	m:
    fstream data;
    int arrc[100];
    int arrquant[100];
    int choice;
    int count = 0;
    float dis = 0;
    float amount = 0;
    float total = 0;
    cout << "\n\n\t\t\t\t RECEIPT\n";

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "Empty database";
    }
	 else {
        list();
        do {
            cout << "Enter product code";
            cin >> arrc[count];
            
            	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Enter numbers only) \n";
	    goto m	;
	}
	
            cout << "Enter product quantity \n";
            cin >> arrquant[count];
            
            	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Enter numbers only) \n";
	    goto m	;
	}
	
            count++;
            cout << "Do you want to buy other product (1/0)?";
            cin >> choice;
            
            	if (cin.fail())
	{
		cin.clear(); cin.ignore(512, '\n');
		cout << "Error 404 (Enter  numbers only) \n";
	    goto m	;
	}
	
        } while (choice == 1);
    data.close();
        cout << "\n\n\t\t---------------Receipt------------\n";
        cout << "Productno\tProduct name\tProduct quantity\tPrice\tAmount\t\tAmount with discount\n";
        for (int i = 0; i < count; i++) {
        
            data.open("database.txt", ios::in);
            while (data >> pcode >> pname >> price >> disc) {
            if (pcode == arrc[i]) {
            amount = price * arrquant[i];
            dis = amount - (amount * disc / 100);
            total = total + dis;
            cout << pcode << "\t\t" << pname << "\t\t" << arrquant[i] << "\t\t\t" << price << "\t" << amount << "\t\t" << dis << "\n";
                }
            }
            data.close();
        }
        cout << "\n\n------------------\n";
        cout << "Total Amount: " << total << endl;
    }
}

int main() {
    shopping obj;
    obj.menu();
    return 0;
}

