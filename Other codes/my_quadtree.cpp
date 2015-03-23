#include<iostream>
#include<stdio.h>
#include<math.h>
#include<complex.h>


class Quadtree
{
Node *root;
Node *buildQuadtree(Grid &G,int m.int d,int level,int,int,int,int);
Rectangle domain;
public:
Quadtree(Grid &G,int m,int d);
~Quadtree();
List<Poiint*> *rangeQuery(Rectangle &range)
};

class Node
{
private:
Node *children[4];
List<Point*> *pts;
int size;
};

typedef struct Rectangle
{int x,y;
int width,height;

}Rectangle;

class Grid
{
int m;
double cellsize;

};

Quadtree::Quadtree(Grid &G ,int m,int d)
{
root = buildQuadtree(G,m,d,0,0,G.m-1,0,G.m-1);
domain = Rectangle(Point(0,0),Point(G.m*G.cellsize,G.m*G.cellsize));


}

Quadtree *Quadtree::buildQuadtree(Grid &G,int m,int d,int level,int imin,int imax,int jmin,int jmax)
{

}

Quadtree::~Quadtree()
{
delete root;
}

Quadtree::Quadtree(List<Point*> *)
