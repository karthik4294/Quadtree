#include<iostream>
#include<stdio.h>
#include<complex.h>
#include<math.h>
#include<time.h>
using namespace std;

int w=0;//Variable to store total number of nodes

//General Node definitions
int BLACK = -1;//Node boundary is completely inside the curve
int WHITE = 1;//Node boundary is completely outside the curve
int GREY = 2;//Node boundary intersects with curve
int RED = 0; //Solution Node where function value at all vertices of the Node is lesser than EPS

double EPS = 0.0001;//Epsilon value for the functions
FILE *p = NULL;
int check = 0;//Flag which changes on finding first grey cell during subdivision

int LEVEL;//Depth of subdivision of quadtree


int child_num = 4;//No: of children for each node
int rect_vert = 4;//No: of vertices of each node in rectangular and circular geometry
int tri_vert = 3;//No: of vertices of each node in triangular geometry

//Rectangular Workspace
double XMAX=2;
double YMAX = 2;
double XMIN=-2;
double YMIN = -2;

//Triangular Workspace
double X0 = 0;		double Y0 = 4.098076032;
double X1 = -2.3660253; double Y1 = -1.5;
double X2 = 2.3660253;  double Y2 = -1.5;

//Circular Workspace
double Pi = 2*acos(0);
double r = 0.01;
double inc = 20;

//Clock definitions to output CPU time at the end of program
clock_t m_st, m_end;
double cpu_time_used;


//Structure holding coordinates of the vertices of Nodes
typedef struct Point
{
	double x,y;
	
}Point;

//Structure holding Node elements
typedef struct Node
{
	Node *child[4];
	Point pt[4];
	int flag;
	double width;
	double height;
	Node *parent;
	queue *back;
	int level;
	int num ;
	double func_val[4];
	Node *link[10];
	Node():num(0){ };
	
		
}Node;

//Structure for queue created 
typedef struct queue
{
	queue *next;
	Node *node_ptr;
}queue;

//Main strucutre pointing to Node struct and the queue stack
typedef struct top
{
	Node *node_top;
	queue *q_top;
	int choice;
	int subdivide;
	int nbr;
		
}top;

//Matlab Functions
void open(int a);
void close();
void call(Node *n,FILE *p,int c);
void mat_tree(Node *n,FILE *p,int c);
		
//Building and printing the tree
void node_Def(Node *n,Node *n_par,double theta,double R,double r,int c);
Node* buildnode(Node *n,Node *n_par,int k,int c);		
void buildtree(Node *n,int level,int c,int t);
int task(Node *n,int c);
int function(Node *n,int d);
void print(Node *n);
void deletetree(Node *n);
		
//Creating queue and tracking neighbours
void create_q(Node *n,queue *q);	
void create_link(Node *n,Node *nd,int c);
void nbr(Node *n,Node *root,int c);
