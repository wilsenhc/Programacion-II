#ifndef _NODO_HPP_
#define _NODO_HPP_
#include <iostream>

template<class Item>
class Nodo
{
    private:
        Item info;
        Nodo<Item> *sig;

    public:
        Nodo();
        Nodo(const Nodo<Item>&);
        //~Nodo();

        void setInfo(Item);
        void setSig(Nodo<Item>*);
        Item getInfo();
        Nodo<Item>* getSig();


        void operator=(const Item &);
        bool operator>(const Nodo<Item>&);
        bool operator<(const Nodo<Item>&);
        bool operator==(const Nodo<Item>&);
        bool operator>=(const Nodo<Item>&);
        bool operator<=(const Nodo<Item>&);

        static void intercambiar(Nodo<Item> *, Nodo<Item> *);
};

/**
 * Constructor de Nodo.
 * @constructs Nodo
 * */
template<class Item>
Nodo<Item>::Nodo()
    : info( 0 ), sig( NULL ) { }

/**
 * Constructor copia de Nodo.
 * @constructs Nodo
 * */
template<class Item>
Nodo<Item>::Nodo(const Nodo<Item>& in)
    : info( in.info ),  sig( NULL) { }

/**
 * Setter de Info.
 * @function
 * @param {Item} Info
 * */
template<class Item>
void Nodo<Item>::setInfo(Item item)
{
    info = item;
}

/**
 * Setter de siguiente Nodo.
 * @function
 * @param {Nodo<Item>*} Apuntador a siguiente nodo
 * */
template<class Item>
void Nodo<Item>::setSig(Nodo<Item> * siguiente)
{
    sig = siguiente;
}

/**
 * Getter de Info.
 * @function
 * @returns {Item} Info Item
 * */
template<class Item>
Item Nodo<Item>::getInfo()
{
    return info;
}

/**
 * Getter de siguiente Nodo.
 * @function
 * @returns {Nodo<Item>*} Siguiente Nodo
 * */
template<class Item>
Nodo<Item>* Nodo<Item>::getSig()
{
    return sig;
}


/**
 * Sobrecarga de operador de Mayor Que de Nodo.
 * */
template<class Item>
bool Nodo<Item>::operator>(const Nodo<Item> &a)
{
    if (this != &a)
        return (this->getInfo() > a.getInfo());

    return false;
}

/**
 * Sobrecarga de operador Menor Que de Nodo.
 * */
template<class Item>
bool Nodo<Item>::operator<(const Nodo<Item> &a )
{
    if (this != &a)
        return (this->getInfo() < a.getInfo());

    return false;
}

/**
 * Sobrecarga de operador de Igual Que de Nodo.
 * */
template<class Item>
bool Nodo<Item>::operator==(const Nodo<Item> &a)
{
    return (this->getInfo() == a.getInfo());
}

/**
 * Sobrecarga de operador Mayor o Igual Que de Nodo.
 * */
template<class Item>
bool Nodo<Item>::operator>=(const Nodo<Item> &a)
{
    return (*this > a || *this == a);
}

/**
 * Sobrecarga de operador Menor o Igual Que de Nodo.
 * */
template<class Item>
bool Nodo<Item>::operator<=(const Nodo<Item> &a)
{
    return (*this < a || *this == a);
}

/**
 * Intercambia la info de dos nodos dados.
 * @static
 * */
template<class Item>
void Nodo<Item>::intercambiar(Nodo<Item> *a, Nodo<Item> *b)
{
    Item aux = a->getInfo();
    a->setInfo(b->getInfo());
    b->setInfo(aux);
}

#endif
