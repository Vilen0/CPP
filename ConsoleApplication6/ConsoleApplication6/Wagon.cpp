// Wagon.cpp
#include "Wagon.h"

Wagon::Wagon(WagonType t) : type(t) {}

WagonType Wagon::getType() const {
    return type;
}
