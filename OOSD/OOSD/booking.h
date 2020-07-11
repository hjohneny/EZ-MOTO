#include<iostream>
#include<fstream>
#include<string>
#ifndef BOOKING_h
#define BOOKING_h
#include "hailer.h"

class booking :public hailer
{

public:

	bool type;
	int basefare;
	char ch;

	booking(string sStuName); // Constructor 
	~booking() {};// Destructor 

	void RequestTrip(); //Polymorphism
	void CancelBooking();
	void CheckBookingStatus();
	void gMotorcycle();

};

#endif