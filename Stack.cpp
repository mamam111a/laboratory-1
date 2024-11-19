
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;


void Stack::Clear() {
    while (head != nullptr) {
        SingleNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}
void Stack::SPUSH(string& cell) {
    SingleNode* node = new SingleNode;
    node->cell = cell;
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->next = head; //////////
        head = node;
    }
}

void Stack::WriteFromFile(string& cell) { ///////////////
    SingleNode* node = new SingleNode;
    node->cell = cell;
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}
void Stack::SPOP() {
    if (head == tail) {  
        delete head;      
        head = tail = nullptr; 
        return;
    }
    SingleNode* current = head; ///////////
    head = head->next;
    delete current;
}
void Stack::SREAD() {
    SingleNode* current = head;
    cout << endl;
    while (current != nullptr) {
        cout << current->cell << " ";
        current = current->next;
    }
    cout << endl;
}
