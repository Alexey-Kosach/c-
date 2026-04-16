#pragma once
#include "Constraint.h"

using namespace std;

/**
 * @brief Класс Slope (уклон)
 *
 * Класс представляет ограничение в виде уклона железнодорожного пути.
 * Уклон задаётся значением в промилле (не более 50) и координатами
 * (в пикетах) начала и конца уклона.
 * Наследуется от абстрактного класса Constraint.
 */
class Slope : public Constraint
{
private:
    double value;      ///< Значение уклона в промилле (0-50)
    Piquet start;      ///< Пикет начала уклона
    Piquet end;        ///< Пикет конца уклона

public:
    /**
     * @brief Конструктор по умолчанию
     * @param value значение уклона (по умолчанию 0.0)
     * @param start пикет начала (по умолчанию Piquet())
     * @param end пикет конца (по умолчанию Piquet())
     */
    Slope(double value = 0.0, const Piquet& start = Piquet(), const Piquet& end = Piquet());

    /**
     * @brief Конструктор копирования
     * @param other объект для копирования
     */
    Slope(const Slope& other);

    /**
     * @brief Деструктор по умолчанию
     */
    ~Slope() = default;

    /**
     * @brief Конструктор перемещения
     * @param other объект для перемещения
     */
    Slope(Slope&& other) noexcept;

    /**
     * @brief Оператор присваивания (копирование)
     * @param other объект для копирования
     * @return ссылка на текущий объект
     */
    Slope& operator=(const Slope& other);

    /**
     * @brief Оператор присваивания (перемещение)
     * @param other объект для перемещения
     * @return ссылка на текущий объект
     */
    Slope& operator=(Slope&& other) noexcept;

    /**
     * @brief Геттер значения уклона
     * @return значение уклона в промилле
     */
    double getValue() const;

    /**
     * @brief Геттер пикета начала
     * @return пикет начала уклона
     */
    Piquet getStart() const;

    /**
     * @brief Геттер пикета конца
     * @return пикет конца уклона
     */
    Piquet getEnd() const;

    /**
     * @brief Сеттер значения уклона с валидацией
     * @param value новое значение уклона (0-50)
     * @throw std::invalid_argument если значение вне диапазона
     */
    void setValue(double value);

    /**
     * @brief Сеттер пикета начала
     * @param start новый пикет начала
     */
    void setStart(const Piquet& start);

    /**
     * @brief Сеттер пикета конца
     * @param end новый пикет конца
     */
    void setEnd(const Piquet& end);

    /**
     * @brief Проверка валидности уклона
     * @return true если значение в диапазоне 0-50, иначе false
     */
    bool isValid() const;

    /**
     * @brief Метод сериализации в строку (переопределение)
     * @return строка в формате "Уклон: X‰, от ПК A+B до ПК C+D"
     */
    string toString() const override;

    /**
     * @brief Метод чтения из потока (переопределение)
     * @param is входной поток
     */
    void readFromStream(istream& is) override;

    /**
     * @brief Оператор сравнения (равенство)
     * @param other объект для сравнения
     * @return true если равны, иначе false
     */
    bool operator==(const Slope& other) const;
};
