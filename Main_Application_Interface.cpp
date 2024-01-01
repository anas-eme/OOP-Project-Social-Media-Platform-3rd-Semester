#include"Main_Application_Interface.h"
#include"User_Manager.h"
#include<iostream> 
#include<string>
#include<conio.h>
using namespace std;
//constructor defination
Main_Application_Interface::Main_Application_Interface()
{
    current_user = nullptr;//initialize the member
}
//main function to run the app
void Main_Application_Interface::run()
{
    char choice;//variable for storing the choice of the user
    //create a default user for sign in illustration
    user_manager.create_User("anas", "123456");//creates a user
    current_user = user_manager.get_User("anas", "123456");//gets the user
    *current_user = User("anas", "123456", "Muhammad Anas", "01/08/2004", "I am a Student at NUST CEME.");
    current_user = nullptr;
    //main application loop
    do
    {
        system("cls");
        //call to welcome function
        welcome_Screen();
        //input loop goes here
        do
        {
            choice = _getch();//input choice
            cout << choice << endl;//display input to the console
            if (choice == '1')
            {
                sign_In();//call to signin
                break;
            }
            else if (choice == '2')
            {
                sign_Up();//call to sign up
                break;
            }                
            else if (choice == '0')//choice to end program
            {
                cout << "\n\tPROGRAM EXITED!" << endl;
                _getch();
                exit(0);
            }              
            else//handle invalid input
                cout << "\tInvalid Choice!" << endl
                << "\tTry Again!" << endl
                << "\tEnter Your Choice(1/2): ";
        } while (true);
        //when sign-in or sign-up is successful then display the profile of the user
        if (!(current_user == nullptr))
        current_user->display_Profile();//call to the display-profile function
        //from now on rest is handled in the display-profile function
    } while (true);
}
//function to print the welcome screen
void Main_Application_Interface::welcome_Screen()
{
    //single cout statement for the output of the welcome interface
    cout << "\t************************************************" << endl
        << "\t      Welcome to the Social Media Platform" << endl
        << "\t************************************************" << endl
        << "\tConnect with friends, share updates, and explore" << endl
        << "\tthe world of social networking." << endl
        << "\tGet ready for a vibrant community experience!" << endl
        << "\t************************************************" << endl
        << endl
        << "\tLet's Get Started!" << endl
        << "\tSelect One of the Following:" << endl
        << "\t\tOR" << endl
        << "\tEnter '0' to exit Application!:" << endl
        << endl
        << "\t1) | Sign In |" << endl
        << "\t2) | Sign Up |" << endl
        << endl
        << "\tEnter Your Choice(1/2): ";
}
void Main_Application_Interface::sign_In()
{
        system("cls");//clear screen for sign in interface
       cout << "\t*****|Sign-In|*****" << endl
            << "\n\tEnter Your Username: ";
       getline(cin, temp_username, '\n');
       cout << "\n\tEnter Your Password: ";
       getline(cin, temp_password, '\n');
       //function to validate user if successfull the user account is retrived and function is ended
       if (user_manager.validate_User(temp_username, temp_password))
       {
           //retrive useraccount
           current_user = user_manager.get_User(temp_username, temp_password);
           return;//end the function
       }
       else
       {
           cout << "\tSign-In Unsuccessful!" << endl;
           cout << "\tTry Again!\n\t";
           system("\tpause");
           current_user = nullptr;//remove the pointer of the user as login was unsuccessful
       }
}
void Main_Application_Interface::sign_Up()
{
    string c_password;//just to store the password to confirm that it matches the previous one
        system("cls");//clear screen for sign up interface
        cout << "\t*****|Sign-Up|*****" << endl
            << "\n\tLet's create an Account for You!" << endl
            << "\n\tEnter a Username: ";
        getline(cin, temp_username, '\n');
        cout << "\n\tEnter a Password: ";
        getline(cin, temp_password, '\n');
        cout << "\n\tConfirm Your Password: ";
        getline(cin, c_password, '\n');
        //if password does not matches
        //continue the loop to run the sign-up again
        if (c_password != temp_password)
        {
            cout << "\n\tEntered Password Does Not Match!" << endl;
            cout << "\tSign-Up Unsuccessful!" << endl;
            cout << "\tTry Again!\n\t";
            system("pause");
        }
        //if password matches run the create-user function
        else
        {
            if (user_manager.create_User(temp_username, temp_password))
            {
                //retrive the user account after signup successful
                current_user = user_manager.get_User(temp_username, temp_password);
                //function to take rest of the data of the user
                current_user->create_profile();
                return;
            }
            //if any case sign-up was unsuccessful continue the loop
            else
            {
                cout << "\tSign-Up Unsuccessful!" << endl;
                cout << "\tTry Again!\n\t";
                system("pause");
                current_user = nullptr;//remove the pointer as due to unsuccessful login
            }
        }
}
Main_Application_Interface::~Main_Application_Interface()
{
    delete(current_user);
}