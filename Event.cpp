#include "Event.h"
#include "Player.h"

// Реализация PositiveEvent: увеличивает здоровье игрока на 10
void PositiveEvent::trigger(Player& player) {
    int newHealth = player.getHealth() + 10;
    if (newHealth > 100) {
        newHealth = 100; // Ограничиваем здоровье максимум 100
    }
    player.setHealth(newHealth);
    std::cout << "PositiveEvent triggered: Health increased to " << newHealth << ".\n";
}


// Реализация NegativeEvent: уменьшает здоровье игрока на 10
void NegativeEvent::trigger(Player& player) {
    int newHealth = player.getHealth() - 10;
    if (newHealth < 0) {
        newHealth = 0; // Ограничиваем здоровье минимум 0
    }
    player.setHealth(newHealth);
    std::cout << "NegativeEvent triggered: Health decreased to " << newHealth << ".\n";
}


// Конструктор TeleportEvent: задаёт координаты для телепортации
TeleportEvent::TeleportEvent(int x, int y) : newX(x), newY(y) {}

// Реализация TeleportEvent: изменяет позицию игрока
void TeleportEvent::trigger(Player& player) {
    player.setPosition(newX, newY); // Перемещаем игрока
    std::cout << "TeleportEvent triggered: Player teleported to (" 
              << newX << ", " << newY << ").\n";
}

ScoreEvent::ScoreEvent(int points) : points(points) {}

void ScoreEvent::trigger(Player& player) {
    player.setScore(player.getScore() + points); // Увеличиваем очки игрока
    std::cout << "ScoreEvent triggered: " << points << " points added. Total Score: " 
              << player.getScore() << ".\n";
}
