// RailwayStation.h
#ifndef RAILWAYSTATION_H
#define RAILWAYSTATION_H

#include <stack>
#include "Wagon.h"

// ����� ��� ������������� ��������������� �������
class RailwayStation {
public:
    void processWagons();

    void setInputTrack(std::stack<Wagon>& input);



    void printOutputTracks() const;

private:
    std::stack<Wagon> inputTrack; // �������� std::
    std::stack<Wagon> outputTrackA; // �������� std::
    std::stack<Wagon> outputTrackB; // �������� std::
};

#endif // RAILWAYSTATION_H
