/* BISECTION METHOD IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: January 31st, 2022 */

#ifndef BISSECAO_H
#define BISSECAO_H

double avaliacao_funcao(const double &x);

double calcula_x(const double &a, const double &b);

void print(const double &a, const double &b, const double &Fa, const double &Fb, 
           const double &x, const double &Fx, const double &deltax, const unsigned &k);

void bissecao(double a, double b, double Toler, unsigned IterMax);

#endif