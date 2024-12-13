// Player.cpp
#include "Player.h"

// Конструктор, инициализирующий характеристики игрока
Player::Player(int health, int score, int x, int y) : health(health), score(score), x(x), y(y) {
    if (health < 0 || health > 100) {
        throw std::invalid_argument("Initial health must be in range [0, 100].");
    }
}


// Геттер для здоровья игрока
int Player::getHealth() const {
    return health;
}

// Геттер для очков игрока
int Player::getScore() const {
    return score;
}

// Сеттер для здоровья игрока с проверкой корректности
void Player::setHealth(int health) {
    if (health >= 0 && health <= 100) {
        this->health = health;
    } else {
        std::cerr << "Error: Health must be in range [0, 100].\n";
    }
}

// Сеттер для очков игрока (очков не может быть меньше нуля)
void Player::setScore(int score) {
    if (score >= 0) {
        this->score = score;
    } else {
        std::cerr << "Error: Score cannot be negative.\n";
    }
}

// Установка новой позиции игрока
void Player::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

// Получение текущей позиции игрока
void Player::getPosition(int &x, int &y) const {
    x = this->x;
    y = this->y;
}

// Вывод текущего состояния игрока (здоровье, очки и позиция)
void Player::printStatus() const {
    std::cout << "Health: " << health << ", Score: " << score << ", Position: (" << x << ", " << y << ")\n";
}