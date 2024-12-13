// GameField.h
#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Cell.h"

// Класс GameField представляет игровое поле как сетку из клеток
class GameField {
private:
    int width;  // Ширина поля
    int height; // Высота поля
    Cell **cells; // Двумерный массив клеток

public:
    // Конструктор по умолчанию и с параметрами
    GameField(int width = 10, int height = 10);
    
    // Деструктор для освобождения памяти
    ~GameField();

    // Конструктор копирования
    GameField(const GameField &other);

    // Оператор присваивания
    GameField &operator=(const GameField &other);

    // Проверка, проходима ли клетка с заданными координатами
    bool isCellPassable(int x, int y) const;

    // Установка проходимости клетки
    void setCellPassable(int x, int y, bool passable);

    // Получение события на клетке
    Event* getEventAt(int x, int y) const;

    // Установка события на клетке
    void setEventAt(int x, int y, Event* event);

    // Генерация уровня 1 с предопределёнными параметрами
    void generateLevel1();

    // Генерация уровня 2 с предопределёнными параметрами
    void generateLevel2();
};

#endif // GAMEFIELD_H
