#include "SharkInit.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

int main()
{
    using std::endl;
    using std::cout;
    using std::cin;
    using std::string;

    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

    cout << "SharkBank(Beta) V1.6.5 \nAll rights reserved (C) [SHARK] co.,ltd.\n";

    cout << endl << "<!> Only use [En letters] and [-] or It will error." << endl << "Enter Your Name : ";
    cin >> UserName;

    static Bank_MS M_user(0.0);
    static Bank_SS S_user("Shark Inc.", 0);
    static Bank_DCS DC_user("Shark Inc.", 0);

    static File_System File_Opr;


    while (true)
    {
        static int sys = 0;

        cout << UserName << " : Welcome! \n";
        cout << "Please Enter : \n"
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

                cout << "Please Enter : \n"
                    << "1: Savings \n"
                    << "2: Withdrawal \n"
                    << "3: Estimate Loan \n"
                    << "4: Estimate Asset \n"
                    << "5: Show All The Information \n"
                    << "6: EXIT \n" 
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
                static long long num_2 = 0;

                cout << "Please Enter : \n"
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
                    S_user.Sto_show();
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
                cout << "Please Enter : \n"
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

    cout << "\nWelcome to use next time! \n";

    std::cout << "\nExiting ... " << endl;
    Sleep(3 * 1000);
}