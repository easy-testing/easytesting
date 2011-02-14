#include "easytesting/set/src/set.h"

#include <math.h>

#include <iostream>

using namespace std;

// Imprime os elementos da lista entre chaves.
void Print(set<int>& l) {
  cout << "{ ";
  for (set<int>::iterator i = l.begin(); i != l.end() ; ++i) {
    cout << *i << " ";
  }
  cout << "} = " << l.size() << endl;
}

int main() {
  set<int> s;
  for (int i = 0; i < 5; ++i) {
    s.insert(i);
    s.insert(-i);
  }

  for (int i = -4; i <= 4; ++i) {
    if (i % 2 == 1 || -i % 2 == 1) {
      s.erase(s.find(i));
    }
  }

  for (set<int>::iterator i = s.begin(); i != s.end() ; ++i) {
    if (*i == 0) {
      s.erase(i);
      break;
    }
  }

  Print(s);
  return 0;
}
