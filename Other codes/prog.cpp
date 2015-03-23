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

//The structures
typedef struct queue queue;
typedef struct top top;
typedef struct Node Node;
typedef struct Point Point;

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

//Class holding all functions related to the quadtree structure
class qtree
{
	public:
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
		int func(Node *n,int d);
		void print(Node *n);
		void deletetree(Node *n);
		
		//Creating queue and tracking neighbours
		void create_q(Node *n,queue *q);	
		void create_link(Node *n,Node *nd,int c);
		void nbr(Node *n,Node *root,int c);
				

};

//Function to open a .m file to which solution point values are exported
void qtree::open(int a)
{
	char *buffer=new char[12];
 
        snprintf(buffer, 12,"new/da%d.m", a);
	

	p = fopen(buffer, "wb");
	
	if (p== NULL)
	{
		printf("Error in opening a file");
	}
	
//For Matlab
	fprintf(p,"clear all; close all;clc;\n datamapaman = cell2mat({");


}

//Closing the first paranthesis to enclose all solution points alone
void qtree::close()
{
	fprintf(p,"});\nxx=datamapaman(:,1);\nyy=datamapaman(:,2);\nhand=plot(xx,yy,'r.');\nhold on\n");
}

//Exporting solution points to the .m file
void qtree::call(Node *n,FILE *p,int c)
{	
	if(c ==1)
	{
	
		if(n->child[0] == NULL )
		{
			if(n->flag == GREY || n->flag == RED )
			fprintf(p,"%lf,%lf;",n->pt[0].x-n->width/2,n->pt[0].y-n->height/2);
		
		}
		
		else
		{	
			for(int k=0;k < child_num;k++)
			call(n->child[k],p,c);
		}

	}
	
	else if(c ==2)
	{
		if(n->child[0] == NULL )
		{
			if(n->flag == GREY || n->flag == RED )
			fprintf(p,"%lf,%lf;",(n->pt[0].x+n->pt[1].x+n->pt[2].x)/3,(n->pt[0].y+n->pt[1].y+n->pt[2].y)/3);
		
		}
		
		else
		{	
			for(int k=0;k < child_num;k++)
			call(n->child[k],p,c);
	
		}	
	}
	
	else if(c == 3)
	{
		if(n->child[0] == NULL )
		{
			if(n->flag == GREY || n->flag == RED )
			fprintf(p,"%lf,%lf;",(n->pt[0].x+n->pt[2].x)/2,(n->pt[0].y+n->pt[2].y)/2);
		
		}
		
		else
		{	
			for(int k=0;k < child_num;k++)
			call(n->child[k],p,c);
	
		}	
	}
}

//Function to plot the generate the quadtree in matlab
void qtree::mat_tree(Node *n,FILE *p,int c)
{
	switch(c)
	{
		case 1:
	
		if (n->child[0] == NULL && n->child[1] == NULL && n->child[2] == NULL && n->child[3] == NULL)

    		{	
			fprintf(p,"rectangle('Position',[%lf,%lf,%lf,%lf]);\n",n->pt[2].x,n->pt[2].y,n->width,n->height);
			
      			return;

    		}

    		else if (n->child[0] != NULL)

    		{

  	   	     for (int i = 0; i < child_num; i++)

                     mat_tree(n->child[i],p,c);

		     return;
	        }


		case 2:
		
		if (n->child[0] == NULL)
		{	
			fprintf(p,"A = [%lf,%lf,%lf;%lf,%lf,%lf];",n->pt[0].x,n->pt[1].x,n->pt[2].x,n->pt[0].y,n->pt[1].y,n->pt[2].y);
			fprintf(p,"A = [A A(:,1) ];line(A(1,:),A(2,:));\n");

     			 return;
		
   	        }

 	        else if (n->child[0] != NULL)
		{

        		for (int i = 0; i < child_num; i++)

       			mat_tree(n->child[i],p,c);

			return;
    		}		
		
		
		case 3:
		if (n->child[0] == NULL)
		{	
			fprintf(p,"x = [%lf,%lf,%lf,%lf];",n->pt[0].x,n->pt[1].x,n->pt[2].x,n->pt[3].x);
			fprintf(p,"y = [%lf,%lf,%lf,%lf];\n",n->pt[0].y,n->pt[1].y,n->pt[2].y,n->pt[3].y);
			fprintf(p,"plot(x,y);\n");
      			return;

    		}

    		else if (n->child[0] != NULL)
		{

        		for (int i = 0; i < child_num; i++)

        		mat_tree(n->child[i],p,c);

			return;
    		}

	}

}


