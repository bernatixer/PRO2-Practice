#include "Poblacio.hh"

Poblacio::Poblacio() {}

void Poblacio::afegir_individu(const Individu& ind) {
  if (esta_individu(ind.consultar_nom())) cout << "  error" << endl;
  else {
    Persona nova_persona;
    nova_persona.ind = ind;
    pair<string, Persona> nou_individu (ind.consultar_nom(), nova_persona);
    habitants.insert(nou_individu);
  }
}

// TO-DO: el pare pot tenir $ pero la mare no!!!!!!!!!!!!!!!!!
bool Poblacio::antecessors(const string nom, const string& ant) const {
  bool trobat;
  Persona pers;
  buscar_persona(nom, trobat, pers);
  if (pers.pare != "$") return pers.pare == ant or pers.mare == ant or antecessors(pers.pare, ant) or antecessors(pers.mare, ant);
  else return false;
}

void Poblacio::reproduir(const Especie& e, const string mare, const string pare, const string fill) {
  bool esta_mare, esta_pare, esta_fill;
  Persona prs_mare, prs_pare, prs_fill;
  buscar_persona(mare, esta_mare, prs_mare);
  buscar_persona(pare, esta_pare, prs_pare);
  buscar_persona(fill, esta_fill, prs_fill);
  if (not esta_mare or not esta_pare or esta_fill) cout << "  error" << endl;
  else {
    if (diff_sexe(prs_mare, prs_pare) and not son_germans(prs_mare, prs_pare) and not (antecessors(mare, pare) or antecessors(pare, mare))) {
      prs_fill.mare = mare;
      prs_fill.pare = pare;
      prs_fill.ind.posar_nom(fill);
      prs_fill.ind.reproduir(e, prs_mare.ind, prs_pare.ind);
      pair<string, Persona> nou_individu (fill, prs_fill);
      habitants.insert(nou_individu);
    } else {
      cout << "  no es posible reproduccion" << endl;
    }
  }
}

bool Poblacio::esta_individu(const string nom) const {
  map<string, Persona>::const_iterator it;
  it = habitants.find(nom);
  if (it == habitants.end()) return false;
  else return true;
}

void Poblacio::buscar_persona(const string nom, bool& trobat, Poblacio::Persona& pers) const {
  map<string, Persona>::const_iterator it;
  it = habitants.find(nom);
  if (it == habitants.end()) trobat = false;
  else {
    trobat = true;
    pers = (*it).second;
  }
}


void Poblacio::buscar_individu(const string nom, bool& trobat, Individu& ind) const {
  Poblacio::Persona pers;
  buscar_persona(nom, trobat, pers);
  if (trobat) ind = pers.ind;
}

void Poblacio::escriure() const {
  map<string, Persona>::const_iterator it;
  for (it = habitants.begin(); it != habitants.end(); ++it) {
    Persona pers = (*it).second;
    cout << "  " << (*it).first << " X" << pers.ind.consultar_sexe() << " (" << pers.pare << "," << pers.mare << ")" << endl;
  }
}

bool Poblacio::son_germans(const Poblacio::Persona& p1, const Poblacio::Persona& p2) const {
  return (p1.mare == p2.mare or p1.pare == p2.pare) and not (p1.mare == "$" and p2.mare == "$") and not (p1.pare == "$" and p2.pare == "$");
}

bool Poblacio::diff_sexe(const Poblacio::Persona& p1, const Poblacio::Persona& p2) const {
  return p1.ind.consultar_sexe() == 'X' and p2.ind.consultar_sexe() == 'Y';
}

void Poblacio::escriure_arbre(const string nom) const {
  bool trobat;
  Poblacio::Persona pers;
  buscar_persona(nom, trobat, pers);
  if (trobat) {
    cout << "  Nivel 0: ";
    int lvl = 1;
    list<string> l = {nom, "$"};
    list<string>::iterator it = l.begin();
    list<string>::iterator aux;
    while (it != l.end()) {
      if (*it == "$") {
        aux = it;
        ++aux;
        if (aux != l.end()) {
          l.insert(l.end(), "$");
          cout << endl << "  Nivel " << lvl << ": ";
          ++lvl;
        }
      } else {
        buscar_persona(*it, trobat, pers);
        cout << *it;
        if (pers.pare != "$") {
          l.insert(l.end(), pers.pare);
          l.insert(l.end(), pers.mare);
        }
        aux = it;
        ++aux;
        if (aux != l.end() and *aux != "$") cout << " ";
      }
      ++it;
    }
    cout << endl;
  } else cout << "  error" << endl;
}

void Poblacio::generar_arbre_i(const string nom, Arbre<string>& arb) const {
  Arbre<string> a1, a2;
  if (nom == "$") arb.plantar(nom, a1, a2);
  else {
    bool trobat;
    Poblacio::Persona pers;
    buscar_persona(nom, trobat, pers);
    generar_arbre_i(pers.pare, a1);
    generar_arbre_i(pers.mare, a2);
    arb.plantar(nom, a1, a2);
  }
}
