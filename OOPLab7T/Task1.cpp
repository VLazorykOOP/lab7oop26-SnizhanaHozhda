#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include "Tasks.h"

using std::cout;
using std::endl;
using std::ostream;
using std::istream;


class TPoint {
    int x, y;
public:
    TPoint() : x(0), y(0) {}
    TPoint(int _x, int _y) : x(_x), y(_y) {}

    TPoint& operator=(const TPoint& s) {
        x = s.x;
        y = s.y;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const TPoint& s);
};

ostream& operator<<(ostream& os, const TPoint& s) {
    os << "(" << s.x << "; " << s.y << ")";
    return os;
}


template <typename T>
void swapElements(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}


template<>
void swapElements<char*>(char*& x, char*& y) {
    char* temp = x;
    x = y;
    y = temp;
}


void runTask1() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    cout << "=== Testing the swapElements Function Template ===" << endl << endl;


    cout << "[KEYBOARD INPUT] Type: int" << endl;
    int intA, intB;
    cout << "Enter number a: ";
    std::cin >> intA;
    cout << "Enter number b: ";
    std::cin >> intB;

    cout << "Before swap: a = " << intA << ", b = " << intB << endl;
    swapElements(intA, intB);
    cout << "After swap:  a = " << intA << ", b = " << intB << endl;
   

    cout << "[FILE INPUT 'input.txt'] Type: double" << endl;



    std::ofstream outFile("input.txt");
    if (outFile.is_open()) {
        outFile << 45.67 << " " << 89.12;
        outFile.close();
    }


    std::ifstream inFile("input.txt");
    double doubleA = 0.0, doubleB = 0.0;
    if (inFile.is_open()) {
        inFile >> doubleA >> doubleB;
        inFile.close();

        cout << "Read from file: a = " << doubleA << ", b = " << doubleB << endl;
        swapElements(doubleA, doubleB);
        cout << "After swap:     a = " << doubleA << ", b = " << doubleB << endl;
    }
    else {
        cout << "Error: Failed to open file input.txt" << endl;
    }
    

 
    cout << "[RANDOM GENERATOR] Type: Class TPoint" << endl;
    TPoint p1(std::rand() % 100, std::rand() % 100);
    TPoint p2(std::rand() % 100, std::rand() % 100);

    cout << "Before swap: p1 = " << p1 << ", p2 = " << p2 << endl;
    swapElements(p1, p2);
    cout << "After swap:  p1 = " << p1 << ", p2 = " << p2 << endl;
  


    cout << "[SPECIALIZATION TEST] Type: char*" << endl;


    char* s1 = new char[20];
    char* s2 = new char[20];
    strcpy_s(s1, 20, "FirstLine");
    strcpy_s(s2, 20, "SecondLine");

    cout << "Before pointer swap:" << endl;
    cout << "s1 points to: " << s1 << " (address: " << (void*)s1 << ")" << endl;
    cout << "s2 points to: " << s2 << " (address: " << (void*)s2 << ")" << endl;


    swapElements<char*>(s1, s2);

    cout << "\nAfter pointer swap:" << endl;
    cout << "s1 points to: " << s1 << " (address: " << (void*)s1 << ")" << endl;
    cout << "s2 points to: " << s2 << " (address: " << (void*)s2 << ")" << endl;

    delete[] s1;
    delete[] s2;

}