
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;



void Queue::Clear() {
    while (head != nullptr) {
        SingleNode* temp = head;
        head = head->next;  
        delete temp;        
    }
    tail = nullptr; 
}

void Queue::QPUSH(string& cell) {
    SingleNode* node = new SingleNode;
    node->cell = cell; 
    node->next = nullptr;

    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}
void Queue::QPOP() {
    SingleNode* node = head;
    head = head->next;
    delete node;
    if (head == nullptr) {
        tail = nullptr;
    }
}
void Queue::QREAD() {
    SingleNode* current = head;
    cout << endl;
    while (current != nullptr) {
        cout << current->cell << " ";
        current = current->next;
    }
    cout << endl;
}
