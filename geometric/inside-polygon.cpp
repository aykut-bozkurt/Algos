#include "inside-polygon.h"

#include <cinttypes>

bool inside_polygon(Point p, std::vector<Point> polygon){
    if(polygon.size() < 3){
        return false;
    }

    Point extreme_p = {INT32_MAX, p.y};
    LineSegment extreme_l = {p, extreme_p};

    unsigned short intersection_count = 0;
    for(std::size_t i = 0; i < polygon.size(); i++){
        LineSegment polygon_edge;
        if(i == polygon.size()-1){
            polygon_edge = {polygon[i], polygon[0]};
        }
        else{
            polygon_edge = {polygon[i], polygon[i+1]};
        }

        if(line_segments_intersect(polygon_edge, extreme_l)){
            if(get_orientation(polygon_edge, p) == Orientation::Orientation_Collinear && in_segment(p, polygon_edge)){
                return true;
            }

            intersection_count++;
        }
    }

    // if odd lines are intersected, then point is inside polygon; else outside if point is not on any edge
    return intersection_count % 2 == 1;
}
