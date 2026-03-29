#include "lib/stack.hpp"
#include "lib/stackFunctions.hpp"

int main() {
    Stack<int> stFir(3);
    Stack<int> stSec(3);

    push(stFir, 1);
    push(stFir, 2);
    push(stFir, 3);

    push(stSec, 4);
    push(stSec, 2);
    push(stSec, 3);

    if (areEqual(stFir, stSec)) {
        std::cout << "equal";
    } else {
        std::cout << "not equal";
    }

    return 0;
}