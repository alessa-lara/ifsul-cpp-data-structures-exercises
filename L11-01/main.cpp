#include "lib/list.hpp"
#include <iostream>

using namespace std;

template <typename T>
void insereAposPrimeiroPar(Node<T>*& list, T val) {
    Node<T>* node = list;

    while ( node != nullptr ) {
        if ( node->data % 2 == 0 ) {
            Node<T>* newNode = new Node<T>;
            newNode->data = val;
            newNode->next = node->next;

            node->next = newNode;
            return;
        }

        node = node->next;
    }
}

template <typename T>
void insereAntesPrimeiroPar(Node<T>*& list, T val) {
    Node<T>* node = list;
    Node<T>* prev;

    while ( node != nullptr ) {
        if ( node->data % 2 == 0 ) {
            Node<T>* newNode = new Node<T>;
            newNode->data = val;
            newNode->next = node;

            prev->next = newNode;
            return;
        }

        prev = node;
        node = node->next;
    }
}

template <typename T>
int totalElementos(Node<T>*& list) {
    Node<T>* node = list;
    int count = 0;

    while ( node != nullptr ) {
        count++;
        node = node->next;
    }

    return count;
}

template <typename T>
bool areEqual(Node<T>*& listOne, Node<T>*& listTwo) {
    Node<T>* node = listOne;
    Node<T>* nodeCompare = listTwo;

    while ( node != nullptr ) {
        if ( node->data != nodeCompare->data )
            return false;

        nodeCompare = nodeCompare->next;
        node = node->next;
    }

    return true;
}

int main() {
    Node<int>* list = nullptr;
    insertEnd(&list, 1);
    insertEnd(&list, 2);
    insertEnd(&list, 3);
    insertEnd(&list, 4);
    show(list);
    cout << endl;

    Node<int>* list2 = nullptr;
    insertEnd(&list2, 1);
    insertEnd(&list2, 2);
    insertEnd(&list2, 3);
    insertEnd(&list2, 4);
    if ( areEqual(list, list2) )
        cout << "listas sao iguais \n";

    cout << totalElementos(list) << endl;

    insereAntesPrimeiroPar(list, 99);
    insereAposPrimeiroPar(list, 77);
    show(list);
}
