#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "ArvoreBinaria.hpp"
#include "TipoItem.hpp"
#include "HashTable.hpp"
#include <string>
#include <getopt.h>
#include <fstream>
#include "msgassert.h"
#include <stdio.h>
#include <cstring>

using namespace std;

using namespace std;
char arq_in[100], arq_out[100];
void parse_args(int argc, char **argv)
{
    extern char *optarg;
    int c;
    arq_in[0] = 0;
    arq_out[0] = 0;

    while ((c = getopt(argc, argv, "i:I:m:M:s:S:o:O:h")) != EOF)
    {
        switch (c)
        {
        case 'i':
        case 'I':
            strcpy(arq_in, optarg);
            break;
        case 'o':
        case 'O':
            strcpy(arq_out, optarg);
            break;
        }
    }
}

int main(int argc, char **argv)
{
    parse_args(argc, argv);

    int usuario_id, email_id, n_palavras, aux_pos, aux_delete = 0;
    int tam_servidor;
    string comando, texto_aux, texto[200];
    TipoItem *no_aux = new TipoItem();

    ifstream input;
    ofstream output;
    input.open(arq_in);
    output.open(arq_out);

    erroAssert(input.is_open(), "Erro ao abrir arquivo de entrada");

    input >> tam_servidor;
    HashTable ht(tam_servidor);

    while (input >> comando >> usuario_id >> email_id)
    {
        if (comando == "ENTREGA")
        {
            input >> n_palavras;
            for (int i = 0; i < n_palavras; i++)
            {
                input >> texto_aux;
                texto[i] = texto_aux;
            }
            TipoItem *email = new TipoItem(email_id, usuario_id, texto, n_palavras);
            aux_pos = ht.Insere(email, usuario_id);
            output << "OK: MENSAGEM " << email_id << " PARA " << usuario_id << " ARMAZENADA EM " << aux_pos << endl;
        }
        else if (comando == "CONSULTA")
        {
            no_aux = ht.Pesquisa(email_id, usuario_id);
            std::cout << "OK: MENSAGEM " << email_id << " PARA " << usuario_id << " ENCONTRADA EM " << no_aux->GetIdEmail() << endl;
            if (no_aux->GetIdEmail() == email_id)
            {
                output << comando << " " << usuario_id << " " << email_id << ": ";

                output << no_aux->GetTexto(n_palavras) << endl;
            }
            else
                output << comando << " " << usuario_id << " " << email_id << ": MENSAGEM INEXISTENTE" << endl;
        }
        else if (comando == "APAGA")
        {
            aux_delete = ht.Remove(usuario_id, email_id);
            if (aux_delete)
                output << "OK: MENSAGEM APAGADA" << endl;
            else
                output << "ERRO: MENSAGEM INEXISTENTE" << endl;
        }
    }
    input.close();
    output.close();
    return 0;
}