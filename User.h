#pragma once
#include"Post.h"
#include<iostream>
#define max_posts 5 //Max allowed posts per user
using namespace std;
//class for the user details
class User
{
private:
	string user_name;//stores the username
	string password;//stores the password
	string name_of_user;//stores the name of the user
	string date_of_birth;//stores the date of birth of the user
	string about;//store the about of the user
	Post* posts = new Post[max_posts];//array to store posts
	int followers = 0;//store followers
	int following = 0;//store following
	int friends = 0;//store friends
protected:
public:
	User();//constructor
	User(string u_name, string pass);//parametrized constructor to create a user
	User(string u_name, string pass, string name, string dob, string ab);//parametrized constructor to create profile
	string get_Username();//function to get the username
	bool validate_Password(string password);//function to validate password
	void create_profile();//function to create the profile after sign up
	void display_Profile();//display the profile information
	void update_Profile();//update the user profile
	string change_Password();//change the password
	void create_Post();//handle creation of a post
	void display_Posts();//display the posts created by user
	~User();//destructor
};