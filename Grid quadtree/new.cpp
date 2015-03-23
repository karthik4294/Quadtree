#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<complex.h>
#include<math.h>
#include<time.h>
#include<omp.h>
using namespace std;

//General definitions
int BLACK = -1;//Node is outside the curve
int WHITE = 1;//Node is inside the curve
int GREY = 2;//Node boundary intersects with curve
int RED = 0; 
double EPS = 0.0001;
FILE *p = NULL;
int LEVEL;
int choice;

//Workspace
double XMAX=2;double YMAX = 2;
double XMIN=-2;double YMIN = -2;

//Rectangle
int rect_box = 100;

//Triangle
int tri_box = 50;

//Circle
double Pi = 2*acos(0);
double r = 0.10;
double e = 0.001;
double inc = 30;

//Clock
clock_t m_st, m_end;
double cpu_time_used;


typedef struct Point
{
	double x,y;
	
}Point;

typedef struct queue queue;
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

typedef struct queue
{
	queue *next;
	Node *node_ptr;
}queue;
class qtree
{
	public:
		void buildtree(Node *n,int level,int c);
		Node* buildnode(Node *n,Node *n_par,int k,int c);
		void node_Def(Node *n,Node *n_par,double i,double j,double theta,int l,int c); 	
		int function(Node *n,int d);
		int task(Node *n,int c);
		void open(int a);
		void close();
		void call(Node *n,FILE *p,int c);
		void create_q(Node *n,queue *q);
		void create_link(Node *n,Node *nd,int c);
		void nbr(Node *n,Node *root,int c);
		void print(Node *n);
		void display(Node *n);
		void mat_tree(Node *n,FILE *p);
		void deletetree(Node *n);

	//qtree();
	//~qtree();
};


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

void qtree::close()
{
	fprintf(p,"});\nxx=datamapaman(:,1);\nyy=datamapaman(:,2);\nhand=plot(xx,yy,'r.');\nhold on\n");




}

void qtree::node_Def(Node *n,Node *n_par,double i,double j,double theta,int l,int c)
{
	switch(c)
	{
	
	case 1:
	if(n_par == NULL)
	{
	n->pt[0].x = j; n->pt[0].y = ((XMAX-XMIN)/rect_box)-i;
	n->pt[1].x = j-((XMAX-XMIN)/rect_box); n->pt[1].y = ((XMAX-XMIN)/rect_box)-i;
	n->pt[2].x = j-((XMAX-XMIN)/rect_box); n->pt[2].y = -i;
	n->pt[3].x = j; n->pt[3].y = -i;
	n->width = ((XMAX-XMIN)/rect_box); n->height = ((YMAX-YMIN)/rect_box);
	n->flag = GREY;
	n->level = 0;			
	}
	break;	
	
	case 2:
	if(n_par == NULL && l==0)
	{
	n->pt[0].x = j; n->pt[0].y = -i;
	n->pt[1].x = j-((XMAX-XMIN)/(2*tri_box)); n->pt[1].y = -i-(pow(3,0.5)*(XMAX-XMIN)/(2*tri_box));
	n->pt[2].x = j+((XMAX-XMIN)/(2*tri_box)); n->pt[2].y = -i-(pow(3,0.5)*(XMAX-XMIN)/(2*tri_box));
	n->flag = GREY;
	n->level = 0;			
	}
	
	if(n_par == NULL && l==1)
	{
	n->pt[0].x = j; n->pt[0].y = i;
	n->pt[1].x = j-((XMAX-XMIN)/(2*tri_box)); n->pt[1].y = i+(pow(3,0.5)*(YMAX-YMIN)/(2*tri_box));
	n->pt[2].x = j+((XMAX-XMIN)/(2*tri_box)); n->pt[2].y = i+(pow(3,0.5)*(YMAX-YMIN)/(2*tri_box));
	n->flag = GREY;
	n->level = 0;			
	}	
	
	break;
	
	case 3:
	if(n_par == NULL)
	{
	n->pt[0].x = j+r*cos(((theta-15)*Pi/180)); n->pt[0].y =i+r*sin(((theta-15)*Pi/180)) ;
	n->pt[1].x = j+r*cos((theta*Pi/180)); n->pt[1].y = i+r*sin((theta*Pi/180));
	n->pt[2].x = j+e*cos((theta*Pi/180)); n->pt[2].y = i+e*sin((theta*Pi/180));
	n->pt[3].x = j+e*cos(((theta-15)*Pi/180)); n->pt[3].y = i+ e*sin(((theta-15)*Pi/180));
	n->flag = GREY;
	n->level = 0;			
	}
	break;
	
	default:
	break;
	
	}	
	
	n->parent = n_par;	

	for(int w=0;w<4;w++)
	n->child[w] = NULL;	

}	

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
			
			//n->flag = WHITE;
	
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
	
			//n->flag = WHITE;			
			
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
	
			//n->flag = WHITE;			
			
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
	
			//n->flag = WHITE;			
				
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
			
			
			//n->flag = WHITE;
	
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
			
			
			//n->flag = WHITE;			
			
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
		
	
			//n->flag = WHITE;			
			
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
			
	
			//n->flag = WHITE;			
				
			break;
	}
	
	}	
	
	}	
	
