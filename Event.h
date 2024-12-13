#ifndef EVENT_H
#define EVENT_H

class Player; // Предварительное объявление класса Player

// Абстрактный базовый класс Event для всех типов событий
class Event {
public:
    // Чисто виртуальный метод, который будет реализован в наследниках
    virtual void trigger(Player& player) = 0;

    // Виртуальный деструктор для корректного удаления наследников
    virtual ~Event() = default;
};

// Класс PositiveEvent — положительное событие, увеличивает здоровье игрока
class PositiveEvent : public Event {
public:
    void trigger(Player& player) override; // Реализация изменения здоровья
};

// Класс NegativeEvent — отрицательное событие, уменьшает здоровье игрока
class NegativeEvent : public Event {
public:
    void trigger(Player& player) override; // Реализация изменения здоровья
};

class ScoreEvent : public Event {
private:
    int points; // Очки, которые добавляются игроку
public:
    ScoreEvent(int points);
    void trigger(Player& player) override;
};

// Класс TeleportEvent — телепортирует игрока на новую позицию
class TeleportEvent : public Event {
private:
    int newX; // Новая координата X
    int newY; // Новая координата Y

public:
    TeleportEvent(int x, int y);          // Конструктор для задания координат
    void trigger(Player& player) override; // Реализация изменения позиции
};

#endif // EVENT_H
