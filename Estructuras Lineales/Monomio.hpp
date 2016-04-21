#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_
#include <iostream>

class Monomio
{
    private:
        float coef;
        int exp;

    public:
        Monomio();
        Monomio(float, int);

        float obtCoef() const;
        int obtExp() const;
        void modCoef(float);
        void modExp(int);
};

/**
 * Constructor de Monomio.
 * @constructs Monomio
 * */
Monomio::Monomio()
{ 
    std::cin >> coef >> exp;
}

/** Constructor sobrecargado de Monomio.
 * @param {float} c - Coeficiente del Monomio.
 * @param {int} e - Exponente del Monomio.
 * @constructs Monomio
 * */
Monomio::Monomio(float c, int e) : coef( c ), exp( e ) { }

/**
 * Get Coef.
 * Funcion miembro getter de Monomio.
 * @function
 * @returns {float} Coeficiente del Monomio.
 * */
float Monomio::obtCoef() const
{
    return coef;
}

/**
 * Get Exp.
 * Funcion miembro getter de Monomio.
 * @function
 * @returns {int} Exponente del Monomio.
 * */
int Monomio::obtExp() const
{
    return exp;
}

/**
 * Set Coef.
 * Funcion miembro setter del Monomio.
 * Modifica el Coeficiente del Monomio.
 * @param {float} c - Coeficiente del Monomio.
 * */
void Monomio::modCoef(float c)
{
    this->coef = c;
}

/**
 * Set Exp.
 * Funcion miembro setter del Monomio.
 * Modifica el Exponente del Monomio.
 * @param {int} e - Exponente del Mononio.
 * */
void Monomio::modExp(int e)
{
    this->exp = e;
}

#endif
