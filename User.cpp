#include"User.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
User::User()
{

}
//constructor to initialize a user to use with signup
User::User(string u_name, string pass)
{
	user_name = u_name;
	password = pass;
}
string User::get_Username()
{
	return user_name;
}
bool User::validate_Password(string passwrd)
{
	return passwrd == password;
}
void User::create_profile()
{
	cout << "\n\tLet's Complete Your Profile!" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
	cout << "\n\tEnter your Full Name: ";
	getline(cin, name_of_user, '\n');
	cout << "\n\tEnter your Date of Birth in (DD/MM/YY) Format: ";
	getline(cin, date_of_birth, '\n');
	cout << "\n\tEnter an About of Your's: ";
	getline(cin, about, '\n');
	cout << "\n\tYour Account Created Successfully!" << endl
		<< "\tPress any key to show your Profile!";
	_getch();
}
void User::display_Profile()
{
	//this makes sure the profile of user exists
	if (name_of_user.empty())
		create_profile();
	char choice;
	do
	{
		system("cls");
		//display the profile menu
		cout << "\n\t\t" << name_of_user << "'s profile" << endl
			<< "\n\tFollowers: " << rand() % 500
			<< "\tFollowing: " << rand() % 200
			<< "\tFriends: " << rand() % 50
			<< "\n\tBio: " << about << endl
			<< "\n\tSelect one of the following:" << endl
			<< "\tJust Enter the Number!" << endl
			<< "\t1> Update profile" << endl
			<< "\t2> Create a Post" << endl
			<< "\t3> Show Posts" << endl
			<< "\t4> Sign-out" << endl
			<< "\t5> Exit Application" << endl;
		do
		{
			//swith choice and run the required function
			cout << "\tEnter your choice: ";
			choice = _getch();
			cout << choice << endl;
			if (choice == '1')
			{
				update_Profile();
			}
			else if (choice == '2')
			{
				create_Post();
			}
			else if (choice == '3')
			{
				display_Posts();
			}
			else if (choice == '4')
			{
				sign_out();
				system("cls");
				return;
			}
			else if (choice == '5')
			{
				cout << "\n\tPROGRAM EXITED!" << endl;
				_getch();
				exit(0);
			}
			else
				cout << "\tInvalid Choice!" << endl
				<< "\tPlease Enter one of the Above!" << endl;
		} while (true);
	} while (true);
}
void User::update_Profile()
{

}
void User::create_Post()
{
}

void User::display_Posts()
{
}

void User::sign_out()
{

}

void User::react_to_Post()
{
}

User::~User()
{
}
