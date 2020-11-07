#include <iostream>
#include <vector>

#include "main.h"

// fills the array with a list of numbers from 2 - (number chosen minus 1)
void fillArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
		arr[i] = i + 2;
}

// makes the array a list of prime numbers from 2 - num
int primeList(int *arr, int &size) {

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			// sorts for primes by seeing if there is a remainder when divided by other values in the array

			if ((arr[j + 1] % arr[i]) == 0) {
				for (int k = j + 1; k < size; k++) // gets rid of the non-primes and fixes the array
					arr[k] = arr[k + 1];

				size = size - 1; // resizes the array because a non-prime was taken out
			}

	return 0;
}

// Turn prime/exponents into symbols
void symbolNum(const std::vector<prime_struct> &primeStuff) {
	std::string symbolList[] = {"null", "0", "null", "f", "null", "¬", "null", "∨", "null", "∀", "null", "(", "null",
								")", "null", "∧", "null", "∃", "null", "=", "null", "x", "null", "y"};

	//2^3 3^3 5^3 7^1 == f f f 0
	for (prime_struct x : primeStuff) {
		if (x.power > (sizeof(symbolList) / sizeof(symbolList[0])) || x.power % 2 == 0) {
			std::cout << "list of primes is unacceptable" << std::endl;
			exit(-1);
		} else
			std::cout << symbolList[x.power] << " ";
	}
}

int main() {
	std::vector<std::string> primeInputList;
	retrievePrimeList(primeInputList);

	std::vector<prime_struct> primeStuff;
	int size = 0;

	for (const std::string &curStr : primeInputList) {
		prime_struct structThing = formatPrimes(curStr, "^");
		primeStuff.push_back(structThing);
		size = structThing.coefficient + 1;
	}

	int arr[size];
	fillArray(arr, size);
	primeList(arr, size);

	// Maybe make this its own func?
	for (int i = 0; i < primeStuff.size(); i++)
		if (primeStuff[i].coefficient != arr[i]) {
			std::cout << "List of primes is unacceptable....  Expected " <<
					  arr[i] << " but got " << primeStuff[i].coefficient << std::endl;

			return -1;
		}

	symbolNum(primeStuff);

	return 0;
}

void retrievePrimeList(std::vector<std::string> &primeList) {
	std::string receivedInput = "0";

	std::cout << "Input a series of primes with proper odd exponents separated by a comma (e.g. 2^7,3^3,5^17)" << std::endl;
	std::cin >> receivedInput;

	std::vector<std::string> receivedInputVect;
	delimiterSplit(receivedInputVect, receivedInput, ",");

	for (const std::string &curExpression : receivedInputVect)
		primeList.push_back(curExpression);
}

void delimiterSplit(std::vector<std::string> &container, std::string strCopy, const std::string &delim) {
	for (;;) {
		int nextPos = strCopy.find(delim);

		if (nextPos != std::string::npos)
			container.push_back(strCopy.substr(0, nextPos));
		else {
			container.push_back(strCopy);
			break;
		}

		strCopy.erase(0, nextPos + delim.length());
	}
}

prime_struct formatPrimes(std::string str, const std::string &delimiter) {
	prime_struct returningPrime{};
	unsigned int position = str.find(delimiter);
	std::string curToken;

	if (str.find(delimiter) != std::string::npos) {
		returningPrime.coefficient = std::stoi(str.substr(0, position));
		str.erase(0, position + delimiter.length());
		returningPrime.power = std::stoi(str);
	} else {
		std::cout << "Something happened while trying to format \"" << str << "\"." << std::endl;
		exit(-1);
	}

	return returningPrime;
}