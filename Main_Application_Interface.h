#pragma once
#include<iostream>
#include"User.h"
#include"User_Manager.h"
using namespace std;
//main clas for the whole application
//can be called as root class
class Main_Application_Interface
{
private:
	//a composition relationship has-a relationship
	User_Manager user_manager;//instantiate an object of user_manager
	User* current_user;//creates a pointer to the instance of the user object
	string temp_username;//stores the user name temporarily
	string temp_password;//stores the password temporarily
protected:
public:
	Main_Application_Interface();//constructor
	void run();//runs the app
	void welcome_Screen();//outputs the welcome screen
	void sign_In();//handles the sign in
	void sign_Up();//handles the sign up
	~Main_Application_Interface();//destructor
};