#pragma once
#include "Cargo.h"
#include "LinkedQueue.h"
#include "Trucks.h"
class SpecialTrucks : public Trucks
{
private:
	TruckType typeOfTruck;
	int truckCapacity;
	Time maintenanceTime;
	int speed;
	Time deliveryInterval;
	int furthestCargoDist;
	int sumLoadUnload;


public:
	LinkedQueue<Cargo*> loadedSpecialCargo = LinkedQueue<Cargo*>();
	SpecialTrucks()
	{
		setID(0);
		typeOfTruck = Normal_Truck;
		truckCapacity = 0;
		maintenanceTime.setTime(0, 0);
		speed = 0;
		furthestCargoDist = getFurthestCargoDist();
		sumLoadUnload = getSumLoadUnload();
	}
	SpecialTrucks(int id, TruckType TT, int TC, Time MT, int Speed)
	{
		setID(id);
		typeOfTruck = TT;
		truckCapacity = TC;
		maintenanceTime = MT;
		speed = Speed;
		furthestCargoDist = getFurthestCargoDist();
		sumLoadUnload = getSumLoadUnload();
	}
	void setTruckType(TruckType type)
	{
		typeOfTruck = type;
	}
	void setTruckCapacity(int capacity)
	{
		truckCapacity = capacity;
	}
	void setMaintenanceTime(Time maintT)
	{
		maintenanceTime = maintT;
	}
	void setSpeed(int Speed)
	{
		speed = Speed;
	}
	void setDeliveryInterval(Time DI)
	{
		deliveryInterval = DI;
	}

	TruckType getTruckType()
	{
		return typeOfTruck;
	}
	int getTruckCapacity()
	{
		return truckCapacity;
	}
	Time getMaintenanceTime()
	{
		return maintenanceTime;
	}
	int getIntMT()
	{
		return maintenanceTime.toInt();
	}
	int getSpeed()
	{
		return speed;
	}
	Time getDeliveryInterval()
	{
		int x = getFurthestCargoDist();
		int DI = x / getSpeed() + sumLoadUnload + furthestCargoDist / getSpeed();

		deliveryInterval.toTime(DI);
		return deliveryInterval;
	}
	int getIntDI()
	{
		int x = getFurthestCargoDist();
		int DI = x / getSpeed() + sumLoadUnload + furthestCargoDist / getSpeed();
		return DI;
	}

	//void calculateFurthestCargo()
	//{
	//	//traverse the queue comparing cargo.distance and returning a furthest distance
	//	int furthest = 0;
	//	Cargo* c;
	//	for (int i = 0; i < getTruckCapacity(); i++)
	//	{
	//		loadedSpecialCargo.dequeue(c);
	//		int x = c->getDeliveryDistance();
	//		if (x > furthest)
	//			furthest = x;
	//		loadedSpecialCargo.enqueue(c);
	//	}
	//	furthestCargoDist = furthest;
	//}

	int getFurthestCargoDist()
	{
		int furthest = 0;
		Cargo* c;
		if (!loadedSpecialCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedSpecialCargo.dequeue(c);
				int x = c->getDeliveryDistance();
				if (c->getDeliveryDistance() == NULL)
					return 0;
				if (x > furthest)
					furthest = x;
				loadedSpecialCargo.enqueue(c);
			}
			furthestCargoDist = furthest;
			return furthestCargoDist;
		}
		return 0;
	}
	

	/*void calculatesumLoadUnload()
	{
		Cargo* c;
		int sum = 0;
		for (int i = 0; i < getTruckCapacity(); i++)
		{
			loadedSpecialCargo.dequeue(c);
			sum = sum + c->getIntLULT();
			loadedSpecialCargo.enqueue(c);
		}
		sumLoadUnload = sum;
	}*/
	int getSumLoadUnload()
	{
		Cargo* c;
		int sum = 0;
		if (!loadedSpecialCargo.isEmpty())
		{
			for (int i = 0; i < getTruckCapacity(); i++)
			{
				loadedSpecialCargo.dequeue(c);
				if (c->getIntLULT() == NULL)
					return 0;
				sum = sum + 2 * c->getIntLULT();
				loadedSpecialCargo.enqueue(c);
			}
			sumLoadUnload = sum;
			return sumLoadUnload;
		}
		return 0;
	}
};

