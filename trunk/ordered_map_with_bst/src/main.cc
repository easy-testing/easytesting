// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Maps

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "ordered_map_with_bst/src/map.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main() {
  map mymap;
  mymap.insert("foo", 10);
  std::cout << "mymap['foo'] is " << mymap["foo"] << '\n';
  return 0;
}
