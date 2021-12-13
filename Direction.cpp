#include"Direction.hpp"

ostream& operator<<(ostream& out, const Direction& d){
    switch (d)
    {
    case Direction::est:
        out << "est";
        break;
    case Direction::ouest:
        out << "ouest";
        break;
    case Direction::nord:
        out << "nord";
        break;
    case Direction::sud:
        out << "sud";
        break;
    case Direction::rester:
        out << "ne pas bouger";
        break;
    default:
        out << "je n'aime pas cette direction";
        break;
    }
    return out;
}