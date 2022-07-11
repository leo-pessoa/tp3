#ifndef TIPO_ITEM
#define TIPO_ITEM

#include <string>

class TipoItem
{
public:
 TipoItem();
 TipoItem(std::string _texto[200], int _id_mail, int tamanho, int _id_usuario);
 int tam_texto;
 int id_mail;
 int id_usuario;
 std::string texto[200];

private:
 int chave;
 TipoItem *esq;
 TipoItem *dir;
 friend class ArvoreBinaria;
 friend class HashTable;
};

#endif