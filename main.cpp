#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#include "header.h"

#include "Array.cpp"
#include "Queue.cpp"
#include "Stack.cpp"
#include "OneList.cpp"
#include "TwoList.cpp"
#include "AVLtree.cpp"
#include "HashTable.cpp"

template <typename T>
void WritingFromFileToStructure(T& structure, void (T::* pushMethod)(string&), const string& filename) {
    ifstream FileRead(filename);
    string tempValue;

    while (getline(FileRead, tempValue)) {
        stringstream ss(tempValue);
        string element;
        while (ss >> element) {
            (structure.*pushMethod)(element);
        }
    }
    FileRead.close();
}
template <typename T>
void WritingFromStructureToFile(T& structure, const string& filename ) {
    ofstream FileWrite(filename);
    SingleNode* current = structure.head;
    while (current != nullptr) {
        FileWrite << current->cell << " ";
        current = current->next;
    }
    FileWrite.close();
}

int main()
{
    cout << "HELLO!\n";
    try { 
    while (true) {
        string command;
        string commandWord;
        string name;
        string element;
        string index;

        cout << endl << "Enter the command: ";

        Array array;
        Queue queue;
        Stack stack;
        OneList onelist;
        TwoList twolist;
        AVL avl;
        HashTable hashtable;
        getline(cin, command);
        stringstream ss(command);

        ss >> commandWord;
        ss >> name;
        ss >> element;
        ss >> index;

        string filename = name + ".txt";

        if (command.find("INFO") != string::npos) {
            ifstream File("INFO.txt");
            string temp;
            cout << endl;
            while (getline(File, temp)) {
                cout << temp << endl;
            }
        }
        else if (command.find("EXIT") != string::npos) {
            cout << endl << "GOOD BYE!" << endl;
            return 0;
        }
        else if (command.at(0) == 'M') {
            
            
            WritingFromFileToStructure(array, &Array::MPUSHend, filename);
;
            if (command.find("MPUSH") != string::npos) {
                if (index == "") {
                    array.MPUSHend(element);
                }
                else {
                    array.MPUSHindex(stoi(index), element);
                }
            }
            else if (command.find("MDEL") != string::npos) {
                index = element;
                array.MDEL(stoi(index));
            }
            else if (command.find("MGETL") != string::npos) {
                index = element;
                string cell = array.MGETL(stoi(index));
                cout << endl << cell << endl;
                continue;
            }
            else if (command.find("MREPL") != string::npos) {
                array.MREPL(stoi(index), element);
            }
            else if (command.find("MSIZE") != string::npos) {
                int cell = array.MSIZE();
                cout << endl << cell << endl;
                continue;
            }
            else if (command.find("MREAD") != string::npos) {
                array.MREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                continue;;
            }
            ofstream FileWrite(name + ".txt");
            for (int i = 0; i < array.size; i++) {
                FileWrite << array.MGETL(i);
            }
            FileWrite.close();
        }
        else if (command.at(0) == 'Q') {

            WritingFromFileToStructure(queue,& Queue::QPUSH, filename);
            if (command.find("QPUSH") != string::npos) {
                queue.QPUSH(element);
            }
            else if (command.find("QPOP") != string::npos) {
                queue.QPOP();
            }
            else if (command.find("QREAD") != string::npos) {
                queue.QREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                continue;
            }
            WritingFromStructureToFile(queue, filename);
        }
        else if (command.at(0) == 'S') {

            WritingFromFileToStructure(stack,& Stack::SPUSH, filename);

            if (command.find("SPUSH") != string::npos) {
                stack.SPUSH(element);
            }
            else if (command.find("SPOP") != string::npos) {
                stack.SPOP();
            }
            else if (command.find("SREAD") != string::npos) {
                stack.SREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                continue;
            }
            WritingFromStructureToFile(stack, filename);
        }
        else if (command.substr(0, 2) == "LO") {

            WritingFromFileToStructure(onelist,& OneList::LONEPUSHtail, filename);
            
            if (command.find("LONEPUSHhead") != string::npos) {
                onelist.LONEPUSHhead(element);
            }
            else if (command.find("LONEPUSHtail") != string::npos) {
                onelist.LONEPUSHtail(element);
            }
            else if (command.find("LONEDELhead") != string::npos) {
                onelist.LONEDELhead();
            }
            else if (command.find("LONEDELtail") != string::npos) {
                onelist.LONEDELtail();
            }
            else if (command.find("LONEDELvalue") != string::npos) {
                onelist.LONEDELvalue(element);
            }
            else if (command.find("LONESEARCH") != string::npos) {
                onelist.LONESEARCH(element);
                continue;
            }
            else if (command.find("LONEREAD") != string::npos) {
                onelist.LONEREAD();
                continue;
            }
            else {
                cout << endl << "Command not found!" << endl;
                continue;
            }

            WritingFromStructureToFile(onelist, filename);
        }
        else if (command.substr(0, 2) == "LT") {

            WritingFromFileToStructure(twolist,& TwoList::LTWOPUSHtail, filename);

            if (command.find("LTWOPUSHhead") != string::npos) {
                twolist.LTWOPUSHhead(element);
            }
            else if (command.find("LTWOPUSHtail") != string::npos) {
                twolist.LTWOPUSHtail(element);
            }
            else if (command.find("LTWODELhead") != string::npos) {
                twolist.LTWODELhead();
            }
            else if (command.find("LTWODELtail") != string::npos) {
                twolist.LTWODELtail();
            }
            else if (command.find("LTWODELvalue") != string::npos) {
                twolist.LTWODELvalue(element);
            }
            else if (command.find("LTWOSEARCH") != string::npos) {
                twolist.LTWOSEARCH(element);
                continue;
            }
            else if (command.find("LTWOREAD") != string::npos) {
                twolist.LTWOREAD();
                continue;
            }
            else {
                cout << endl << "Command not found!" << endl;
                continue;
            }
            ofstream FileWrite(name + ".txt");
            DoubleNode* current = twolist.head;
            while (current != nullptr) {
                FileWrite << current->cell << " ";
                current = current->next;
            }
            FileWrite.close();
        }
        else if (command.at(0) == 'T') {

            WritingFromFileToStructure(avl, &AVL::TPUSH, filename);

            if (command.find("TPUSH") != string::npos) {
                avl.TPUSH(element);
            }
            else if (command.find("TDEL") != string::npos) {
                avl.TDEL(element);
            }
            else if (command.find("TSEARCH") != string::npos) {
                if (avl.TSEARCH(element)) {
                    cout << endl << "The element was found!!!" << endl;
                }
                else {
                    cout << endl << "The element was not found" << endl;
                }
            }
            else if (command.find("TREAD") != string::npos) {
                avl.TREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                continue;
            }
            ofstream FileWrite(name + ".txt");
            avl.TSaveToFile(avl.root, FileWrite);
            FileWrite.close();
        }
        else if (command.at(0) == 'H') {
            string key = element;
            string value = index;

            ifstream FileRead(filename);
            if (FileRead.is_open()) {
                string key, value;
                while (FileRead >> key >> value) {
                    hashtable.HPUSH(key, value); 
                }
                FileRead.close();
            }
            if (command.find("HPUSH") != string::npos) {
                hashtable.HPUSH(key, value);
            }
            else if (command.find("HDEL") != string::npos) {
                hashtable.HDEL(key);
            }
            else if (command.find("HGET") != string::npos) {
                string temp = hashtable.HGET(key);
                cout << endl << temp << endl;
            }
            else if (command.find("HREAD") != string::npos) {
                hashtable.HREAD();
            }
            else {
                cout << endl << "Command not found!" << endl;
                continue;
            }
            ofstream FileWrite(filename);
            if (FileWrite.is_open()) {
                for (int i = 0; i < hashtable.size; i++) { 
                    NodeHash* current = hashtable.table[i];
                    while (current != nullptr) { 
                        FileWrite << current->key << " " << current->value << endl; 
                        current = current->next;
                    }
                }
                FileWrite.close(); 
            }
        }
        else {
            cout << endl << "The command was not found!" << endl;
            continue;
        }
    }
    }
    catch (...) {
        cerr << endl << "UNKNOWN ERROR!!!" << endl;
    }
    
}


