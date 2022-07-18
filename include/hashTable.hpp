#ifndef HASH_MAP_TABLE
#define HASH_MAP_TABLE

#include "arvoreBinaria.hpp"

#include <iostream>

class hashTable
{
public:
  hashTable();
  hashTable(int _tamanho);
  void entrega(std::ifstream &input, std::ofstream &output, int usuario_id, int email_id, std::string *texto);
  void apaga(std::ofstream &output, int usuario_id, int email_id);
  void consulta(std::ofstream &output, int usuario_id, int email_id, std::string *texto);

private:
  int tamanho;
  int hash(int chave);
  arvoreBinaria *Tabela;
};

#endif