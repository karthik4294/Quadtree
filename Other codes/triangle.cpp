#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<complex.h>
#include<math.h>
#include<omp.h>
//#include"mdefs.h"
using namespace std;

int BLACK = -1;//Node is outside the curve
int WHITE = 1;//Node is inside the curve
int GREY = 2;//Node boundary intersects with curve
int RED = 0; 
double EPS = 0.0001;
FILE *p = NULL;
double Pi = 2*acos(0);
double XMAX=2;double YMAX = 2;
double XMIN=-2;double YMIN = -2;
int box = 100;
//int p =0;

//static int level = 0;

typedef struct Point
{
	double x,y;
	
}Point;

typedef struct queue queue;
typedef struct Node
{
	Node *child[4];
	Point pt[3];
	int flag;
	double width;
	double height;
	Node *parent;
	queue *back;
	int level;
	int num ;
	double func_val[3];
	Node *link[8];
	Node():num(0){ }
		
}Node;

typedef struct queue
{
	queue *next;
	Node *node_ptr;
}queue;
class qtree
{
	public:
		void buildtree(Node *n,int level);
		Node* buildnode(Node *n,Node *n_par,int k,FILE *p);
		void node_Def(Node *n,Node *n_par,double i,double j,int l);		
		int function(Node *n,int d);
		int task(Node *n);
		void open(int a);
		void close();
		void call(Node *n,FILE *p);
		void create_q(Node *n,queue *q);
		void create_link(Node *n,Node *nd);
		void nbr(Node *n,Node *root);
		void print(Node *n);
		void display(Node *n);
		void mat_tree(Node *n,FILE *p);
		void deletetree(Node *n);

	qtree();
	~qtree();
};


void qtree::open(int a)
{
	char *buffer=new char[12];
 
        snprintf(buffer, 12,"tri/da%d.m", a);
	

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

void qtree::node_Def(Node *n,Node *n_par,double i,double j,int l)
{
	if(n_par == NULL && l==0)
	{
	n->pt[0].x = j; n->pt[0].y = -i;
	n->pt[1].x = j-0.02; n->pt[1].y = -i-0.034641;
	n->pt[2].x = j+0.02; n->pt[2].y = -i-0.034641;
	n->flag = GREY;
	n->level = 0;			
	}
	
	if(n_par == NULL && l==1)
	{
	n->pt[0].x = j; n->pt[0].y = i;
	n->pt[1].x = j-0.02; n->pt[1].y = i+0.034641;
	n->pt[2].x = j+0.02; n->pt[2].y = i+0.034641;
	n->flag = GREY;
	n->level = 0;			
	}
	/*else if(n_par == NULL && l==1)
	{
	n->pt[0].x = 0 ; n->pt[0].y = 0;
	n->pt[1].x = -2; n->pt[1].y = -2;
	n->pt[2].x = 2; n->pt[2].y = -2;
	n->flag = GREY;
	n->level = 0;			
	}
	
	else if(n_par == NULL && l==2)
	{
	n->pt[0].x = 0 ; n->pt[0].y = 0;
	n->pt[1].x = 2; n->pt[1].y = -2;
	n->pt[2].x =  2; n->pt[2].y = 2;
	n->flag = GREY;
	n->level = 0;			
	}
	
	else if(n_par == NULL && l==3)
	{
	n->pt[0].x = 0 ; n->pt[0].y = 0;
	n->pt[1].x = 2; n->pt[1].y = 2;
	n->pt[2].x = 2; n->pt[2].y = -2;
	n->flag = GREY;
	n->level = 0;			
	}*/

	n->parent = n_par;	

	for(int w=0;w<4;w++)
	n->child[w] = NULL;	

}	

Node* qtree::buildnode(Node *n,Node *n_par,int k,FILE *p)
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

return n;

}

void qtree::create_q(Node *n,queue *q_par)
{
	queue *q_son = new queue;
	n->back = q_par;
	q_par->next = q_son; 
	q_par->node_ptr = n;
	if(n->child[0] == NULL)// && n->flag == GREY)
	{
		return;
	}
		
	else
	{	
		for(int k=0;k<4;k++)
		create_q(n->child[k],q_son);
	}
}

void qtree::buildtree(Node *n, int l)
{
	if(n->parent!=NULL)	
	n->flag = task(n);	

	if((n->flag == GREY) && l<7)
	{
			
		//#pragma omp parallel for
		for(int k =0; k < 4; k++)
		{
			Node *nd = new Node;
			n->child[k] = new Node;
			node_Def(n->child[k],n,0,0,0);
			n->child[k]->level = (n->level) + 1;
	                nd = buildnode(n->child[k],n, k,p);		
			buildtree(nd,nd->level);
			
		}
	
		
        }

	
	
}

int qtree::task(Node *n)
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

int qtree::function(Node *n,int d)
{double t;
double x = n->pt[d].x;
double y = n->pt[d].y;
/*double parameters[1] = {135};

double cond5,thmin;
	double z=parameters[0];

	thmin = 0; 	

	  cond5 =  -1.*acos(0.006666666666666667*pow(pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(-1.*z + 110.*cos(y)*sin(x),2),
       -0.5)*(-5400. + pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(-1.*z + 110.*cos(y)*sin(x),2)))\
    + acos(pow(pow(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(z - 110.*cos(y)*sin(x),2),-0.5)*
     (-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
        ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2))));

	t = cond5-thmin;*/
//cout << "f = " << t<<"\n";
	t = pow(x,2)+pow(y,2)-0.01;
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


void qtree::create_link(Node *n,Node *nd)
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
		create_link(n,nd->child[m]);		
	}
	
}

