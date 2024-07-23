
#include "SharkInit.h"
#include <iomanip>
#include <iostream>
#include <Windows.h>

double Bank_DCS::DC_Money = 0.0;
std::string Bank_DCS::company = "Shark Inc.";

Bank_DCS::Bank_DCS() {}

Bank_DCS::Bank_DCS(std::string company_ = "Shark Inc.", double DC_Money_ = 0.0)
{
	using namespace std;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);

	DC_Money = DC_Money_;
	company = company_;
	DC_Money += Add_money;
	cout << setprecision(2) << "\n[Dream Card]" << "\a Credit " << Add_money << " CNY to Your Dream Card account." << endl;
}

Bank_DCS::~Bank_DCS()
{
	std::cout << "BDCSI : [Finish]" << std::endl;
	Sleep(1000);
}

void Bank_DCS::DC_Savings(double sav)
{
	if (sav < 0)
	{
		std::cout << "Error : The deposit amount is less than 0 CNY." << std::endl
				  << std::endl;
		Sleep(2000);
	}
	else
	{
		if (sav > Bank_MS::Money)
			std::cout << "Error : The amount cannot be greater than the balance." << std::endl
					  << std::endl;
		else
		{
			DC_Money += sav;
			Bank_MS::Money -= sav;
			File_System::F_Write("DCsys", DC_Money);
			File_System::F_Write("Msys",Bank_MS::Money);
			std::cout << "[Dream Card] account balance : " << DC_Money << "CNY." << std::endl
					  << std::endl;
		}
		Sleep(2000);
	}
}
	void Bank_DCS::DC_Withdrawal(double wit)
	{
		if (wit < 0)
		{
			std::cout << "Error : The withdrawal amount is less than 0 CNY." << std::endl
					  << std::endl;
			Sleep(2000);
		}
		else if (wit > DC_Money)
		{
			std::cout << "Error : The amount cannot be greater than the balance." << std::endl
					  << std::endl;
		}
		else
		{
			DC_Money -= wit;
			Bank_MS::Money += wit;
			File_System::F_Write("DCsys", DC_Money);
			std::cout << "[Dream Card] account balance : " << DC_Money << "CNY." << std::endl;
		}
		Sleep(2000);
	}

	void Bank_DCS::DC_show()
	{
		using namespace std;
		ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
		streamsize prec = cout.precision(3);
		cout.precision(2);

		cout << "[" << company << "]" << endl;
		cout << "Dream Card Money : " << DC_Money << "CNY" << endl
			 << endl;

		cout.setf(orig, ios_base::floatfield);
		cout.precision(prec);

		Sleep(2000);
	}
