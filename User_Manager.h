#pragma once
#include"User.h"
#include<iostream>
#define max_users 5 //this sets the maximum users to be allowed to create account
using namespace std;
//class for handling the users
class User_Manager
{
private:
	User* current_User;//pointer to the current user
	User users[max_users];//array to store the users
protected:
public:
	User_Manager();//constructor
	bool validate_User(string u_name, string password);//validates the user with initially stored data i.e for sign-in
	bool create_User(string u_name, string password);//creates a new user i.e for sign-up
	void get_User(string u_name, string password);//after sign-in or sign-up gets the user profile
	~User_Manager();//destructor
};