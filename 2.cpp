/*
 * По результатам олимпиады участники награждаются дипломами. Набравшие одинаковые баллы получают
 * дипломы одинаковой степени. Призером олимпиады считается участник, получивший диплом не хуже III степени. 
 По результатам олимпиады определите количество призеров.
 Реализовать функцию, входными аргументами которой будет число участников олимпиады и массив результатов.
 Функция возвращает число призеров.
 Мои допущения:
 Число участников пока что константа (SIZE). Результаты могут быть от 0 до 12 баллов. Призёры — первые три места.
 */
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
#define SIZE 25
#define MIN_N 0
#define MAX_N 12

template<typename T>
void fillArray(T m[], int size = SIZE) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		m[i] = MIN_N + rand() % (MAX_N - MIN_N);
}

template<typename T>
void printArray(T m[], int size = SIZE) {
	for (int i = 0; i < size; i++)
		cout << m[i] << " ";
	cout << endl;
}

template<typename T>
void swap(T l[], int i, int j) {
	T t { };
	t = l[i];
	l[i] = l[j];
	l[j] = t;
}

template<typename T>
void bubbleSortArray(T ar[], int size = SIZE) {
	bool sorted { 0 };
	while (!sorted) {
		sorted = 1;
		for (int i = 1; i < size; i++) {
			if (ar[i - 1] > ar[i]) {
				swap(ar, i - 1, i);
				sorted = 0;
			}
		}
	}
}

template<typename T>
int numberOfWinners(T ar[], int size = SIZE) {
	bubbleSortArray(ar, size);
	int n { 1 };
	T max { ar[0] };
	for (int i = 2, j = 1; i > 0 && j < SIZE; j++) {
		if (ar[j] == max) {
			n++;
		} else {
			n++;
			i--;
			max = ar[j];
		}
	}
	return n;
}

int main() {
	int results[SIZE] { };
	fillArray(results, SIZE);
	printArray(results, SIZE);
	cout << "Number of winners: " << numberOfWinners(results, SIZE);

	return 0;
}
