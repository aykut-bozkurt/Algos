#include "is-square.h"

#include <cmath>

static float distance(Point p1, Point p2){
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

bool is_square(Point p1, Point p2, Point p3, Point p4){
    auto epsilon = 0.0001f;
    auto dist1 = distance(p1, p2);
    auto dist2 = distance(p1, p3);
    auto dist3 = distance(p1, p4);

    if(dist1 == 0 || dist2 == 0 || dist3 == 0){
        return false;
    }
    else if(dist1 == dist2 && std::abs(dist3 - std::sqrt(2) * dist1) <= epsilon){
        return true;
    }
    else if(dist1 == dist3 && std::abs(dist2 - std::sqrt(2) * dist1) <= epsilon){
        return true;
    }
    else if(dist2 == dist3 && std::abs(dist1 - std::sqrt(2) * dist2) <= epsilon){
        return true;
    }
    else{
        return false;
    }
}
