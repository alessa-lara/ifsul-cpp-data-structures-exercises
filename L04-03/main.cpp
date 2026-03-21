#include "lib/stackDyn.hpp"
#include <random>

using namespace std;

void ordenar(int* arr, int* len) {
    Stack<int> aux;
    Stack<int> ord;

    for ( int i = 0; i < *len; i++ ) {
        push(&aux, arr[i]);
    }

    bool ordered = false;
    push(&ord, pop(&aux));
    while ( !ordered ) {
        int s = pop(&aux);
        if ( s > peek(&aux) ) {
            push(&ord, pop(&aux));
            push(&aux, s);
        } else {
            push(&ord, s);
        }
        cout << "aux: "; show(&aux);
        cout << "ord: "; show(&ord);
    }

    deleteStack(&aux);
    deleteStack(&ord);
}

int main() {
    // random values setup
    random_device randDev;
    mt19937 rng(randDev());
    uniform_int_distribution<> dist(1, 100.0);
    // random end

    int arr[3];

    for ( int i = 0; i < 3; i++ ) {
        arr[i] = dist(rng);
    }

    ordenar(arr, new int (3));

    return 0;
}