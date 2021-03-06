#pragma once

#include <iostream>
#include <vector>
#include <conio.h> // Needed for _getch
#include <fstream> // Needed for the password file I/O

void printTable(std::vector <int> cursorPos);
std::string move(std::vector <int>& cursorPos);
void end();
std::fstream password("Password.txt", std::ios::in | std::ios::out | std::ios::trunc); // Trunc deletes the previous file content

bool loop = true;

void create()
{
    std::string strPasswordfromboard;
    std::vector <int> cursorPos{ 0,0 };
    loop = true;
    //std::fstream password("Password.txt", std::ios::in | std::ios::out | std::ios::trunc); // Trunc deletes the previous file content

    std::cout << "Please insert a password sequence by using WASD keys. Press ENTER when the sequence is complete.\n" << std::endl;

    strPasswordfromboard = move(cursorPos);

    /*while (loop == true) {

        printTable(cursorPos);
        move(cursorPos);

    }*/
}

void printTable(std::vector <int> cursorPos)
{
    char cursor = '_'; // A symbol to show the cursor's position

    std::vector <std::vector <char>> table{ {'A','B','C','D'},
                                            {'E','F','G','H'},
                                            {'I','J','K','L'},
                                            {'M','N','O','P'} }; // A vector to store the content of the table

    for (unsigned int i = 0; i < table.size(); i++) {
        for (unsigned int j = 0; j < table[i].size(); j++) {
            if (i == cursorPos.at(0) && j == cursorPos.at(1)) {

                table[i][j] = cursor;
            }
            else {
                std::cout << table[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::string move(std::vector <int>& cursorPos) {
    std::string strPassword{ 'A' };
    std::vector <std::vector <char>> table{ {'A','B','C','D'},
                                            {'E','F','G','H'},
                                            {'I','J','K','L'},
                                            {'M','N','O','P'} };
    char move;
    while (loop)
    {
        printTable(cursorPos);
        move = _getch();
        if (move == 'a' && cursorPos.at(1) != 0) {

            cursorPos.at(1) = (cursorPos.at(1) - 1);
            strPassword += table[cursorPos.at(0)][cursorPos.at(1)];
        }

        else if (move == 'd' && cursorPos.at(1) != 3) {
            cursorPos.at(1) = (cursorPos.at(1) + 1);
            strPassword += table[cursorPos.at(0)][cursorPos.at(1)];
        }

        else if (move == 'w' && cursorPos.at(0) != 0) {
            cursorPos.at(0) = (cursorPos.at(0) - 1);
            strPassword += table[cursorPos.at(0)][cursorPos.at(1)];
        }

        else if (move == 's' && cursorPos.at(0) != 3) {
            cursorPos.at(0) = (cursorPos.at(0) + 1);
            strPassword += table[cursorPos.at(0)][cursorPos.at(1)];
        }

        else if (move == '\r') {
            loop = false;
            return strPassword;
        }
    }
}

void end() {
    password.close();
    std::cout << "Password registered.\n";
    loop = false;
}