#include "Cell.h"
#include "Event.h"

// Конструктор. Устанавливает параметры проходимости и событие для клетки
Cell::Cell(bool passable, Event* event) : isPassable(passable), event(event) {}

// Деструктор. Удаляет событие, связанное с клеткой, если оно существует
Cell::~Cell() {
    delete event;
}

// Возвращает, является ли клетка проходимой
bool Cell::getPassable() const {
    return isPassable;
}

// Устанавливает, является ли клетка проходимой
void Cell::setPassable(bool passable) {
    isPassable = passable;
}

// Возвращает указатель на событие, связанное с клеткой
Event* Cell::getEvent() const {
    return event;
}

// Устанавливает событие для клетки. Освобождает предыдущее событие
void Cell::setEvent(Event* event) {
    delete this->event; // Удаляем предыдущее событие
    this->event = event; // Устанавливаем новое событие
}
