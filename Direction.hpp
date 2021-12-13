#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include<iostream>
#include<ostream>

using namespace std;

enum class Direction {
    est,
    ouest,
    nord,
    sud,
    rester
};

ostream& operator<<(ostream&, const Direction&);

#endif