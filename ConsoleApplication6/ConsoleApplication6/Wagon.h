// Wagon.h
#ifndef WAGON_H
#define WAGON_H

// ���� �������
enum WagonType {
    TYPE_A,
    TYPE_B
};

// ����� ��� ������������� ������
class Wagon {
public:
    Wagon(WagonType t);

    WagonType getType() const;

private:
    WagonType type;
};

#endif // WAGON_H
