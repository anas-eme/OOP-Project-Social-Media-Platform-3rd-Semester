#pragma once
//main clas for the whole application
//can be called as root class
class Main_Application_Interface
{
private:
protected:
public:
	Main_Application_Interface(){}//constructor
	void run(){}//runs the app
	void welcome_Screen(){}//outputs the welcome screen
	void sign_In(){}//handles the sign in
	void sign_Up(){}//handles the sign up
	void user_Profile(){}//displays the profile
	~Main_Application_Interface(){}//destructor
};