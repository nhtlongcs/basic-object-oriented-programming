#ifndef VEH_H
#define VEH_H

class Vehicle
{
protected:
	double m_gasRate;  // gallons per km
	double m_goodRate; // goods per km
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
		double Temp = distance * (m_gasRate + m_goodRate * m_good);
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
class Bike : public Vehicle
{
public:
	Bike() : Vehicle()
	{
		m_gasRate = 2.0 / 100;
		m_goodRate = (0.1 / 10) / 100;
	}
	Bike(double gas, double good, double dist) : Vehicle(gas, good, dist)
	{
		m_gasRate = 2.0 / 100;
		m_goodRate = (0.1 / 10) / 100;
	}
};
class Truck : public Vehicle
{
public:
	Truck() : Vehicle()
	{
		m_gasRate = 20.0 / 100;
		m_goodRate = (1.0 / 1000) / 100;
	}
	Truck(double gas, double good, double dist) : Vehicle(gas, good, dist)
	{
		m_gasRate = 20.0 / 100;
		m_goodRate = (1.0 / 1000) / 100;
	}
};
#endif