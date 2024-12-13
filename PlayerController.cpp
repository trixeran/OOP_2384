#include "PlayerController.h"
#include "GameField.h"
#include "Event.h"

// Конструктор инициализирует ссылки на игрока и игровое поле
PlayerController::PlayerController(Player &player, GameField &field) : player(player), field(field) {}

// Метод для перемещения игрока
void PlayerController::move(Direction direction) {
    int x, y;
    player.getPosition(x, y); // Получаем текущую позицию игрока

    // Определяем новую позицию в зависимости от направления
    switch (direction) {
        case UP:
            y -= 1; // Сдвиг вверх
            break;
        case DOWN:
            y += 1; // Сдвиг вниз
            break;
        case LEFT:
            x -= 1; // Сдвиг влево
            break;
        case RIGHT:
            x += 1; // Сдвиг вправо
            break;
    }

    // Проверяем, можно ли пройти на новую клетку
    if (field.isCellPassable(x, y)) {
        player.setPosition(x, y); // Обновляем позицию игрока

        // Проверяем, есть ли событие на новой клетке
        Event* event = field.getEventAt(x, y);
        if (event) {
            event->trigger(player); // Активируем событие, если оно есть
        }
    } else {
        // Если клетка непроходима, выводим сообщение об ошибке
        std::cout << "Cannot move to position (" << x << ", " << y << ") - Cell is not passable.\n";
    }
}
