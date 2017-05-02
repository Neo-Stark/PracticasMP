#include <iostream>
using namespace std;

struct Celda
{
    int info;
    Celda *sig;
};

class MiLista
{
  private:
    Celda *l;
    bool Vacia();

  public:
    MiLista();
    ~MiLista();
    void Destruir();
    void Aniadir_primero(int x);
    void Eliminar_primero();
    void Aniadir_final(int x);
    void Eliminar_final();
    void Ordenar();
    void Encadenar(const MiLista &);
    void Mezclar(const MiLista &lista1, const MiLista &lista2);

    friend istream &operator>>(istream &is, MiLista &lista);
    friend ostream &operator<<(ostream &os, const MiLista &lista);
};

////////////////////////////////////////////////////////////////////////////////
int main()
{
    int x;
    MiLista lista, lista2, lista3;

    cout << "Introducir elementos lista1 (x1, ..., xi, ... 0): ";
    cin >> lista;
    cout << "Introducir elementos lista2 (x1, ..., xi, ... 0): ";
    cin >> lista2;

    lista3.Mezclar(lista, lista2);
    cout << "\n Orden total: " << lista3;

    lista.Ordenar();
    cout << "\nLa lista1 ordenada es: " << lista;

    lista2.Ordenar();
    cout << "\nLa lista2 ordenada es: " << lista2;

    lista.Encadenar(lista2);
    cout << "\nLas listas encadenadas son: " << lista;
}

///////////////////////////////////////////////////////////////
MiLista::MiLista() : l(0) {}

MiLista::~MiLista()
{
    while (!Vacia())
        Eliminar_primero();

    l = 0;
}

void MiLista::Destruir()
{
    while (!Vacia())
        Eliminar_primero();

    l = 0;
}

bool MiLista::Vacia()
{
    return l == 0;
}

void MiLista::Ordenar()
{
    Celda *actual, *siguiente;
    int aux;

    actual = l;
    while (actual->sig != 0)
    {

        siguiente = actual->sig;

        while (siguiente != 0)
        {
            if (actual->info > siguiente->info)
            {
                aux = actual->info;
                actual->info = siguiente->info;
                siguiente->info = aux;
            }
            siguiente = siguiente->sig;
        }
        actual = actual->sig;
    }
}

void MiLista::Aniadir_primero(int x)
{
    Celda *nuevo;

    nuevo = new Celda;
    nuevo->info = x;
    nuevo->sig = l;
    l = nuevo;
}

void MiLista::Eliminar_primero()
{
    Celda *p;

    if (l != 0)
    {
        p = l;
        l = l->sig;
        delete p;
    }
}

void MiLista::Aniadir_final(int x)
{
    Celda *nuevo;
    Celda *p;

    if (l == 0)
        Aniadir_primero(x);
    else
    {
        nuevo = new Celda;

        nuevo->info = x;
        nuevo->sig = 0;

        p = l;
        while (p->sig != 0)
            p = p->sig;

        p->sig = nuevo;
    }
}

void MiLista::Eliminar_final()
{
    Celda *p, *pant;

    if (l != 0)
    {
        p = l;
        while (p->sig != 0)
        {
            pant = p;
            p = p->sig;
        }

        if (p == l)
        {
            delete l;
            l = 0;
        }
        else
        {
            delete p;
            pant->sig = 0;
        }
    }
}

istream &operator>>(istream &is, MiLista &lista)
{
    int x;

    lista.Destruir();

    is >> x;
    while (x != 0)
    {
        lista.Aniadir_final(x);
        is >> x;
    }

    return is;
}

ostream &operator<<(ostream &os, const MiLista &lista)
{
    Celda *p = lista.l;
    while (p != 0)
    {
        os << p->info << ' ';
        p = p->sig;
    }

    return os;
}

void MiLista::Encadenar(const MiLista &lista2)
{
    Celda *p = lista2.l;
    while (p != 0)
    {
        Aniadir_final(p->info);
        p = p->sig;
    }
}

void MiLista::Mezclar(const MiLista &lista1, const MiLista &lista2)
{
    Encadenar(lista1);
    Encadenar(lista2);
    Ordenar();
}