//Defining a node 
void qtree::node_Def(Node *n,Node *n_par,double theta,double R,double r,int c)
{
	switch(c)
	{
	
		case 1:
		if(n_par == NULL)
		{
			n->pt[0].x = XMAX; n->pt[0].y = YMAX;
			n->pt[1].x = XMIN; n->pt[1].y = YMAX;
			n->pt[2].x = XMIN; n->pt[2].y = YMIN;
			n->pt[3].x = XMAX; n->pt[3].y = YMIN;
			n->width = XMAX-XMIN; n->height = YMAX-YMIN;
			n->flag = WHITE;
			n->level = 0;			
		}
		break;	
	
		case 2:
		if(n_par == NULL)
		{
			n->pt[0].x = X0; n->pt[0].y = Y0 ;
			n->pt[1].x = X1; n->pt[1].y = Y1;
			n->pt[2].x = X2; n->pt[2].y = Y2;
			n->flag = WHITE;
			n->level = 0;			
		}
		break;
	
		case 3:
		if(n_par == NULL)
		{
			n->pt[0].x = R*cos(((theta-inc)*Pi/180)); n->pt[0].y =R*sin(((theta-inc)*Pi/180)) ;
			n->pt[1].x = R*cos((theta*Pi/180)); n->pt[1].y = R*sin((theta*Pi/180));
			n->pt[2].x = r*cos((theta*Pi/180)); n->pt[2].y = r*sin((theta*Pi/180));
			n->pt[3].x = r*cos(((theta-inc)*Pi/180)); n->pt[3].y = r*sin(((theta-inc)*Pi/180));
			n->flag = WHITE;
			n->level = 0;			
		}
		break;
	
		default:
		break;
	
	}	
	
	n->parent = n_par;	

	for(int w=0;w<child_num;w++)
	n->child[w] = NULL;	

}	

