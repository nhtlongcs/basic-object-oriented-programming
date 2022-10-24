#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
using namespace std;
class Cinema
{
protected:
	int m_M, m_N;
	int m_cost;
	vector<vector<bool>> m_a;

public:
	Cinema(const int &m, const int &n)
	{
		m_M = m;
		m_N = n;
		m_cost = 80000;
		m_a.resize(m);
		for (int i = 0; i < m; ++i)
			m_a[i].resize(n);
	}
	bool Check(int m, int n)
	{
		return (!m_a[m - 1][n - 1]);
	}
	int Cost(int m, int n)
	{
		int mid = (m_M + 1) / 2;
		return abs(m - mid) * 3000 + m_cost;
	}
	bool Book(int m, int n)
	{
		if (Check(m, n))
		{
			m_a[m - 1][n - 1] = 1;
			return 1;
		}
		return 0;
	}
	int Profit()
	{
		int Ans = 0;
		for (int i = 1; i <= m_M; ++i)
			for (int j = 1; j <= m_N; ++j)
				if (!Check(i, j))
				{
					Ans += Cost(i, j);
				}
		return Ans;
	}
	~Cinema(){};
};
class HighClassCinema : public Cinema
{
private:
	int m_day;

public:
	HighClassCinema(const int &m, const int &n, int day) : Cinema(m, n)
	{
		m_cost = 120000;
		m_day = day;
	}
	int Cost(int m, int n)
	{
		int Ans = Cinema::Cost(m, n);
		if (m_day == 5)
			Ans = (Ans * 80) / 100;
		return Ans;
	}

	int Profit()
	{
		int Ans = 0;
		for (int i = 1; i <= m_M; ++i)
			for (int j = 1; j <= m_N; ++j)
				if (!Check(i, j))
				{
					Ans += HighClassCinema::Cost(i, j);
				}
		return Ans;
	}

	~HighClassCinema(){};
};

#endif