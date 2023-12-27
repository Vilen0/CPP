// Wagon.h
#ifndef WAGON_H
#define WAGON_H

// Типы вагонов
enum WagonType {
    TYPE_A,
    TYPE_B
};

// Класс для представления вагона
class Wagon {
public:
    Wagon(WagonType t);

    WagonType getType() const;

private:
    WagonType type;
};

#endif // WAGON_H
