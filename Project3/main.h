//
// Created by apsaw on 10/30/2020.
//
#include <string>

struct prime_struct {
	int coefficient;
	int power;
};

void fillArray(int *arr, int size);
int primeList(int *arr, int &size);
void symbolNum(const std::vector<prime_struct> &primeStuff);
void retrievePrimeList(std::vector<std::string> &primeList);
void delimiterSplit(std::vector<std::string> &container, std::string strCopy, const std::string &delim);

prime_struct formatPrimes(std::string str, const std::string &delimiter);