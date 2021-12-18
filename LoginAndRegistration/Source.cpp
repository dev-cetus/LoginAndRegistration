#include "Login.h"
#include "Registration.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

std::string username();
std::string password();
void displayMenu();
bool createSession(std::string username, std::string passwd);

int main()
{
	int choice = 0;

	while (choice != 3)
	{
		displayMenu();
		std::cin >> choice;
		system("cls");

		switch (choice)
			{
			case 1: {
				std::cout << "LOGIN \n\n";
				std::string usr = username();
				std::string passwd = password();

				Login login = Login();

				login.setUsername(usr);
				login.setPassword(passwd);

				if (login.run())
				{
					createSession(usr, passwd);
					std::cout << "Success!";
				}
				else
				{
					std::cout << "Login fail.";
				}

				break;
			}
			case 2: {
				std::cout << "REGISTRATION \n\n";
				std::string user = username();
				std::string pass = password();

				Registration signup = Registration();

				signup.setUsername(user);
				signup.setPassword(pass);

				if (signup.run())
				{
					createSession(user, pass);
					std::cout << "Success!";
				}
				else
				{
					std::cout << "Fail.";
				}
				break;
			}
			case 3: {
				std::cout << "Goodbye\n";
				break;
			}
			default: {
				displayMenu();
				std::cin >> choice;
				system("cls");
			}
			break;
		}
	}

	system("PAUSE");


	return 0;
}

bool createSession(std::string username, std::string passwd)
{
	try {
		fs::create_directory("sessions");

		std::string filename = "sessions\\session-";
		filename += std::to_string(rand());
		filename += ".txt";

		std::ofstream Session(filename);

		Session << "Username: " << username << std::endl;
		Session << "Password: " << passwd << std::endl;

		Session.close();

		return true;

	}catch (...) {
		return false;
	}
}


std::string username()
{
	std::string username;

	std::cout << "Username: ";
	std::cin >> username;

	return username;
}


std::string password()
{
	std::string password;

	std::cout << "Password: ";
	std::cin >> password;

	return password;
}


void displayMenu()
{

	std::cout << "Menu\n";
	std::cout << "1 - Login\n";
	std::cout << "2 - Registration\n";
	std::cout << "3 - Quit\n";
}

