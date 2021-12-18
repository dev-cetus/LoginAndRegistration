#pragma once
#include <iostream>
class Registration
{
private:
	std::string username;
	std::string password;

public:
	void setUsername(std::string &username);
	void setPassword(std::string &password);
	bool run();
};

