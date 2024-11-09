#pragma once
using namespace std;
#include <iostream>

struct SingleNode {
    string cell;
    SingleNode* next;

};
struct DoubleNode {
    string cell;
    DoubleNode* next;
    DoubleNode* prev;
};

struct AVLnode {

    string key;
    AVLnode* left;
    AVLnode* right;
    int height;

    AVLnode(string key) : key(key), left(nullptr), right(nullptr), height(1) {}

};

struct NodeHash {
    string key;
    string value;
    NodeHash* next;

    NodeHash(string& k, string& v) : key(k), value(v), next(nullptr) {}
};

struct Array {
    string* data;
    int size;
    int maxSize;

    Array();
    ~Array();
    void MPUSHend(string& value);
    void MPUSHindex(const int& index, string& value);
    string MGETL(const int& index);
    void MDEL(const int& index);
    void MREPL(const int& index, string& value);
    int MSIZE();
    void MREAD();
};
Array::Array() : size(0), maxSize(1000) {
    data = new string[maxSize];
}
Array::~Array() {
    delete[] data;  
}
struct Queue {
    string cell;
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;

    ~Queue();

    void QPUSH(string& cell);
    void QPOP();
    void QREAD();
    void Clear();
};
Queue::~Queue() {
    Clear();
}
struct Stack {
    string cell;
    ~Stack();
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
    void SPUSH(string& cell);
    void SPOP();
    void SREAD();
    void Clear();
};

Stack::~Stack() {
    Clear();
}
struct OneList {
    ~OneList();
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
    void LONEPUSHhead(string& cell);
    void LONEPUSHtail(string& cell);
    void LONEDELhead();
    void LONEDELtail();
    void LONEDELvalue(string& value);
    void LONESEARCH(string& value);
    void LONEREAD();
    void Clear();
};

OneList::~OneList() {
    Clear();
}
struct TwoList {
    ~TwoList();

    DoubleNode* head = nullptr;
    DoubleNode* tail = nullptr;
    void LTWOPUSHhead(string& element);
    void LTWOPUSHtail(string& element);
    void LTWODELhead();
    void LTWODELtail();
    void LTWODELvalue(string& value);
    void LTWOSEARCH(string& value);
    void LTWOREAD();

    void Clear();
};

TwoList::~TwoList() {
    Clear();
}
struct AVL {
    AVLnode* root;
    AVL() : root(nullptr) {};

    ~AVL();
    void TDestroyAVL(AVLnode* node);
    string key;
    unsigned char height;
    SingleNode* left;
    SingleNode* right;

    int THeight(AVLnode* node);
    int TBalance(AVLnode* node);
    AVLnode* TRightRotate(AVLnode* y);
    AVLnode* TLeftRotate(AVLnode* x);
    AVLnode* TInsert(AVLnode* node, string & key);
    AVLnode* TMinValueLeftNode(AVLnode* node);
    AVLnode* TDeleteNode(AVLnode* root, string& key);
    AVLnode* TSearch(AVLnode* node, string& key);
    void TDisplay(AVLnode* node);
    void TPUSH(string& key);
    void TDEL(string& key);
    bool TSEARCH(string& key);
    void TREAD();

    void TSaveToFile(AVLnode* node, ofstream& FileWrite);
    
};

AVL::~AVL() {
    TDestroyAVL(root);
}
struct HashTable {
    NodeHash** table; // массив указателей на узлы хеш-таблицы
    int size; 
    int count; 
    
    HashTable(int initialSize = 100);
    int HashFunc(string& str);
    void HPUSH( string& key, string& value);
    string HGET( string& key);
    void HDEL( string& key);
    void HREAD();

    void HDestroyTable(NodeHash* node);
    ~HashTable();
};

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
         HDestroyTable(table[i]);
    }
    delete[] table;
}
