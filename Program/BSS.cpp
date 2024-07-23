#include "SharkInit.h"
#include <iostream>
#include <Windows.h>

long long Bank_SS::shares = 0;
double Bank_SS::share_val = 0.0;
double Bank_SS::total_val = 0.0;

Bank_SS::Bank_SS() { }

Bank_SS::Bank_SS(const std::string& co = "Shark Inc.", long long shares_ = 0)
{
	company = co;

	if (shares_ < 0)
	{
		std::cout << "Error : Number of shares can't be negative." << std::endl
			<< "[SHARK]" << "shares set to 0." << std::endl << std::endl;
		shares = 0;
	}
	else
	{
		shares = shares_;
	}
	share_val = rannum(9.50, 25.50);
	set_tot();
}

Bank_SS::~Bank_SS()
{
	std::cout << "BSSI : [Finish]" << std::endl << std::endl;
	Sleep(1000);
}

void Bank_SS::buy(long long num)
{
	using std::cout;
	using std::endl;

	if (num < 0)
	{
		cout << "Error : Number of shares purchased can't be negative." << endl
			<< "Transaction is aborted" << endl << endl;
	}
	else
	{
		if ((Bank_MS::Money - (num * share_val)) < 0) { cout << "Transaction is aborted" << endl << endl; }
		else
		{
			shares += num;
			Bank_MS::Money -= (num * share_val);
			File_System::F_Write("Msys",Bank_MS::Money);
			File_System::F_Write("Ssys",shares);
			set_tot();
			Sto_show();
		}
	}

	Sleep(2000);
}

void Bank_SS::sell(long long num)
{
	using std::endl;
	using std::cout;

	if (num < 0)
	{
		cout << "Error : Number of shares purchased can't be negative."
			<< "Transaction is aborted" << endl << endl;
	}
	else if (num > shares)
	{
		cout << "Error : You can't sell more than you have."
			<< "Transaction is aborted" << endl << endl;
	}
	else
	{
		shares -= num;
		set_tot();
		Bank_MS::Money += (num * share_val);
		File_System::F_Write("Msys",Bank_MS::Money);
		File_System::F_Write("Ssys",shares);
		Sto_show();
	}
	Sleep(2000);
}

void Bank_SS::Sto_show()
{
	using namespace std;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);

	cout << "[SHARK]" << endl
		<< "Shares : " << shares << endl;

	cout.precision(2);

	cout << "Share Price : " << share_val << "CNY" << endl
		<< "Total Worth : " << total_val << "CNY" << endl << endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

	Sleep(2000);
}
