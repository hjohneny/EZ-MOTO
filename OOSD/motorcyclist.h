#ifndef MOTORCYCLIST_h
#define MOTORCYCLIST_h

class motorcyclist :public user
{
public:
	int UserID;
	float Rating;
	string UserName, UserPassword ,Location;
	void Login()
	{
		clrscr();
		heading1();
		cout << "\n  Enter motorcyclist details & ride details...\n\n";
		cout << "\n  Enter the motorcyclist username: ";
		cin >> UserName;
		cout << "  Enter password: ";
		cin >> UserPassword;
	//search user database

	}
	void Register()//Register into database
	{
		ifstream in;

		cout << "  Enter your Name: ";
		in.open("database.txt", ios::in);
		cin >> UserName;

		cout << "  Enter your password: ";
		in.open("database.txt", ios::in);
		cin >> UserPassword;

	}
	void RateUser()
	{
	}
	void AcceptRequest()
	{
	}
	void GetLocation()
	{
	}
	void ViewHailerDetails()
	{
	}
};

#endif