#include<iostream>
#include<fstream>
#include<string>
#ifndef BILLING_h
#define BILLING_h
#include "booking.h"
#include "account.h"

class billing :public booking,account
{

public:

	int BillingID, UserID, LocationID, BookingID;
	float TotalFare;

	billing(int BillingID); // Constructor 
	~billing() {};// Destructor 

	void GenerateBill(); //Polymorphism
	void CalCharges();
	void CalTotalPayableAmount();

};

#endif