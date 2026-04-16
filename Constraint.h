#pragma once
#include <iostream>
#include <string>
#include "Piquet.h"

using namespace std;

/**
 * @brief Абстрактный базовый класс Constraint (ограничение)
 *
 * Представляет собой абстрактное ограничение на железнодорожном пути.
 * Ограничение задано значением и координатами (в пикетах) начала и конца.
 */
class Constraint
{
public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Constraint() = default;

    /**
     * @brief Чисто виртуальный метод сериализации в строку
     * @return сериализованная строка
     */
    virtual string toString() const = 0;

    /**
     * @brief Чисто виртуальный метод чтения из потока
     * @param is входной поток
     */
    virtual void readFromStream(istream& is) = 0;

    /**
     * @brief Статический метод чтения из стандартного потока ввода
     * @return указатель на объект Constraint (конкретного типа)
     */
    static Constraint* readFromStdIn();

    /**
     * @brief Оператор присваивания (копирование)
     * @param other объект для копирования
     * @return ссылка на текущий объект
     */
    Constraint& operator=(const Constraint& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other объект для перемещения
     * @return ссылка на текущий объект
     */
    Constraint& operator=(Constraint&& other) noexcept;

    /**
     * @brief Перегрузка оператора вывода
     * @param os поток вывода
     * @param c объект класса Constraint
     * @return переопределённый поток вывода
     */
    friend ostream& operator<<(ostream& os, const Constraint& c);
};
