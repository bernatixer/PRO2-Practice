#include "ParCrom.hh"

ParCrom::ParCrom() {
  //
}

void ParCrom::reproduir(const int li, const int k, vector<int> mare, vector<int> pare) {
  for (int i = k; i < li; ++i) {
    int aux = mare[i];
    mare[i] = pare[i];
    pare[i] = aux;
  }
  parell.first = mare;
  parell.second = pare;
}

void ParCrom::llegir(const int li) {
  vector<int> v1(li);
  parell.first = v1;
  parell.second = v1;
  for (int i = 0; i < li; ++i) cin >> (parell.first)[i];
  for (int i = 0; i < li; ++i) cin >> (parell.second)[i];
}

void ParCrom::llegir_sexual(const int l1, const int l2) {
  vector<int> v1(l1);
  vector<int> v2(l2);
  parell.first = v1;
  parell.second = v2;
  for (int i = 0; i < l1; ++i) cin >> (parell.first)[i];
  for (int i = 0; i < l2; ++i) cin >> (parell.second)[i];
}

void ParCrom::escriure_primer(const int li) const {
  for (int i = 0; i < li-1; ++i) cout << (parell.first)[i] << " ";
  cout << (parell.first)[li-1] << endl;
}

void ParCrom::escriure_segon(const int li) const {
  for (int i = 0; i < li-1; ++i) cout << (parell.second)[i] << " ";
  cout << (parell.second)[li-1] << endl;
}

vector<int> ParCrom::primer() const {
  return parell.first;
}

vector<int> ParCrom::segon() const {
  return parell.second;
}
