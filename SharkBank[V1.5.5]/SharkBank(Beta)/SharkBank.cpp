#include "SharkInit.h"
#include <iostream>
#include <Windows.h>

int main()
{
    using std::endl;
    using std::cout;
    using std::cin;
    using std::string;

    string USERNAME;

    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

    cout << "SharkBank(Beta) V1.5.5" << std::endl
        << "版权所有 (C) [SHARK] co.,ltd. 保留所有权利." << std::endl << std::endl;

    cout << "Enter Your Name : ";
    cin >> USERNAME;
    static Bank_MSI M_user(USERNAME, 0.00);
    static Bank_SSI S_user("Shark co.,ltd.", 0);
    static Bank_DCSI DC_user("Shark co.,ltd.");

    //cout << "Enter your name : ";
    //cin >> user_name;

    //update(-, -);

    while (true)
    {
        static int sys = 0;

        cout << "[WELCOME]" << endl << endl;
        cout << "Please Enter :" << std::endl
            << "1: [Money Management System]\n"
            << "2: [Stock Management System]\n"
            << "3: [Dream_Card Management System]\n"
            << "(other to exit)\n"
            << endl;
        cin >> sys;
        switch (sys)
        {
        case 1:
            while (true)
            {
                int Options;
                static double num_1 = 0.0;
                static int years = 1;

                cout << "Please Enter : " << endl
                    << "1: Savings" << endl
                    << "2: Withdrawal" << endl
                    << "3: Estimate Loan" << endl
                    << "4: Estimate Asset" << endl
                    << "5: Show All The Information" << endl
                    << "6: EXIT" << endl
                    << endl;

                cin >> Options;

                switch (Options)
                {
                case 1:
                    cout << "Enter value:";
                    cin >> num_1;
                    M_user.Savings(num_1);
                    break;

                case 2:
                    cout << "Enter value:";
                    cin >> num_1;
                    M_user.Withdrawal(num_1);
                    break;

                case 3:
                    cout << "Enter Loan Money : ";
                    cin >> num_1;

                    cout << "Enter Loan Time(year) : ";
                    cin >> years;
                    M_user.Estimate_Loan(num_1, years);
                    break;

                case 4:
                    cout << "Enter Time(year) : ";
                    cin >> years;
                    M_user.Estimate_asset(years);
                    break;

                case 5:
                    M_user.show();
                    S_user.Sto_show();
                    DC_user.DC_show();
                    break;
                default:
                    break;
                }
                if (6 == Options)break;
            }
            break;

        case 2:
            while (true)
            {
                int Options;
                static long num_2 = 0;

                cout << "Please Enter : " << endl
                    << "1: Buy Shares\n"
                    << "2: Sell Shares\n"
                    << "3: Show Information\n"
                    << "4: EXIT\n"
                    << endl;

                cin >> Options;

                switch (Options)
                {
                case 1:
                    cout << "Enter value : ";
                    cin >> num_2;
                    S_user.buy(num_2);
                    break;

                case 2:
                    cout << "Enter value : ";
                    cin >> num_2;
                    S_user.sell(num_2);
                    break;

                case 3:
                    S_user.show();
                    break;

                default:
                    break;
                }
                if (4 == Options)break;
            }
            break;

        case 3:


            while (true)
            {
                static double num_3 = 0.0;
                int Options;
                cout << "Please Enter : " << endl
                    << "1: Savings\n"
                    << "2: Withdrawal\n"
                    << "3: Show Information\n"
                    << "4: EXIT\n"
                    << endl;
                cin >> Options;

                switch (Options)
                {
                case 1:
                    cout << "Enter value : ";
                    cin >> num_3;
                    DC_user.DC_Savings(num_3);
                    break;

                case 2:
                    cout << "Enter value : ";
                    cin >> num_3;
                    DC_user.DC_Withdrawal(num_3);
                    break;

                case 3:
                    DC_user.DC_show();
                    break;

                default:
                    break;
                }
                if (4 == Options)break;
            }

            break;

        default:
            break;
        }

        if (1 != sys && 2 != sys && 3 != sys)break;
    }

    cout << endl << "Welcome to use next time!" << endl;

    std::cout << endl << "Exiting ... " << endl;
    Sleep(3 * 1000);
}