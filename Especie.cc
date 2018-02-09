#include "Especie.hh"

Especie::Especie() {}

void Especie::llegir_informacio_especie() {
  cin >> N;
  li = vector<int>(N+1);
  for (int i = 0; i <= N; ++i) cin >> li[i];
  cin >> lx >> ly;
}

int Especie::mida_cromosoma_sexual(const char c) const {
  if (c == 'X') return lx;
  else return ly;
}

int Especie::mida_cromosoma(const int i) const {
  return li[i];
}

int Especie::consultar_N() const {
  return N;
}
