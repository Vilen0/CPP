#include "Test.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool Test::runTests() {
    
    return testInputFromKeyboard();
}


bool Test::testInputFromKeyboard() {
    stringstream inputStream("5\n1\n2\n1\n2\n1\n");

    streambuf* oldCin = cin.rdbuf(inputStream.rdbuf());

    streambuf* oldCout = cout.rdbuf(nullptr);

    TrainStation station;
    station.inputTrainComposition();

    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);

    size_t mainTrackSize = station.getMainTrackSize();
    return (mainTrackSize == 5);
}
