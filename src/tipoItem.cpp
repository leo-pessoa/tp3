#include <iostream>
#include "tipoItem.hpp"

tipoItem::tipoItem()
{
 id_usuario = -1;
 tam_texto = -1;
 id_mensagem = -1;
 *texto = "";
 esq = NULL;
 dir = NULL;
};

tipoItem::tipoItem(std::string *_texto, int _id_mensagem, int tamanho, int _id_usuario)
{
 id_usuario = _id_usuario;
 tam_texto = tamanho;
 id_mensagem = _id_mensagem;
 for (int i = 0; i < tamanho; i++)
 {
  texto[i] = _texto[i];
 }
}
