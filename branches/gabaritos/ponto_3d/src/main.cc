#include <iostream>
#include <ostream>

#include "ponto_3d/src/ponto_3d.h"

using std::cout;
using std::endl;
using std::ostream;

ostream& operator<<(ostream& sout, Ponto3D& p) {
  sout << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
  return sout;
}

int main() {
  Ponto3D p(15, 0, 15);
  cout << p << endl;
  p.Transladar(-7.5, -7.5, 0);
  p.Rotacionar('Z', - PI / 6);
  p.Transladar(7.5, 7.5, 0);
  cout << p << endl;
  return 0;
}
