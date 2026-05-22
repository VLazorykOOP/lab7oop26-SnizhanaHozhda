#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Tasks.h"

using std::cout;
using std::endl;


template <typename T>
class BinaryTree {
private:
 
    struct Node {
        T data;        
        Node* left;     
        Node* right;    

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root; 

   
    Node* insertInternal(Node* node, T val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertInternal(node->left, val);
        }
        else if (val > node->data) {
            node->right = insertInternal(node->right, val);
        }
        return node;
    }

   
    bool searchInternal(Node* node, T val) const {
        if (node == nullptr) 
            return false;
        if (node->data == val) 
            return true;
        if (val < node->data)
            return searchInternal(node->left, val);
        return searchInternal(node->right, val);
    }

    
    void printDescendingInternal(Node* node) const {
        if (node != nullptr) {
            printDescendingInternal(node->right); //Рекурсія ліворуч
            cout << node->data << " ";
            printDescendingInternal(node->left); //Рекурсія ліворуч
        }
    }

  
    void printAscendingInternal(Node* node) const {
        if (node != nullptr) {
            printAscendingInternal(node->left);  //Рекурсія праворуч
            cout << node->data << " ";
            printAscendingInternal(node->right); //Рекурсія праворуч
        }
    }

 
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;         //рекурсивне очищення бінарного дерева
        }
    }

public:
   
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        clear(root);
    }

    void insert(T val) {
        root = insertInternal(root, val);
    }

    bool search(T val) const {
        return searchInternal(root, val);
    }

    void printDescending() const {
        printDescendingInternal(root);
        cout << endl;
    }

    void printAscending() const {
        printAscendingInternal(root);
        cout << endl;
    }
};



void runTask3() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    cout << "=== Testing the Parameterized Binary Tree ===" << endl << endl;

  
    cout << "[MODE 1] Keyboard Input (Type: int)" << endl;
    BinaryTree<int> intTree;
    int count, val;

    cout << "How many int elements do you want to enter? ";
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        cout << "Enter element #" << i + 1 << ": ";
        std::cin >> val;
        intTree.insert(val);
    }

    cout << "Ascending order (from smallest to largest): ";
    intTree.printAscending();
    cout << "Descending order (from largest to smallest): ";
    intTree.printDescending();

    int searchInt;
    cout << "Enter a number to search in the tree: ";
    std::cin >> searchInt;
    cout << "Search result for " << searchInt << ": "
        << (intTree.search(searchInt) ? "FOUND" : "NOT FOUND") << endl;

    cout << "--------------------------------------------------" << endl;

 
    cout << "[MODE 2] File Input from 'tree_data.txt' (Type: double)" << endl;


    std::ofstream outFile("tree_data.txt");
    if (outFile.is_open()) {
        outFile << "5.5 2.2 7.7 1.1 3.3 6.6 8.8";
        outFile.close();
    }

    BinaryTree<double> doubleTree;
    std::ifstream inFile("tree_data.txt");
    double doubleVal;

    if (inFile.is_open()) {
        cout << "Reading elements from file: ";
        while (inFile >> doubleVal) {
            cout << doubleVal << " | ";
            doubleTree.insert(doubleVal);
        }
        cout << endl;
        inFile.close();

        cout << "Ascending order: ";
        doubleTree.printAscending();
        cout << "Descending order: ";
        doubleTree.printDescending();

        double searchDouble = 3.3;
        cout << "Search result for " << searchDouble << ": "
            << (doubleTree.search(searchDouble) ? "FOUND" : "NOT FOUND") << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }

 
    cout << "[MODE 3] Random Number Generator (Type: char)" << endl;
    BinaryTree<char> charTree;

    cout << "Generated random characters: ";
    for (int i = 0; i < 8; ++i) {
       
        char randChar = 'A' + (std::rand() % 26);
        cout << randChar << " ";
        charTree.insert(randChar);
    }
    cout << endl;

    cout << "Ascending order (alphabetical): ";
    charTree.printAscending();
    cout << "Descending order (reverse alphabetical): ";
    charTree.printDescending();

 
}