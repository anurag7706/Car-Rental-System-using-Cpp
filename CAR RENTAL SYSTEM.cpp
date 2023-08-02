#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iomanip>

using namespace std;

void login(); 

class customer
{
private:
public:
    string customername;
    string carmodel;
    string carnumber;
    char data;
};

class rent : public customer
{
public:
    int days = 0, rentalfee = 0;

    void inputData()
    {
        login();
        cout << "\t\t\t\tPlease Enter your Name: ";
        cin >> customername;
        cout << endl;

        do
        {
            cout << "\t\t\t\tPlease Select a Car" << endl;
            cout << "\t\t\t\tEnter 'A' for Tesla 20011." << endl;
            cout << "\t\t\t\tEnter 'B' for Hyundai 2015." << endl;
            cout << "\t\t\t\tEnter 'C' for Ford 2017." << endl;
            cout << "\t\t\t\tChoose a Car from the above options: ";
            cin >> carmodel;
            cout << endl;

            
        } while (carmodel != "A" && carmodel != "B" && carmodel != "C");

        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Please provide the following information: " << endl;
        cout << "Please select a Car No. : ";
        cin >> carnumber;
        cout << "Number of days you wish to rent the car: ";
        cin >> days;
        cout << endl;
    }

    void calculate()
    {
        sleep(1);
        system("clear");
        cout << "Calculating rent. Please wait..." << endl;
        sleep(2);

        if (carmodel == "A" || carmodel == "a")
            rentalfee = days * 56;
        else if (carmodel == "B" || carmodel == "b")
            rentalfee = days * 60;
        else if (carmodel == "C" || carmodel == "c")
            rentalfee = days * 75;
    }

    void showRent()
    {
        cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
        cout << "\t\t    /////////////////////////////////////////////////////////////" << endl;
        cout << "\t\t    | Invoice No. :" << "------------------|" << setw(10) << "#Cnb81353" << " |" << endl;
        cout << "\t\t    | Customer Name:" << "-----------------|" << setw(10) << customername << " |" << endl;
        cout << "\t\t    | Car Model :" << "--------------------|" << setw(10) << carmodel << " |" << endl;
        cout << "\t\t    | Car No. :" << "----------------------|" << setw(10) << carnumber << " |" << endl;
        cout << "\t\t    | Number of days :" << "---------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t    | Your Rental Amount is :" << "--------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t    | Caution Money :" << "----------------|" << setw(10) << "0" << " |" << endl;
        cout << "\t\t    | Advanced :" << "---------------------|" << setw(10) << "0" << " |" << endl;
        cout << "\t\t     ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t    | Total Rental Amount is :" << "-------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t     ________________________________________________________" << endl;
        cout << "\t\t     # This is a computer-generated invoice and it does not" << endl;
        cout << "\t\t     require an authorized signature #" << endl;
        cout << " " << endl;
        cout << "\t\t    /////////////////////////////////////////////////////////////" << endl;
        cout << "\t\t    You are advised to pay up the amount before the due date." << endl;
        cout << "\t\t    Otherwise, a penalty fee will be applied." << endl;
        cout << "\t\t    /////////////////////////////////////////////////////////////" << endl;
        int f;
        system("PAUSE");

        system("clear");

        ifstream inf("thanks.txt");
        char str[300];
        while (inf)
        {
            inf.getline(str, 300);
            if (inf)
                cout << str << endl;
        }
        inf.close();
    }
};

class welcome
{
public:
    void displayWelcome()
    {
        ifstream in("welcome.txt");
        if (!in)
        {
            cout << "By ANURAG ";
        }

        char str[1000];
        while (in)
        {
            in.getline(str, 1000);
            if (in)
                cout << str << endl;
        }
        in.close();
        sleep(1);
        cout << "\nStarting the program, please wait..." << endl;
        sleep(1);
        cout << "\nLoading up files..." << endl;
        sleep(1);
        system("clear");
    }
};

void login()
{
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
    cout << "\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\tEnter Password: ";
    ch = getchar();
    while (ch != '\n') // Read until the Enter key is pressed
    {
        pass.push_back(ch);
        ch = getchar();
    }
    if (pass == "pass")
    {
        cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
        sleep(2);
        system("clear");
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again!\n\n";
        sleep(2);
        system("clear");
        login();
    }
}

int main()
{
    welcome obj;
    obj.displayWelcome();

    rent r;
    r.inputData();
    r.calculate();
    r.showRent();

    return 0;
}

