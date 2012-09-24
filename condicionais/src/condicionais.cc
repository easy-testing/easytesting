// Copyright 2012 Universidade Federal de Minas Gerais (UFMG)
#include "condicionais/src/condicionais.h"
#include <cmath>
#include <string>

using std::string;

int menor(int x, int y) {
  if (x < y) {
    return x;
  } else {
    return y;
  }
}

int maior(int x, int y, int z) {
  if ((x > y) && (x > z)) {
    // Verifica se x é maior
    return x;
  } else if (y > z) {
    // Verifica se y é maior.
    return y;
  } else {
    // Se z é maior.
    return z;
  }
}

bool par(int x) {
  if (x % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

bool triangulo(float a, float b, float c) {
  if ((a < (b + c)) && (b < (a + c)) && (c < (a + b))) {
    return true;
  } else {
    return false;
  }
}

bool equilatero(float a, float b, float c) {
  if (triangulo(a, b, c)) {
    if ((a == b) && (a == c)) {
      return true;
    }
  }
  return false;
}

bool isosceles(float a, float b, float c) {
  if (triangulo(a, b, c)) {
    if ( (a == b) || (a == c) || (b == c) ) {
      return true;
    }
  }
  return false;
}

bool escaleno(float a, float b, float c) {
  if (triangulo(a, b, c) && !isosceles(a, b, c) && !equilatero(a, b, c)) {
    return true;
  } else {
    return false;
  }
}

string signo(int dia, int mes) {
  std::string sig;
  if (mes == 3) {
    if (dia <= 22) {
      sig = "Peixes";
    } else if (dia >= 23) {
      sig = "Ares";
    }
  } else if (mes == 4) {
    if (dia <= 20) {
      sig = "Ares";
    } else if (dia >= 21) {
      sig = "Touro";
    }
  } else if (mes == 5) {
    if (dia <= 21) {
      sig = "Touro";
    } else if (dia >= 22) {
      sig = "Gemeos";
    }
  } else if (mes == 6) {
    if (dia <= 21) {
      sig = "Gemeos";
    } else if (dia <= 22) {
      sig = "Cancer";
    }
  } else if (mes == 7) {
    if (dia <= 22) {
      sig = "Cancer";
    } else if (dia >= 23) {
      sig = "Leao";
    }
  } else if (mes == 8) {
    if (dia <= 23) {
      sig = "Leao";
    } else if (dia >= 24) {
      sig = "Virgem";
    }
  } else if (mes == 9) {
    if (dia <= 22) {
      sig = "Virgem";
    } else if (dia >= 23) {
      sig = "Libra";
    }
  } else if (mes == 10) {
    if (dia <= 23) {
      sig = "Libra";
    } else if (dia >= 24) {
      sig = "Escorpiao";
    }
  } else if (mes == 11) {
    if (dia <= 22) {
      sig = "Escorpiao";
    } else if (dia >= 23) {
      sig = "Sargitario";
    }
  } else if (mes == 12) {
    if (dia <= 21) {
      sig = "Sargitario";
    } else if (dia >= 22) {
      sig = "Capricornio";
    }
  } else if (mes == 1) {
    if (dia <= 20) {
      sig = "Capricornio";
    } else if (dia >= 21) {
      sig = "Aquario";
    }
  } else if (mes == 2) {
    if (dia <= 18) {
      sig = "Aquario";
    } else if (dia >= 19) {
      sig = "Peixes";
    }
  }
  return sig;
}


