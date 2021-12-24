#include "convex_hull.h"

#include <algorithm>

std::vector<Point> convex_hull(std::vector<Point>& points){
    std::vector<Point> convex_hull;

    std::sort(points.begin(), points.end(), [](const auto& p1, const auto& p2){
        return p1.x < p2.x;
    });

    // start with point with min x
    std::size_t prev_idx = 0;
    std::size_t idx = 0;

    // cur point + next point should be most counterclockwised oriented line segment relative to all other points
    do{
        // add next found point in hull
        convex_hull.push_back(points[idx]);

        // set prev included point idx
        prev_idx = idx;

        // set idx to next candid point idx
        idx = (idx + 1) % points.size();
        for(std::size_t i = 0; i < points.size(); i++){
            // if i th point constructs more counterclockwised segment than candidate point, update next point as i th point
            if(get_orientation({points[prev_idx], points[i]}, points[idx]) == Orientation::Orientation_Counter_clockwise){
                idx = i;
            }
        }
    }while(idx != 0);

    return convex_hull;
}
