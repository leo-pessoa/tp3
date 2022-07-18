#include "hashTable.hpp"
#include <iostream>
#include <fstream>

hashTable::hashTable()
{
}

hashTable::hashTable(int _tamanho)
{
  tamanho = _tamanho;
  Tabela = new arvoreBinaria[tamanho];
}

tipoItem *hashTable::pesquisa(int chave, int id_user)
{
  int pos = hash(id_user);
  tipoItem *item = new tipoItem();
  item = Tabela[pos].pesquisa(chave, id_user);
  return item;
}

int hashTable::insere(tipoItem *_email, int _id_usuario)
{
  int pos;
  pos = hash(_id_usuario);
  Tabela[pos].insere(_email);
  return pos;
}

int hashTable::hash(int chave)
{
  return chave % tamanho;
}

// métodos referentes às operações na arvore e impressao de saida
void hashTable::entrega(std::ifstream &input, std::ofstream &output, int usuario_id, int email_id, std::string *texto)
{
  int n_palavras = 0;
  input >> n_palavras;
  for (int i = 0; i < n_palavras; i++)
  {
    input >> texto[i];
  }

  tipoItem *mensagem = new tipoItem(texto, email_id, n_palavras, usuario_id);

  int posicao_entrega = hash(usuario_id);
  Tabela[posicao_entrega].insere(mensagem);

  output << "OK: MENSAGEM " << email_id << " PARA " << usuario_id << " ARMAZENADA EM " << posicao_entrega << "\n";
}

void hashTable::apaga(std::ofstream &output, int usuario_id, int email_id)
{
  int pos = hash(usuario_id);
  int indice_delecao = Tabela[pos].remove(email_id);
  indice_delecao ? output << "OK: MENSAGEM APAGADA"
                          << "\n"
                 : output << "ERRO: MENSAGEM INEXISTENTE"
                          << "\n";
}

void hashTable::consulta(std::ofstream &output, int usuario_id, int email_id, std::string *texto)
{

  int pos = hash(usuario_id);
  tipoItem *item_pesquisa = new tipoItem();
  item_pesquisa = Tabela[pos].pesquisa(email_id, usuario_id);

  if (item_pesquisa->id_mail != email_id)
  {
    output << "CONSULTA " << usuario_id << " " << email_id << ": MENSAGEM INEXISTENTE"
           << "\n";
  }

  else
  {
    output << "CONSULTA " << usuario_id << " " << email_id << ": ";

    for (int i = 0; i < item_pesquisa->tam_texto - 1; i++)
    {
      output << item_pesquisa->texto[i] << " ";
    }

    output << item_pesquisa->texto[item_pesquisa->tam_texto - 1] << "\n";
  }
}