#ifndef Gramatica_hpp
#define Gramatica_hpp


#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


using namespace std;


typedef struct{
    int A;
    int B;
    int C;
} rule;

typedef vector<rule> grammar;

typedef set<int> conjunto;
typedef map<int,conjunto> row;
typedef map<int,row> table;


class Gramatica{
    
    public:

        Gramatica(grammar &);
        bool CYK(grammar &, string &);
        
        rule Rule(int a,int b,int c){
            rule aux;

            aux.A = a;
            aux.B = b;
            aux.C = c;

            return aux;
        }

        int simboloInicial(grammar &G){  return G[0].A;  }

        void busquedaCaracteres(grammar &, conjunto &, char);

        void busquedaCombinaciones(grammar &, conjunto &, conjunto &, conjunto &);
};


#endif