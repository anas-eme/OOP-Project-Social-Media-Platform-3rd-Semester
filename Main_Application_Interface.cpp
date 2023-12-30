#include"Main_Application_Interface.h"
#include"User_Manager.h"
#include<iostream>
#include<conio.h>
using namespace std;
//constructor defination
Main_Application_Interface::Main_Application_Interface()
{
    
}
//main function to run the app
void Main_Application_Interface::run()
{
    char choice;//variable for storing the choice of the user
    //main application loop
    do
    {
        welcome_Screen();
        choice = _getch();
        switch (toupper(choice))
        {
        case 'A':
            sign_In();
            break;
        case 'B':
            sign_Up();
            break;
        default:
            cout << "Invalid choice";
        }
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
        << endl
        << "\ta) | Sign In |" << endl
        << "\tb) | Sign Up |" << endl
        << endl
        << "\tEnter Your Choice(a/b): " << endl;
}
void Main_Application_Interface::sign_In()
{
    system("cls");//clear screen for sign in interface
   cout << "*****|Sign-In|*****" << endl
        << "Enter Username: ";
   cout << "Enter Password: ";
   if (user_manager.validate_User())
   {
       user_manager.get_User();
   }
}
void Main_Application_Interface::sign_Up()
{
    system("cls");//clear screen for sign up interface
    cout << "*****|Sign-Up|*****" << endl
        << "Let's create an Account for You!" << endl
        << "Enter a Username: ";
    cout << "Enter a Password: ";
    cout << "Confirm Your Password: ";
    if (user_manager.create_User())
    {
        user_manager.get_User();
    }
}
void Main_Application_Interface::user_Profile()
{

}
Main_Application_Interface::~Main_Application_Interface()
{

}