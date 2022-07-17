#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "arvoreBinaria.hpp"
#include "tipoItem.hpp"
#include "hashTable.hpp"
#include <string>
#include <getopt.h>
#include <fstream>
#include "msgassert.h"
#include <stdio.h>
#include <cstring>

using namespace std;

char nome_entrada[100], nome_saida[100];

void parseArgs(int argc, char **argv)
{
    extern char *optarg;
    int c;
    nome_entrada[0] = 0;
    nome_saida[0] = 0;

    while ((c = getopt(argc, argv, "i:I:o:O:h")) != EOF)
    {
        switch (c)
        {
        case 'o':
            strcpy(nome_saida, optarg);
            break;
        case 'O':
            strcpy(nome_saida, optarg);
            break;
        case 'i':
            strcpy(nome_entrada, optarg);
            break;
        case 'I':
            strcpy(nome_entrada, optarg);
            break;
        }
    }
}

int main(int argc, char **argv)
{
    parseArgs(argc, argv);

    ifstream input;
    ofstream output;
    input.open(nome_entrada);
    output.open(nome_saida);

    erroAssert(input.is_open(), "Erro no arquivo de entrada");

    int tam_servidor;

    input >> tam_servidor;
    hashTable ht(tam_servidor);

    string comando, texto[200];
    int usuario_id, email_id;

    while (input >> comando >> usuario_id >> email_id)
    {
        if (comando == "ENTREGA")
        {
            ht.entrega(input, output, usuario_id, email_id, texto);
        }

        else if (comando == "APAGA")
        {
            ht.apaga(output, usuario_id, email_id);
        }

        else if (comando == "CONSULTA")
        {
            ht.consulta(output, usuario_id, email_id, texto);
        }
    }

    input.close();
    output.close();
    return 0;
}