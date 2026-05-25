#include <iostream>
#include <sstream>
#include "Array.h"

using namespace std;

/**
 * @brief Конструктор по умолчанию - создаёт пустой массив
 */
vector::vector() : array(nullptr), size(0) {}

/**
 * @brief Конструктор со списком инициализации
 * @param list список начальных значений
 */
vector::vector(const initializer_list<int> list) : size(list.size()) {
	array = new int[size];
	size_t i = 0;
	for (int elem : list)
		array[i++] = elem;
}

/**
 * @brief Деструктор - освобождает память
 */
vector::~vector() {
	delete[] array;
}

/**
 * @brief Конструктор копирования
 * @param other массив для копирования
 */
vector::vector(const vector& other) : size(other.size) {
	array = (size > 0) ? new int[size] : nullptr;
	for (size_t i = 0; i < size; ++i)
		array[i] = other.array[i];
}

/**
 * @brief Конструктор перемещения
 * @param other массив для перемещения
 */
vector::vector(vector&& other) : size(other.size), array(other.array) {
	other.size = 0;
	other.array = nullptr;
}

/**
 * @brief Проверка на пустоту
 * @return true если элементов нет
 */
bool vector::isEmpty() const {
	return size == 0;
}

/**
 * @brief Получение размера
 * @return количество элементов
 */
size_t vector::getSize() const {
	return size;
}

/**
 * @brief Преобразование в строку
 * @return строковое представление массива
 */
string vector::toString() const {
	if (isEmpty())
		return "Пусто";
	stringstream ss;
	for (size_t i = 0; i < size; ++i) {
		ss << array[i];
		if (i < size - 1)
			ss << " ";
	}
	return ss.str();
}

/**
 * @brief Вставка элемента в заданную позицию
 * @param index место для вставки
 * @param element значение
 */
void vector::push(const size_t index, const int element) {
	size_t insertIndex = (index > size) ? size : index;
	int* newArray = new int[size + 1];
	for (size_t i = 0, j = 0; i < size + 1; ++i) {
		if (i == insertIndex)
			newArray[i] = element;
		else newArray[i] = array[j++];
	}
	delete[] array;
	array = newArray;
	size++;
}

/**
 * @brief Удаление элемента по индексу
 * @param index позиция удаляемого элемента
 */
void vector::pop(const size_t index) {
	if (index >= size)
		return;
	int* newArray = (size > 1) ? new int[size - 1] : nullptr;
	for (size_t i = 0, j = 0; i < size; ++i) {
		if (i == index)
			continue;
		newArray[j++] = array[i];
	}
	delete[] array;
	array = newArray;
	size--;
}

/**
 * @brief Замена элемента по индексу
 * @param index позиция элемента
 * @param element новое значение
 */
void vector::replace(const size_t index, const int element) {
	if (index < size)
		array[index] = element;
}

/**
 * @brief Доступ к элементу по индексу
 * @param index позиция элемента
 * @return ссылка на элемент
 * @throws out_of_range если индекс выходит за границы
 */
int& vector::operator[](const size_t index) {
	if (index >= size) {
		throw out_of_range("Нет такого элемента в массиве.");
	}
	return array[index];
}

/**
 * @brief Доступ к элементу по индексу (только чтение)
 * @param index позиция элемента
 * @return константная ссылка на элемент
 * @throws out_of_range если индекс выходит за границы
 */
const int& vector::operator[](const size_t index) const {
	if (index >= size) {
		throw out_of_range("Нет такого элемента в массиве.");
	}
	return array[index];
}

/**
 * @brief Оператор присваивания копированием
 * @param other массив-источник
 * @return ссылка на текущий объект
 */
vector& vector::operator=(const vector& other) {
	if (this != &other) {
		delete[] array;
		size = other.size;
		array = (size > 0) ? new int[size] : nullptr;
		for (size_t i = 0; i < size; ++i)
			array[i] = other.array[i];
	}
	return *this;
}

/**
 * @brief Оператор присваивания перемещением
 * @param other массив-источник
 * @return ссылка на текущий объект
 */
vector& vector::operator=(vector&& other) {
	if (this != &other) {
		delete[] array;
		size = other.size;
		array = other.array;

		other.size = 0;
		other.array = nullptr;
	}
	return *this;
}

/**
 * @brief Сравнение на равенство
 * @param other массив для сравнения
 * @return true если все элементы совпадают
 */
bool vector::operator==(const vector& other) const {
	if (size != other.size)
		return false;
	for (size_t i = 0; i < size; ++i)
		if (array[i] != other.array[i])
			return false;
	return true;
}

/**
 * @brief Сравнение на неравенство
 * @param other массив для сравнения
 * @return true если массивы отличаются
 */
bool vector::operator!=(const vector& other) const {
	return !(*this == other);
}

/**
 * @brief Вывод массива в поток
 * @param os поток вывода
 * @param vec выводимый массив
 * @return поток вывода
 */
ostream& operator<<(ostream& os, const vector& vec) {
	os << vec.toString();
	return os;
}

/**
 * @brief Ввод значения из потока с добавлением в массив
 * @param is входной поток
 * @param vec массив для добавления
 * @return входной поток
 */
istream& operator>>(istream& is, vector& vec) {
	int val = 0;
	if (is >> val) {
		vec.push(vec.size, val);
	}
	return is;
}
