#pragma once
//class for handling the users
class User_Manager
{
private:
protected:
public:
	User_Manager(){}//constructor
	bool validate_User() { return 0; }//validates the user with initially stored data i.e for sign-in
	bool create_User() { return 0; }//creates a new user i.e for sign-up
	void get_User(){}//after sign-in or sign-up gets the user profile
	~User_Manager(){}//destructor
};