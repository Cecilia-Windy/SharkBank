#include "SharkInit.h"
#include <iomanip>
#include <iostream>
#include <Windows.h>


Bank_DCSI::Bank_DCSI() { DC_Money += rannum(10.00, 35.00); }

Bank_DCSI::Bank_DCSI(std::string company_)
{
	using namespace std;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);

	company = company_;
	double add_money = rannum(10.00, 35.00);
	DC_Money += add_money;
	cout << setprecision(2) << "[Dream Card]" << "\a Credit " << add_money << " RMB to Your Dream Card account." << endl << endl;
}

Bank_DCSI::~Bank_DCSI() 
{ 
	std::cout << "BDCSI : [Finish]" << std::endl;
	Sleep(1000);
}

void Bank_DCSI::DC_Savings(double sav)
{
	if(sav < 0)
	{
		std::cout << "Error : The deposit amount is less than 0 RMB." << std::endl << std::endl;
		Sleep(2000);
	}
	else if(sav > Money)
	{
		std::cout << "Error : The amount cannot be greater than the balance." << std::endl << std::endl;
	}
	else
	{
		DC_Money += sav;
		Withdrawal(sav);
		std::cout << "[Dream Card] account balance : " << DC_Money << "RMB." << std::endl << std::endl;
	}
	Sleep(2000);
}

void Bank_DCSI::DC_Withdrawal(double wit)
{
	if (wit < 0)
	{
		std::cout << "Error : The withdrawal amount is less than 0 RMB." << std::endl << std::endl;
		Sleep(2000);
	}
	else if(wit > DC_Money)
	{
		std::cout << "Error : The amount cannot be greater than the balance." << std::endl << std::endl;
	}
	else
	{
		DC_Money -= wit;
		Savings(wit);
		std::cout << "[Dream Card] account balance : " << DC_Money << "RMB." << std::endl;
	}
	Sleep(2000);
}

void Bank_DCSI::DC_show() const
{
	using namespace std;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);
	cout.precision(2);

	cout << "[" << company << "]" << endl;
	cout << "Dream Card Money : " << DC_Money << "RMB" << endl << endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

	Sleep(2000);
}