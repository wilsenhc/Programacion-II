#ifndef _LISTA_HPP_
#define _LISTA_HPP_
#include "Nodo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

template<class Item>
class Lista
{
private:
    int length;
    Nodo<Item> *primero;
    Nodo<Item> *ultimo;

public:
    Lista();
    Lista(const Lista<Item>&);
    ~Lista();

    int longitud() const;
    bool esVacia() const;
    void insertar(Item, int);
    Item consultar(int) const;
    Item getPrimero() const;
    Item getUltimo() const;
    void eliminar(int);
    void modificar(Item, int);      // TODO: Implementar
    void vaciar();
    Lista<Item> sublista(int, int);
    void invertir();
    void ordenar();
    void bubbleSort();
    bool estaOrdenada() const;
    
    // Taller 1
    int mediana() const;
    // Fin Taller 1

    void operator=(const Lista<Item> &);
    bool operator>(const Lista<Item> &) const;
    bool operator<(const Lista<Item> &) const;
    bool operator==(const Lista<Item> &) const;
    bool operator>=(const Lista<Item> &) const;
    bool operator<=(const Lista<Item> &) const;

    template<class Items>
    friend std::ostream& operator<<(std::ostream&, const Lista<Items> &);

private:
    Nodo<Item>* _invertir(Nodo<Item>*);
    void _desordenar();
};

/**
* Constructor de Lista.
* Construye una Lista vacia.
* @constructs Lista
* */
template<class Item>
Lista<Item>::Lista()
    : length(0), primero(NULL), ultimo(NULL) { }

/**
* Constructor copia de Lista.
* @constructs Lista
* */
template<class Item>
Lista<Item>::Lista(const Lista<Item>& in)
{
    if (in.primero != NULL)
    {
        primero = new Nodo<Item>();
        primero->setInfo(in.primero->getInfo());
        Nodo<Item> *inaux = in.primero->getSig();
        Nodo<Item> *thisaux = this->primero;
        Nodo<Item> *nuevo;
        while (inaux != NULL)
        {
            nuevo = new Nodo<Item>();
            nuevo->setInfo(inaux->getInfo());
            thisaux->setSig(nuevo);
            thisaux = thisaux->getSig();
            inaux = inaux->getSig();
        }
        ultimo = nuevo;
    }
    this->length = in.length;
}

/**
* Destructor de Lista.
* Primero vacia la Lista y luego destruye.
* */
template<class Item>
Lista<Item>::~Lista()
{
    this->vaciar();
}

/**
* Muestra longitud de la lista.
* @returns int Longitud de la lista
* */
template<class Item>
int Lista<Item>::longitud() const
{
    return this->length;
}

/**
* Indica si la lista esta vacia.
* @returns {bool} TRUE sí esta vacia.
* */
template<class Item>
bool Lista<Item>::esVacia() const
{
    return this->length == 0;
}

/**
* Insertar en la lista.
* @param e El Item a insertar en lista.
* @param pos Posicion en la lista a insertar.
* */
template<class Item>
void Lista<Item>::insertar(Item e, int pos)
{
    if (pos < 1 || pos > length + 2)
        std::cout << "Posicion invalida" << std::endl;
    else
    {
        Nodo<Item> *nuevo, *actual, *siguiente;
        nuevo = new Nodo<Item>();
        nuevo->setInfo(e);

        if (length == 0)
        {
            primero = nuevo;
            ultimo = nuevo;
        }
        else if (pos == 1)
        {
            nuevo->setSig(primero);
            primero = nuevo;
        }
        else if (pos == length + 1)
        {
            ultimo->setSig(nuevo);
            ultimo = nuevo;
        }
        else
        {
            actual = primero;
            siguiente = actual->getSig();
            for (int i = 2; i < pos; i++)
            {
                actual = siguiente;
                siguiente = siguiente->getSig();
            }
            actual->setSig(nuevo);
            nuevo->setSig(siguiente);
        }
        length++;
    }
}

/**
* Consultar elemento de la lista
* @function
* @param {int} pos - Posicion a consultar
* */
template<class Item>
Item Lista<Item>::consultar(int pos) const
{
    if (pos < 1 || pos > length + 1)
        std::cout << "Posicion invalida" << std::endl;
    else
    {
        if (pos == 1)
            return primero->getInfo();
        else if (pos == length)
            return ultimo->getInfo();
        else
        {
            Nodo<Item> *act = primero;
            for (int i = 1; i < pos; i++)
                act = act->getSig();

            return act->getInfo();
        }
    }
}

/**
* Get Primero.
* Funcion miembro getter de Lista.
* Retorna el primer Item de la Lista.
* @returns {Item} Primer Item de la Lista.
* */
template<class Item>
Item Lista<Item>::getPrimero() const
{
    return this->primero->getInfo();
}

