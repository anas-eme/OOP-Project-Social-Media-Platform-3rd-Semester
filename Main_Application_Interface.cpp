#include"Main_Application_Interface.h"
#include"User_Manager.h"
#include<iostream>
#include<Windows.h>
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
    //main application loop
    do
    {
        //call to welcome function
        welcome_Screen();
        //input loop goes here
        do
        {
            choice = _getch();//input choice
            cout << choice << endl;//display input to the console
            Sleep(100);//wait to make the input clear to user
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
                return;
            }              
            else//handle invalid input
                cout << "\tInvalid Choice!" << endl
                << "\tTry Again!" << endl
                << "\tEnter Your Choice(1/2): ";
        } while (true);
        //when sign-in or sign-up is successful display the profile of the user
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
    //loop to ensure successful login
    do
    {
        system("cls");//clear screen for sign in interface
       cout << "\t*****|Sign-In|*****" << endl
            << "\n\tEnter Your Username: ";
       cin >> temp_username;//input username
       cout << "\n\tEnter Your Password: ";
       cin >> temp_password;//input password
       //function to validate user if successfull the user account is retrived and function is ended
       if (user_manager.validate_User(temp_username, temp_password))
       {
           //retriver useraccount
           user_manager.get_User(temp_username, temp_password);
           return;//end the function
       }
       else
       {
           cout << "\tSign-In Unsuccessful!" << endl;
           cout << "\tTry Again!\n\t";
           system("\tpause");
       }
    } while (true);
}
void Main_Application_Interface::sign_Up()
{
    string c_password;//just to store the password to confirm that it matches the previous one
    //loop to ensure successful sign-up
    do
    {
        system("cls");//clear screen for sign up interface
        cout << "\t*****|Sign-Up|*****" << endl
            << "\n\tLet's create an Account for You!" << endl
            << "\n\tEnter a Username: ";
        cin >> temp_username;//input username
        cout << "\n\tEnter a Password: ";
        cin >> temp_password;//input password
        cout << "\n\tConfirm Your Password: ";
        cin >> c_password;//confirm password
        //if password does not matches
        //continue the loop to run the sign-up again
        if (c_password != temp_password)
        {
            cout << "\n\tEntered Password Does Not Match!" << endl;
            cout << "\tSign-In Unsuccessful!" << endl;
            cout << "\tTry Again!\n\t";
            system("pause");
            continue;
        }
        //if password matches run the create-user function
        else
        {
            if (user_manager.create_User(temp_username, temp_password))
            {
                //retrive the user account after signup successful
                user_manager.get_User(temp_username, temp_password);
                return;
            }
            //if any case sign-up was unsuccessful continue the loop
            else
            {
                cout << "\tSign-In Unsuccessful!" << endl;
                cout << "\tTry Again!\n\t";
                system("pause");
            }
        }
    } while (true);
}
Main_Application_Interface::~Main_Application_Interface()
{
    delete(current_user);
}