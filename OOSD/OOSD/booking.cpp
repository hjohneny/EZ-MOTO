#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include "booking.h"

using namespace std;

booking::booking(string sName) :hailer(sName){

	cout << "Processing hailer bookings";
}

//polymorphism the implementation should be different than the super class
void booking::RequestTrip(){
	ofstream out;
	out.open("bookings.txt", ios::out | ios::app);
	out << name << " " << ph << " " << dd << " " << mm << " " << yy << " " << type << " " << destn << " " << cst << "\n";
	out.close();
}

void booking::CancelBooking(){
	int count = 0;
	char ch = 'n';
	ifstream in;

	in.open("bookings.txt");

	cout << "\n\n  Enter the customer's name for whom you'd like to cancel the booking: ";
	string n;
	cin >> n;
	transform(n.begin(), n.end(), n.begin(), ::toupper);

	in >> name;
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	in >> ph >> dd >> mm >> yy >> type >> destn >> cst;
	while (in)
	{
		if (n == name)
			++count;
		in >> name;
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		in >> ph >> dd >> mm >> yy >> type >> destn >> cst;

	}

	cout << "\n\n  " << count << " matching records found in database...";
	if (count > 0)
	{
		cout << " Are you sure, you want to cancel " << n << "'s booking? : (Y/N) ";
		cin >> ch;
	}

	cout << endl << endl;
	in.close();

	if (ch == 'y' || ch == 'Y')
	{
		ofstream out;
		out.open("temp");
		in.open("bookings.txt");
		in >> name;
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		in >> ph >> dd >> mm >> yy >> type >> destn >> cst;
		while (in)
		{
			if (n == name)
				goto next;
			out << name << " " << ph << " " << dd << " " << mm << " " << yy << " " << type << " " << destn << " " << cst << "\n";
		next:
			in >> name;
			transform(name.begin(), name.end(), name.begin(), ::toupper);
			in >> ph >> dd >> mm >> yy >> type >> destn >> cst;

		}
		in.close();
		out.close();
		remove("bookings.txt");
		rename("temp", "bookings.txt");
		clrscr();
		heading1();
		cout << "\n\n  " << n << "'s Booking has been cancelled.\n\n";
	}

}

void booking::CheckBookingStatus(){
	string date;
	const int nameWidth = 20;
	cout << endl;
	cout << "\t\t\t\t\t\t\t ALL SCHEDULED BOOKINGS";
	cout << "\n\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~\n\n";
	cout << "\t\b\b~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n\t  No.\t\t\b\b\b\b\b Name\t\t\b Contact No.\t\t\b\b\b\b\b Motorcycle Type\t\b Destination\t    DOJ\t\t\t\b Total Fare\n";
	cout << "\t\b\b~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl << endl;
	int i = 1;
	ifstream in;
	in.open("bookings.txt", ios::in);
	if (!in)
	{
		cout << "\n\n\n\t\t  ***** ERROR 12, FILE COULD NOT BE OPENED *****\n\n";
		exit(0);
	}

	in >> name;
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	in >> ph >> dd >> mm >> yy >> type >> destn >> cst;
	transform(destn.begin(), destn.end(), destn.begin(), ::toupper);
	string cst1 = "RM" + NumberToString(cst);
	date = NumberToString(dd) + "/" + NumberToString(mm) + "/" + NumberToString(yy);
	while (!in.eof())
	{
		printEle(" ", 10);
		printEle(i, 10);
		printEle(name, nameWidth);
		printEle(ph, nameWidth);
		type ? (printEle("EX5", nameWidth)) : (printEle("Ysuku", nameWidth));
		printEle(destn, nameWidth);
		printEle(date, nameWidth);
		printEle(cst1, nameWidth);
		cout << endl;
		in >> name;
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		in >> ph >> dd >> mm >> yy >> type >> destn >> cst;
		transform(destn.begin(), destn.end(), destn.begin(), ::toupper);
		cst1 = "RM" + NumberToString(cst);
		date = NumberToString(dd) + "/" + NumberToString(mm) + "/" + NumberToString(yy);
		i++;
	}
	in.close();
	cout << endl;
	cout << "\t\b\b~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n\t\t\t\t\t\t\t ***** END OF RECORD ******\n";
	cout << "\t\b\b~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl << endl;
}

void booking::gMotorcycle()
{
	cout << "\n   Select Motorcycle type to proceed....\n\n   1. EX5 (110cc) @ RM 3/KM\n   2. Ysuku (150cc) @ RM 3.50/KM\n\n\n\n   Enter your choice: ";
	cin >> ch;
	switch (ch)
	{
	case '1': getdata();
		type = 0;
		basefare = 7;
		dest();
		calFare(basefare);
		save2file();
		break;

	case '2': getdata();
		type = 1;
		basefare = 11;
		dest();
		calFare(basefare);
		save2file();
		break;

	default: quit();
	}
}