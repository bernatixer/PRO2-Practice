#include "Individu.hh"

Individu::Individu() {}

void Individu::reproduir(const Especie& e, const Individu& mare, const Individu& pare) {
  cromosomes = vector<ParCrom>(e.consultar_N());
  int c1, c2, k;
  cin >> c1 >> c2 >> k;
  if (c1 == 0) {
    if (c2 == 0) par_sexual.reproduir(e.mida_cromosoma(0), k, mare.par_sexual.primer(), pare.par_sexual.primer());
    else par_sexual.reproduir(e.mida_cromosoma(0), k, mare.par_sexual.primer(), pare.par_sexual.segon());
  } else {
    if (c2 == 0) par_sexual.reproduir(e.mida_cromosoma(0), k, mare.par_sexual.segon(), pare.par_sexual.primer());
    else par_sexual.reproduir(e.mida_cromosoma(0), k, mare.par_sexual.segon(), pare.par_sexual.segon());
  }
  if (c2 == 0) sexe = 'X';
  if (c2 == 1) sexe = 'Y';
  for (int i = 0; i < e.consultar_N(); ++i) {
    cin >> c1 >> c2 >> k;
    if (c1 == 0) {
      if (c2 == 0) cromosomes[i].reproduir(e.mida_cromosoma(i+1), k, mare.cromosomes[i].primer(), pare.cromosomes[i].primer());
      else cromosomes[i].reproduir(e.mida_cromosoma(i+1), k, mare.cromosomes[i].primer(), pare.cromosomes[i].segon());
    } else {
      if (c2 == 0) cromosomes[i].reproduir(e.mida_cromosoma(i+1), k, mare.cromosomes[i].segon(), pare.cromosomes[i].primer());
      else cromosomes[i].reproduir(e.mida_cromosoma(i+1), k, mare.cromosomes[i].segon(), pare.cromosomes[i].segon());
    }
  }
}

void Individu::llegir(const Especie& e) {
  cromosomes = vector<ParCrom>(e.consultar_N());
  cin >> nom >> sexe;
  par_sexual.llegir_sexual(e.mida_cromosoma_sexual('X'), e.mida_cromosoma_sexual(sexe));
  for (int i = 0; i < e.consultar_N(); ++i) {
    ParCrom par;
    par.llegir(e.mida_cromosoma(i+1));
    cromosomes[i] = par;
  }
}

void Individu::escriure(const Especie& e) const {
  cout << "  X: ";
  par_sexual.escriure_primer(e.mida_cromosoma_sexual('X'));
  cout << "  " << sexe << ": ";
  par_sexual.escriure_segon(e.mida_cromosoma_sexual(sexe));
  for (int i = 0; i < e.consultar_N(); ++i) {
    cout << "  " << i+1 << ".1: ";
    cromosomes[i].escriure_primer(e.mida_cromosoma(i+1));
    cout << "  " << i+1 << ".2: ";
    cromosomes[i].escriure_segon(e.mida_cromosoma(i+1));
  }
}

string Individu::consultar_nom() const {
  return nom;
}

char Individu::consultar_sexe() const {
  return sexe;
}

void Individu::posar_nom(const string nou_nom) {
  nom = nou_nom;
}
