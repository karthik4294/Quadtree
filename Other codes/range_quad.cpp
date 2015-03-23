/*******

This program defines a square between the point (0,0) and (500,500).

100 points are taken randomnly and segregated into different childs of the root .

The condition for further subdivision of a child is that the node should  contail more than 10 points

The program builds the quadtree and prints on screen the points of the children nodes.

The following coordinate system has been followed.

		   __________  (500,500)
                 |     |       |
		 |  1  | 0     |
		 |  _________  |
		 |     |       |
	         |  2  |  3    |
             (0,0)  __________



*******/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


typedef struct Point
{
   int x,y;

}Point;

class Node

{
public: 
	int posX;
	int posY;
	int width;
	int height;
	Node *child[4];         
        Point array[100];

};

//typedef class Node Node;

class quadtree
	{
		public:
		void setnode(Node *xy,int x,int y,int w,int h);
		Node buildtree(Node* n);
		void printtree(Node* n,int depth);		
		void deletetree(Node* n);
		Node *BuildNode(Node* n, Node  *nParent, int index);		
	 	static int pointArray_size(Node *n);
		//Node *rootNode ;		
		int randn();		
                quadtree();
		~quadtree();
							
	friend class Node;

	};



int quadtree::randn()

{

    int a;

    a=rand()%501;

    return a;

}

int quadtree::pointArray_size(Node *n)

{

    int m = 0,i;

    for (i = 0;i<=100; i++)

       if(n->array[i].x <= 500 && n->array[i].y <= 500)

            m++;

    return (m);

}

void quadtree::setnode(Node *xy,int x,int y,int w,int h)

{

    int i;

    xy->posX = x;

    xy->posY = y;

    xy->width= w;

    xy->height= h;

    for(i=0;i<100;i++)

    {

        xy->array[i].x=501;
       xy->array[i].y=501;

    }

    for (int i = 0; i < 4; i++)

        xy->child[i] = NULL;

}



Node* quadtree:: BuildNode(Node *n, Node *nParent, int index)

{

    int numParentPoints, i,j = 0;


    setnode(n, 0, 0, 0, 0);

     

    switch(index)

    {

        case 0: 

             

            n->posX = nParent->posX+nParent->width/2;

            n->posY = nParent->posY+nParent->height/2;

            break;

             

        case 1: 

             

            n->posX = nParent->posX;

            n->posY = nParent->posY+nParent->height/2;

            break;

             

        case 2: 

             

            n->posX = nParent->posX;

            n->posY = nParent->posY;

            break;

             

        case 3: 

            

            n->posX = nParent->posX+nParent->width/2;

            n->posY = nParent->posY;

           break;

             

    }

     

    

   n->width = nParent->width/2;

    n->height = nParent->height/2;

     

    

    numParentPoints = pointArray_size(nParent);

     

   switch(index)

    {

        case 0: 
            for(i = 0; i < numParentPoints-1; i++)

           {

           

                if(nParent->array[i].x<=500 && nParent->array[i].x > nParent->posX+nParent->width/2 && nParent->array[i].y > nParent->posY + nParent->height/2 && nParent->array[i].x <= nParent->posX + nParent->width && nParent->array[i].y <= nParent->posY + nParent-> height)

                {

                    

                  n->array[j].x = nParent ->array[i].x;

                    n->array[j].y = nParent ->array[i].y;

                    j++;

                }

            }

            break;

        case 1: 

            for(i = 0; i < numParentPoints-1; i++)

            {

                

                if(nParent->array[i].x<=500 && nParent->array[i].x > nParent->posX && nParent->array[i].y > nParent->posY+ nParent-> height/2 && nParent->array[i].x <= nParent->posX + nParent->width/2 && nParent->array[i].y <= nParent->posY + nParent->height)

                {

                    

                    n->array[j].x = nParent ->array[i].x;

                    n->array[j].y = nParent ->array[i].y;

                    j++;

                }

            }

            break;

        case 2: 

            for(i = 0; i < numParentPoints-1; i++)

            {

                

               if(nParent->array[i].x<=500 && nParent->array[i].x > nParent->posX && nParent->array[i].y > nParent->posY && nParent->array[i].x <= nParent->posX + nParent->width/2 && nParent->array[i].y <= nParent->posY + nParent->height/2)

               {  

                    

                    n->array[j].x = nParent ->array[i].x;

                    n->array[j].y = nParent ->array[i].y;

                    j++;

                }

            }

            break;

             

        case 3: 

            for(i = 0; i < numParentPoints-1; i++)

            {

                

                if(nParent->array[i].x<=500 && nParent->array[i].x > nParent->posX +  nParent->width/2 && nParent->array[i].y > nParent->posY && nParent->array[i].x <= nParent->posX + nParent->width && nParent->array[i].y <= nParent->posY + nParent->height/2)

                {

                    

                   n->array[j].x = nParent ->array[i].x;

                    n->array[j].y = nParent ->array[i].y;

                    j++;

                }

            }

            break;

             

    }

    return n;

}

quadtree::quadtree()
{

//buildtree(n);

}


Node quadtree::buildtree(Node *n)
{

Node * nodeIn = new Node;   
    int points = pointArray_size(n);

     
  if(points > 10)

    {

        for(int k =0; k < 4; k++)

        {

            n->child[k] = new Node;      

            nodeIn = BuildNode(n->child[k], n, k);

            buildtree(nodeIn);

        }

    }

}

void quadtree::printtree(Node* n,int depth)
{//depth=0;
    for (int i = 0; i < depth; i++)

        cout<<"\t";

         

    if (n->child[0] == NULL)

    {

        int points = pointArray_size(n);

        cout<<"Points: "<<points<<"\n";//<<"\t"<<"The points are";
  
	//for (int i = 0; i < depth+1; i++)

//        cout<<"\t";	

	for(int w=0;w<10;w++)
	{
		if(n->array[w].x>500 || n->array[w].y>500)
			{
			}
		else
			{
				cout<<"("<<n->array[w].x<<","<<n->array[w].y<<")"<<"\n";
				 //for (int k = 0; k < depth; k++)
				//cout<<"\t";			
				
			}
	}

        return;

    }

    else if (n->child[0] != NULL)

    {

        cout<<"Children:\n";

        for (int i = 0; i < 4; i++)

            printtree(n->child[i], depth + 1);
	
        return;

    }

}

void deletetree(Node *n)

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


quadtree::~quadtree()
	{
		//deletetree(rootNode);
	}	


int main(void)
{
	
	Node *rootNode = new Node;

	int i,x[100],y[100];

	quadtree qtree;	
	
	qtree.setnode(rootNode,0, 0, 500, 500);
	
	

	for(i=0;i<100;i++)

    	{

        x[i]=i,y[i]=i;//x[i]=qtree.randn();

        //y[i]=qtree.randn();

    	rootNode->array[i].x=x[i];
   
        rootNode->array[i].y=y[i];
	
	}
	
	qtree.buildtree(rootNode);
	qtree.printtree(rootNode,0);
	deletetree(rootNode);
	
	


}
