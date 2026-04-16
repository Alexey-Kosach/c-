#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

/**
 * @brief Класс Piquet (пикет)
 *
 * Пикет — единица измерения расстояния на железной дороге.
 * Состоит из номера пикета (целое число) и смещения (дробное число).
 * Пикеты могут быть стандартными (длина 100 м) или немерными.
 */
class Piquet
{
private:
    int number;      ///< Номер пикета
    double shift;    ///< Смещение в метрах
    bool isStandard; ///< Флаг стандартности (true - стандартный, false - немерный)

public:
    /**
     * @brief Конструктор по умолчанию
     * @param number номер пикета (по умолчанию 0)
     * @param shift смещение в метрах (по умолчанию 0.0)
     * @param isStandard флаг стандартности (по умолчанию true)
     */
    Piquet(int number = 0, double shift = 0.0, bool isStandard = true);

    /**
     * @brief Конструктор копирования
     * @param other объект для копирования
     */
    Piquet(const Piquet& other);

    /**
     * @brief Деструктор по умолчанию
     */
    ~Piquet() = default;

    /**
     * @brief Конструктор перемещения
     * @param other объект для перемещения
     */
    Piquet(Piquet&& other) noexcept;

    /**
     * @brief Оператор присваивания (копирование)
     * @param other объект для копирования
     * @return ссылка на текущий объект
     */
    Piquet& operator=(const Piquet& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other объект для перемещения
     * @return ссылка на текущий объект
     */
    Piquet& operator=(Piquet&& other) noexcept;

    /**
     * @brief Геттер номера пикета
     * @return номер пикета
     */
    int getNumber() const;

    /**
     * @brief Геттер смещения
     * @return смещение в метрах
     */
    double getShift() const;

    /**
     * @brief Геттер флага стандартности
     * @return true если стандартный, false если немерный
     */
    bool getIsStandard() const;

    /**
     * @brief Преобразование пикета в метры
     * @return расстояние в метрах
     */
    double toMeters() const;

    /**
     * @brief Оператор сравнения (равенство)
     * @param other объект для сравнения
     * @return true если равны, иначе false
     */
    bool operator==(const Piquet& other) const;

    /**
     * @brief Оператор сравнения (неравенство)
     * @param other объект для сравнения
     * @return true если не равны, иначе false
     */
    bool operator!=(const Piquet& other) const;

    /**
     * @brief Оператор сравнения (меньше)
     * @param other объект для сравнения
     * @return true если текущий меньше, иначе false
     */
    bool operator<(const Piquet& other) const;

    /**
     * @brief Оператор сравнения (больше)
     * @param other объект для сравнения
     * @return true если текущий больше, иначе false
     */
    bool operator>(const Piquet& other) const;

    /**
     * @brief Оператор сравнения (меньше или равно)
     * @param other объект для сравнения
     * @return true если текущий меньше или равен, иначе false
     */
    bool operator<=(const Piquet& other) const;

    /**
     * @brief Оператор сравнения (больше или равно)
     * @param other объект для сравнения
     * @return true если текущий больше или равен, иначе false
     */
    bool operator>=(const Piquet& other) const;

    /**
     * @brief Переопределение оператора вывода ("сдвиг влево")
     * @param os поток вывода
     * @param p объект класса Piquet
     * @return переопределённый поток вывода
     */
    friend ostream& operator<<(ostream& os, const Piquet& p);

    /**
     * @brief Переопределение оператора ввода ("сдвиг вправо")
     * @param is входной поток
     * @param p объект класса Piquet
     * @return переопределённый входной поток
     */
    friend istream& operator>>(istream& is, Piquet& p);

    /**
     * @brief Метод сериализации в строку
     * @return строка в формате "ПК Номер+Смещение" или "ПК 0Номер+Смещение"
     */
    string toString() const;
};
