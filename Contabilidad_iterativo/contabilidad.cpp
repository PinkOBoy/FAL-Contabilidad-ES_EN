/*
* Solucion aportada por el profesor de la FdI (UCM):
* Solution given by FdI's (UCM) professor:
*   ANTONIO ALEJANDRO SANCHEZ RUIZ-GRANADOS
* Editada y completada por:
* Edited and completed by:
*   JAIME B.
*/
#include <iostream>
#include <vector>
using namespace std;

//PRECONDICION: true
bool property(const vector<int>& v); // return bool p
/* POSCONDICION:
* p = EXISTE a : 0 <= a < v.size() : v[a] = (SUMA b : a < b < v.size() : v[b])
*/

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // compute and write the solution
    cout << (property(v) ? "YES" : "NO") << endl;
    /* == to:
    * if (property(v))
        cout << "YES" << endl;
      else cout << "NO" << endl;
    */
    return true;
}

int main() {
    while (solve());

    return 0;
}

/*COMPLEJIDAD DEL ALGORITMO
*   Sabemos que todas las instrucciones ejecutadas tienen coste constante.
*
*   Existe un bucle dentro del algoritmo que ejecuta instrucciones de coste
*   constante para, en el peor de los casos, todos los elementos del vector
*   v.
* 
*   Por ello, definiendo n como el numero de elementos del vector v, podemos
*   afirmar que el coste del algoritmo será:
* 
*       O(n)
*/
/*COMPLEXITY OF THE ALGORITHM
*   We know all executed instructions belong to O(1).
* 
*   Inside our algorithm exists a loop, which executes instructions of constant
*   cost for, in the worst case scenario, every element of vector v.
* 
*   Therefore, defining n as the number of elements of vector v, we can affirm
*   that the cost of our algorithm equals to:
* 
*       O(n)
*/
bool property(const vector<int>& v) {
    int i = v.size() - 1;
    int suma = 0; // sum v[i+1..]

    // FUNCION DE COTA = i 
    while (i >= 0 && v[i] != suma) {
        suma += v[i];
        --i;
    }
    /*INVARIANTE:
    *   -1 <= i < v.size()
    * &&
    *   suma = SUMA e : i < e < v.size() : v[e]
    */

    return i >= 0;
}