/**
* Get Ultimo.
* Funcion miembro getter de Lista.
* Retorna el ultimo Item de la Lista.
* @returns {Item} Ultimo Item de la Lista.
* */
template<class Item>
Item Lista<Item>::getUltimo() const
{
    return this->ultimo->getInfo();
}

template<class Item>
void Lista<Item>::modificar(Item e, int pos)
{

}

/**
* Eliminar de lista
* @function
* @param {int} pos - Posicion a eliminar
* */
template<class Item>
void Lista<Item>::eliminar(int pos)
{
    if (pos < 1 || pos > length + 1)
        std::cout << "Posicion invalida" << std::endl;
    else if (this->esVacia())
        std::cout << "Lista vacia" << std::endl;
    else
    {
        // TODO: Revisar algoritmo
        Nodo<Item> *last, *now, *next;

        now = primero;
        next = now->getSig();

        for (int i = 1; i < pos; i++)
        {
            last = now;
            now = last->getSig();
            next = now->getSig();
        }
        last->setSig(next);

        delete now;
        length--;
    }
}

/**
* Vaciar lista.
* */
template<class Item>
void Lista<Item>::vaciar()
{
    if (!esVacia())
    {
        Nodo<Item> *actual, *next;
        actual = primero;
        next = actual->getSig();

        for (int i = 1; i < length; i++)
        {
            delete actual;
            actual = next;
            next = actual->getSig();
        }
        delete actual;

        length = 0;
        primero = NULL;
        ultimo = NULL;
    }
}


/**
* Invertir Lista.
* Invierte los elementos de la Lista.
* */
template<class Item>
void Lista<Item>::invertir()
{
    this->ultimo = _invertir(this->primero);
    this->ultimo->setSig(NULL);
}

/**
* @desc Sublista.
* Genera una Sublista a partir de una Lista inicial.
* @function
* @param {int} low - Posicion incial de la Sublista.
* @param {int} high - Posicion final de la Sublista.
* @returns {Lista<Item>} Sublista generada.
* */
template<class Item>
Lista<Item> Lista<Item>::sublista(int low, int high)
{
    // Swap preventivo
    if (low > high)
    {
        int aux = low;
        low = high;
        high = aux;
    }

    Lista<Item> *lista = new Lista<Item>();

    if ((low >= 1 && low <= length) && (high >= 1 && high <= length))
    {

        Nodo<Item> *aux = primero;
        Nodo<Item> *aux2 = NULL;
        Nodo<Item> *nuevo;

        for (int i = 1; i <= high; i++)
        {
            if (i >= low)
            {
                nuevo = new Nodo<Item>(*aux);

                if (i == low)
                    lista->primero = nuevo;
                else
                    aux2->setSig(nuevo);

                aux2 = nuevo;
            }
            aux = aux->getSig();
        }
        ultimo = nuevo;
        lista->length = abs(high - low) + 1;
    }
    return *lista;
}

template<class Item>
void Lista<Item>::ordenar()
{
    this->bubbleSort();
}

/**
* Ordena los elementos de la lista.
* Ordena de menor a mayor los elementos de la lista, utilizando
* el algoritmo de ordenamiento Bubble Sort.
* */

template<class Item>
void Lista<Item>::bubbleSort()
{
    if (!estaOrdenada())
    {
        int n = this->length;
        for (int pasada = 0; pasada < n - 1; pasada++)
        {
            Nodo<Item> *pivot = this->primero;
            Nodo<Item> *pivotNext = pivot->getSig();
            for (int j = 0; j < n - pasada - 1; j++)
            {
                if (pivot->getInfo() > pivotNext->getInfo())
                    Nodo<Item>::intercambiar(pivot, pivotNext);

                pivot = pivotNext;
                pivotNext = pivotNext->getSig();
            }
        }
    }
}

/**
* Indica si la lista esta ordenada.
* @function
* @returns {bool} TRUE sí esta ordenada
* */
template<class Item>
bool Lista<Item>::estaOrdenada() const
{
    bool ordenada = true;
    if (!esVacia())
    {
        Nodo<Item> *pivot = this->primero;
        Nodo<Item> *pivotNext = pivot->getSig();
        int i = 0;

        do
        {
            if (pivot->getInfo() > pivotNext->getInfo())
                ordenada = false;

            pivot = pivotNext;
            pivotNext = pivotNext->getSig();
            i++;
        } while (i < length && pivotNext != NULL && ordenada);

    }
    return ordenada;
}

/**
* Sobrecarga de operador de ostream (Out Stream) para Lista.
* Permite mostrar por pantalla el contenido de la lista mediante el uso del operador '<<'
* Necesita que el 'Item' a sobrecargar igualmente pueda ser mostrado por pantalla
* utilizando este mismo operador.
* */
template<class Item>
std::ostream& operator<<(std::ostream& out, const Lista<Item> &list)
{
    Nodo<Item> *nodo;
    nodo = list.primero;
    for (int i = 0; i < list.length; i++, nodo = nodo->getSig())
        out << nodo->getInfo() << std::endl;

    return out;
}

