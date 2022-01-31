/* BISECTION METHOD IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: January 31st, 2022 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "Bissecao.hpp"

using namespace std;

double avaliacao_funcao(const double &x){

    return 0.05 * pow(x, 3) - 0.4 * pow(x, 2) + 3 * x * sin(x);

}

double calcula_x(const double &a, const double &b){

    return (a+b)/2.0;

}

void print(const double &a, const double &b, const double &Fa, const double &Fb, 
           const double &x, const double &Fx, const double &deltax, const unsigned &k){

    
    cout << setprecision(5) << fixed << k << "   " << a 
        << "   " << Fa << "  ";

    if((Fa < 10 && Fa > 0) || (Fa > -1 * 10 && Fa < 0)) cout << " ";
        
    cout << b << "  ";
        
    if((Fb < 10 && Fb > 0) || (Fb > -1 * 10 && Fb < 0)) cout << " ";

    cout << Fb << "    "; 
    cout << scientific << deltax << "    ";
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed << x << "    ";

    if(Fx > 0) cout << " ";
             
    cout << scientific << Fx << endl;
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed;

}

void bissecao(double &a, double &b, double &Toler, unsigned &IterMax){

    cout << "\n\tCalculo de raiz pelo metodo da bissecao\n" << endl;

    cout << "k     a_k       Fa_k       b_k         Fb_k      deltax_k         x_k          Fx_k" << endl;

    int Info;

    unsigned k = 0;

    double deltax = fabs(b - a)/2;

    double Fa = avaliacao_funcao(a);
    double Fb = avaliacao_funcao(b);

    double x = calcula_x(a, b);
    double Fx = avaliacao_funcao(x);

    while(1){

        print(a, b, Fa, Fb, x, Fx, deltax, k);

        if(Fa * Fb > 0){

            Info = -1;

            goto Final;

        }

        if((deltax <= Toler && fabs(Fx) <= Toler) || k >= IterMax){

            goto SaiDoLoop;

        }

        if(Fx * Fa > 0){

            a = x;
            Fa = Fx;

        }

        else{

            b = x;
            Fb = Fx;

        }

        deltax = deltax/2;

        x = calcula_x(a, b);
        Fx = avaliacao_funcao(x);

        k++;

    }

    SaiDoLoop:

    if(deltax <= Toler && fabs(Fx) <= Toler){

        Info = 0;

    }

    else{

        Info = 1;

    }

    Final:

    cout << endl;
    
    if(Info == 0){
        
        cout << "Raiz = " << x << endl;

    }

    cout << "Iter = " << k << endl;
    cout << "Info = " << Info << endl << endl;

}
