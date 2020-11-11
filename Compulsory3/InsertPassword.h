#pragma once

#include <iostream>
#include <vector>
#include <conio.h> // Needed for _getch
#include <fstream> // Needed for the password file I/O

#include "CreatePassword.h"

std::vector <int> moveInsert(std::vector <int>& cursorPos);
void endInsert();


void insert()
{

    std::cout << "Please insert a password sequence by using WASD keys. Press ENTER when the sequence is complete.\n" << std::endl;
    bool loop = true;

    std::vector <int> cursorPos{ 0,0 };

    std::string strPasswordfromboard;
    strPasswordfromboard = move(cursorPos);
    /*while (loop == true) {

        printTable(cursorPos);
        moveInsert(cursorPos);

    }*/



}



std::vector <int> moveInsert(std::vector <int>& cursorPos) {
    char move;
    move = _getch();
    if (move == 'a' && cursorPos.at(1) != 0) {
        cursorPos.at(1) = (cursorPos.at(1) - 1);
        password << "cursorPos.at(1) = " << cursorPos.at(1) << std::endl;


    }

    if (move == 'd' && cursorPos.at(1) != 3) {
        cursorPos.at(1) = (cursorPos.at(1) + 1);
        password << "cursorPos.at(1) = " << cursorPos.at(1) << std::endl;
    }

    if (move == 'w' && cursorPos.at(0) != 0) {
        cursorPos.at(0) = (cursorPos.at(0) - 1);
        password << "cursorPos.at(0) = " << cursorPos.at(0) << std::endl;
    }

    if (move == 's' && cursorPos.at(0) != 3) {
        cursorPos.at(0) = (cursorPos.at(0) + 1);
        password << "cursorPos.at(0) = " << cursorPos.at(0) << std::endl;
    }

    if (move == '\r') {
        endInsert();
    }


    return cursorPos;
}

void endInsert() {
    password.close();
    std::cout << "Password registered.\n";
    exit(0);
}