//Splitting a node into 4 children depending on geometry
Node* qtree::buildnode(Node *n,Node *n_par,int k,int c)
{
	
	if(c == 1)
	{
		if(n->parent!=NULL )
		{	
			switch(k)
			{
				case 0:
				n->pt[0].x = n_par->pt[0].x;
				n->pt[0].y = n_par->pt[0].y;
			
				n->pt[1].x = n_par->pt[0].x-((n_par->width)/2);
				n->pt[1].y = n_par->pt[0].y;
			
				n->pt[2].x = n_par->pt[0].x-((n_par->width)/2);
				n->pt[2].y = n_par->pt[0].y-((n_par->height)/2);

				n->pt[3].x = n_par->pt[0].x;
				n->pt[3].y = n_par->pt[0].y-((n_par->height)/2);
			
				n->width = ((n_par->width)/2);
				n->height = ((n_par->height)/2);
	
				break;
			case 1:

				n->pt[0].x = n_par->pt[1].x+((n_par->width)/2);
				n->pt[0].y = n_par->pt[1].y;
			
				n->pt[1].x = n_par->pt[1].x;
				n->pt[1].y = n_par->pt[1].y;
			
				n->pt[2].x = n_par->pt[1].x;
				n->pt[2].y = n_par->pt[1].y-((n_par->height)/2);

				n->pt[3].x = n_par->pt[1].x+((n_par->width)/2);
				n->pt[3].y = n_par->pt[1].y-((n_par->height)/2);
			
				n->width = ((n_par->width)/2);
				n->height = ((n_par->height)/2);
			
			
				break;


			case 2:

				n->pt[0].x = n_par->pt[2].x+((n_par->width)/2);
				n->pt[0].y = n_par->pt[2].y+((n_par->height)/2);
			
				n->pt[1].x = n_par->pt[2].x;
				n->pt[1].y = n_par->pt[2].y+((n_par->height)/2);
			
				n->pt[2].x = n_par->pt[2].x;
				n->pt[2].y = n_par->pt[2].y;

				n->pt[3].x = n_par->pt[2].x+((n_par->width)/2);
				n->pt[3].y = n_par->pt[2].y;
			
				n->width = ((n_par->width)/2);
				n->height = ((n_par->height)/2);		
			
				break;

			case 3:

				n->pt[0].x = n_par->pt[3].x;
				n->pt[0].y = n_par->pt[3].y+((n_par->height)/2);
			
				n->pt[1].x = n_par->pt[3].x-((n_par->width)/2);
				n->pt[1].y = n_par->pt[3].y+((n_par->height)/2);
			
				n->pt[2].x = n_par->pt[3].x-((n_par->width)/2);
				n->pt[2].y = n_par->pt[3].y;

				n->pt[3].x = n_par->pt[3].x;
				n->pt[3].y = n_par->pt[3].y;
			
				n->width = ((n_par->width)/2);
				n->height = ((n_par->height)/2);		
				
				break;
			}
	
		}
	
	}
	
	
	else if(c == 2)
	{
		if(n->parent!=NULL )
		{	
			switch(k)
			{
			case 0:
				n->pt[0].x = n_par->pt[0].x;
				n->pt[0].y = n_par->pt[0].y;
			
				n->pt[1].x = (n_par->pt[0].x+n_par->pt[1].x)/2;
				n->pt[1].y = (n_par->pt[0].y+n_par->pt[1].y)/2;
			
				n->pt[2].x = (n_par->pt[0].x+n_par->pt[2].x)/2;
				n->pt[2].y = (n_par->pt[0].y+n_par->pt[2].y)/2;

				break;
			case 1:

				n->pt[0].x = (n_par->pt[0].x+n_par->pt[1].x)/2;
				n->pt[0].y = (n_par->pt[0].y+n_par->pt[1].y)/2;
			
				n->pt[1].x = n_par->pt[1].x;
				n->pt[1].y = n_par->pt[1].y;
			
				n->pt[2].x = (n_par->pt[1].x+n_par->pt[2].x)/2;
				n->pt[2].y = (n_par->pt[1].y+n_par->pt[2].y)/2;	
			
				break;


			case 2:

				n->pt[0].x = (n_par->pt[1].x+n_par->pt[2].x)/2;
				n->pt[0].y = (n_par->pt[1].y+n_par->pt[2].y)/2;		
			
				n->pt[1].x = (n_par->pt[0].x+n_par->pt[2].x)/2;
				n->pt[1].y = (n_par->pt[0].y+n_par->pt[2].y)/2;
			
				n->pt[2].x = (n_par->pt[0].x+n_par->pt[1].x)/2;
				n->pt[2].y = (n_par->pt[0].y+n_par->pt[1].y)/2;
			
			
				break;

			case 3:

				n->pt[0].x = (n_par->pt[0].x+n_par->pt[2].x)/2;
				n->pt[0].y = (n_par->pt[0].y+n_par->pt[2].y)/2;
			
				n->pt[1].x = (n_par->pt[1].x+n_par->pt[2].x)/2;
				n->pt[1].y = (n_par->pt[1].y+n_par->pt[2].y)/2;
			
				n->pt[2].x = n_par->pt[2].x;
				n->pt[2].y = n_par->pt[2].y;
			
				
				break;
			}
	
			}
	
	}

	else if(c == 3)
	{
		if(n->parent!=NULL )
		{	
		switch(k)
		{
			case 0:
				n->pt[0].x = n_par->pt[0].x;
				n->pt[0].y = n_par->pt[0].y;
			
				n->pt[1].x = (n_par->pt[0].x+n_par->pt[1].x)/2;
				n->pt[1].y = (n_par->pt[0].y+n_par->pt[1].y)/2;
			
				n->pt[2].x = (n_par->pt[0].x+n_par->pt[2].x)/2;
				n->pt[2].y = (n_par->pt[0].y+n_par->pt[2].y)/2;

				n->pt[3].x = (n_par->pt[0].x+n_par->pt[3].x)/2;
				n->pt[3].y = (n_par->pt[0].y+n_par->pt[3].y)/2;
			
				break;
			case 1:

				n->pt[0].x = (n_par->pt[0].x+n_par->pt[1].x)/2;
				n->pt[0].y = (n_par->pt[0].y+n_par->pt[1].y)/2;
			
				n->pt[1].x = n_par->pt[1].x;
				n->pt[1].y = n_par->pt[1].y;
				n->pt[2].x = (n_par->pt[1].x+n_par->pt[2].x)/2;
				n->pt[2].y = (n_par->pt[1].y+n_par->pt[2].y)/2;

				n->pt[3].x = (n_par->pt[0].x+n_par->pt[2].x)/2;
				n->pt[3].y = (n_par->pt[0].y+n_par->pt[2].y)/2;			
			
				break;


			case 2:

				n->pt[0].x = (n_par->pt[0].x+n_par->pt[2].x)/2;
				n->pt[0].y = (n_par->pt[0].y+n_par->pt[2].y)/2;
			
				n->pt[1].x = (n_par->pt[1].x+n_par->pt[2].x)/2;
				n->pt[1].y = (n_par->pt[1].y+n_par->pt[2].y)/2;
			
				n->pt[2].x = n_par->pt[2].x;
				n->pt[2].y = n_par->pt[2].y;

				n->pt[3].x = (n_par->pt[2].x+n_par->pt[3].x)/2;;
				n->pt[3].y = (n_par->pt[2].y+n_par->pt[3].y)/2;
			
				break;

			case 3:

				n->pt[0].x = (n_par->pt[0].x+n_par->pt[3].x)/2;
				n->pt[0].y = (n_par->pt[0].y+n_par->pt[3].y)/2;
			
				n->pt[1].x = (n_par->pt[0].x+n_par->pt[2].x)/2;
				n->pt[1].y = (n_par->pt[0].y+n_par->pt[2].y)/2;
			
				n->pt[2].x = (n_par->pt[2].x+n_par->pt[3].x)/2;
				n->pt[2].y = (n_par->pt[2].y+n_par->pt[3].y)/2;

				n->pt[3].x = n_par->pt[3].x;
				n->pt[3].y = n_par->pt[3].y;	
				
				break;
			}
	
		}	
	
	}	
	
return n;

}

