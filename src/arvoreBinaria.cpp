#include <iostream>
#include <string>
#include "arvoreBinaria.hpp"

arvoreBinaria::arvoreBinaria()
{
  raiz = NULL;
};

void arvoreBinaria::insere(tipoItem *item)
{
  insereRecursivo(raiz, item);
};

void arvoreBinaria::insereRecursivo(tipoItem *&p, tipoItem *item)
{
  if (p == NULL)
  {
    p = item;
  }
  else
  {
    item->id_mail < p->id_mail ? insereRecursivo(p->esq, item)
                               : insereRecursivo(p->dir, item);
  }
};

tipoItem *arvoreBinaria::pesquisa(int chave, int id_user)
{
  return pesquisaRecursivo(raiz, chave, id_user);
};

tipoItem *arvoreBinaria::pesquisaRecursivo(tipoItem *p, int chave, int id_user)
{

  tipoItem *aux = new tipoItem();
  if (p == NULL)
  {
    aux->id_mail = -1;
    return aux;
  }

  if (chave < p->id_mail)
  {
    return pesquisaRecursivo(p->esq, chave, id_user);
  }

  if (chave > p->id_mail)
  {
    return pesquisaRecursivo(p->dir, chave, id_user);
  }

  if (id_user == p->id_usuario)
  {
    return p;
  }

  return aux;
};

int arvoreBinaria::remove(int chave)
{
  return removeRecursivo(raiz, chave);
};

int arvoreBinaria::removeRecursivo(tipoItem *&p, int chave)
{
  tipoItem *aux;
  if (p == NULL)
  {
    return 0;
  }
  if (chave < p->id_mail)
  {
    return removeRecursivo(p->esq, chave);
  }
  else if (chave > p->id_mail)
  {
    return removeRecursivo(p->dir, chave);
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
    if (p->esq == NULL)
    {
      aux = p;
      p = p->dir;
      delete aux;
      return 1;
    }
    antecessor(p, p->esq);
    return 1;
  }

  return 0;
};

void arvoreBinaria::antecessor(tipoItem *q, tipoItem *&r)
{
  if (r->dir != NULL)
  {
    antecessor(q, r->dir);
    return;
  }
  q->chave = r->chave;
  q = r;
  r = r->esq;
  free(q);
}
