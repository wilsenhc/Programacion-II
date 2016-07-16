/* QuadTree.hpp
 * 
 * Universidad de Carabobo
 * Facultad Experimental de Ciencias y Tecnologia
 * Departamento de Computacion
 * Progamacion II
 * Seccion 02
 * Proyecto Arboles I-2016
 * 
 * Freddy Duran     C.I: 24.547.626 <freddyjdr03@gmail.com>
 * Wilsen Hernandez C.I: 24.993.998 <wilsenh95@gmail.com>
 * 
 * Julio, 2016
 * 
 * Estilo de documentacion: JSDoc.
 * Se puede generar la documentacion con Doxygen en LaTeX o HTML.
 * */
#ifndef _QUADTREE_HPP_
#define _QUADTREE_HPP_
#include <iostream>
#include <list>
#include <math.h>

using std::list; 

enum Color { BLANCO, NEGRO, GRIS };

class QuadTree
{
    public:
        /**
         * Valor constante que indica la cantidad de hijos en cada nodo.
         * @constant
         * @type {int}
         * */
		static const int MAX_HIJOS = 4;
        
    private:    
        Color info;
        QuadTree **hijos;
        
    public:
        /// @constructs QuadTree Retorna un QuadTree nulo        
        QuadTree() : info(BLANCO), hijos(NULL) { };
        
        QuadTree(const QuadTree&);
        
        QuadTree(list<Color>&);
        
        /// @constructs QuadTree Crea un QuadTree con raiz e y 0 (cero) hijos
        QuadTree(Color e) : info(e), hijos(NULL) { };

        ~QuadTree();
        
        bool es_nulo() const;
        
        /** Color.
         * Retorna el color del nodo raiz del QuadTree.
         * @function
         * @returns {Color}
         * */
        Color color() const { return info; };
        
        int pixels_en_negro(int max_alt) const;
        
        void Union(QuadTree, QuadTree);

};

/**
 * Constructor copia.
 *  
 * Si el nodo actual es blanco o negro, se copia el valor
 * y no se le asignan hijos 
 * Si no es blanco o negro, es gris. Por lo tanto se genera un nuevo
 * array de hijos y se proceden a copiar los hijos, uno por uno
 * de manera recursiva 
 * 
 * @constructs QuadTree
 * */
QuadTree::QuadTree(const QuadTree &arg)
{
    
    if (arg.info == BLANCO || arg.info == NEGRO)
    {
        info = arg.info;
        hijos = NULL;
    }
    else
    {
        this->info = GRIS;
        hijos = new QuadTree*[5];
        for (int i = 0; i < QuadTree::MAX_HIJOS; i++)
        {
            QuadTree *nodo = new QuadTree(*arg.hijos[i]);
            this->hijos[i] = nodo;
        }
    }
}

/**
 * Constructor Lista preorden.
 * 
 * Si la lista es no vacia, se toma el Color en la primera posicion
 * y se coloca en el nodo raiz.
 * Si el Color es gris, se genera un nuevo array de hijos, sino
 * se mantiene vacio el array. 
 * 
 * @constructs QuadTree
 * @param {list<Color>} pre - Lista preorden
 * */
QuadTree::QuadTree(list<Color> &pre)
{

    if (!pre.empty())
    {
        Color e = pre.front();
        pre.pop_front();
        this->info = e;
        if (e == GRIS)
        {
            hijos = new QuadTree*[MAX_HIJOS];
            for (int i = 0; i < QuadTree::MAX_HIJOS; i++)
            {
				QuadTree *nodo = new QuadTree(pre);
                this->hijos[i] = nodo;
            }
        }
        else
            hijos = NULL;
        
    }
}

/**
 * Destructor.
 * 
 * Si el color de la raiz es gris se eliminan los hijos uno por uno,
 * y luego se libera de memoria el array de hijos.
 * Si no es gris, no hace falta hacer nada porque en el resto de los
 * casos el nodo raiz no maneja memoria dinamicamente */
QuadTree::~QuadTree()
{
    if (info == GRIS)
    {
        for (int i = 0; i < QuadTree::MAX_HIJOS; i++)
            delete hijos[i];
        delete hijos;
    }
}


/**
 * Indica si el QuadTree es nulo.
 * 
 * Si es blanco, negro o gris es no nulo 
 * @function
 * @returns {bool}
 * */
bool QuadTree::es_nulo() const
{
	if(info == BLANCO || info == NEGRO || info == GRIS)
		return false;
	else
		return true;
}

/**
 * Pixels en negro.
 * Retorna la cantidad de pixels negros del QuadTree cuya altura 
 * maxima es max_alt.
 * Si el nodo raiz es blanco, se retorna que hay 0 pixels negros.
 * Si es negro, se retorna MAX_HIJOS^(max_alt).
 * Si no es blanco o negro, es gris, se retorna la suma de pixeles
 * de sus hijos.
 * 
 * @function
 * @param {int} max_alt - Altura maxima del arbol.
 * @returns {int} Cantidad de pixels en negro.
 * */

int QuadTree::pixels_en_negro(int max_alt) const
{
	if(info == BLANCO)
		return 0;
	else if(info == NEGRO)
		return pow(MAX_HIJOS,max_alt);
	else
	{
        int acum = 0;
	
		for(int i = 0; i < QuadTree::MAX_HIJOS; i++)
			acum = acum + hijos[i]->pixels_en_negro(max_alt-1);
		
		return acum;
	}
}

/** 
 * Union.
 * Genera el QuadTree resultante de la suma de qt1 y qt2.
 * 
 * Si al menos uno de los dos QuadTree es no-nulo se unen.
 * 
 * Si al menos uno de las dos raices es negro, se coloca la nueva 
 * raiz en negro. Si al menos una de las dos es blanco, se coloca
 * el color de la que no es blanca, y en el ultimo caso se descartan
 * todas las posibilidades y entonces es: gris.
 * 
 * Si el nuevo nodo raiz es gris, se crea un nuevo array de hijos
 * Si ambos nodos q1 y q2 tienen hijos, se hace la suma de ellos.
 * Si solamente uno de los dos tiene hijos, se hace una copia de
 * ese nodo raiz.
 * Sino es gris, el nodo raiz no tendra hijos.
 * 
 * @param {QuadTree} qt1
 * @param {QuadTree} qt2
 * */
void QuadTree::Union(QuadTree q1, QuadTree q2)
{
    
    if (!q1.es_nulo() || !q2.es_nulo())
    {
        if (q1.info == NEGRO || q2.info == NEGRO)
            info = NEGRO;
        else if (q1.info == BLANCO)
			info = q2.info;
		else if (q2.info == BLANCO)
			info = q1.info;
        else
            info = GRIS;
            
        if (info == GRIS)
        {
            hijos = new QuadTree*[MAX_HIJOS];
            for (int i = 0; i < QuadTree::MAX_HIJOS; i++)
            {
                QuadTree *nodo;
                if(q1.hijos  && q2.hijos)
                {
                    nodo = new QuadTree();
                    nodo->Union(*q1.hijos[i], *q2.hijos[i]);
                }
                else if (q1.hijos)
                    nodo = new QuadTree(*q1.hijos[i]);
                else
                    nodo = new QuadTree(*q2.hijos[i]);
                
                hijos[i] = nodo;
            }
        }
        else
            hijos = NULL;
    }
}
#endif
