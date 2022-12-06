#include "Gramatica.hpp"


Gramatica::Gramatica(grammar &G){

    G.push_back(Rule('M','M','A'));
    G.push_back(Rule('M','V',2001));
    G.push_back(Rule(2001,':' + 1000,2002));
    G.push_back(Rule(2002,'Q',';' + 1000));

    G.push_back(Rule('A','V',2003));
    G.push_back(Rule(2003,':' + 1000,2004));
    G.push_back(Rule(2004,'Q',';' + 1000));

    G.push_back(Rule('Q','P', 2005));
    G.push_back(Rule(2005,'?' + 1000, 2006));
    G.push_back(Rule(2006,'Q',2007));
    G.push_back(Rule(2007,':' + 1000,'Q'));

    G.push_back(Rule('Q','P',2008));
    G.push_back(Rule(2008,'|' + 1000,'T'));

    G.push_back(Rule('Q','T',2009));
    G.push_back(Rule(2009,'&' + 1000,'F'));

    G.push_back(Rule('Q','(' + 1000,2010));
    G.push_back(Rule(2010,'Q',')' + 1000));

    G.push_back(Rule('Q','!' + 1000,'F'));

    G.push_back(Rule('Q','p',0));
    G.push_back(Rule('Q','q',0));
    G.push_back(Rule('Q','r',0));
    G.push_back(Rule('Q','1',0));
    G.push_back(Rule('Q','0',0));

    G.push_back(Rule('P','P',2011));
    G.push_back(Rule(2011,'|' + 1000,'T'));

    G.push_back(Rule('P','T',2012));
    G.push_back(Rule(2012,'&' + 1000,'F'));

    G.push_back(Rule('P','(' + 1000,2013));
    G.push_back(Rule(2013,'Q',')' + 1000));

    G.push_back(Rule('P','!' + 1000,'F'));

    G.push_back(Rule('P','p',0));
    G.push_back(Rule('P','q',0));
    G.push_back(Rule('P','r',0));
    G.push_back(Rule('P','1',0));
    G.push_back(Rule('P','0',0));

    G.push_back(Rule('T','T',2014));
    G.push_back(Rule(2014,'&' + 1000,'F'));

    G.push_back(Rule('T','(' + 1000,2015));
    G.push_back(Rule(2015,'Q',')' + 1000));

    G.push_back(Rule('T','!' + 1000,'F'));

    G.push_back(Rule('T','p',0));
    G.push_back(Rule('T','q',0));
    G.push_back(Rule('T','r',0));
    G.push_back(Rule('T','1',0));
    G.push_back(Rule('T','0',0));

    G.push_back(Rule('F','(' + 1000,2016));
    G.push_back(Rule(2016,'Q',')' + 1000));

    G.push_back(Rule('F','!' + 1000,'F'));

    G.push_back(Rule('F','p',0));
    G.push_back(Rule('F','q',0));
    G.push_back(Rule('F','r',0));
    G.push_back(Rule('F','1',0));
    G.push_back(Rule('F','0',0));

    G.push_back(Rule('V','p',0));
    G.push_back(Rule('V','q',0));
    G.push_back(Rule('V','r',0));

    G.push_back(Rule(':' + 1000,':',0));
    G.push_back(Rule(';' + 1000,';',0));
    G.push_back(Rule('?' + 1000,'?',0));
    G.push_back(Rule('|' + 1000,'|',0));
    G.push_back(Rule('&' + 1000,'&',0));
    G.push_back(Rule('(' + 1000,'(',0));
    G.push_back(Rule(')' + 1000,')',0));
    G.push_back(Rule('!' + 1000,'!',0));

}


bool Gramatica::CYK(grammar &G, string &w){ //bbab
    table n;

    int longitud = w.length();
    for(int i = 1; i <= longitud; i++) busquedaCaracteres(G, n[i][1], w[i - 1]);
    for(int j = 2; j <= longitud; j++){
        for(int i = 1; i <= (longitud - j + 1); i++){
            for(int k = 1; k <= j-1; k++) busquedaCombinaciones(G, n[i][k], n[i + k][j - k], n[i][j]);
        }
    }
    if(n[1][longitud].find(simboloInicial(G)) != n[1][longitud].end()) return true;
        else return false;
}

void Gramatica::busquedaCaracteres(grammar &G, conjunto &aux, char w){

    for(int i = 0; i < G.size(); i++)   if((G[i].C == 0) && (G[i].B == w))  aux.insert(G[i].A);                                     
}

void Gramatica::busquedaCombinaciones(grammar &G, conjunto &a, conjunto &b, conjunto &r){

    for(conjunto::iterator i = a.begin(); i != a.end(); i++){
        for(conjunto::iterator j = b.begin(); j != b.end(); j++){
            for(int m = 0; m < G.size(); m++)   if((G[m].B == *i) && (G[m].C == *j)) r.insert(G[m].A);
        }
    }
}