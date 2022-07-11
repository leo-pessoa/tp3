#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP
#include "TipoItem.hpp"

class TipoNo : public TipoItem
{
public:
  TipoNo();

private:
  TipoItem item;
  TipoNo *esq;
  TipoNo *dir;

  friend class ArvoreBinaria;
};

class ArvoreBinaria
{
public:
  ArvoreBinaria();
  ~ArvoreBinaria();
  void Insere(TipoItem *item);
  void Caminha(int tipo);
  void Limpa();
  TipoItem *Pesquisa(int chave, int id_user);
  int Remove(int chave);
  int RemoveRecursivo(TipoNo *&p, int chave);
  void Antecessor(TipoItem *q, TipoItem *&r);

private:
  TipoNo *PesquisaRecursivo(TipoNo *p, int chave, int id_user);
  void InsereRecursivo(TipoNo *&p, TipoItem *item);
  void ApagaRecursivo(TipoNo *p);
  TipoNo *raiz;
};

#endif