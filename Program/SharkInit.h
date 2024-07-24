#pragma once

#include <string>

double rannum(double, double);

static std::string UserName = "Temp";

class File_System;

class Bank_MS   //Bank Money System
{
public:
	friend class File_System;
	friend class Bank_SS;
	friend class Bank_DCS;

	Bank_MS();
	Bank_MS(double);
	~Bank_MS();

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


class Bank_SS //Bank Stock System
{
public:
	friend class File_System;
	friend void Bank_MS::show() const;

	Bank_SS();
	Bank_SS(const std::string& co, long long shares_);
	~Bank_SS();

	void buy(long long num);
	void sell(long long num);
	static void Sto_show();

private:
	std::string company;
	static long long shares;
	static double share_val;
	static double total_val;

	void set_tot() { total_val = shares * share_val; };
};

class Bank_DCS //Bank Dream Card System
{
public:
	friend class File_System;
	friend void Bank_MS::show() const;

	Bank_DCS();
	Bank_DCS(std::string,double);
	~Bank_DCS();

	void DC_Savings(double);
	void DC_Withdrawal(double);
	static void DC_show();
private:
	static std::string company;
	static double DC_Money;
};

class File_System //File Operation
{
public:
	File_System();
	~File_System();

	static bool F_Write(std::string Sys,double s_);
	void F_Read(std::string Sys, double& Data);
	void F_Read(std::string Sys, long long& Data);
	static inline void F_Flush();

private:
	static std::fstream User_File;
	static std::string Path;
};
