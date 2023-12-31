#include"User.h"
#include<iostream>
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

}
void User::display_Profile()
{

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

void User::react_to_Post()
{
}
