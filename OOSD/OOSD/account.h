#include<iostream>
#include<fstream>
#include<string>
#ifndef ACCOUNT_h
#define ACCOUNT_h
#include "hailer.h"

class account :public hailer
{

public:

	bool AccountNo;
	int UserID;
	float CreditBalance;

	account(int UserID); // Constructor 
	~account() {};// Destructor 

	void CheckBalance(); //Polymorphism
	void TopUpCredit();
	void GrantBill();
	void RequestBill();

};

#endif