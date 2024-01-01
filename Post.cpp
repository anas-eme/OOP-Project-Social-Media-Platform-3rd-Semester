#include"Post.h"
#include<string>
Post::Post()
{
	
}
bool Post::make_post(string c)
{
	content = c;
	if (!content.empty())
		return true;
	else
		return false;
}
string Post::display()
{
	return content;
}
Post::~Post()
{
}