/**
* Sobrecarga de operador de Asignacion para Lista.
* Permite hacer una copia de una lista mediante el uso del operador '='.
* Ejemplo: Lista2 = Lista1.sublista(a, b).
* */
template<class Item>
void Lista<Item>::operator=(const Lista<Item> & list)
{
    if (this != &list)
    {
        Nodo<Item> *listPivot = list.primero;
        Nodo<Item> *thisPivot = this->primero;
        Nodo<Item> *nuevo;
        for (int i = 1; i <= list.length; i++, listPivot = listPivot->getSig())
        {
            nuevo = new Nodo<Item>();
            nuevo->setInfo(listPivot->getInfo());

            if (i == 1)
            {
                this->primero = nuevo;
                thisPivot = nuevo;
            }
            else
            {
                thisPivot->setSig(nuevo);
                thisPivot = thisPivot->getSig();
            }
        }
        ultimo = nuevo;
        this->length = list.length;
    }
}

/**
* Sobrecarga de operador de Mayor Que para Lista.
* Indica si una Lista tiene o no mas elementos que otra, utilizando
* el operador '>'.
* */
template<class Item>
bool Lista<Item>::operator>(const Lista<Item> &v) const
{
    if (this != &v)
        return (this->length > v.length);

    return false;
}

/**
* Sobrecarga de operador de Menor Que para Lista.
* Indica si una Lista tiene o no menos elementos que otra, utilizando
* el operador '<'.
* */
template<class Item>
bool Lista<Item>::operator<(const Lista<Item> &v) const
{
    return !(*this > v);
}

/**
* Sobrecarga de operador de Igual Que para Lista.
* Indica si una Lista tiene o no los mismos elementos que otra,
* utilizando el operador '=='.
* */
template<class Item>
bool Lista<Item>::operator==(const Lista<Item> &v) const
{
    if (this != &v)
    {
        if (this->length == v.length)
        {
            Nodo<Item> *thisPivot = this->primero;
            Nodo<Item> *vPivot = v.primero;
            bool esIgual;
            int i = 0;

            do
            {
                esIgual = (thisPivot->getInfo() == vPivot->getInfo());
                i++;
            } while (i <= this->length && esIgual);

            return esIgual;
        }

        return false;
    }

    return true;
}


/**
* Sobrecarga de operador de Mayor o Igual Que para Lista.
* Indica si una Lista tiene mas elementos o es igual que otra,
* utilizando el operador '>='.
* */
template<class Item>
bool Lista<Item>::operator>=(const Lista<Item> &v) const
{
    if (this != &v)
        return (*this > v || *this == v);

    return true;
}


/**
* Sobrecarga de operador de Menor o Igual Que para Lista.
* Indica si una Lista tiene menos elementos o es igual que otra,
* utilizando el operador '<='.
* */
template<class Item>
bool Lista<Item>::operator<=(const Lista<Item> &v) const
{
    if (this != &v)
        return (*this < v || *this == v);

    return true;
}

/**
* Invertir lista.
* Helper Method para Invertir la Lista.
* Invierte los elementos de la lista recursivamente.
* Esta funcion debe mantenerse como privada.
* @private
* */
template<class Item>
Nodo<Item>* Lista<Item>::_invertir(Nodo<Item>*nodo)
{
    if (nodo->getSig() == NULL) // ¿Es el ultimo nodo?
        this->primero = nodo;
    else
        _invertir(nodo->getSig())->setSig(nodo);

    return nodo;
}

/**
* Desordenar la lista dada.
* Helper Method para el Algoritmo de QuickSort.
* Privado porque no le veo uso fuera del algoritmo de QuickSort.
* Su nivel de acceso puede ser modificado sí es necesario.
* @private */
template<class Item>
void Lista<Item>::_desordenar()
{
    std::srand(time(NULL));
    Nodo<Item> *iPivot = this->primero;
    Nodo<Item> *jPivot;
    for (int i = 0; i < this->length; i++)
    {
        int r = std::rand() % (i + 1);
        jPivot = this->primero;

        for (int j = 0; j < r; j++)
            jPivot = jPivot->getSig();

        Nodo<Item>::intercambiar(iPivot, jPivot);

        iPivot = iPivot->getSig();
    }
}

/**
 * Metodo para Calcular la mediana de una lista de Enteros.
 * Desarrolada para utilizar en el Taller 1 de Programacion II.
 * Semestre 1-2016
 * @returns int La mediana de la Lista de Enteros.
 * */
template<class Item>
int Lista<Item>::mediana() const
{
    Nodo<Item> *aux = this->primero;
    int median = 0;
    
    for (int i = 0; i < length; i++, aux = aux->getSig())
        median += aux->getInfo();
        
    return median / length;
}

#endif
