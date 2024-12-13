// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

// Класс игрока, содержит характеристики игрока, такие как здоровье, очки и положение.
class Player {
private:
    int health; // Здоровье игрока
    int score;  // Очки игрока
    int x, y;   // Позиция игрока на игровом поле

public:
    // Конструктор с параметрами по умолчанию для нового игрока
    Player(int health = 100, int score = 0, int x = 0, int y = 0);

    // Геттеры для получения текущих характеристик
    int getHealth() const;
    int getScore() const;

    // Сеттеры для изменения характеристик с проверкой значений
    void setHealth(int health);
    void setScore(int score);

    // Методы для работы с позицией игрока
    void setPosition(int x, int y);
    void getPosition(int &x, int &y) const;

    // Вывод текущего состояния игрока
    void printStatus() const;
};

#endif // PLAYER_H