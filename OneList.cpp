
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;


void OneList::Clear() {
    while (head != nullptr) {
        SingleNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}
void OneList::LONEPUSHhead(string& cell) {

    SingleNode* node = new SingleNode;
    node->cell = cell;
    node->next = nullptr;

    if (head == nullptr) {
        head = tail = node;
    }
    else {
        node->next = head;
        head = node;
    }
}

void OneList::LONEPUSHtail(string& cell) {
    
    SingleNode* node = new SingleNode;
    node->cell = cell;
    node->next = nullptr;
    if (tail == nullptr) {
        head = tail = node;
    }
    else {

        tail->next = node;
        tail = node;
    }

}

void OneList::LONEDELhead() {
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    SingleNode* node = head;
    head = head->next;
    delete node;
    if (head == nullptr) {
        tail = nullptr;
    }

}
void OneList::LONEDELtail() {
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    SingleNode* current = head;

    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;

   
}

void OneList::LONEDELvalue(string&value) {
    SingleNode* node = head;
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    if (head->cell == value) {
        LONEDELhead();
        return;
    }
    while (node != nullptr && node->next != nullptr &&  node->next->cell != value ) {
        if (node == nullptr) {
            cout << "\nNo value found!" << endl;
            return;
        }
        node = node->next;
    }
    
    SingleNode* toDelete = node->next;  
    node->next = toDelete->next;
    if (toDelete == tail) {
        tail = toDelete;
    }
    delete toDelete;

}

void OneList::LONESEARCH(string& value) {
    SingleNode* node = head;
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    int index = 0;
    if (head->cell == value) {
        cout << "\nThe element is found! Index: " << index << endl;
        return;
    }
    while (node != nullptr && node->cell != value) {
        node = node->next;
        index++;
    }
    if (node == nullptr) {
        cout << "\nNo value found!" << endl;
        return;
    }
    cout << "\nThe element is found! Index: " << index << endl;
    
}
void OneList::LONEREAD() {
    SingleNode* node = head;
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    cout << endl;
    while (node != nullptr) {
        cout << node->cell << " ";
        node = node->next;
    }
    cout << endl;
}


