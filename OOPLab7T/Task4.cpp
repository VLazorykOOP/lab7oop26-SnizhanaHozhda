#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
        Node* parent;

        Node(T val, Node* p = nullptr) : data(val), left(nullptr), right(nullptr), parent(p) {}
    };

    Node* root;

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        Iterator& operator++() {
            if (current == nullptr) return *this;

            if (current->right != nullptr) {
                current = current->right;
                while (current->left != nullptr) {
                    current = current->left;
                }
            }
            else {
                Node* p = current->parent;
                while (p != nullptr && current == p->right) {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }
    };

    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        clear(root);
    }

    void insert(T val) {
        if (root == nullptr) {
            root = new Node(val);
            return;
        }

        Node* curr = root;
        Node* lastParent = nullptr;

        while (curr != nullptr) {
            lastParent = curr;
            if (val < curr->data) {
                curr = curr->left;
            }
            else if (val > curr->data) {
                curr = curr->right;
            }
            else {
                return;
            }
        }

        if (val < lastParent->data) {
            lastParent->left = new Node(val, lastParent);
        }
        else {
            lastParent->right = new Node(val, lastParent);
        }
    }

    Iterator begin() {
        if (root == nullptr) return Iterator(nullptr);
        Node* curr = root;
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return Iterator(curr);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

void runTask4() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    cout << "=== Testing Binary Tree with Custom Iterator ===\n\n";

    cout << "[MODE 1] Keyboard Input (Type: int)\n";
    BinaryTree<int> intTree;
    int count, val;

    cout << "How many numbers to enter? ";
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        cout << "Element [" << i + 1 << "]: ";
        std::cin >> val;
        intTree.insert(val);
    }

    cout << "Displaying tree using our ITERATOR (ascending order):\n";
    for (BinaryTree<int>::Iterator it = intTree.begin(); it != intTree.end(); ++it) {
        cout << *it << " ";
    }


    cout << "[MODE 2] Reading from file 'numbers.txt' (Type: double)\n";

    std::ofstream outFile("numbers.txt");
    if (outFile.is_open()) {
        outFile << "44.4 11.1 88.8 22.2 66.6 99.9";
        outFile.close();
    }

    BinaryTree<double> doubleTree;
    std::ifstream inFile("numbers.txt");
    double dVal;

    if (inFile.is_open()) {
        while (inFile >> dVal) {
            doubleTree.insert(dVal);
        }
        inFile.close();

        cout << "Elements from file displayed via ITERATOR:\n";
        for (auto it = doubleTree.begin(); it != doubleTree.end(); ++it) {
            cout << *it << " ";
        }
   
    }
    else {
        cout << "Error opening file!\n";
    }

    cout << "[MODE 3] Random Number Generator (Type: char)\n";
    BinaryTree<char> charTree;

    cout << "Generated random letters: ";
    for (int i = 0; i < 7; ++i) {
        char rChar = 'A' + (std::rand() % 26);
        cout << rChar << " ";
        charTree.insert(rChar);
    }
    cout << "\n";

    cout << "Sorted alphabetical output via ITERATOR:\n";
    for (auto it = charTree.begin(); it != charTree.end(); ++it) {
        cout << *it << " ";
    }
    
}