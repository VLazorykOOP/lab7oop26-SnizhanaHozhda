// OOPLab7T.cpp 
//

#include <iostream>
#include <clocale>
#include "Tasks.h"


int main()
{
   
    std::cout << "Laboratorna 7  \n";
    int choice;

    do {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "                MAIN MENU                 " << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "1. Task 1: Swap two arguments" << std::endl;
        std::cout << "2. Task 2: Find maximum of 4 elements" << std::endl;
        std::cout << "3. Task 3: Parameterized binary tree" << std::endl;
        std::cout << "4. Task 4: Binary tree with Iterator" << std::endl;
        std::cout << "0. Exit program" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Enter task number [0-4]: ";

        std::cin >> choice;

        
        if (std::cin.fail()) {
            std::cin.clear();            
            std::cin.ignore(32767, '\n');
            std::cout << "Error! Please enter a number from 0 to 4." << std::endl;
            continue;
        }

        std::cout << std::endl;

     
        switch (choice) {
        case 1:
            std::cout << ">>> Running Task 1 <<<\n" << std::endl;
            runTask1();
            break;
        case 2:
            std::cout << ">>> Running Task 2 <<<\n" << std::endl;
            runTask2();
            break;
        case 3:
            std::cout << ">>> Running Task 3 <<<\n" << std::endl;
            runTask3();
            break;
        case 4:
            std::cout << ">>> Running Task 4 <<<\n" << std::endl;
            runTask4();
            break;
        case 0:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Select a number from 0 to 4." << std::endl;
            break;
        }

    } while (choice != 0); 

    return 0;
}



