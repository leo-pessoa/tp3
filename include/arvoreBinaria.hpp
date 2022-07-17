#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP
#include "tipoItem.hpp"

class arvoreBinaria
{
public:
  arvoreBinaria();
  void insere(tipoItem *item);
  tipoItem *pesquisa(int chave, int id_user);
  int remove(int chave);
  int removeRecursivo(tipoItem *&p, int chave);

private:
  tipoItem *pesquisaRecursivo(tipoItem *p, int chave, int id_user);
  void insereRecursivo(tipoItem *&p, tipoItem *item);
  tipoItem *raiz;
  void antecessor(tipoItem *q, tipoItem *&r);
};

#endif