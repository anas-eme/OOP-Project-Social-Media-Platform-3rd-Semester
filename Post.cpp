#include"Post.h"
#include<string>
Post::Post()
{
	
}
bool Post::make_post(string c)//return true only if the post creation was successfull
{
	content = c;
	if (!content.empty())//statement to check whether the content is empty or not
		return true;
	else
		return false;
}
string Post::display()//just returns the post
{
	return content;
}
Post::~Post()
{
}