void qtree::nbr(Node *n, Node *root)
{
	
	
	if(n->child[0] == NULL)
	{
		if(n->flag == GREY)		
		create_link(n,root);

		else
		return;	
	}
	
	else if(n->child[0] != NULL)
	{
		for(int j=0;j<4;j++)
		nbr(n->child[j],root);		
		
	}
	

}

void qtree::print(Node *n)
{		

	{
		if(n->child[0] == NULL)// && n->flag == GREY)
		{
			if(n->flag == GREY || n->flag == RED)
			{//for(int j=0;j<n->num;j++)			
			//display(n->link[j]);
			display(n);
			}
		}	

		
		else
		{	
			for(int k=0;k<4;k++)
			print(n->child[k]);
	
		}
	}
/*while((n->back->next)!= NULL)
{
	display(n);
	n->back = n->back->next;
}*/
}

void qtree::display(Node *n)
{
	//cout<<"\nThe thread is"<<omp_get_thread_num();
	cout<<"\nThe solution points are";
	cout<<"\nx = "<<(n->pt[0].x+n->pt[1].x+n->pt[2].x)/3;
	cout<<"\ty = "<<(n->pt[0].y+n->pt[1].y+n->pt[2].y)/3<<"\n";
	
}

void qtree::call(Node *n,FILE *p)
{int a=1;
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
		call(n->child[k],p);
	
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
if (n->child[0] == NULL)

    {	
	fprintf(p,"A = [%lf,%lf,%lf;%lf,%lf,%lf];",n->pt[0].x,n->pt[1].x,n->pt[2].x,n->pt[0].y,n->pt[1].y,n->pt[2].y);
	fprintf(p,"A = [A A(:,1) ];line(A(1,:),A(2,:));\n");

      return;

    }

    else if (n->child[0] != NULL)

    {

        for (int i = 0; i < 4; i++)

        mat_tree(n->child[i],p);

	return;
    }
}


qtree::qtree()
{

}

qtree::~qtree()
{

}




int main(void)
{  //	double i=(YMIN+((YMAX-YMIN)/box)),l = (YMIN+((YMAX-YMIN)/box));double j=(XMIN+((XMAX-XMIN)/box));
	class qtree init;
	init.open(0);
	//omp_set_num_threads(2);
	queue *q = new queue;
	
		
		//#pragma omp parallel for private(l)			
		for(double i=-2;i<=2;i=i+0.034641)	
		{
			for(double j = -1.98;j<=1.98;j=j+0.04)
	
			{
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,0);
		
	        	qt.buildtree(root,0);				
			
			qt.create_q(root,q);
			
			qt.nbr(root,root);
			
			//qt.print(root);
			
			qt.call(root,p);		
		       	
			//cout<<"\n\nCompleted thread:"<<omp_get_thread_num()<<"\n";
			qt.deletetree(root);
	
	          	}
		}

		
		for(double i=1.965359;i>=-2;i=i-0.034641)	
		{
			for(double j = -2;j<=2;j=j+0.04)
	
			{
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,1);
		
	        	qt.buildtree(root,0);				
			
			qt.create_q(root,q);
			
			qt.nbr(root,root);
			
			//qt.print(root);
			
			qt.call(root,p);		
		       	
			//cout<<"\n\nCompleted thread:"<<omp_get_thread_num()<<"\n";
			qt.deletetree(root);
	
	          	}
		}	

		init.close(); 
		
		for(double i=-2;i<=2;i=i+0.034641)	
		{
			for(double j = -1.98;j<=1.98;j=j+0.04)
	
			{
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,0);
		
	        	qt.buildtree(root,0);				
			
			//qt.create_q(root,q);
			
			//qt.nbr(root,root);
			
			//qt.print(root);
			
			//qt.call(root,p);		
		      	qt.mat_tree(root,p);
			//cout<<"\n\nCompleted thread:"<<omp_get_thread_num()<<"\n";
			qt.deletetree(root);
	
	          	}
		}

		
		for(double i=1.965359;i>=-2;i=i-0.034641)	
		{
			for(double j = -2;j<=2;j=j+0.04)
	
			{
			class qtree qt;			
			
			Node *root = new Node;
			
			qt.node_Def(root,NULL,i,j,1);
		
	        	qt.buildtree(root,0);				
			
			//qt.create_q(root,q);
			
			//qt.nbr(root,root);
			
			//qt.print(root);
			
			//qt.call(root,p);		
		      	qt.mat_tree(root,p);
			//cout<<"\n\nCompleted thread:"<<omp_get_thread_num()<<"\n";
			qt.deletetree(root);
	
	          	}
		}	
	
	fprintf(p,"xmin=min(xx);xmax=max(xx);ymin=min(yy);ymax=max(yy);\naxis([xmin xmax ymin ymax]);\naxis('square');set(hand, 'MarkerSize', 1);");
	fclose(p);
}
