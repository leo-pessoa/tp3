#ifndef HASH_MAP_TABLE
#define HASH_MAP_TABLE

#include "ArvoreBinaria.hpp"

#include <iostream>

class HashTable
{
public:
  HashTable();
  HashTable(int _tamanho);
  TipoItem *Pesquisa(int chave, int id_user);
  int Insere(TipoItem *_email, int _id_usuario);
  int Remove(int id_usuario, int id_email);

private:
  int tamanho;
  int Hash(int chave);
  ArvoreBinaria *Tabela;
};

#endif