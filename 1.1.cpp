/*
 * Задание 1.1
 Написать перегруженные функции (int, double, char) для выполнения следующих   задач:
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
#define MIN_N -100
#define MAX_N 100
#define MIN_C 1
#define MAX_C 255

void fillMatrix(int m[SIZE][SIZE]);
void fillMatrix(double m[SIZE][SIZE]);
void fillMatrix(char m[SIZE][SIZE]);
void printMatrix(int m[SIZE][SIZE]);
void printMatrix(double m[SIZE][SIZE]);
void printMatrix(char m[SIZE][SIZE]);
int minOnMD(int m[SIZE][SIZE]);
double minOnMD(double m[SIZE][SIZE]);
char minOnMD(char m[SIZE][SIZE]);
int maxOnMD(int m[SIZE][SIZE]);
double maxOnMD(double m[SIZE][SIZE]);
char maxOnMD(char m[SIZE][SIZE]);
void printArray(int m[SIZE], int size = SIZE);
void printArray(double m[SIZE], int size = SIZE);
void printArray(char m[SIZE], int size = SIZE);
void swap(int l[SIZE], int i, int j);
void swap(double l[SIZE], int i, int j);
void swap(char l[SIZE], int i, int j);
void bubbleSortArray(int ar[SIZE], int size = SIZE);
void bubbleSortArray(double ar[SIZE], int size = SIZE);
void bubbleSortArray(char ar[SIZE], int size = SIZE);
void byRowSort(int m[SIZE][SIZE]);
void byRowSort(double m[SIZE][SIZE]);
void byRowSort(char m[SIZE][SIZE]);

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

void fillMatrix(int m[SIZE][SIZE]) {
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			m[i][j] = MIN_N + rand() % (MAX_N - MIN_N + 1);
}

void fillMatrix(double m[SIZE][SIZE]) {
	srand(time(NULL));
	double mul { };
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			mul = (double) rand() / RAND_MAX;
			m[i][j] = MIN_N + (MAX_N - MIN_N) * mul;
		}
}

void fillMatrix(char m[SIZE][SIZE]) {
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			m[i][j] = MIN_C + rand() % (MAX_C - MIN_C + 1);
}

void printMatrix(int m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void printMatrix(double m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void printMatrix(char m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int minOnMD(int m[SIZE][SIZE]) {
	int min { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] < min)
			min = m[i][i];
	return min;
}

double minOnMD(double m[SIZE][SIZE]) {
	double min { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] < min)
			min = m[i][i];
	return min;
}

char minOnMD(char m[SIZE][SIZE]) {
	char min { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] < min)
			min = m[i][i];
	return min;
}

int maxOnMD(int m[SIZE][SIZE]) {
	int max { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] > max)
			max = m[i][i];
	return max;
}

double maxOnMD(double m[SIZE][SIZE]) {
	double max { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] > max)
			max = m[i][i];
	return max;
}

char maxOnMD(char m[SIZE][SIZE]) {
	char max { m[0][0] };
	for (int i = 0; i < SIZE; i++)
		if (m[i][i] > max)
			max = m[i][i];
	return max;
}

void printArray(int m[SIZE], int size) {
	for (int i = 0; i < size; i++)
		cout << m[i] << " ";
	cout << endl;
}

void printArray(double m[SIZE], int size) {
	for (int i = 0; i < size; i++)
		cout << m[i] << " ";
	cout << endl;
}

void printArray(char m[SIZE], int size) {
	for (int i = 0; i < size; i++)
		cout << m[i] << " ";
	cout << endl;
}

void swap(int l[SIZE], int i, int j) {
	int t { };
	t = l[i];
	l[i] = l[j];
	l[j] = t;
}

void swap(double l[SIZE], int i, int j) {
	double t { };
	t = l[i];
	l[i] = l[j];
	l[j] = t;
}

void swap(char l[SIZE], int i, int j) {
	char t { };
	t = l[i];
	l[i] = l[j];
	l[j] = t;
}

void bubbleSortArray(int ar[], int size) {
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

void bubbleSortArray(double ar[], int size) {
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

void bubbleSortArray(char ar[], int size) {
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

void byRowSort(int m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		bubbleSortArray(m[i]);
	}
}

void byRowSort(double m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		bubbleSortArray(m[i]);
	}
}

void byRowSort(char m[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		bubbleSortArray(m[i]);
	}
}
