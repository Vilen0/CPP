// RailwayStation.h
#ifndef RAILWAYSTATION_H
#define RAILWAYSTATION_H

#include <stack>
#include "Wagon.h"

// Класс для представления железнодорожной станции
class RailwayStation {
public:
    void processWagons();

    void setInputTrack(std::stack<Wagon>& input);



    void printOutputTracks() const;

private:
    std::stack<Wagon> inputTrack; // Добавьте std::
    std::stack<Wagon> outputTrackA; // Добавьте std::
    std::stack<Wagon> outputTrackB; // Добавьте std::
};

#endif // RAILWAYSTATION_H
