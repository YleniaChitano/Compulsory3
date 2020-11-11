#include <iostream>
#include "CreatePassword.h"
#include "InsertPassword.h"


void menu();

int main()
{
    char account;
    std::cout << "Welcome to Battleship!\n\n";
    account:
    std::cout << "Press 1 if you want to create a new account or 2 to log in to your previous account.\n";
    std::cin >> account;

    if (account == '1')
    {
    create();
	menu();
    }

    else if (account == '2')
    {
        insert();
    }
    
    else {
        std::cout << "Invalid input\n";
        goto account;
    }
}


void menu()
{
	char choice;
choice:
	std::cout << "Please Select an option ( 1-3) : \n\n";
	std::cout << "1: Change the password\n";
	std::cout << "2: Play battleship\n";
	std::cout << "3: Quit\n";
	std::cin >> choice;

	if (choice == '1')
	{
		create();
		menu();
	}

	else if (choice == '3')
	{
		exit(0);
	}

	else
	{
		std::cout << "Invalid input.\n";
		goto choice;
	}
}

std::vector <char> GeneratePasswordSequence()
{
	std::fstream password("Password.txt", std::ios::out);
	std::vector <char> table{ {'A','B','C','D'},{'E','F','G','H'}, {'I','J','K','L'}, {'M','N','O','P'} };
	std::vector <char> sequence;
	std::cout << table.at(password);
	

}