/**
 * @mainpage Practica de PRO2

Practica de PRO2; <em>Bernat Torres</em>.

*/

/** @file main.cc
    @brief Programa principal de <em>Practica PRO2</em>.
*/

#include "Especie.hh"
#include "Poblacio.hh"

/** @brief Programa principal de <em>Practica PRO2</em>.
*/
int main() {
    Especie e;
    Poblacio p;
    Individu ind; // Individu auxiliar per a opercions varies

    e.llegir_informacio_especie();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      ind.llegir(e);
      p.afegir_individu(ind);
    }

    string s;
    cin >> s;
    while (s != "acabar") {
      if (s == "anadir_individuo") {
        ind.llegir(e);
        cout << "anadir_individuo " << ind.consultar_nom() << endl;
        p.afegir_individu(ind);
      } else if (s == "reproduccion_sexual") {
        string n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        cout << "reproduccion_sexual " << n1 << " " << n2 << " " << n3 << endl;
        p.reproduir(e, n1, n2, n3);
      } else if (s == "escribir_arbol_genealogico") {
        string n1;
        cin >> n1;
        cout << "escribir_arbol_genealogico " << n1 << endl;
        p.escriure_arbre(n1);
      } else if (s == "completar_arbol_genealogico") {
        Arbre<string> arbre_par;
        llegir_arbre_gen(arbre_par, "$");
        cout << "completar_arbol_genealogico " << arbre_par.arrel() << endl << " ";
        if (p.esta_individu(arbre_par.arrel())) {
          Arbre<string> arbre_cmp;
          p.generar_arbre_i(arbre_par.arrel(), arbre_cmp);
          bool es_parcial = true;
          compararar_arbre_gen(arbre_cmp, arbre_par, es_parcial);
          if (es_parcial) escriure_arbre_gen(arbre_cmp);
          else cout << " no es arbol parcial";
          cout << endl;
        } else cout << " no es arbol parcial" << endl;
      } else if (s == "escribir_poblacion") {
        cout << "escribir_poblacion" << endl;
        p.escriure();
      } else if (s == "escribir_genotipo") {
        string n1;
        cin >> n1;
        cout << "escribir_genotipo " << n1 << endl;
        bool trobat;
        p.buscar_individu(n1, trobat, ind);
        if (trobat) ind.escriure(e);
        else cout << "  error" << endl;
      }
      cin >> s;
    }
    cout << "acabar" << endl;
}
