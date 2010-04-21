CC = c++ -Wall

main: main.cc polinomios.o test.h gtest/gtest-all.o
	$(CC) polinomios.o gtest-all.o main.cc -o main

polinomioa.o: polinomios.h polinomios.cc
	$(CC) -c polinomios.cc

gtest/gtest-all.o: gtest/gtest.h gtest/gtest-all.cc
	$(CC) -c gtest/gtest-all.cc

clean:
	rm main *.o -f
