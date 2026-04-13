#include "lib/menu.hpp"
#include "lib/queueDyn.hpp"
#include "lib/stackDyn.hpp"

using namespace std;

struct Cliente {
    string nome;
    int codigo;
    uint idade;
    float saldo;

    Cliente();
    Cliente(string nome, int codigo, uint idade, float saldo) {
        this->nome = nome;
        this->codigo = codigo;
        this->idade = idade;
        this->saldo = saldo;
    }
};

bool search(Queue<Cliente>& queue, int cod) {
    if ( isEmpty(queue) )
        throw std::logic_error("Queue vazia");

    NodeQueue<Cliente>* curr = queue.head;
    while ( curr != nullptr ) {
        if ( curr->data.codigo == cod )
            return true;
        curr = curr->next;
    }

    return false;
}

bool search(Stack<Cliente>& stack, int cod) {
    Node<Cliente>* node = stack.top;

    while ( node != nullptr ) {
        if ( node->data.codigo == cod ) {
            return true;
        }

        node = node->next;
    }

    return false;
}

void ordenar(Stack<Cliente>& stack) {
    bool trocou;
    do {
        trocou = false;
        Node<Cliente>* no = stack.top;
        while ( no != NULL && no->next != NULL ) {
            if ( no->data.nome > no->next->data.nome ) {
                Cliente aux = no->data;
                no->data = no->next->data;
                no->next->data = aux;
                trocou = true;
            }
            no = no->next;
        }
    } while ( trocou == true );
}

// THROWS: logic_error
void cadastrar(Stack<Cliente> pilhaCad) {
    string nome;
    int codigo;
    uint idade;
    float saldo;

    cout << "Informar nome: ";
    cin >> nome;

    cout << endl
         << "Informar codigo: ";
    cin >> codigo;
    if ( search(pilhaCad, codigo) ) {
        throw logic_error("Código já existe");
    }

    cout << endl
         << "Informar idade: ";
    cin >> idade;

    cout << endl
         << "Informar saldo: ";
    cin >> saldo;

    // TODO: o certo seria validar, mas eu n quero

    Cliente novo(nome, codigo, idade, saldo);

    push(pilhaCad, novo);
    ordenar(pilhaCad);
    cout << endl
         << "Cliente cadastrado com sucesso";
}

// THROWS: logic_error
void addToQueue(Queue<int> queue, Stack<Cliente> cadastros, int codigo) {
    if ( search(queue, codigo) ) {
        throw logic_error("Cliente já existe na fila");
    }

    if ( !search(cadastros, codigo) ) {
        throw logic_error("Código do cliente inexistente");
    }

    Node<Cliente>* curr = cadastros.top;
    while ( curr != nullptr ) {
        if ( curr->data.codigo == codigo ) {
            enqueue(queue, codigo);
            cout << "Cliente adicionado na fila com sucesso";
            return;
        }
        curr = curr->next;
    }
}

int main() {
    Stack<Cliente> cadastro;
    Queue<int> P;
    Queue<int> N;

    string opcoes[5] = {
        "cadastrar",
        "adicionar na fila",
        "mostrar",
        "atender",
        "mostrar dados do banco",
    };

    int ret;
    do {
        ret = menu("", opcoes, size_t(5));

        switch ( ret ) {
            case 1:
                try {
                    cadastrar(cadastro);
                } catch ( logic_error& e ) {
                    cout << e.what();
                }
                break;
        }

        try {
            addToQueue(P, cadastro, 0);
        } catch ( logic_error& e ) {
            cout << e.what();
        }
    } while ( ret != 0 );

    return 0;
}
