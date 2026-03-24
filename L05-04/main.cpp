#include "lib/menu.hpp"
#include "lib/hang.hpp"
#include "lib/queue.hpp"

using namespace std;

struct Aviao {
    int codigo;
    int passageiros;
    string empresa;

    Aviao() = default;
    Aviao(int cod, int nPassageiros, string nomeEmpresa) {
        codigo = cod;
        passageiros = nPassageiros;
        empresa = nomeEmpresa;
    }
};

void showAviao(Aviao* aviao) {
    cout << "codigo: " << aviao->codigo << ", ";
    cout << "numero de passageiros: " << aviao->passageiros << ", ";
    cout << "empresa: " << aviao->empresa << "; " << endl;
}

Aviao inputAviao() {
    int cod;
    int nPassageiros;
    string nomeEmpresa;

    cout << "Insira o codigo do aviao:";
    cin >> cod;
    cout << endl;
    cout << "Insira a quantia de passageiros que o aviao carrega:";
    cin >> nPassageiros;
    cout << endl;
    cout << "Insira o nome da empresa: ";
    cin >> nomeEmpresa;
    cout << endl;

    Aviao aviao(cod, nPassageiros, nomeEmpresa);

    showAviao(&aviao);

    return aviao;
}

void show(Queue<Aviao>* queue) {
    if (isEmpty(queue)) {
        throw std::logic_error("Queue Vazia");
    }

    int curr = queue->head;
    for (int i = 0; i < queue->len; i++) {
        showAviao(queue->data);
        curr++;

        if (curr == queue->capacity) {
            curr = 0;
        }
    }
}

int main() {
    Queue queue = Queue<Aviao>(5);
    Aviao av;

    string opcoes[6] = {
        "Fechar Programa",
        "Imprimir o Nº de aviões à espera de decolar",
        "Entrada de um novo avião para decolar",
        "Decolagem de um avião",
        "Listar todos os aviões à espera para decolagem",
        "Listar as características do próximo avião a decolar",
    };

    int uOpt;
    do {
        uOpt = menu("", opcoes, 6);

        switch (uOpt) {
            case 1:
                cout << "Avioes a espera: ";
                cout << queue.len;
                cout << endl;
                hang();
                break;
            case 2:
                enqueue(&queue, inputAviao());
                hang();
                break;
            case 3:
                try {
                    av = dequeue(&queue);
                    showAviao(&av);
                    hang();
                } catch (std::logic_error) {
                    cout << "Fila vazia" << endl;
                    hang();
                }
                break;
            case 4:
                show(&queue);
                hang();
                break;
            case 5:
                av = peek(&queue);
                showAviao(&av);
                hang();
                break;
        }
    } while (uOpt != 0);

    deleteQueue(&queue);
    return 0;
}