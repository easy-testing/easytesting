// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Maps.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "unordered_map_with_set/src/unordered_map.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main() {
  unordered_map mymap;
  mymap.insert("foo", 10);
  mymap.insert("bar", 20);
  std::cout << "mymap['foo'] is " << mymap["bar"] << '\n';
  return 0;
}
