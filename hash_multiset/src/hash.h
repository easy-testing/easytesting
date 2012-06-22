// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_HASH_MULTISET_SRC_HASH_H_
#define TRUNK_HASH_MULTISET_SRC_HASH_H_

#include <string>

int hash(int x, int max_size);

int hash(float x, int max_size);

int hash(std::string& x, int max_size);

#endif  // TRUNK_HASH_MULTISET_SRC_HASH_H_

