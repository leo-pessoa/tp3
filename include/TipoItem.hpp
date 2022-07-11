#ifndef TIPO_ITEM
#define TIPO_ITEM

#include <string>

class TipoItem
{
public:
 TipoItem();
 TipoItem(int _id_email, int _id_usuario, std::string *_texto, int tamanho);
 int GetIdEmail();
 int GetUserId();
 std::string GetTexto(int tamanho);
 void SetIdEmail(int _id_email);
 void SetIdUsuario(int _id_usuario);
 void Imprime();
 bool Vazio();

private:
 int id_email, id_usuario;
 std::string texto[200];
};

#endif