return n;

}

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
		for(int k=0;k<4;k++)
		create_q(n->child[k],q_son);
	}
}

void qtree::buildtree(Node *n, int l,int c)
{
	if(n->parent!=NULL)	
	n->flag = task(n,c);	

	if(n->flag == GREY && l<LEVEL)
	{
		for(int k =0; k < 4; k++)
		{
			Node *nd = new Node;
			n->child[k] = new Node;
			node_Def(n->child[k],n,0,0,0,0,c);
			n->child[k]->level = (n->level) + 1;
	                nd = buildnode(n->child[k],n, k,c);		
			buildtree(nd,nd->level,c);
			
		}
	
		
        }

	
	
}

int qtree::task(Node *n,int c)
{	
	
	if(c == 1 || c == 3)
	{
	double a[4];
	
	for(int d=0;d<4;d++)
	{
		a[d] = function(n,d);
	}	

	if(a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1)
	{		
		//n->flag = WHITE;	
		return WHITE;
	}

	else if(a[0] == -1 && a[1] == -1 && a[2] == -1 && a[3] == -1)
	{		//q=create_q(n,nd,q);
		//n->flag = BLACK;	
		return BLACK;
	}

	else if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
	{		
		//n->flag = RED;	
		return RED;
	}
	else if(a[0] == 10 || a[1] == 10 || a[2] == 10 || a[3] == 10)
	{
	
		return BLACK;	
	}
	else
	{		
		//n->flag = GREY;	
		return GREY;
	}

	}
	
	else if(c == 2)
	{
	double a[3];
	
	for(int d=0;d<3;d++)
	{
		a[d] = function(n,d);
	}	

	if(a[0] == 1 && a[1] == 1 && a[2] == 1)
	{		
		//n->flag = WHITE;	
		return WHITE;
	}

	else if(a[0] == -1 && a[1] == -1 && a[2] == -1)
	{		//q=create_q(n,nd,q);
		//n->flag = BLACK;	
		return BLACK;
	}

	else if(a[0] == 0 && a[1] == 0 && a[2] == 0 )
	{		
		//n->flag = RED;	
		return RED;
	}
	else if(a[0] == 10 || a[1] == 10 || a[2] == 10)
	{
	
		return BLACK;	
	}
	else
	{		
		//n->flag = GREY;	
		return GREY;
	}
	
	}	
	

		
}

