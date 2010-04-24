CC = c++ -Wall

main: main.cc polinomios.o test/test.h test/gtest-all.o
	$(CC) polinomios.o test/gtest-all.o main.cc -o main

polinomioa.o: polinomios.h polinomios.cc
	$(CC) -c polinomios.cc

gtest/gtest-all.o: test/gtest.h test/gtest-all.cc
	$(CC) -c test/gtest-all.cc

clean:
	rm main *.o build/* -f
