#include "stackDyn.hpp"
#include <random>

using namespace std;

float mediaAritmetica(Stack<float>* stack) {
    int i = 0;
    float sum = 0;
    Node<float>* node = stack->top;
    
    while ( node != nullptr ) {
        sum += node->data;
        i++;
        node = node->next;
    }

    return sum / i;
}

int main() {
    // random values setup
    random_device randDev;
    mt19937 rng(randDev());
    uniform_real_distribution<float> dist(1.0f, 100.0f);
    // random end

    Stack<float> stack;

    for (int i = 0; i < 3; i++) {
        push(&stack, dist(rng));
    }

    float res = mediaAritmetica(&stack);

    cout << res;

    deleteStack(&stack);

    return 0;
}