#include <iostream>
#include <string>
#include "ArvoreBinaria.hpp"

TipoNo::TipoNo()
{
  item.SetIdEmail(-1);
  esq = NULL;
  dir = NULL;
}

ArvoreBinaria::ArvoreBinaria()
{
  raiz = NULL;
};

ArvoreBinaria::~ArvoreBinaria()
{
  Limpa();
};

void ArvoreBinaria::Insere(TipoItem *item)
{
  InsereRecursivo(raiz, item);
};

void ArvoreBinaria::InsereRecursivo(TipoNo *&p, TipoItem *item)
{
  if (p == NULL)
  {
    p = new TipoNo();
    p->item = *item;
  }
  else
  {
    if (p->item.GetIdEmail() < p->item.GetIdEmail())
      InsereRecursivo(p->esq, item);
    else
      InsereRecursivo(p->dir, item);
  }
};

TipoItem *ArvoreBinaria::Pesquisa(int chave, int id_user)
{
  return PesquisaRecursivo(raiz, chave, id_user);
}

TipoNo *ArvoreBinaria::PesquisaRecursivo(TipoNo *p, int chave, int id_user)
{

  TipoNo *aux = new TipoNo();

  if (p == NULL)
  {
    aux->SetIdEmail(-1);
    return aux;
  }
  if (chave < p->item.GetIdEmail())
    return PesquisaRecursivo(p->esq, chave, id_user);
  else if (chave > p->item.GetIdEmail())
    return PesquisaRecursivo(p->dir, chave, id_user);
  else
  {
    if (id_user == p->item.GetUserId())
      return p;
    else
      return aux;
  }
};

void ArvoreBinaria::Limpa()
{
  ApagaRecursivo(raiz);
  raiz = NULL;
}

int ArvoreBinaria::Remove(int chave)
{
  return RemoveRecursivo(raiz, chave);
}

int ArvoreBinaria::RemoveRecursivo(TipoNo *&p, int chave)
{
  if (p == NULL)
    return 0;
  if (chave < p->item.GetIdEmail())
    return RemoveRecursivo(p->esq, chave);
  else if (chave > p->item.GetIdEmail())
    return RemoveRecursivo(p->dir, chave);
  else
  {
    if (p->esq == NULL && p->dir == NULL)
    {
      delete p;
      p = NULL;
      return 0;
    }
    else if (p->esq == NULL)
    {
      TipoNo *aux = p;
      p = p->dir;
      delete aux;
      return 1;
    }
    else if (p->dir == NULL)
    {
      TipoNo *aux = p;
      p = p->esq;
      delete aux;
      return 1;
    }
    else
    {
      TipoNo *aux = p->dir;
      while (aux->esq != NULL)
        aux = aux->esq;
      p->item = aux->item;
      return RemoveRecursivo(p->dir, aux->item.GetIdEmail());
    }
  }

  return 0;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
  if (p != NULL)
  {
    ApagaRecursivo(p->esq);
    ApagaRecursivo(p->dir);
    delete p;
  }
}