#include"User.h"
#include"Post.h"
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
	rand();//just to initialize some random value
	//randomize for every user
	followers = rand() % 500;
	following = rand() % 50;
	friends = rand() % 50;
}
//constructor to initialize a user to predefined values for the sign in illustration purpose
User::User(string u_name, string pass, string name, string dob, string ab)
{
	user_name = u_name;
	password = pass;
	name_of_user = name;
	date_of_birth = dob;
	about = ab;
	rand();//just to initialize some random value
	//randomize for every user
	followers = rand() % 500;
	following = rand() % 50;
	friends = rand() % 50;
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
	cout << "\n\tEnter your Full Name: ";
	getline(cin, name_of_user, '\n');
	cout << "\n\tEnter your Date of Birth in (DD/MM/YY) Format: ";
	getline(cin, date_of_birth, '\n');
	cout << "\n\tEnter a BIO of Your's: ";
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
			<< "\n\tFollowers: " << followers
			<< "\tFollowing: " << following
			<< "\tFriends: " << friends
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
				break;
			}
			else if (choice == '2')
			{
				create_Post();
				break;
			}
			else if (choice == '3')
			{
				display_Posts();
				break;
			}
			else if (choice == '4')
			{
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
	char choice;
	system("cls");
	cout << "\n\tSelect one of the following:" << endl
		<< "\tJust Enter the Number!" << endl
		<< "\n\t1> Change Password" << endl
		<< "\t2> Change Bio" << endl;
	do
	{
		//swith choice and run the required function
		cout << "\n\tEnter your choice: ";
		choice = _getch();
		cout << choice << endl;
		if (choice == '1')
		{
			password = change_Password();//call to change password function
			break;
		}
		else if (choice == '2')
		{
			cout<<"\n\tEnter New Bio: ";
			getline(cin,about,'\n');
			cout << "\n\tBio Updated!\n\t";
			system("pause");
			break;
		}
		else
		{
			cout<<"\tInvalid Choice!"<<endl;
		}
	} while (true);
}
string User::change_Password()
{
	string temp1, temp2;
	do
	{
		cout << "\n\tEnter  Old Password: ";
		getline(cin, temp1, '\n');
		if (validate_Password(temp1))
		{
			cout << "\n\tEnter Your New Password: ";
			getline(cin, temp1, '\n');
			cout << "\tEnter Password Again: ";
			getline(cin, temp2, '\n');
			if (temp1 == temp2)
			{
				cout << "\n\tPassword Updated!\n\t";
				system("pause");
				return temp1;
			}
			else
				cout << "\tPassword Does Not Match!" << endl
				<< "\tPlease Try Again!" << endl;
		}
		else
			cout << "\n\tYou Entered the Wrong Password!" << endl;
	} while (true);
	
	
}
void User::create_Post()
{
	string temp;
	bool post_created = false;
	cout << "\n\tLet's create a Post!" << endl
		<< "\n\tEnter content of the Post and press Enter to Create:" << endl
		<< "\n\tPost: ";
	getline(cin, temp, '\n');
	for (int i = 0; i < max_posts; i++)
	{
		if (posts[i].display().empty())
		{
			if (posts[i].make_post(temp))
			{
				cout << "\n\tPost Created Successfully!\n\t";
				post_created = true;
				break;
			}
		}
		else
			post_created = false;
	}
	if(!post_created)
		cout << "\n\tPost Creation UnSuccessfull!\n\t";
	system("pause");
}

void User::display_Posts()
{
	bool post_created = false;
	for (int i = 0; i < max_posts; i++)
		if (!(posts[i].display().empty()))
			post_created = true;
	if (post_created)
	{
		cout << "\n\tYou Created the Following Posts:" << endl;
		for (int i = 0; i < max_posts && !(posts[i].display().empty()); i++)
			cout << "\n\tPost" << i + 1 << " :" << endl
			<< "\t\t" << posts[i].display() << "\n\t";
		cout << "\n\t";
		system("pause");
	}
	else		
	{
		cout << "\n\tYou Didn't Created any Post!\n\t";
		system("pause");
	}
}

void User::react_to_Post()
{
}

User::~User()
{
}
