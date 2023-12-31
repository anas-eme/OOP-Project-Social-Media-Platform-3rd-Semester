#include"User_Manager.h"
#include"User.h"
User_Manager::User_Manager()
{
}
bool User_Manager::validate_User(string u_name, string password)
{
    //an auto for loop to validate the user and return true or false
	 for (User& user : users) 
     {
            if (user.get_Username() == u_name && user.validate_Password(password)) 
            {
                return true;//after validation return true
            }
     }
     return false;//if in any case unsuccessful login return false
}
//create a user account
bool User_Manager::create_User(string u_name, string password)
{
    // Check if the username is already taken
    for (User& user : users) 
    {
        if (user.get_Username() == u_name) 
        {
            cout << "\tUsername already exists. Please choose a different one.\n" << endl;
            return false;
        }
    }
    // Find an empty slot for the new user
    for (User& user : users) {
        if (user.get_Username().empty()) {
            user = User(u_name, password);
            cout << "\t\n1" << endl;
            return true;
        }
    }  
    cout<<"\tUser limit reached. Cannot create a new user.\n" << endl; 
    return false;
}
User* User_Manager::get_User(string u_name, string password)
{
    //loop to return the pointer to required user
    for (User& user : users)
    {
        if (user.get_Username() == u_name && user.validate_Password(password))
        {
            return &user;//return the address of the current user according to the username and password
        }
    }
}
User_Manager::~User_Manager()
{
}
