#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <math.h>
class Account
{
protected:
	float m_soDu;

public:
	float baoSoDu()
	{
		return m_soDu;
	}
	void napTien(float soTien) { m_soDu += soTien; }
	bool rutTien(float soTien)
	{
		if (soTien <= m_soDu)
		{
			m_soDu -= soTien;
			return true;
		}
		return false;
	}
	Account(){};
	Account(float soDu)
	{
		m_soDu = soDu;
	}
	~Account(){};
};

class SavingAccount : public Account
{
private:
	int m_kyHangGui;
	float m_laiSuat;
	int m_soThang;

public:
	void napTien(float soTien)
	{
		int p = m_soThang / m_kyHangGui;
		m_soDu = m_soDu * pow(1 + m_laiSuat, p);
		m_soThang = 0;
		Account::napTien(soTien);
	}
	bool rutTien(float soTien)
	{
		int p = m_soThang / m_kyHangGui;
		float temp = m_soDu * pow(1 + m_laiSuat, p);
		if (soTien <= temp)
		{

			m_soDu = temp;
			return Account::rutTien(soTien);
			m_soThang = 0;
		}
		else
			return false;
	}
	void tangThang()
	{
		m_soThang++;
	}
	SavingAccount(){};
	SavingAccount(float soDu, int kyHang, float laisuat, int soThang) : Account(soDu)
	{
		m_kyHangGui = kyHang;
		m_laiSuat = laisuat;
		m_soThang = soThang;
	}
	~SavingAccount(){};
};

#endif