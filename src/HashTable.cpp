#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable()
{
}

HashTable::HashTable(int _tamanho)
{
  tamanho = _tamanho;
  Tabela = new ArvoreBinaria[tamanho];
}

TipoItem *HashTable::Pesquisa(int chave, int id_user)
{
  int pos = Hash(id_user);
  TipoItem *item = new TipoItem();
  item = Tabela[pos].Pesquisa(chave, id_user);
  return item;
}

int HashTable::Insere(TipoItem *_email, int _id_usuario)
{
  int pos;
  pos = Hash(_id_usuario);
  Tabela[pos].Insere(_email);
  return pos;
}

int HashTable::Remove(int id_usuario, int id_email)
{
  int pos;
  pos = Hash(id_usuario);
  return Tabela[pos].Remove(id_email);
}

int HashTable::Hash(int chave)
{
  return chave % tamanho;
}