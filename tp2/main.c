#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polygon.h"


void ReadFromFile(FILE* input){
    int instances, vertices;
    int i,j,nx,dx, ny, dy, id;
    float x, y;
    char auxx, auxy;
    fscanf(input,"%d", &instances);
    fscanf(input,"%d", &vertices);
printf("numvertices = %d \n", vertices);
    //reading each instance
    for(i=0; i<instances; i++){
        Polygon* polygon = CreatePolygon();
        polygon->size_=vertices;
printf("instance = %d \n", i+1);
        //reading each vertice
        for(j=0; j<vertices; j++){
            Point* point;
            fscanf(input,"%d%c%d%d%c%d",&nx, &auxx, &dx, &ny, &auxy, &dy);
printf("numeros  %d / %d, %d / %d \n",nx,dx,ny,dy);
            id = j+1;
            x = nx/(dx);
            y = ny/(dy);
            point = CreatePoint(x, y, id);
printf("id  %d => x = %f,y = %f \n",id,x,y);
            InsertPointInPolygon(polygon, point, j);
dumpPoint(polygon, id);
        }
dumpPolygon(polygon,vertices);
    }
    fclose(input);
}


int main (int argc, char* argv[]) {
   
    if (argc<2){
        puts("O NOME DO ARQUIVO NAO FOI ESPECIFICADO");
        return 0;
    } else {
        FILE* input;
        input = fopen(argv[1], "r");
        if (input == NULL){
            puts("O ARQUIVO NAO FOI ABERTO");
            return 0;
        } else {
            ReadFromFile(input);
        }
        return 0;
    }
}
