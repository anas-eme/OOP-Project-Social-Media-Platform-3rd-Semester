#pragma once
#include<iostream>
using namespace std;
//class for the user details
class User
{
private:
	string user_name;//stores the username
	string password;//stores the password
	string name_of_user;//stores the name of the user
	string date_of_birth;//stores the date of birth of the user
	string about;//store the about of the user
protected:
public:
	User();//constructor
	User(string u_name, string pass);//parametrized constructor to create a user
	string get_Username();//function to get the username
	bool validate_Password(string password);//function to validate password
	void create_profile();//function to create the profile after sign up
	void display_Profile();//display the profile information
	void update_Profile();//update the user profile
	void create_Post();//handle creation of a post
	void display_Posts();//display the posts created by user
	void sign_out();//sign out the user account
	void react_to_Post();//handle the likes and comments
	~User();//destructor
};