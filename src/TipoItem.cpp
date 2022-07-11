#include "TipoItem.hpp"
#include <string>
using namespace std;

TipoItem::TipoItem()
{
 id_email = -1;
}

TipoItem::TipoItem(int _id_email, int _id_usuario, string _texto)
{
 id_email = _id_email;
 id_usuario = _id_usuario;
 texto = _texto;
}

void TipoItem::SetIdEmail(int _id_email)
{
 id_email = _id_email;
}

void TipoItem::SetIdUsuario(int _id_usuario)
{
 id_usuario = _id_usuario;
}

void TipoItem::SetTexto(std::string _texto)
{
 texto = _texto;
}

int TipoItem::GetIdEmail()
{
 return id_email;
}

std::string TipoItem::GetTexto()
{
 return texto;
}

int TipoItem::GetUserId()
{
 return id_usuario;
}
