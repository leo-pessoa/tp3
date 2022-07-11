#include <iostream>
#include <string>
#include "ArvoreBinaria.hpp"

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

void ArvoreBinaria::InsereRecursivo(TipoItem *&p, TipoItem *item)
{
  if (p == NULL)
  {
    p = item;
  }
  else
  {
    if (item->id_mail < p->id_mail)
    {

      InsereRecursivo(p->esq, item);
    }
    else
    {
      InsereRecursivo(p->dir, item);
    }
  }
};

TipoItem *ArvoreBinaria::Pesquisa(int chave, int id_user)
{
  return PesquisaRecursivo(raiz, chave, id_user);
};

TipoItem *ArvoreBinaria::PesquisaRecursivo(TipoItem *p, int chave, int id_user)
{

  TipoItem *aux = new TipoItem();
  if (p == NULL)
  {
    aux->id_mail = -1;
    return aux;
  }
  else if (chave < p->id_mail)
  {
    return PesquisaRecursivo(p->esq, chave, id_user);
  }
  else if (chave > p->id_mail)
    return PesquisaRecursivo(p->dir, chave, id_user);
  else
  {
    if (id_user == p->id_usuario)
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

void ArvoreBinaria::ApagaRecursivo(TipoItem *p)
{
  if (p != NULL)
  {
    ApagaRecursivo(p->esq);
    ApagaRecursivo(p->dir);
    delete p;
  }
};

int ArvoreBinaria::Remove(int chave)
{
  return RemoveRecursivo(raiz, chave);
};

int ArvoreBinaria::RemoveRecursivo(TipoItem *&p, int chave)
{
  TipoItem *aux;
  if (p == NULL)
  {
    return 0;
  }
  if (chave < p->id_mail)
  {
    return RemoveRecursivo(p->esq, chave);
  }
  else if (chave > p->id_mail)
  {
    return RemoveRecursivo(p->dir, chave);
  }
  else
  {
    if (p->dir == NULL)
    {
      aux = p;
      p = p->esq;
      delete aux;
      return 1;
    }
    else if (p->esq == NULL)
    {
      aux = p;
      p = p->dir;
      delete aux;
      return 1;
    }
    else
    {
      Antecessor(p, p->esq);
      return 1;
    }
  }

  return 0;
};

void ArvoreBinaria::Antecessor(TipoItem *q, TipoItem *&r)
{
  if (r->dir != NULL)
  {
    Antecessor(q, r->dir);
    return;
  }
  q->chave = r->chave;
  q = r;
  r = r->esq;
  free(q);
}
