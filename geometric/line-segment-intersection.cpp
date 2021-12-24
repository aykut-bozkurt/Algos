#include "line-segment-intersection.h"

#include <algorithm>

bool in_segment(Point p, LineSegment l){
    if (p.x <= std::max(l.p1.x, l.p2.x) && p.x >= std::min(l.p1.x, l.p2.x) &&
        p.y <= std::max(l.p1.y, l.p2.y) && p.y >= std::min(l.p1.y, l.p2.y))
        return true;

    return false;
}

Orientation get_orientation(LineSegment l, Point p3){
    // m2 - m1 == 0 => collinear
    // m2 - m1 > 0 => counterclockwise
    // m2 - m1 < 0 => clockwise
    int theta = (p3.y - l.p2.y) * (l.p2.x - l.p1.x) - (l.p2.y - l.p1.y) * (p3.x - l.p2.x);
    if(theta == 0){
        return Orientation::Orientation_Collinear;
    }
    else if(theta > 0){
        return Orientation::Orientation_Counter_clockwise;
    }
    else{
        return Orientation::Orientation_Clockwise;
    }
}

bool line_segments_intersect(LineSegment l1, LineSegment l2){
    auto o1 = get_orientation(l1, l2.p1);
    auto o2 = get_orientation(l1, l2.p2);
    auto o3 = get_orientation(l2, l1.p1);
    auto o4 = get_orientation(l2, l1.p2);

    if(o1 != o2 && o3 != o4){
        return true;
    }

    if(o1 == Orientation::Orientation_Collinear && in_segment(l2.p1, l1)){
        return true;
    }
    else if(o2 == Orientation::Orientation_Collinear && in_segment(l2.p2, l1)){
        return true;
    }
    else if(o3 == Orientation::Orientation_Collinear && in_segment(l1.p1, l2)){
        return true;
    }
    else if(o4 == Orientation::Orientation_Collinear && in_segment(l1.p2, l2)){
        return true;
    }

    return false;
}
