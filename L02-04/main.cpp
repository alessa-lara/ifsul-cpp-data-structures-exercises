#include "lib/menu.cpp"
#include "lib/stack.hpp"

using namespace std;

int main() {
    string opcoes[6] = {
        "Criar pilha",
        "Inserir",
        "Remover",
        "Consultar",
        "Mostrar",
        "Sair",
    };

    int menuIn;
    Stack<int> stack;
    bool init = false;
    while ( true ) {
        menuIn = menu("", opcoes, 6);

        if ( menuIn == 0 ) {
            int len;
            cout << "Insira o tamanho da pilha: ";
            cin >> len;
            if ( isInit(&stack) ) {
                deleteStack(&stack);
            }
            newStack(&stack, len);
        } else if ( menuIn == 1 ) {
            if ( !isInit(&stack) ) {
                cout << "erro: pilha não criada";
                hang();
                continue;
            }

            int val;
            cin >> val;
            int ret = search(&stack, val);
            if ( ret ) {
                cout << "Não é permitida a inserção de valores duplicados";
                hang();
                continue;
            }

            if ( isFull(&stack) ) {
                cout << "Pilha sem espaços disponíveis";
                hang();
                continue;
            }
            push(&stack, val);
        } else if ( menuIn == 2 ) {
            if ( !isInit(&stack) ) {
                cout << "erro: pilha não criada";
                hang();
                continue;
            }

            if ( isEmpty(&stack) ) {
                cout << "Pilha vazia";
                hang();
                continue;
            };
            int ret = pop(&stack);
            cout << "valor " << ret << " removido";
            hang();
        } else if ( menuIn == 3 ) {
            if ( !isInit(&stack) ) {
                cout << "erro: pilha não criada";
                hang();
                continue;
            }

            int val;
            cin >> val;
            int ret = search(&stack, val);
            if ( ret ) {
                cout << "Valor presente na pilha";
            } else {
                cout << "Valor não encontrado na pilha";
            }
            hang();
        } else if ( menuIn == 4 ) {
            if ( !isInit(&stack) ) {
                cout << "erro: pilha não criada";
                hang();
                continue;
            }

            show(&stack);
            hang();
        } else if ( menuIn == 5 ) {
            return 0;
        }
    }

    return 0;
}
