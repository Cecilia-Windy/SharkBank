
#include "SharkInit.h"
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <Windows.h>



double rannum(double x, double y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(x, y);
    return dis(gen);
}


double Bank_MSI::Money = 0.0;
double Bank_MSI::Deposit_Int = rannum(1.55, 3.00);
double Bank_MSI::Loan_Int = rannum(2.95, 4.55);


Bank_MSI::Bank_MSI(){ }

Bank_MSI::Bank_MSI(double Money_ = 0.0)
{
    Deposit_Int = rannum(1.55, 3.00);
    Loan_Int = rannum(2.95, 4.55);
    Money = Money_;
}

Bank_MSI::~Bank_MSI()
{
    std::cout << "BMSI : [Finish]\n";
    Sleep(1000);
}


void Bank_MSI::Savings(double sav)
{
    if (sav < 0) {
        std::cout << "Error : The deposit amount is less than 0 CNY." << std::endl << std::endl;
    }
    else {
        Money += sav;
        File_System::F_Write("Msys",Money);
        std::cout << std::setprecision(2) << "Bank account balance : " << Money << " CNY." << std::endl << std::endl;

    }
    Sleep(2000);
}

bool Bank_MSI::Withdrawal(double wit)
{
    using std::cout;
    if (wit < 0) {
        cout << "Error : The withdrawal amount is less than 0 CNY." << std::endl << std::endl;
        Sleep(2000);

        return true;
    }
    else if (wit > Bank_MSI::Money)
    {
        cout << "Error : The withdrawal amount is greater than the balance." << std::endl << std::endl;
        Sleep(2000);

        return true;
    }
    else {
        Money -= wit;
        std::cout << std::setprecision(2) << "Bank account balance : " << Money << " CNY." << std::endl << std::endl;
        Sleep(2000);

        return false;
    }
}

void Bank_MSI::Estimate_Loan(double loan_money, int loan_time) const
{
    if (loan_time <= 0)
    {
        std::cout << "Error : Time cannot be negative.";
    }
    else
    {
        double interest = loan_money * loan_time * (Loan_Int / 100.0);
        double lmli = interest + loan_money;
        std::cout << std::setprecision(3)
            << "Loan " << loan_money << " CNY." << std::endl
            << lmli << " CNY should be repaid after " << loan_time << " year(s)." << std::endl << std::endl;
    }
    Sleep(2000);
}

void Bank_MSI::Estimate_asset(int years) const
{
    if (years <= 0)
    {
        std::cout << "Error : Time cannot be negative.";
    }
    else
    {
        double expected_asset = (Money * Deposit_Int / 100.0) * years + Money;
        std::cout << std::setprecision(3) << "Estimated in " << years << " years your assets are : " << expected_asset << " CNY." << std::endl << std::endl;
    }
    Sleep(2000);
}

void Bank_MSI::show() const
{
    using namespace std;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);

    cout.precision(2);

    cout << "[SHARK]" << endl
        << "Balance : " << Money << endl << endl;

    cout << "Today's lending rate : " << Loan_Int << endl
        << "Today's deposit rates : " << Deposit_Int << endl << endl;

    Bank_SSI::Sto_show();
    Bank_DCSI::DC_show();

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);

    Sleep(2000);
}

