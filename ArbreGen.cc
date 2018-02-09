#include "ArbreGen.hh"

void llegir_arbre_gen(Arbre<string>& a, string marca) {
  Arbre<string> a1, a2;
  string x;
  cin >> x;
  if (x != marca) {
    llegir_arbre_gen(a1, marca);
    llegir_arbre_gen(a2, marca);
    a.plantar(x, a1, a2);
  }
}

void escriure_arbre_gen(Arbre<string>& a) {
  if (not a.es_buit()) {
    Arbre<string> a1, a2;
    string x = a.arrel();
    a.fills(a1, a2);
    cout << " " << x;
    escriure_arbre_gen(a1);
    escriure_arbre_gen(a2);
    a.plantar(x, a1, a2);
  }
}

void compararar_arbre_gen(Arbre<string>& complet, Arbre<string>& parcial, bool& es_parcial) {
  if (not es_parcial) return;
  Arbre<string> complet_fe, complet_fd, parcial_fe, parcial_fd;
  if (parcial.es_buit() and not complet.es_buit()) {
    renombrar(complet, "*");
  } else if (not parcial.es_buit() and not complet.es_buit()) {
    string arrel = parcial.arrel();
    if (arrel != complet.arrel()) es_parcial = false;
    else {
      complet.fills(complet_fe, complet_fd);
      parcial.fills(parcial_fe, parcial_fd);
      compararar_arbre_gen(complet_fe, parcial_fe, es_parcial);
      compararar_arbre_gen(complet_fd, parcial_fd, es_parcial);
      complet.plantar(arrel, complet_fe, complet_fd);
    }
  }
}

void renombrar(Arbre<string>& arbre, const string marca) {
  if (not arbre.es_buit()) {
    string arrel = arbre.arrel();
    Arbre<string> fe, fd;
    arbre.fills(fe, fd);
    renombrar(fe, marca);
    renombrar(fd, marca);
    if (arrel == "$") arbre.plantar(arrel, fe, fd);
    else arbre.plantar(marca + arrel + marca, fe, fd);
  }
}
