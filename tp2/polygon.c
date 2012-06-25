#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "polygon.h"

Point* CreatePoint(float x, float y, int id)
{
    Point* point;
    point = (Point*) malloc(sizeof(Point));   
    point->x_ = x;
    point->y_ = y;
    point->id_= id;
    return point;
}

Polygon* CreatePolygon(int size){
    Polygon* polygon;
    polygon = (Polygon*) malloc(sizeof(Polygon));
    polygon->size_=size;
    return polygon;
}

void InsertPointInPolygon(Polygon* polygon, Point* point, int index){
    polygon->polygon_[index] = point;
}

Point* getIndexPoint(Polygon* polygon, int id){
    Point* point;
    int index = id-1;
    point = polygon->polygon_[index]; 
    return point;
}

void dumpPoint(Polygon* polygon, int id){
    Point* point;
    //point = polygon->polygon_[id-1];
    point = getIndexPoint(polygon, id);
    float x = point->x_;
    float y = point->y_;
    printf("Point id %d = (%f,%f)",id,x,y);
}

void dumpPolygon(Polygon* polygon, int max){
    int i = 0;
    printf("Polygon : \n");
    for(i=0; i<max; i++){
        dumpPoint(polygon, i+1);
        printf("\n");
    }
}

void desalloc(Polygon* polygon){
    free(polygon);
}

Line* CreateLine(Polygon* polygon, Point* p1, Point* p2){
    Line* line;
    line = (Line*) malloc(sizeof(Line));
    p1 = line->p1_;
    p2 = line->p2_;
    return line;
    
}


void Triangularizacao(Polygon* polygon){
    int size = polygon->size_;
    int max = size*(size - 2); 
    int i;
    Line* diagonais;    
    diagonais = (Line*) malloc(sizeof(Line)*max);
    for (i=0; i<max; i++){
        int j = i+1;
        diagonais[i] = CreateLine(polygon, polygon->polygon_[j-1],
                                   polygon->polygon_[j+1]);
    }
}

/*
int clockwise(Point* p1, Point* p2, Point* p3){
    int dx1, dx2, dy1, dy2;
    dx1 = p1*x - p0*x; dy1 = p1*y - p0*y;
    dx2 = p2*x - p0*x; dy2 = p2*y - p0*y;
    if (dx1*dy2 > dy1*dy2) return +1;
    if (dx1*dy2 < dy1*dy2) return -1;
    if (dx1*dx2 < 0) || (dy1*dy2) < 0) return -1;
    if ((dx1*dx1 + dy1*dy1) < ( dx2*dx2 + dy2*dy2)) return +1;
    return 0;
}
*/

/*int intersect ()
*/






/*
void desalloc(Line* line){
    free(line);
}*/
