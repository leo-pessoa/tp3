#include "TipoItem.hpp"
#include <string>
using namespace std;

TipoItem::TipoItem()
{
 id_email = -1;
}

TipoItem::TipoItem(int _id_email, int _id_usuario, string *_texto, int tamanho)
{
 id_email = _id_email;
 id_usuario = _id_usuario;
 for (int i = 0; i < tamanho; i++)
 {
  texto[i] = _texto[i];
 }
}

void TipoItem::SetIdEmail(int _id_email)
{
 id_email = _id_email;
}

void TipoItem::SetIdUsuario(int _id_usuario)
{
 id_usuario = _id_usuario;
}

int TipoItem::GetIdEmail()
{
 return id_email;
}

std::string TipoItem::GetTexto(int tamanho)
{
 string texto_aux = "";
 for (int i = 0; i < tamanho; i++)
 {
  texto_aux += texto[i];
 }
 return texto_aux;
}

int TipoItem::GetUserId()
{
 return id_usuario;
}
