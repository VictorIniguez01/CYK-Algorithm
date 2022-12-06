#include "Gramatica.hpp"

int main(){

    string w = "p:r?((((0|1)&0)&1)|0):1;r:0;";

    grammar G;
    Gramatica a(G);

    if (a.CYK(G,w)) cout << "accepted\n";
		else cout << "rejected\n";

  return 0;
}