//Recursively called to build the quadtree
void qtree::buildtree(Node *n, int l,int c,int t)
{		

	if(t == 1)
	{	
		if(n->parent!=NULL)	
		{
			n->flag = task(n,c);
			if(n->flag == GREY && check == 0){check = n->level;}
		}

		if(check!=0 && l>=check)
		{
			if((n->flag == GREY) && l<LEVEL)
			{
				for(int k =0; k < child_num; k++)
				{
					Node *nd = new Node;
					n->child[k] = new Node;
					node_Def(n->child[k],n,0,0,0,c);
					n->child[k]->level = (n->level) + 1;
					nd = buildnode(n->child[k],n, k,c);		
					buildtree(nd,nd->level,c,t);
			
				}
	
		
 		       }

		}
	
		else if(check!=0 && l<check)
		{
			if((n->flag == GREY || n->flag == WHITE) && l<LEVEL)
			{
				for(int k =0; k < child_num; k++)
				{
					Node *nd = new Node;
					n->child[k] = new Node;
					node_Def(n->child[k],n,0,0,0,c);
					n->child[k]->level = (n->level) + 1;
					nd = buildnode(n->child[k],n, k,c);		
					buildtree(nd,nd->level,c,t);
			
				}
		
			}

		}

		else if(check == 0)
		{
			if((n->flag == WHITE) && l<LEVEL)
			{
				for(int k =0; k < child_num; k++)
				{
					Node *nd = new Node;
					n->child[k] = new Node;
					node_Def(n->child[k],n,0,0,0,c);
					n->child[k]->level = (n->level) + 1;
					nd = buildnode(n->child[k],n, k,c);		
					buildtree(nd,nd->level,c,t);
			
				}
		
	      		  }	
		}
	
}
	
	else if(t == 2)
	{
		if(n->parent!=NULL)	
		n->flag = task(n,c);
		if((n->flag == GREY || n->flag == WHITE) && l<LEVEL)
		{
			for(int k =0; k < child_num; k++)
			{
				Node *nd = new Node;
				n->child[k] = new Node;
				node_Def(n->child[k],n,0,0,0,c);
				n->child[k]->level = (n->level) + 1;
			        nd = buildnode(n->child[k],n, k,c);		
				buildtree(nd,nd->level,c,t);
			
			}
	
		}
	
	}

	else cout<<"No such choice";return;

	
}

