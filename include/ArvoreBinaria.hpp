#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP
#include "TipoItem.hpp"

class ArvoreBinaria
{
public:
  ArvoreBinaria();
  ~ArvoreBinaria();
  void Insere(TipoItem *item);
  void Limpa();
  TipoItem *Pesquisa(int chave, int id_user);
  int Remove(int chave);
  int RemoveRecursivo(TipoItem *&p, int chave);

private:
  TipoItem *PesquisaRecursivo(TipoItem *p, int chave, int id_user);
  void InsereRecursivo(TipoItem *&p, TipoItem *item);
  void ApagaRecursivo(TipoItem *p);
  TipoItem *raiz;
  void Antecessor(TipoItem *q, TipoItem *&r);
};

#endif