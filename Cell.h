#ifndef CELL_H
#define CELL_H

class Event; // Предварительное объявление класса Event, чтобы избежать циклической зависимости

// Класс Cell представляет клетку игрового поля
class Cell {
private:
    bool isPassable; // Указывает, является ли клетка проходимой
    Event* event;    // Указатель на событие, связанное с клеткой (может быть nullptr)

public:
    // Конструктор по умолчанию. Принимает параметр проходимости и событие (по умолчанию nullptr)
    Cell(bool passable = true, Event* event = nullptr);

    // Деструктор. Освобождает память, занятую событием
    ~Cell();

    // Возвращает, является ли клетка проходимой
    bool getPassable() const;

    // Устанавливает, является ли клетка проходимой
    void setPassable(bool passable);

    // Возвращает указатель на событие, связанное с клеткой
    Event* getEvent() const;

    // Устанавливает событие для клетки. Предыдущее событие удаляется
    void setEvent(Event* event);
};

#endif // CELL_H
