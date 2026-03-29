#include "lib/stack.hpp"
#include "lib/stackFunctions.hpp"

int main() {
    Stack<int> stack(5);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    show(stack);
    std::cout << std::endl;
    
    reverseStack(stack);

    show(stack);

    return 0;
}