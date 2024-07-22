#pragma once

#include <string>

double rannum(double, double);

static double Add_money = rannum(10.00, 35.00);
static std::string UserName = "Temp";

class File_System;

class Bank_MSI   //Bank Money System Init
{
public:
	friend class File_System;
	friend class Bank_SSI;
	friend class Bank_DCSI;

	Bank_MSI();
	Bank_MSI(double);
	~Bank_MSI();

	void Savings(double);
	bool Withdrawal(double);
	void Estimate_Loan(double, int) const;
	void Estimate_asset(int years) const;
	void show() const;

private:
	static double Deposit_Int; //Deposit_Interest
	static double Loan_Int; //Loan_Interest

protected:
	static double Money;
};


class Bank_SSI //Bank Stock System Init
{
public:
	friend class File_System;
	friend void Bank_MSI::show() const;

	Bank_SSI();
	Bank_SSI(const std::string& co, long n);
	~Bank_SSI();

	void buy(long num);
	void sell(long num);
	static void Sto_show();

private:
	std::string company;
	static long shares;
	static double share_val;
	static double total_val;

	void set_tot() { total_val = shares * share_val; };
};

class Bank_DCSI
{
public:
	friend class File_System;
	friend void Bank_MSI::show() const;

	Bank_DCSI();
	Bank_DCSI(std::string,double);
	~Bank_DCSI();

	void DC_Savings(double);
	void DC_Withdrawal(double);
	static void DC_show();
private:
	static std::string company;
	static double DC_Money;
};

class File_System
{
public:
	File_System();
	~File_System();

	static bool F_Write(std::string Sys,double s_);
	template <typename Anytype>
	Anytype F_Read(std::string Sys);
	static struct Temp_DataD { double s; }TD;
	static struct Temp_DataL { long s; }TL;
	static inline void F_Flush();

private:
	static std::fstream User_File;
	//std::string F_path = "C:\\Program Files\\SharkBank\\Data";
	static std::string Path;
};
