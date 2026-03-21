#include "lib/queue.hpp"
#include "lib/queueFunctions.hpp"

void testSearch(Queue<int>* q, int val) {
    if (search(q, val)) {
        cout << val << " found" << std::endl;
    } else {
        cout << val << " not found" << std::endl;
    }
}

void testSearchAux(Queue<int>* q, int val) {
    if (searchAux(q, val)) {
        cout << val << " found" << std::endl;
    } else {
        cout << val << " not found" << std::endl;
    }
}

int main() {
    Queue<int> queue(3);
    enqueue(&queue, 1);
    enqueue(&queue, 4);
    enqueue(&queue, 2);

    testSearch(&queue, 0);
    testSearch(&queue, 1);

    testSearchAux(&queue, 0);
    testSearchAux(&queue, 1);

    return 0;
}