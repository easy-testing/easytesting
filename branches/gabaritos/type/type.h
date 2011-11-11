// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_TYPE_TYPE_H_
#define BRANCHES_GABARITOS_TYPE_TYPE_H_

#include<string>

// Type define o tipo dos elementos contidos nas estruturas de dados.
// É definido aqui desta forma para evitar usa templates, que na versão atual
// de C++ é muito difícil de usar para a maioria dos alunos.
//
#ifdef TYPE_STRING
  typedef std::string Type;
#elif TYPE_DOUBLE
  typedef double Type;
#elif TYPE_FLOAT
  typedef float Type;
#elif TYPE_INT
  typedef int Type;
#elif TYPE_CHAR
  typedef char Type;
#endif

#endif  BRANCHES_GABARITOS_TYPE_TYPE_H_