int qtree::function(Node *n,int d)
{double t;
double x = n->pt[d].x;
double y = n->pt[d].y;
double parameters[1] = {135};
double cond7,sf1,sf2,cf1,cf2,thmin;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	thmin = 0; 	
	
	cond7 = -1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
        pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
      (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
        pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2))) + 
   acos(pow(pow(z + 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
       pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
     (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
        (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y))));

	t = cond7-thmin;


//cout << "f = " << t<<"\n";
	//t = pow(x,2)+pow(y,2)-1;
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
		for(int m=0;m<4;m++)
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
		for(int m=0;m<4;m++)
		create_link(n,nd->child[m],c);		
	}
	}
	
}

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
		for(int j=0;j<4;j++)
		nbr(n->child[j],root,c);		
		
	}
	

}

void qtree::print(Node *n)
{		

	{
		if(n->child[0] == NULL)// && n->flag == GREY)
		{
			if(n->flag == GREY || n->flag == RED)
			{
			display(n);
			}
		}	

		
		else
		{	
			for(int k=0;k<4;k++)
			print(n->child[k]);
	
		}
	}

}

void qtree::display(Node *n)
{
	cout<<"\nThe solution points are";
	cout<<"\nx = "<<n->pt[0].x-n->width/2;
	cout<<"\ty = "<<n->pt[0].y-n->height/2<<"\n";
	
}

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
		for(int k=0;k<4;k++)
		call(n->child[k],p,c);
	
	}

	}
	
	else if(c ==2)
	{
	if(n->child[0] == NULL )
	{
		if(n->flag == GREY || n->flag == RED )
		fprintf(p,"%lf,%lf;",(n->pt[0].x+n->pt[1].x+n->pt[2].x)/3,(n->pt[0].y+n->pt[1].y+n->pt[2].y)/3);
		//for(int i=0;i<n->num;i++)		
		//fprintf(p,"%lf,%lf;",n->link[i]->pt[0].x-n->link[i]->width/2,n->link[i]->pt[0].y-n->link[i]->height/2);
	}
		
	else
	{	
		for(int k=0;k<4;k++)
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
		for(int k=0;k<4;k++)
		call(n->child[k],p,c);
	
	}	
	}
}

void qtree::deletetree(Node *n)
{

if (n->child[0] == NULL)

    {

        delete n;

        return;

    }

    else if (n->child[0] != NULL)

    {

        for (int i = 0; i < 4; i++)

        deletetree(n->child[i]);

        return;

    }
}
void qtree::mat_tree(Node *n,FILE *p)
{
if (n->child[0] == NULL && n->child[1] == NULL && n->child[2] == NULL && n->child[3] == NULL)

    {	
	fprintf(p,"rectangle('Position',[%lf,%lf,%lf,%lf]);\n",n->pt[2].x,n->pt[2].y,n->width,n->height);

      return;

    }

    else if (n->child[0] != NULL)

    {

        for (int i = 0; i < 4; i++)

        mat_tree(n->child[i],p);

	return;
    }
}


/*qtree::qtree()
{

}

qtree::~qtree()
{

}*/




