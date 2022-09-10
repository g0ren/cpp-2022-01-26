/*
 * Задание 1.2
 Написать шаблоны функций  для выполнения следующих   задач:
 ■ Инициализация квадратной матрицы;
 ■ Вывод матрицы на экран;
 ■ Определение максимального и минимального элемента на главной диагонали матрицы;
 ■ Сортировка элементов по возрастанию отдельно для каждой строки матрицы.
 */
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
#define SIZE 5
#define MIN_N 1
#define MAX_N 255

template<typename T>
void fillMatrix(T m[SIZE][SIZE]) {
	srand(time(NULL));
	double mul { };
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			mul = (double) rand() / RAND_MAX;
			m[i][j] = MIN_N + (MAX_N - MIN_N) * mul;
		}
}

template<typename T>
void printMatrix(T m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

template<typename T>
T minOnMD(T m[SIZE][SIZE]) {
	T min { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] < min)
			min = m[i][i];
	return min;
}

template<typename T>
T maxOnMD(T m[SIZE][SIZE]) {
	T max { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] > max)
			max = m[i][i];
	return max;
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
void byRowSort(T m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		bubbleSortArray(m[i]);
	}
}

int main() {
	int im[SIZE][SIZE] { };
	double dm[SIZE][SIZE] { };
	char cm[SIZE][SIZE] { };
	fillMatrix(im);
	fillMatrix(dm);
	fillMatrix(cm);

	cout << "Int matrix:" << endl;
	printMatrix(im);
	cout << "Min on main diagonal: " << minOnMD(im)
			<< ", Max on main diagonal: " << maxOnMD(im) << endl;
	byRowSort(im);
	cout << "Rowwise sorted:" << endl;
	printMatrix(im);

	cout << endl;

	cout << "Double matrix:" << endl;
	printMatrix(dm);
	cout << "Min on main diagonal: " << minOnMD(dm)
			<< ", Max on main diagonal: " << maxOnMD(dm) << endl;
	byRowSort(dm);
	cout << "Rowwise sorted:" << endl;
	printMatrix(dm);

	cout << endl;

	cout << "Char matrix:" << endl;
	printMatrix(cm);
	cout << "Min on main diagonal: " << minOnMD(cm)
			<< ", Max on main diagonal: " << maxOnMD(cm) << endl;
	byRowSort(cm);
	cout << "Rowwise sorted:" << endl;
	printMatrix(cm);
	cout << endl;

	return 0;
}
