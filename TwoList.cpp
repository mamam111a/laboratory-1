
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;


void TwoList::Clear() {/////
    while (head != nullptr) {
        DoubleNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}
void TwoList:: LTWOPUSHhead(string& element) {
    DoubleNode* node = new DoubleNode;
    node->cell = element;
    node->next = nullptr;
    node->prev = nullptr;

    if (head == nullptr) {
        head = tail = node;
    }
    else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}
void TwoList::LTWOPUSHtail(string& element) {
    DoubleNode* node = new DoubleNode;
    node->cell = element;
    node->next = nullptr;
    node->prev = nullptr;
    if (tail == nullptr) {
        head = tail = node;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}




void TwoList::LTWODELhead() {
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    DoubleNode* node = head;
    head = head->next;
    delete node;
    if (head == nullptr) {
        tail = nullptr;
    }
}
void TwoList::LTWODELtail() {
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    DoubleNode* current = tail->prev; //убрали while
    current->next = tail->next;
    delete tail;
    tail = current;
    tail->next = nullptr;
    tail->prev = current->prev;
}

void TwoList::LTWODELvalue(string& value) {
    DoubleNode* node = head;
    if (head == nullptr) {
        cout << "\nThe list is empty!" << endl;
        return;
    }
    if (head->cell == value) {
        LTWODELhead();
        return;
    }
    while (node != nullptr && node->cell != value) {
        node = node->next;
    }
    if (node == nullptr) {
        cout << "\nNo value found!" << endl;
        return;
    }
    if(node->prev) {
        node->prev->next = node->next;
    }
    else {
        head = node->prev;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    else {
        tail = node->next;
    }

    delete node;

}


void TwoList::LTWOSEARCH(string& value) {
    DoubleNode* node = head;
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
void TwoList::LTWOREAD() {
    DoubleNode* node = head;
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

