#include "inside-triangle.h"

#include <cmath>

static float get_triangle_area(Point p1, Point p2, Point p3){
    // area = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1 - y2)]/2
    return std::abs( (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0f );
}

bool inside_triangle(Point p1, Point p2, Point p3, Point p4){
    float tri_area = get_triangle_area(p1,p2,p3);
    float area_total_p = get_triangle_area(p1,p2,p4) + get_triangle_area(p1,p3,p4) + get_triangle_area(p2,p3,p4);
    if(std::abs(area_total_p - tri_area) <= 0.0001){
        return true;
    }
    else{
        return false;
    }
}
