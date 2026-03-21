#include "lib/stackDyn.hpp"
#include <iostream>

using namespace std;

template <typename T>
void showRecursive(Node<T>* node) {
    cout << node->data << ", ";
    if (node->next != nullptr) {
        showRecursive(node->next);
    }
}

int main() {
    Stack<int> stack;
    for (int i = 0; i < 5; i++) {
        int val = i + 5 * 3 % 4;
        cout << val << ", ";
        push(&stack, val);
    }
    cout << endl;
    cout << "print recursivo: ";

    showRecursive(stack.top);

    return 0;
}
