#include <iostream>
#include <vector>
#include <chrono> // Для подсчета времени
#include <cstdlib> // Для функции rand
#include <ctime> // Для инициализации генератора случайных чисел
using namespace std;

int counterFunctionLeft()
{
	static long int counterLeft = 0;
	counterLeft++;
	return counterLeft;
}
int counterFunctionRight()
{
	static long int counterRight = 0;
	counterRight++;
	return counterRight;
}

void shakerSort(vector<int>& arr, int s) {
	int left = 0;
	int right = arr.size() - 1;
	bool swapped = false;
	switch (s)
	{
	case(1):// Сортировка по возрастанию
	{
		do {
			// Проход слева направо
			for (int i = left; i < right; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					swap(arr[i], arr[i + 1]);
					swapped = true;
					counterFunctionRight();
				}
			}
			right--;

			if (!swapped) {
				break; // Если не было перестановок, то массив уже отсортирован
			}

			swapped = false;

			// Проход справа налево
			for (int i = right; i > left; i--)
			{
				if (arr[i] < arr[i - 1])
				{
					swap(arr[i], arr[i - 1]);
					swapped = true;
					counterFunctionLeft();
				}
			}
			left++;
		} while (swapped);
		break;
	}
	default:
		do {
			// Проход слева направо
			for (int i = left; i < right; i++)
			{
				if (arr[i] < arr[i + 1])
				{
					swap(arr[i], arr[i + 1]);
					swapped = true;
					counterFunctionRight();
				}
			}
			right--;

			if (!swapped) {
				break; // Если не было перестановок, то массив уже отсортирован
			}

			swapped = false;

			// Проход справа налево
			for (int i = right; i > left; i--)
			{
				if (arr[i] > arr[i - 1])
				{
					swap(arr[i], arr[i - 1]);
					swapped = true;
					counterFunctionLeft();
				}
			}
			left++;
		} while (swapped);
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;// Размер Массива
	int x = 0, y = 100;// Переменный диапазона размера массива
	int s = 0, v = 0;// S - Тип сортировки  V - Заполнение массива самостоятельно
	vector<int> arr;
	srand(time(nullptr));


	cout << "Введите размер массива: ";
	cin >> n;
	cout << "Заполнить массив:\n0 - Самостоятельно\n1 - Автоматически\n:";
	cin >> v;
	if (v == 1)
	{
		cout << "Введите диапазон массива от ";
		cin >> x;
		cout << "до ";
		cin >> y;
	}
	cout << "1 - Отсортировать по ВОЗРАСТАНИЮ \n0 - Остортировать по УБЫВАНИЮ\n:";
	cin >> s;

	if (v == 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v;
			arr.push_back(v);
		}
	}
	else
	{
		if (x < 0)
		{
			for (int i = 0; i < n; i++)
			{
				arr.push_back(rand() % (y - x + 1) + x);
			}
		}
		else {
			for (int i = 0; i < n; i++)
			{
				arr.push_back(x + rand() % y);
			}
		}
	}
	cout << "Исходный массив:" << endl;
	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;

	auto startTime = chrono::high_resolution_clock::now();// Записываем текущее время перед выполнением сортировки
	shakerSort(arr, s);
	auto endTime = chrono::high_resolution_clock::now();// Время завершения алгоритма

	cout << "Отсортированный массив:" << endl;
	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;
	cout << "Общее количесвто итераций: " << counterFunctionLeft() + counterFunctionRight() << endl;
	cout << "Количество проходов СЛЕВА НАПРАВО -> :" << counterFunctionRight() << endl;
	cout << "Количество проходов СПРАВА НАЛЕВО <- :" << counterFunctionLeft() << endl;
	auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
	cout << "Время затраченное на выполнение: " << duration.count() << " мс " << endl;// Итого времени понадобилось для выполнения алгоритма
	system("pause");
	return 0;
}