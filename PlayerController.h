#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Player.h"

// Предварительное объявление класса GameField, чтобы избежать циклических зависимостей
class GameField;

// Перечисление возможных направлений для движения игрока
enum Direction {
    UP,    // Вверх
    DOWN,  // Вниз
    LEFT,  // Влево
    RIGHT  // Вправо
};

// Класс PlayerController отвечает за управление движением игрока и взаимодействие с игровым полем
class PlayerController {
private:
    Player &player; // Ссылка на объект игрока
    GameField &field; // Ссылка на объект игрового поля

public:
    // Конструктор класса, принимает ссылки на игрока и игровое поле
    PlayerController(Player &player, GameField &field);

    // Метод для перемещения игрока в заданном направлении
    void move(Direction direction);
};

#endif // PLAYERCONTROLLER_H
