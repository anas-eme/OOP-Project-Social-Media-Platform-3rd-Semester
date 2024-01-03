#include"User_Manager.h"
#include"User.h"
User_Manager::User_Manager()
{
}
bool User_Manager::validate_User(string u_name, string password)
{
    //an auto for loop to validate the user and return true or false
    for (int i = 0; i < max_users; i++)
     {
            if (users[i].get_Username() == u_name && users[i].validate_Password(password)) 
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
    for (int i = 0; i < max_users; i++)
    {
        if (users[i].get_Username() == u_name) 
        {
            cout << "\tUsername already exists. Please choose a different one.\n" << endl;
            return false;
        }
    }
    // Find an empty slot for the new user
    for (int i = 0; i < max_users; i++)
    {
        if (users[i].get_Username().empty()) {
            users[i] = User(u_name, password);
            return true;
        }
    }  
    cout<<"\tUser limit reached. Cannot create a new user.\n" << endl; 
    return false;
}
User* User_Manager::get_User(string u_name, string password)
{
    //loop to return the pointer to required user
    for (int i = 0; i < max_users; i++)
    {
        if ((users[i].get_Username() == u_name) && (users[i].validate_Password(password)))
        {
            return &users[i];//return the address of the current user according to the username and password
        }
    }
    return nullptr;
}
User_Manager::~User_Manager()
{
    delete[] users;//delete the memory at the end of the program
}