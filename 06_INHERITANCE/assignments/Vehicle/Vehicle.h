#ifndef VEH_H
#define VEH_H

class Vehicle
{
protected:
	double m_gasRate;
	double m_goodRate;
	double m_gas;
	double m_good;
	double m_distance;

public:
	void addGood(double good)
	{
		m_good += good;
	}
	void takeGood(double good)
	{
		m_good -= good;
	}
	void addGas(double Gas)
	{
		m_gas += Gas;
	}
	bool checkGas()
	{
		return (m_gas == 0);
	}
	double getGas()
	{
		return m_gas;
	}
	bool run(double distance)
	{
		double Temp = distance * m_gasRate + distance * m_goodRate * m_good;
		if (Temp < m_gas)
		{
			m_gas -= Temp;
			m_distance += m_distance;
			return true;
		}
		return false;
	}
	Vehicle()
	{
		m_gas = 0;
		m_good = 0;
		m_distance = 0;
	};
	Vehicle(double gas, double good, double dist)
	{
		m_gas = gas;
		m_good = good;
		m_distance = dist;
	}
	~Vehicle(){};
};
class Motor : public Vehicle
{
public:
	Motor() : Vehicle()
	{
		m_gasRate = 2.0 / 100;
		m_goodRate = (0.1 / 10) / 100;
	}
	Motor(double gas, double good, double dist) : Vehicle(gas, good, dist)
	{
		m_gasRate = 2.0 / 100;
		m_goodRate = (0.1 / 10) / 100;
	}
};
class Car : public Vehicle
{
public:
	Car() : Vehicle()
	{
		m_gasRate = 20.0 / 100;
		m_goodRate = (1.0 / 1000) / 100;
	}
	Car(double gas, double good, double dist) : Vehicle(gas, good, dist)
	{
		m_gasRate = 20.0 / 100;
		m_goodRate = (1.0 / 1000) / 100;
	}
};
#endif