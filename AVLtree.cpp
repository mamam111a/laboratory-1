
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;


void AVL::TDestroyAVL(AVLnode* node) {
    if (node == nullptr) {
        return;
    }
    TDestroyAVL(node->left);
    TDestroyAVL(node->right);
    delete node;
}

int AVL::THeight(AVLnode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height; 
}

int AVL::TBalance(AVLnode* node) {
    if (node == nullptr) return 0; 
    return THeight(node->left) - THeight(node->right); 
}
AVLnode* AVL::TRightRotate(AVLnode* node) {
    AVLnode* A = node->left; // левый потомок узла становится А
    AVLnode* B = A->right;  // правый потомок узла А становится В

    A->right = node; // А становится корнем, ноде становится правым потомком
    node->left = B; // левый потомок ноде становится В

    node->height = max(THeight(node->left), THeight(node->right)) + 1; // ноде и А становятся двумя разными поддеревьями
    A->height = max(THeight(A->left), THeight(A->right)) + 1;

    return A; // корень
}


AVLnode* AVL::TLeftRotate(AVLnode* node) { //симметрия
    AVLnode* A = node->right;
    AVLnode* B = A->left;

    A->left = node;
    node->right = B;

    node->height = max(THeight(node->left), THeight(node->right)) + 1;
    A->height = max(THeight(A->left), THeight(A->right)) + 1;

    return A;
}
AVLnode* AVL::TInsert(AVLnode* node,  string&key) {
    // если текущий узел пустой, создаем новый узел с переданным ключом
    if (node == nullptr) {
        return new AVLnode(key);
    }
    //рекурсивно вставляем в левое поддерево
    if (key < node->key) {
        node->left = TInsert(node->left, key);
    }
    // рекурсивно вставляем в правое поддерево
    else if (key > node->key) {
        node->right = TInsert(node->right, key);
    }
    // если ключ уже существует, возвращаем текущий узел 
    else {
        return node; //(без дубликатов)
    }

    node->height = 1 + max(THeight(node->left), THeight(node->right)); // обновляем высоту текущего узла

    // вычисляем баланстекущего узла
    int balance = TBalance(node);

    // левый-левый
    if (balance > 1 && key < node->left->key)
        return TRightRotate(node);

    // левый-правый
    if (balance > 1 && key > node->left->key) {
        node->left = TLeftRotate(node->left); //меняет местами
        return TRightRotate(node);
    }
    // правый-правый
    if (balance < -1 && key > node->right->key)
        return TLeftRotate(node);

    // правый-левый
    if (balance < -1 && key < node->right->key) {
        node->right = TRightRotate(node->right); // меняет местами
        return TLeftRotate(node);
    }

    return node; // возвращаем корень поддерева
}
AVLnode* AVL::TMinValueLeftNode(AVLnode* node) {
    AVLnode* current = node;
    while (current->left != nullptr) // идем по левому поддереву до самого левого узла
        current = current->left;
    return current;
}
AVLnode* AVL::TDeleteNode(AVLnode* root, string &key) {
    if (root == nullptr) {
        return root; // если дерево пустое
    }
    // рекурсивно удаляем в левом поддереве
    if (key < root->key)
        root->left = TDeleteNode(root->left, key);
    // рекурсивно удаляем в правом поддереве
    else if (key > root->key)
        root->right = TDeleteNode(root->right, key);
    // если ключ совпадает с ключом текущего узла, удаляем текущий узел
    else {
        // если у текущего узла нет одного из потомков или оба потомка отсутствуют
        if (root->left == nullptr || root->right == nullptr) {
            // выбираем непустого потомка или nullptr, если оба потомка отсутствуют
            AVLnode* temp = root->left ? root->left : root->right;

            // если непустой потомок отсутствует, удаляем текущий узел
            if (temp == nullptr) {
                temp = root; //переходим к этому потомку
                root = nullptr; //обнуляем его
            }
            // если есть непустой потомок, копируем его данные в текущий узел
            else
                *root = *temp;

            delete temp; // освобождаем память удаляемого узла
        }
        // если у текущего узла есть оба потомка
        else {
            AVLnode* temp = TMinValueLeftNode(root->right); // находим узел с минимальным ключом в правом поддереве
            root->key = temp->key; // копируем ключ минимального узла в текущий узел
            root->right = TDeleteNode(root->right, temp->key); // рекурсивно удаляем минимальный узел из правого поддерева
        }
    }

    // если дерево стало пустым после удаления, возвращаем его
    if (root == nullptr) {
        return root;
    }
    // обновляем высоту текущего узла
    root->height = 1 + max(THeight(root->left), THeight(root->right));

    // вычисляем баланс текущего узла
    int balance = TBalance(root);

    // левый-левый случай: баланс-фактор > 1 и баланс-фактор левого поддерева >= 0
    if (balance > 1 && TBalance(root->left) >= 0)
        return TRightRotate(root);

    // левый-правый случай: баланс-фактор > 1 и баланс-фактор левого поддерева < 0
    if (balance > 1 && TBalance(root->left) < 0) {
        root->left = TLeftRotate(root->left);
        return TRightRotate(root);
    }

    // правый-правый случай: баланс-фактор < -1 и баланс-фактор правого поддерева <= 0
    if (balance < -1 && TBalance(root->right) <= 0)
        return TLeftRotate(root);

    // правый-левый случай: баланс-фактор < -1 и баланс-фактор правого поддерева > 0
    if (balance < -1 && TBalance(root->right) > 0) {
        root->right = TRightRotate(root->right);
        return TLeftRotate(root);
    }

    return root; // возвращаем корень поддерева
}

AVLnode* AVL::TSearch(AVLnode* node, string & key) {
    if (node == nullptr || node->key == key) {// если узел пустой или ключ найден, возвращаем узел
        return node;
    }

    if (key < node->key)
        return TSearch(node->left, key); 
    else
        return TSearch(node->right, key);
}
void AVL::TDisplay(AVLnode* node) {
    if (node != nullptr) {
        cout << node->key << " "; // выводим ключ текущего узла
        TDisplay(node->left); // рекурсивно обходим левое поддерево
        TDisplay(node->right); // рекурсивно обходим правое поддерево
    }
}
void AVL::TSaveToFile(AVLnode* node, ofstream& FileWrite) {
    if (node == nullptr) {
        return;
    }

    FileWrite << node->key << " "; // записываем ключ текущего узла

    // рекурсивно записываем левое и правое поддеревья
    TSaveToFile(node->left, FileWrite);
    TSaveToFile(node->right, FileWrite);
}

void AVL::TPUSH(string &key) {
    root = TInsert(root, key);
}

void AVL::TDEL(string& key) {
    root = TDeleteNode(root, key);
}

bool AVL::TSEARCH(string&key) {
    return TSearch(root, key) != nullptr;
}

void AVL::TREAD() {
    TDisplay(root);
    cout << endl;
}

