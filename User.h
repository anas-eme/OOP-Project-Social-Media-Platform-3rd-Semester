#pragma once
#include<iostream>
using namespace std;
//class for the user details
class User
{
private:
	string user_name;
	string password;
	string name_of_user;
protected:
public:
	User();//constructor
	User(string u_name, string pass);//parametrized constructor to create a user
	string get_Username();//function to get the username
	bool validate_Password(string password);//function to validate password
	void update_Profile();//update the user profile
	void display_Profile();//display the profile information
	void create_Post();//handle creation of a post
	void display_Posts();//display the posts created by user
	void react_to_Post();//handle the likes and comments
	~User(){}//destructor
};