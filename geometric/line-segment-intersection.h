#pragma once

// orientation of triplet points
enum class Orientation{
    Orientation_Clockwise = 0,
    Orientation_Counter_clockwise = 1,
    Orientation_Collinear = 2,
};

struct Point{
    int x;
    int y;
};

struct LineSegment{
    Point p1;
    Point p2;
};

bool in_segment(Point p, LineSegment l);
Orientation get_orientation(LineSegment l, Point p3);
bool line_segments_intersect(LineSegment l1, LineSegment l2);
