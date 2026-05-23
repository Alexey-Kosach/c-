#include <iostream>
#include <Windows.h>
#include "../2. 2/Array.h"

enum { push = 1, pop, replace_elem };
using namespace std;

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main() {
	int n = 0;
	cout << "Выберите размер вашего массива:" << endl;
	cin >> n;
	if (n <= 0) {
		cout << "Размер должен быть больше 0;" << endl;
		return 1;
	}

	vector v;
	cout << "Введите " << n << " элементов:" << endl;
	for (size_t i = 0; i < n; ++i) {
		int val = 0;
		cin >> val;
		v.push(v.getSize(), val);
	}

	cout << "Текущий массив: " << v << endl;
	cout << "Выберите метод: " << push << " - добавить элемент, " << pop << " - удалить элемент, " << replace_elem << " - заменить элемент" << endl;
	int choice = 0;
	cin >> choice;

	switch (choice) {
	case push: {
		int idx = 0, val = 0;
		cout << "Введите индекс и значение для добавления:" << endl;
		cin >> idx >> val;
		v.push(idx, val);
		break;
	}
	case pop: {
		size_t idx = 0;
		cout << "Введите индекс для удаления:" << endl;
		cin >> idx;
		v.pop(idx);
		break;
	}
	case replace_elem: {
		size_t idx = 0;
		int val = 0;
		cout << "Введите индекс и новое значение:" << endl;
		cin >> idx >> val;
		v.replace(idx, val);
		break;
	}
	default:
		cout << "Неверный выбор." << endl;
		return 1;
	}
	cout << "Новый массив: " << v << endl;
	if (!v.isEmpty()) cout << "Первый элемент: " << v[0] << endl;
	return 0;
}