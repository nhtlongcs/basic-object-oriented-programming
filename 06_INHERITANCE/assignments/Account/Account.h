#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <math.h>
class Account
{
protected:
	float m_balance;

public:
	float currBalance()
	{
		return m_balance;
	}
	void deposit(float amount) { m_balance += amount; }
	bool withdraw(float amount)
	{
		if (amount <= m_balance)
		{
			m_balance -= amount;
			return true;
		}
		return false;
	}
	Account(){};
	Account(float init_balance)
	{
		m_balance = init_balance;
	}
	~Account(){};
};

class SavingAccount : public Account
{
private:
	int m_peroid;
	float m_profitRate;
	int m_months;

public:
	SavingAccount(){};
	SavingAccount(float init_balance, int peroid, float profitRate, int months) : Account(init_balance)
	{
		m_peroid = peroid;
		m_profitRate = profitRate;
		m_months = months;
	}
	~SavingAccount(){};
	void deposit(float amount)
	{
		int p = m_months / m_peroid;
		m_balance = m_balance * pow(1 + m_profitRate, p);
		m_months = 0;
		Account::deposit(amount);
	}
	bool withdraw(float amount)
	{
		int p = m_months / m_peroid;
		float temp = m_balance * pow(1 + m_profitRate, p);
		if (amount <= temp)
		{

			m_balance = temp;
			m_months = 0;
			return Account::withdraw(amount);
		}
		else
			return false;
	}
	void incMonth()
	{
		m_months++;
	}
};

#endif