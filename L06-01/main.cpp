#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "lib/queue.hpp"

using namespace std;

struct Doc {
    string name;
    int pages;
};

ifstream openFile(string file) {
    ifstream arq(file);

    if (!arq.is_open()) {
        throw runtime_error("Falha na abertura do arquivo");
    }

    return arq;
}

void mostrar(Queue<Doc>& queue) {
    // TODO MOSTRAR O NOME DE CADA ARQUIVO QUE TA NA FILA
}

int main() {
    Queue<Doc> p(0);
    Queue<Doc> n(0);

    ifstream file = openFile("entrada.txt");

    stringstream strBuff;
    string s = "";
    string temp = "";

    while (getline(file, s)) {
        strBuff = stringstream(s);
        string op;
        strBuff >> op;

        if (op == "MOSTRAR") {
            string queueId;
            strBuff >> queueId;
            if (queueId == "P") {
                mostrar(p);
            } else if (queueId == "N") {
                mostrar(n);
            } else {
                cout << "ERRO: Identificação da fila inválida";
            }
        } else if (op == "INICIALIZAR") {
            if (isInit(&p)) {
                deleteQueue(&p);
            }

            if (isInit(&n)) {
                deleteQueue(&n);
            }

            int size;
            strBuff >> size;

            p = Queue<Doc>(size);
            n = Queue<Doc>(size);
        } else if (op == "ENFILEIRARDOC") {
            Doc doc;
            string queueId;

            strBuff >> doc.name;
            strBuff >> doc.pages;

            strBuff >> queueId;

            if (queueId == "P") {
                enqueue(&p, doc);
            } else if (queueId == "N") {
                enqueue(&n, doc);
            } else {
                cout << "ERRO: Identificação da fila inválida";
            }
        } else if (op == "IMPRIMIRDOC") {
            string queueId;
            strBuff >> queueId;

            if (queueId == "P") {
                dequeue(&p);
            } else if (queueId == "N") {
                dequeue(&n);
            } else {
                cout << "ERRO: Identificação da fila inválida";
            }
        } else if (op == "TOTALPAG") {
            //TODO IMPLEMENTAR
        } else if (op == "CONSULTAR") {
            string strBusca = "";
            string queueId;

            strBuff >> strBusca;
            strBuff >> queueId;

            if (queueId == "P") {
            } else if (queueId == "N") {
                dequeue(&n);
            } else {
                cout << "ERRO: Identificação da fila inválida";
            }

        }

        s = "";
    }

    return 0;
}