#ifndef TIPO_ITEM
#define TIPO_ITEM

#include <string>

class tipoItem
{
public:
 tipoItem();
 tipoItem(std::string _texto[200], int _id_mensagem, int tamanho, int _id_usuario);
 int tam_texto;
 int id_mensagem;
 int id_usuario;
 std::string texto[200];

private:
 int chave;
 tipoItem *esq;
 tipoItem *dir;
 friend class arvoreBinaria;
 friend class hashTable;
};

#endif