//Returns the state of each node
int qtree::task(Node *n,int c)
{	
	
	if(c == 1 || c == 3)
	{
		double a[4];
	
		for(int d=0;d <rect_vert;d++)
		{
			a[d] = func(n,d);
		}	

		if(a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1)
		{		
		
			return WHITE;
		}

		else if(a[0] == -1 && a[1] == -1 && a[2] == -1 && a[3] == -1)
		{	
			return BLACK;
		}

		else if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
		{			
			return RED;
		}
		else if(a[0] == 10 || a[1] == 10 || a[2] == 10 || a[3] == 10)
		{
			return WHITE;	
		}
		else
		{			
			return GREY;
		}

		}
	
	else if(c == 2)
	{
		double a[3];
	
		for(int d=0;d < tri_vert;d++)
		{
			a[d] = func(n,d);
		}	

		if(a[0] == 1 && a[1] == 1 && a[2] == 1)
		{		
			return WHITE;
		}

		else if(a[0] == -1 && a[1] == -1 && a[2] == -1)
		{		
			return BLACK;
		}

		else if(a[0] == 0 && a[1] == 0 && a[2] == 0 )
		{			
			return RED;
		}
		else if(a[0] == 10 || a[1] == 10 || a[2] == 10)
		{
	
			return WHITE;	
		}
		else
		{		
			return GREY;
		}
	
	}	
	

		
}

//Calculating the value of function 
int qtree::func(Node *n,int d)
{
	double t;
	double x = n->pt[d].x;
	double y = n->pt[d].y;


	//t = pow(x,2)+pow(y,2)-1;//Circle 

	//t = 2*pow(x,2)+pow(y,2)-1;//Ellipse
	
	t = 2*pow(x,2)-pow(y,2)-1;//Hyperbola


	n->func_val[d] = t;		
				
	if(t>EPS)
	return 1;

	if(t<-EPS)
	return -1;

	if(t<=EPS && t>=-EPS)
	return 0;

	else
	return 10;

}	 

//Prints the solution points on the screen
void qtree::print(Node *n)
{		
	if(n->child[0] == NULL)// && n->flag == GREY)
	{
		if(n->flag == GREY || n->flag == RED)
		{
			cout<<"\nThe solution points are";
			cout<<"\nx = "<<n->pt[0].x-n->width/2;
			cout<<"\ty = "<<n->pt[0].y-n->height/2<<"\n";
		}
	}	

		
	else
	{	
		for(int k=0;k < child_num;k++)
		print(n->child[k]);
	
	}
	

}


//Deleting all nodes
void qtree::deletetree(Node *n)
{
	if (n->child[0] == NULL)
	{
		w++;
	
		delete n;

		return;

   	}

    	else if (n->child[0] != NULL)
	{

		for (int i = 0; i < child_num; i++)

		deletetree(n->child[i]);

		return;

    	}
	
}



//Creating a queue containing root and its children linked like a list
void qtree::create_q(Node *n,queue *q_par)
{	
	queue *q_son = new queue;	
	n->back = q_par;
	q_par->next = q_son; 
	q_par->node_ptr = n;	
		
	if(n->child[0] == NULL)
	{
		return;
	}
		
	else
	{	
		for(int k=0;k < child_num;k++)
		create_q(n->child[k],q_son);
	}
	

}

