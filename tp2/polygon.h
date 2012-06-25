#ifndef _polygon_h_
#define _polygon_h_

typedef struct point {
    float x_;
    float y_;
    int id_ ;
} Point;

typedef struct line {
    Point* p1_;
    Point* p2_;
} Line;

typedef struct polygon {
    Point* polygon_[1000];
    int size_;
    //struct point* polygon_[1000];
} Polygon;

Point* CreatePoint(float x, float y, int id);

Polygon* CreatePolygon();

void InsertPointInPolygon(Polygon* polygon, Point* point, int id);

Point* getIndexPoint(Polygon* polygon, int id);

void dumpPoint(Polygon* polygon, int id);

void dumpPolygon(Polygon* polygon, int max);


#endif

