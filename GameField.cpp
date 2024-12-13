// GameField.cpp
#include "GameField.h"
#include "Event.h"
#include <stdexcept>
#include <iostream>

// Конструктор инициализации игрового поля с заданной шириной и высотой
GameField::GameField(int width, int height) : width(width), height(height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive.");
    }
    cells = new Cell *[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
    }
}

// Деструктор освобождает память, выделенную для массива клеток
GameField::~GameField() {
    for (int i = 0; i < height; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

// Конструктор копирования создаёт глубокую копию объекта
GameField::GameField(const GameField &other) : width(other.width), height(other.height) {
    cells = new Cell *[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
        for (int j = 0; j < width; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

// Оператор присваивания с глубоким копированием
GameField &GameField::operator=(const GameField &other) {
    if (this == &other) return *this;

    for (int i = 0; i < height; ++i) {
        delete[] cells[i];
    }
    delete[] cells;

    width = other.width;
    height = other.height;

    cells = new Cell *[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
        for (int j = 0; j < width; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }

    return *this;
}

// Проверка, проходима ли клетка
bool GameField::isCellPassable(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        std::cout << "Cell at (" << x << ", " << y << ") is out of bounds and not passable.\n";
        return false; // Клетка за пределами поля считается непроходимой
    }
    return cells[y][x].getPassable();
}

// Установка проходимости клетки
void GameField::setCellPassable(int x, int y, bool passable) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        std::cout << "Cannot set passability for cell at (" << x << ", " << y << ") - out of bounds.\n";
        return; // Игнорируем установку для клетки за пределами поля
    }
    cells[y][x].setPassable(passable);
}

// Получение события на клетке
Event* GameField::getEventAt(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        std::cout << "Cell at (" << x << ", " << y << ") is out of bounds, no event exists.\n";
        return nullptr; // Для клеток за пределами поля события нет
    }
    return cells[y][x].getEvent();
}

// Установка события на клетке
void GameField::setEventAt(int x, int y, Event* event) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        std::cout << "Cannot set event for cell at (" << x << ", " << y << ") - out of bounds.\n";
        return; // Игнорируем установку для клетки за пределами поля
    }
    cells[y][x].setEvent(event);
}

// Генерация уровня 1 с предопределёнными событиями и проходимостью
void GameField::generateLevel1() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x].setPassable(true);
        }
    }
    setEventAt(1, 1, new PositiveEvent());
    setEventAt(2, 2, new NegativeEvent());
    setEventAt(3, 3, new TeleportEvent(0, 0));
    setEventAt(4, 4, new ScoreEvent(50)); // Новое событие начисления очков
}

// Генерация уровня 2 с предопределёнными событиями
void GameField::generateLevel2() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x].setPassable(true);
        }
    }
    setEventAt(0, 0, new PositiveEvent());
    setEventAt(4, 4, new TeleportEvent(0, 0));
    setEventAt(2, 3, new ScoreEvent(100)); // Новое событие начисления очков
}