int main(void)
{  
	class qtree init;
	init.open(0);
	
	queue *q = new queue;
	
	cout<<"\nEnter geometry number\n"<<"1.Rectangles\n2.Triangles\n3.Circles\n";

	cin>>choice;	
	
	switch(choice)
	{
	case 1:
	cout<<"\nEnter depth of quadtree\n";
	
	cin>>LEVEL;	
	
	m_st = clock();
	
	for(double i=(YMIN+((YMAX-YMIN)/rect_box));i<=YMAX;i=i+((YMAX-YMIN)/rect_box))
	{	
		
		for(double j=(YMIN+((YMAX-YMIN)/rect_box));j<=YMAX;j=j+((YMAX-YMIN)/rect_box))
		{
	
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,0,0,choice);
		
	                qt.buildtree(root,0,choice);				
			
			qt.create_q(root,q);
			
			qt.nbr(root,root,choice);
			
			//qt.print(root);
			
			qt.call(root,p,choice);		
			
			qt.deletetree(root);
	
		}
		                

	
	}
	
	init.close();  
	
	
	m_end=clock();
	cpu_time_used = ((double) (m_end - m_st))/CLOCKS_PER_SEC;
	
	cout<<"\n\n Time used :"<<cpu_time_used<<endl; 

	fprintf(p,"xmin=min(xx);xmax=max(xx);ymin=min(yy);ymax=max(yy);\naxis([-1.5 1.5 -1.5 1.5]);\naxis('square');set(hand, 'MarkerSize', 1);");
	fclose(p);
	
	break;
	
	
	case 2:
	cout<<"\nEnter depth of quadtree\n";
	
	cin>>LEVEL;	
	
	m_st = clock();
	
	for(double i=YMIN;i<=YMAX;i=i+(pow(3,0.5)*(YMAX-YMIN)/(2*tri_box)))	
		{
			for(double j = XMIN+((XMAX-XMIN)/(2*tri_box));j<=XMAX-((XMAX-XMIN)/(2*tri_box));j=j+((XMAX-XMIN)/(tri_box)))
	
			{
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,0,0,choice);
		
	        	qt.buildtree(root,0,choice);				
			
			qt.create_q(root,q);
			
			qt.nbr(root,root,choice);
			
			//qt.print(root);
			
			qt.call(root,p,choice);		
		       	
			qt.deletetree(root);
	
	          	}
		}

		
	for(double i=YMAX-(pow(3,0.5)*(XMAX-XMIN)/(2*tri_box));i>=YMIN;i=i-(pow(3,0.5)*(YMAX-YMIN)/(2*tri_box)))	
		{
			for(double j = XMIN;j<=XMAX;j=j+((XMAX-XMIN)/(tri_box)))
	
			{
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,0,1,choice);
		
	        	qt.buildtree(root,0,choice);				
			
			qt.create_q(root,q);
			
			qt.nbr(root,root,choice);
			
			//qt.print(root);
			
			qt.call(root,p,choice);		
		       	
			qt.deletetree(root);
	
	          	}
		}	

	
	init.close();  
	
	
	m_end=clock();
	cpu_time_used = ((double) (m_end - m_st))/CLOCKS_PER_SEC;
	
	cout<<"\n\n Time used :"<<cpu_time_used<<endl; 

	fprintf(p,"xmin=min(xx);xmax=max(xx);ymin=min(yy);ymax=max(yy);\naxis([-1.5 1.5 -1.5 1.5]);\naxis('square');set(hand, 'MarkerSize', 1);");
	fclose(p);
	
	break;


	case 3:
	cout<<"\nEnter depth of quadtree\n";
	
	cin>>LEVEL;	
	
	m_st = clock();

	for(double i =YMIN;i<=YMAX;i=i+r)
	{
	for(double j =XMIN;j<=XMAX;j=j+r)
	{	
	for(double theta =inc;theta<=360;theta=theta+inc)
		{
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,theta,0,choice);
		
	                qt.buildtree(root,0,choice);				
			
			qt.create_q(root,q);
			
			//qt.nbr(root,root,choice);
			
			//qt.print(root);
			
			qt.call(root,p,choice);		
			
			qt.deletetree(root);
		}
	}
		
	}	
	init.close();  
	
	
	m_end=clock();
	cpu_time_used = ((double) (m_end - m_st))/CLOCKS_PER_SEC;
	
	cout<<"\n\n Time used :"<<cpu_time_used<<endl; 

	fprintf(p,"xmin=min(xx);xmax=max(xx);ymin=min(yy);ymax=max(yy);\naxis([-1.5 1.5 -1.5 1.5]);\naxis('square');set(hand, 'MarkerSize', 1);");
	fclose(p);
	
	break;
	
	default: cout<<"\nNo such choice";
	break;	
	
	}
	
}
