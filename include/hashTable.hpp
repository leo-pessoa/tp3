#ifndef HASH_MAP_TABLE
#define HASH_MAP_TABLE

#include "arvoreBinaria.hpp"

#include <iostream>

class hashTable
{
public:
  hashTable();
  hashTable(int _tamanho);
  tipoItem *pesquisa(int chave, int id_user);
  int insere(tipoItem *_email, int _id_usuario);
  int remove(int id_usuario, int id_email);
  void entrega(std::ifstream &input, std::ofstream &output, int usuario_id, int email_id, std::string *texto);
  void apaga(std::ofstream &output, int usuario_id, int email_id);
  void consulta(std::ofstream &output, int usuario_id, int email_id, std::string *texto);

private:
  int tamanho;
  int hash(int chave);
  arvoreBinaria *Tabela;
};

#endif