//Function which makes a Node to point to neighbours which are GREY
void qtree::create_link(Node *n,Node *nd,int c)
{	
	if(c == 1 || c == 3)
	{
		if(nd->child[0] == NULL)
		{
			if(nd->flag == GREY)
			{
				if((nd->pt[2].x == n->pt[0].x && nd->pt[2].y == n->pt[0].y) ||
				   (nd->pt[3].x == n->pt[0].x && nd->pt[3].y == n->pt[0].y) ||	
				   (nd->pt[3].x == n->pt[1].x && nd->pt[3].y == n->pt[1].y) ||	
				   (nd->pt[0].x == n->pt[1].x && nd->pt[0].y == n->pt[1].y) ||
				   (nd->pt[0].x == n->pt[2].x && nd->pt[0].y == n->pt[2].y) ||
				   (nd->pt[1].x == n->pt[2].x && nd->pt[1].y == n->pt[2].y) ||
				   (nd->pt[1].x == n->pt[3].x && nd->pt[1].y == n->pt[3].y) ||
				   (nd->pt[1].x == n->pt[0].x && nd->pt[1].y == n->pt[0].y) )
				{
		
					n->link[n->num] = nd;	
					//cout<<"\nHold on "<<n->link[n->num]->pt[0].x<<"\t"<<n->link[n->num]->pt[0].y;
					n->num=n->num + 1;	
				}
		
			}
			
			else
			return;	
			
		}
		
		else
		{
			for(int m=0; m < child_num;m++)
			create_link(n,nd->child[m],c);		
		}
	
	}
	
	else if(c ==2)
	{
		if(nd->child[0] == NULL)
		{
			if(nd->flag == GREY)
			{
				if((nd->pt[0].x == n->pt[0].x && nd->pt[0].y == n->pt[0].y) ||
				   (nd->pt[0].x == n->pt[1].x && nd->pt[0].y == n->pt[1].y) ||	
				   (nd->pt[0].x == n->pt[2].x && nd->pt[0].y == n->pt[2].y) ||	
				   (nd->pt[1].x == n->pt[0].x && nd->pt[1].y == n->pt[0].y) ||
				   (nd->pt[1].x == n->pt[1].x && nd->pt[1].y == n->pt[1].y) ||
				   (nd->pt[1].x == n->pt[2].x && nd->pt[1].y == n->pt[2].y) ||
				   (nd->pt[2].x == n->pt[0].x && nd->pt[2].y == n->pt[0].y) ||
				   (nd->pt[2].x == n->pt[1].x && nd->pt[2].y == n->pt[1].y) ||
				   (nd->pt[2].x == n->pt[2].x && nd->pt[2].y == n->pt[2].y))
				{
		
					n->link[n->num] = nd;	
					//cout<<"\nHold on "<<n->link[n->num]->pt[0].x<<"\t"<<n->link[n->num]->pt[0].y;
					n->num=n->num + 1;	
				}
		
			}
			
			else
			return;	
			
		}
		else
		{
			for(int m=0;m < child_num;m++)
			create_link(n,nd->child[m],c);		
		}
	}
	
}

//Recursion function to link neighbours of all nodes
void qtree::nbr(Node *n, Node *root,int c)
{
	if(n->child[0] == NULL)
	{
		if(n->flag == GREY)		
		create_link(n,root,c);

		else
		return;	
	}
	
	else if(n->child[0] != NULL)
	{
		for(int j=0;j < child_num;j++)
		nbr(n->child[j],root,c);		
		
	}
	

}


