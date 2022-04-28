#pragma once
//Daniel Blakeman
//CIS 2207 502
//Create a function called bool isSameTree(Tree *); 
//that will take an argument of a tree.  It will return a true if the argument is the equivalent tree.
#include<exception>
#include<stdexcept>
#include<string>
class NotFoundException : public std::exception
{
public:
	NotFoundException(const std::string& message = "");
};