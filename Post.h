#pragma once
#include<iostream>
using namespace std;
//class to handle a post
class Post
{
private:
	string content;//store the content of the post
protected:
public:
	Post();//constructor
	bool make_post(string c);//function to create a post
	string display();//to display the post
	~Post();//destructor
};