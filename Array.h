#pragma once
#include <iostream>
#include <initializer_list>
#include <string>

using namespace std;

/**
 * @brief Класс вектор(массив)
 **/
class vector {
private:
	/**
	 * @brief Данные в векторе(массиве)
	 **/
	int* array;

	/**
	 * @brief Длина вектора (размер массива)
	 **/
	size_t size;
public:
	/**
	 * @brief Конструктор пустого вектора
	 */
	vector();

	/**
	 * @brief Конструктор заполнения массива через 'initializer_list'
	 * @param list элементы массива
	 */
	vector(const initializer_list<int> list);

	/**
	 * @brief Конструктор копирования вектора
	 * @param other другой вектор
	 */
	vector(const vector& other);

	/**
	* @brief Конструктор перемещения
	* @param other - другой вектор
	*/
	vector(vector&& other);

	/**
	 * @brief Деструктор
	 */
	~vector();

	/**
	 * @brief Вывести содержимое вектора в строку
	 * @return строку с данными вектора
	 */
	string toString() const;

	/**
	 * @brief Получение размера массива
	 * @return полученный размер
	 */
	size_t getSize() const;

	/**
	 * @brief Добавление нового элемента по индексу с выделением памяти
	 * @param index номер(индекс) элемента
	 * @param element сам элемент
	 */
	void push(const size_t index, const int element);

	/**
	 * @brief Удаление элемента по индексу с освобождением памяти
	 * @param index индекс элемента
	 */
	void pop(const size_t index);

	/**
	 * @brief Замена элемента по индексу
	 * @param index индекс элемента
	 * @param element новый элемент
	 */
	void replace(const size_t index, const int element);

	/**
	 * @brief Оператор присваивания копирования
	 * @param other другой vector
	 * @return новый скопированный массив
	 */
	vector& operator=(const vector& other);

	/**
	* @brief Оператор присваивания перемещением
	* @param other - другой вектор
	* @return указатель на текущий объект
	*/
	vector& operator=(vector&& other);

	/**
	 * @brief Переопределение оператора сравнения(равенство)
	 * @param other объект класса vector
	 * @return true, если равенство выполнено иначе false
	 */
	bool operator==(const vector& other) const;

	/**
	 * @brief Переопределение оператора сравнения(неравенство)
	 * @param other объект класса vector
	 * @return true, если равенство не выполнено, иначе false
	 */
	bool operator!=(const vector& other) const;

	/**
	 * @brief Проверяет, не пуст ли массив
	 * @return true, если пуст
	 */
	bool isEmpty() const;

	/**
	 * @brief Получить элемент по индексу
	 * @param index индекс элемента
	 * @return элемент по индексу
	 */
	int& operator[](size_t index);

	/**
	 * @brief Получить элемент по индексу(только чтение)
	 * @param index индекс элемента
	 * @return элемент по индексу
	 */
	const int& operator[] (const size_t index) const;

	/**
	 * @brief Переопределение оператора вывода
	 * @param os поток вывода
	 * @param vec объект класса vector
	 * @return Переопределённый поток вывода
	 */
	friend ostream& operator<<(ostream& os, const vector& vec);

	/**
	 * @brief Переопределение оператора ввода
	 * @param is входной поток
	 * @param vec объект класса vector
	 * @return входной поток
	 */
	friend istream& operator>>(istream& is, vector& vec);
};
