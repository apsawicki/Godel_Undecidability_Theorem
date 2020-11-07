#include <iostream>

using namespace std;

void fillArray(int *arr, int size) { // fills the array with a list of numbers from 2 - (number chosen minus 1)
	for (int i = 0; i < size; i++)
		arr[i] = i + 2;
}

int primeList(int *arr, int &size, int num) {// makes the array a list of prime numbers from 2 - num
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			// sorts for primes by seeing if there is a remainder when divided by other values in the array
			if (arr[j + 1] % arr[i] == 0) {
				for (int k = j + 1; k < size; k++) // gets rid of the non-primes and fixes the array
				{
					arr[k] = arr[k + 1];
				}
				size = size - 1; // resizes the array because a non-prime was taken out
			}

	return 0;
}

int primeSum(int *arr, int size, int num) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (arr[i] + arr[j] == num) {
				cout << arr[i] << " + " << arr[j] << " = " << num << endl;

				return 0;
			}

	cout << "there are no primes that sum to " << num << endl;
	return 0;
}

int main() {
	int num = 0;

	while (num < 2) {
		cout << "enter an even number(num > 2): ";
		cin >> num;
	}

	int size = num - 2;

	int *arr = nullptr;
	arr = new int[size]{};

	fillArray(arr, size);

	primeList(arr, size, num);

	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;

	primeSum(arr, size, num);

	delete[] arr;
	return 0;
}