#include "Player.h"
#include "PlayerController.h"
#include "GameField.h"
#include <iostream>

int main() {
    // Создание игрока с начальными характеристиками
    Player player;
    player.printStatus(); // Вывод начального состояния игрока

    // Создание игрового поля размером 5x5
    GameField field(5, 5);

    // Генерация первого уровня с предопределёнными событиями
    field.generateLevel1();

    // Создание контроллера для управления игроком
    PlayerController controller(player, field);

    // Пример перемещения игрока, чтобы активировать все события
    std::cout << "\n";

    //RED ARROW
    std::cout << "Direction: DOWN\n";
    controller.move(DOWN);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: DOWN\n";
    controller.move(DOWN);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: DOWN\n";
    controller.move(DOWN);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    //BLUE ARROW
    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: DOWN\n";
    controller.move(DOWN);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: DOWN\n";
    controller.move(DOWN);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: RIGHT\n";
    controller.move(RIGHT);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: DOWN\n";
    controller.move(DOWN);
    player.printStatus();
    std::cout << "\n";

    std::cout << "Direction: DOWN\n";
    controller.move(DOWN);
    player.printStatus();
    std::cout << "\n";



    return 0;
}