int main(void)
{  
	class qtree qt;
	
	Node *root = new Node;
	
	queue *q = new queue;
	
	top *m = new top;
	
	cout<<"\nEnter geometry number\n"<<"1.Rectangle\n2.Triangle\n3.Circle\n";

	cin>>m->choice;
	
	cout<<"\nEnter subdivision method number\n"<<"1.New method\n2.Normal method\n";

	cin>>m->subdivide;	
	
	cout<<"\nEnter 1 if you want to track neighbours else enter 0\n";
		
	cin>>m->nbr;
	
	switch(m->choice)
	{
		case 1:
	
		cout<<"\nEnter depth of quadtree\n";
	
		cin>>LEVEL;	
	
		m_st = clock();
				
		m->node_top = root;
	
		m->q_top = q;
		
		qt.open(1);
			
		qt.node_Def(root,NULL,0,0,0,m->choice);
		
		qt.buildtree(root,0,m->choice,m->subdivide);				
			
		qt.create_q(root,q);
			
		if(m->nbr == 1)qt.nbr(root,root,m->choice);
			
		//qt.print(root);//Uncomment if you want to print out solutions
		
		qt.call(root,p,m->choice);
	
		qt.close();  	
			
		//qt.mat_tree(root,p,m->choice);//Uncomment if you want to see the quadtree in matlab plot		
			
		qt.deletetree(root);
			
		m_end=clock();

		cpu_time_used = ((double) (m_end - m_st))/CLOCKS_PER_SEC;
	
		cout<<"\n\n Time used :"<<cpu_time_used<<endl; 

		fprintf(p,"xmin=min(xx);xmax=max(xx);ymin=min(yy);ymax=max(yy);\naxis([-2 2 -2 2]);\naxis('square');set(hand, 'MarkerSize', 1);");
	
		fclose(p);
	
		break;
	
	
		case 2:
	
		cout<<"\nEnter depth of quadtree\n";
	
		cin>>LEVEL;	
	
		m_st = clock();
	
		m->node_top = root;

		m->q_top = q;	

		qt.open(2);		
			
		qt.node_Def(root,NULL,0,0,0,m->choice);
		
		qt.buildtree(root,0,m->choice,m->subdivide);				
			
		qt.create_q(root,q);
			
		if(m->nbr == 1) qt.nbr(root,root,m->choice);
			
		//qt.print(root);//Uncomment if you want to print out solutions
			
		qt.call(root,p,m->choice);
	
		qt.close(); 			
		
		//qt.mat_tree(root,p,m->choice);//Uncomment if you want to see the quadtree in matlab plot				
			       	
		qt.deletetree(root);
			
		m_end=clock();
	
		cpu_time_used = ((double) (m_end - m_st))/CLOCKS_PER_SEC;
	
		cout<<"\n\n Time used :"<<cpu_time_used<<endl; 

		fprintf(p,"xmin=min(xx);xmax=max(xx);ymin=min(yy);ymax=max(yy);\naxis([-3 3 -2 5]);\naxis('square');set(hand, 'MarkerSize', 1);");
	
		fclose(p);
	
		break;


	case 3:
		
	cout<<"\nEnter depth of quadtree\n";
	
	cin>>LEVEL;	
	
	m_st = clock();

	qt.open(3);
	
	for(double R = 1;R<=2;R++)//Splitting initial circle into wo concurrent circles
	{
		for(double theta =inc;theta<=360;theta=theta+inc)
		{					
						
			m->node_top = root;
	
			m->q_top = q;			

			qt.node_Def(root,NULL,theta,R,r,m->choice);
		
	                qt.buildtree(root,0,m->choice,m->subdivide);				
			
			qt.create_q(root,q);
			
			if(m->nbr == 1) qt.nbr(root,root,m->choice);
			
			//qt.print(root);//Uncomment if you want to print out solutions
			
			qt.call(root,p,m->choice);		
			
			qt.deletetree(root);
		}

	r = R;
	}
	
	qt.close();  	
	
	//Uncomment if you want to see the quadtree in matlab plot		
	for(double R = 1;R<=2;R++)
	{
		for(double theta =inc;theta<=360;theta=theta+inc)
		{						

			qt.node_Def(root,NULL,theta,R,r,m->choice);
		
	                qt.buildtree(root,0,m->choice,m->subdivide);			
			
			qt.mat_tree(root,p,m->choice);			
			
			qt.deletetree(root);
		}

	r = R;
	}

	
	
	
	
	m_end=clock();
	
	cpu_time_used = ((double) (m_end - m_st))/CLOCKS_PER_SEC;
	
	cout<<"\n\n Time used :"<<cpu_time_used<<endl; 

	fprintf(p,"xmin=min(xx);xmax=max(xx);ymin=min(yy);ymax=max(yy);\naxis([-2 2 -2 2]);\naxis('square');set(hand, 'MarkerSize', 1);");
	
	fclose(p);
	
	break;
	
	default: cout<<"\nNo such choice";
	break;	
	
	}

cout<<"No: of nodes "<<w<<"\n";	

}
