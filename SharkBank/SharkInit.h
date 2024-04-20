#pragma once

#include <string>



double rannum(double, double);

class Bank_MSI   //Bank Money System Init
{
public:
	std::string username;

	Bank_MSI();
	Bank_MSI(std::string, double);
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


class Bank_SSI : public Bank_MSI //Bank Stock System Init
{
public:
	Bank_SSI();
	Bank_SSI(const std::string& co, long n = 0);
	~Bank_SSI();

	void buy(long num);
	void sell(long num);
	//void update(double price);
	void Sto_show() const;

private:
	std::string company;
	long shares;
	double share_val;
	double total_val;

	void set_tot() { total_val = shares * share_val; };
};

class Bank_DCSI : public Bank_MSI
{
public:
	Bank_DCSI();
	Bank_DCSI(std::string);
	~Bank_DCSI();

	void DC_Savings(double);
	void DC_Withdrawal(double);
	void DC_show() const;
private:
	std::string company;
	double DC_Money = 0.0;
};

