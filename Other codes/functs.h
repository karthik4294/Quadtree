#ifndef GLOBAL_H
	#include "global.h"
#endif

typedef double (*fptr)(double x, double y, double* parameters);
fptr fn_ptr_selector(int fn_no);

double function1(double x,double y, double* parameters);
double function2(double x,double y, double* parameters);
double function3(double x,double y, double* parameters);
double function4(double x,double y, double* parameters);
double function5(double x,double y, double* parameters);
double function6(double x,double y, double* parameters);
double function7(double x,double y, double* parameters);
double function8(double x,double y, double* parameters);
double function9(double x,double y, double* parameters);
double function10(double x,double y, double* parameters);
double function11(double x,double y, double* parameters);
double function12(double x,double y, double* parameters);
double function13(double x,double y, double* parameters);
double function14(double x,double y, double* parameters);
double function15(double x,double y, double* parameters);
double function16(double x,double y, double* parameters);

double function1(double x,double y, double* parameters)
{
double c1,temp1,temp2,temp3,t1,t2,t3,g1,g2,g3,ct1,st1,ct2,st2,ct3,st3,cg1,sg1,cg2,sg2,cg3,sg3,cf2,sf2,cf1,sf1;
double z=parameters[0];
cf2=cos(y);
sf2=sin(y);
cf1=cos(x);
sf1=sin(x);

temp1=6.666666666666667*pow(pow(0.1 - 0.055*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        ((3.*cf1 - 1.*cf2)*(cf1 + cf2) + 
          3.*pow(sf1,2)*pow(sf2,2)),2) + 
     pow(0.11*cf2*sf1 - 1.*z,2),-0.5)*
   (-0.0054 + pow(0.1 - 0.055*pow(pow(cf1 + cf2,2) + 
          pow(sf1,2)*pow(sf2,2),-0.5)*
        ((3.*cf1 - 1.*cf2)*(cf1 + cf2) + 
          3.*pow(sf1,2)*pow(sf2,2)),2) + 
     pow(0.11*cf2*sf1 - 1.*z,2));

temp2=6.666666666666667*pow(pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 - 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 + 1.7320508075688772*sf2) - 1.*z,2),-0.5)*
   (-0.0054 + pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 - 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 + 1.7320508075688772*sf2) - 1.*z,2));

temp3=6.666666666666667*pow(pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 + 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 - 1.7320508075688772*sf2) - 1.*z,2),-0.5)*
   (-0.0054 + pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 + 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 - 1.7320508075688772*sf2) - 1.*z,2));



	t1=atan2(-0.11*cf2*sf1 + z,-0.1 + 0.055*pow(pow(cf1 + cf2,2) + 
		  pow(sf1,2)*pow(sf2,2),-0.5)*
		((3.*cf1 - 1.*cf2)*(cf1 + cf2) + 
		  3.*pow(sf1,2)*pow(sf2,2))) - 
	   1.*acos(temp1);

	t2=atan2(
	      0.055*(cf2*sf1 + 1.7320508075688772*sf2) + z,-0.1 + 0.11*cf2*
		pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
		(cf1 + cf2 - 1.7320508075688772*sf1*sf2)) - 
	   1.*acos(temp2);

	t3=atan2(
	      0.055*(cf2*sf1 - 1.7320508075688772*sf2) + z,-0.1 + 0.11*cf2*
		pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
		(cf1 + cf2 + 1.7320508075688772*sf1*sf2)) - 
	   1.*acos(temp3);

	ct1=cos(t1);
	ct2=cos(t2);
	ct3=cos(t3);
	st1=sin(t1);
	st2=sin(t2);
	st3=sin(t3);

	g1=atan2((-3*st1)/40. - (11*cf2*sf1)/100. + z,-0.1 - (3*ct1)/40. + (11*pow(pow(cf1 + cf2,2) + 
		 pow(sf1,2)*pow(sf2,2),-0.5)*
	       ((3*cf1 - cf2)*(cf1 + cf2) + 3*pow(sf1,2)*pow(sf2,2))
	       )/200);

	g2=atan2(
	   (-3*st2)/40. + (11*(cf2*sf1 + pow(3,0.5)*sf2))/200. + z,-0.1 - (3*ct2)/40. + (11*cf2*
	       pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
	       (cf1 + cf2 - pow(3,0.5)*sf1*sf2))/100);

	g3=atan2(
	   (-3*st3)/40. + (11*(cf2*sf1 - pow(3,0.5)*sf2))/200. + z,-0.1 - (3*ct3)/40. + (11*cf2*
	       pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
	       (cf1 + cf2 + pow(3,0.5)*sf1*sf2))/100);



	cg1=cos(g1);
	cg2=cos(g2);
	cg3=cos(g3);
	sg1=sin(g1);
	sg2=sin(g2);
	sg3=sin(g3);
	//c1=(pow(x-3,2)+pow(y-3,2)-10);
	//workspace=(temp1-1)*(temp2-1)*(temp3-1);


	c1=(-((0.6 + (21*cg1)/100. + (3*ct1)/20. + (3*ct2)/10.)*sg2 + 
		4*cg2*((21*sg1)/200. + (3*(st1 - st2))/40.))*
	      ((0.6 + (21*cg2)/100. + (3*ct2)/20. + (3*ct3)/10.)*sg3 + 
		4*cg3*((21*sg2)/200. + (3*(st2 - st3))/40.))*
	      ((0.6 + (21*cg3)/100. + (3*ct1)/10. + (3*ct3)/20.)*sg1 + 
		4*cg1*((21*sg3)/200. + (3*(-st1 + st3))/40.))) - 
	   (((0.6 + (21*cg2)/100. + (3*ct1)/10. + (3*ct2)/20.)*sg1 + 
		4*cg1*((21*sg2)/200. + (3*(-st1 + st2))/40.))*
	      ((0.6 + (21*cg1)/100. + (3*ct1)/20. + (3*ct3)/10.)*sg3 + 
		4*cg3*((21*sg1)/200. + (3*(st1 - st3))/40.))*
	      ((0.6 + (21*cg3)/100. + (3*ct2)/10. + (3*ct3)/20.)*sg2 + 
		4*cg2*((21*sg3)/200. + (3*(-st2 + st3))/40.)));




return (c1);

//double k;
//k = pow(x,2)+pow(y,2)-6;
//return k;
}

double function2(double x,double y,double* parameters)
{

double z=parameters[0];
double c1;
double cf2,sf2,cf1,sf1;

int temp;



cf2=cos(y);
sf2=sin(y);
cf1=cos(x);
sf1=sin(x);

c1=6.666666666666667*pow(pow(0.1 - 0.055*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        ((3.*cf1 - 1.*cf2)*(cf1 + cf2) + 
          3.*pow(sf1,2)*pow(sf2,2)),2) + 
     pow(0.11*cf2*sf1 - 1.*z,2),-0.5)*
   (-0.0054 + pow(0.1 - 0.055*pow(pow(cf1 + cf2,2) + 
          pow(sf1,2)*pow(sf2,2),-0.5)*
        ((3.*cf1 - 1.*cf2)*(cf1 + cf2) + 
          3.*pow(sf1,2)*pow(sf2,2)),2) + 
     pow(0.11*cf2*sf1 - 1.*z,2));


return (fabs(c1)-1);

//double k;
//k = pow(x,2)+pow(y,2)-8;
//return k;
}

double function3(double x,double y,double* parameters)
{

double z=parameters[0];
double c1;
double cf2,sf2,cf1,sf1;


cf2=cos(y);
sf2=sin(y);
cf1=cos(x);
sf1=sin(x);


c1=6.666666666666667*pow(pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 - 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 + 1.7320508075688772*sf2) - 1.*z,2),-0.5)*
   (-0.0054 + pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 - 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 + 1.7320508075688772*sf2) - 1.*z,2));





return (fabs(c1)-1);

//double k;
//k = pow(x,2)+4*pow(y,2)-4;
//return k;
}


double function4(double x,double y,double* parameters)
{

double z=parameters[0];
double c1;
double cf2,sf2,cf1,sf1;


cf2=cos(y);
sf2=sin(y);
cf1=cos(x);
sf1=sin(x);


c1=6.666666666666667*pow(pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 + 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 - 1.7320508075688772*sf2) - 1.*z,2),-0.5)*
   (-0.0054 + pow(0.1 - 0.11*cf2*
        pow(pow(cf1 + cf2,2) + pow(sf1,2)*pow(sf2,2),-0.5)*
        (cf1 + cf2 + 1.7320508075688772*sf1*sf2),2) + 
     pow(-0.055*(cf2*sf1 - 1.7320508075688772*sf2) - 1.*z,2));


return (fabs(c1)-1);

//double k;
//k = pow(x,2)+pow(y,2)-1;
//return k;

}


double function5(double x,double y, double* parameters)
{	
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

	return cond5-thmin;
}


double function6(double x,double y, double* parameters)
{	
	double cond5, sf1,sf2,cf1,cf2,thmax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	thmax = Pi/2; 	

	  cond5 =  -1.*acos(0.006666666666666667*pow(pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(-1.*z + 110.*cos(y)*sin(x),2),
       -0.5)*(-5400. + pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(-1.*z + 110.*cos(y)*sin(x),2)))\
    + acos(pow(pow(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(z - 110.*cos(y)*sin(x),2),-0.5)*
     (-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
        ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2))));

	return cond5-thmax;
}


double function7(double x,double y, double* parameters)
{	
	double cond6,sf1,sf2,cf1,cf2,thmin;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	thmin = 0; 	
	
	cond6 = -1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
        pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
      (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
        pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2))) + 
   acos(pow(pow(z + 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
       pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
     (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
        (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y))));
	return cond6-thmin;
}


double function8(double x,double y, double* parameters)
{	
	double cond6, sf1,sf2,cf1,cf2,thmax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	thmax = Pi/2; 	
	
	cond6 = -1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
        pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
      (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
        pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
           (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2))) + 
   acos(pow(pow(z + 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
       pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
     (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
        (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y))));

	return cond6-thmax;
}


double function9(double x,double y, double* parameters)
{	
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

	return cond7-thmin;
}


double function10(double x,double y, double* parameters)
{	
	double cond7, sf1,sf2,cf1,cf2,thmax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	thmax = Pi/2; 	
	
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
	
	return cond7-thmax;
}


double function11(double x,double y, double* parameters)
{	
	double cond8, sf1,sf2,cf1,cf2,delmax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	delmax = Pi/3;
	
	cond8 = acos((pow(3,-0.5)*(100 + 75*cos(1.*acos(0.006666666666666667*
               pow(pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
                 pow(-1.*z + 110.*cos(y)*sin(x),2),-0.5)*
               (-5400. + pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
                 pow(-1.*z + 110.*cos(y)*sin(x),2))) - 
            acos(pow(pow(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                   ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
                pow(z - 110.*cos(y)*sin(x),2),-0.5)*
              (-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2))))) - 
         55*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          ((3*cos(x) - cos(y))*(cos(x) + cos(y)) + 3*pow(sin(x),2)*pow(sin(y),2)))*
       (-18150*cos(x)*pow(3,0.5)*pow(cos(y),2)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),
           -0.5)*sin(x) - 18150*pow(3,0.5)*pow(cos(y),3)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*sin(x) - 
         18150*cos(y)*pow(3,0.5)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(sin(y),2)*sin(x)))/1.90575e6 + (pow(3,-0.5)*
       (-18150*cos(y)*pow(3,0.5)*pow(cos(x),3)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),
           -0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         36300*pow(3,0.5)*pow(cos(x),2)*pow(cos(y),2)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         18150*cos(x)*pow(3,0.5)*pow(cos(y),3)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),
           -0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         18150*cos(x)*cos(y)*pow(3,0.5)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*pow(sin(x),2)*pow(sin(y),2))*
       (-z + 110*cos(y)*sin(x) - 75*sin(1.*acos(0.006666666666666667*
               pow(pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
                 pow(-1.*z + 110.*cos(y)*sin(x),2),-0.5)*
               (-5400. + pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
                 pow(-1.*z + 110.*cos(y)*sin(x),2))) - 
            acos(pow(pow(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                   ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
                pow(z - 110.*cos(y)*sin(x),2),-0.5)*
              (-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)))))))/1.90575e6);
	
	return cond8-delmax;
}


double function12(double x,double y, double* parameters)
{	
	double cond9, sf1,sf2,cf1,cf2,delmax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	delmax = Pi/3;
	
	  cond9 = acos((pow(3,-0.5)*(-18150*cos(x)*pow(3,0.5)*pow(cos(y),2)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*sin(x) - 
         18150*pow(3,0.5)*pow(cos(y),3)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          sin(x) - 18150*cos(y)*pow(3,0.5)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),
           -0.5)*pow(sin(y),2)*sin(x))*((-100 - 75*cos(1.*
                acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                    pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                       (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                  (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                    pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                       (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2))) - 
               acos(pow(pow(z + 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                   pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                      (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                 (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y))))))/2. + 
         55*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*(cos(x) + cos(y) - pow(3,0.5)*sin(x)*sin(y))))/
     1.90575e6 + (pow(3,-0.5)*(18150*pow(3,0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*pow(sin(x),2)*
          pow(sin(y),3) + 18150*cos(x)*cos(y)*pow(3,0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*sin(y) + 
         18150*pow(3,0.5)*pow(cos(x),2)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*sin(y) + 
         18150*pow(3,0.5)*pow(cos(y),2)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*pow(sin(x),2)*sin(y))*
       (((100 + 75*cos(1.*acos(0.006666666666666667*
                    pow(pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                      pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                         (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                    (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                      pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                         (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2))) - 
                 acos(pow(pow(z + 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                     pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                        (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                   (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                      (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y))))))*pow(3,0.5))/2. - 
         55*cos(y)*pow(3,0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          (cos(x) + cos(y) - pow(3,0.5)*sin(x)*sin(y))))/1.90575e6 + 
    (pow(3,-0.5)*(-18150*cos(y)*pow(3,0.5)*pow(cos(x),3)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         36300*pow(3,0.5)*pow(cos(x),2)*pow(cos(y),2)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         18150*cos(x)*pow(3,0.5)*pow(cos(y),3)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),
           -0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         18150*cos(x)*cos(y)*pow(3,0.5)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*pow(sin(x),2)*pow(sin(y),2))*
       (-z - 55*(cos(y)*sin(x) + pow(3,0.5)*sin(y)) - 
         75*sin(1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                 pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
               (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                 pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2))) - 
            acos(pow(pow(z + 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
                pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                   (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
              (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)))))))/1.90575e6);

	
	return cond9-delmax;
}

double function13(double x,double y, double* parameters)
{	
	double cond10, sf1,sf2,cf1,cf2,delmax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	delmax = Pi/3;
	
	 cond10 = acos((pow(3,-0.5)*(-18150*cos(x)*pow(3,0.5)*pow(cos(y),2)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*sin(x) - 
         18150*pow(3,0.5)*pow(cos(y),3)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          sin(x) - 18150*cos(y)*pow(3,0.5)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),
           -0.5)*pow(sin(y),2)*sin(x))*((-100 - 75*cos(1.*
                acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                    pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                       (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                  (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                    pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                       (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2))) - 
               acos(pow(pow(z + 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                   pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                      (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                 (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y))))))/2. + 
         55*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*(cos(x) + cos(y) + pow(3,0.5)*sin(x)*sin(y))))/
     1.90575e6 + (pow(3,-0.5)*(18150*pow(3,0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*pow(sin(x),2)*
          pow(sin(y),3) + 18150*cos(x)*cos(y)*pow(3,0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*sin(y) + 
         18150*pow(3,0.5)*pow(cos(x),2)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*sin(y) + 
         18150*pow(3,0.5)*pow(cos(y),2)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*pow(sin(x),2)*sin(y))*
       (-((100 + 75*cos(1.*acos(0.006666666666666667*
                     pow(pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                       pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                          (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                     (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                       pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                          (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2))) - 
                  acos(pow(pow(z + 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                      pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                         (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
                    (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                       (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y))))))*pow(3,0.5))/2. + 
         55*cos(y)*pow(3,0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          (cos(x) + cos(y) + pow(3,0.5)*sin(x)*sin(y))))/1.90575e6 + 
    (pow(3,-0.5)*(-18150*cos(y)*pow(3,0.5)*pow(cos(x),3)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         36300*pow(3,0.5)*pow(cos(x),2)*pow(cos(y),2)*
          pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         18150*cos(x)*pow(3,0.5)*pow(cos(y),3)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),
           -0.5)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5) - 
         18150*cos(x)*cos(y)*pow(3,0.5)*pow(2*cos(x)*cos(y) + pow(cos(x),2) + pow(cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
          pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*pow(sin(x),2)*pow(sin(y),2))*
       (-z - 55*(cos(y)*sin(x) - pow(3,0.5)*sin(y)) - 
         75*sin(1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                 pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
               (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                 pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                    (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2))) - 
            acos(pow(pow(z + 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
                pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                   (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
              (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)))))))/1.90575e6);

	
	return cond10-delmax;
}

double function14(double x,double y, double* parameters)
{	
	double cond11, sf1,sf2,cf1,cf2,gammax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	gammax = 2*Pi/3;
	
	cond11 = -atan(pow(100 + 75*cos(1.*acos(0.006666666666666667*
             pow(pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
               pow(-1.*z + 110.*cos(y)*sin(x),2),-0.5)*
             (-5400. + pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
               pow(-1.*z + 110.*cos(y)*sin(x),2))) - 
          acos(pow(pow(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(z - 110.*cos(y)*sin(x),2),
             -0.5)*(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
               ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2))))) - 
       55*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
        ((3*cos(x) - cos(y))*(cos(x) + cos(y)) + 3*pow(sin(x),2)*pow(sin(y),2)),-1)*
     (-z + 110*cos(y)*sin(x) - 75*sin(1.*acos(0.006666666666666667*
             pow(pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
               pow(-1.*z + 110.*cos(y)*sin(x),2),-0.5)*
             (-5400. + pow(100. - 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + 
               pow(-1.*z + 110.*cos(y)*sin(x),2))) - 
          acos(pow(pow(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)),2) + pow(z - 110.*cos(y)*sin(x),2),
             -0.5)*(-100. + 55.*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
               ((3.*cos(x) - 1.*cos(y))*(cos(x) + cos(y)) + 3.*pow(sin(x),2)*pow(sin(y),2)))))));
	
	return cond11-gammax;
}


double function15(double x,double y, double* parameters)
{	
	double cond12, sf1,sf2,cf1,cf2,gammax;
	double z=parameters[0];
	sf1 = sin(x);
	cf1 = cos(x);
	sf2 = sin(y);
	cf2 = cos(y);
	gammax = 2*Pi/3;
	
	cond12 = atan(pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),0.5)*
    pow(-220*cos(x)*cos(y) - 220*pow(cos(y),2) + 200*pow(pow(1 + cos(x)*cos(y),2),0.5) + 
      150*cos(1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
              pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
            (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
              pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2))) - 
         acos(pow(pow(z + 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
             pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
           (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
              (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)))))*pow(pow(1 + cos(x)*cos(y),2),0.5) + 
      110*pow(3,0.5)*sin(x)*sin(2*y),-1)*(2*z + 110*cos(y)*sin(x) + 110*pow(3,0.5)*sin(y) + 
      150*sin(1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
              pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
            (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
              pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2))) - 
         acos(pow(pow(z + 55.*(cos(y)*sin(x) + 1.7320508075688772*sin(y)),2) + 
             pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
           (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
              (cos(x) + cos(y) - 1.7320508075688772*sin(x)*sin(y)))))));
	
	return cond12-gammax;
}

double function16(double x,double y, double* parameters)
{	
	double cond13, f1,f2,gammax;
	double z=parameters[0];
	f1 = x;
	f2 = y;
	gammax = 2*Pi/3;
	
cond13=-atan(pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),0.5)*
     pow(-220*cos(x)*cos(y) - 220*pow(cos(y),2) + 200*pow(pow(1 + cos(x)*cos(y),2),0.5) + 
       150*cos(1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
               pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
             (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
               pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2))) - 
          acos(pow(pow(z + 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
              pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
            (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
               (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)))))*pow(pow(1 + cos(x)*cos(y),2),0.5) - 
       110*pow(3,0.5)*sin(x)*sin(2*y),-1)*(-2*z - 110*cos(y)*sin(x) + 110*pow(3,0.5)*sin(y) - 
       150*sin(1.*acos(0.006666666666666667*pow(pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
               pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
             (-5400. + pow(-1.*z - 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
               pow(100. - 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                  (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2))) - 
          acos(pow(pow(z + 55.*(cos(y)*sin(x) - 1.7320508075688772*sin(y)),2) + 
              pow(-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
                 (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)),2),-0.5)*
            (-100. + 110.*cos(y)*pow(pow(cos(x) + cos(y),2) + pow(sin(x),2)*pow(sin(y),2),-0.5)*
               (cos(x) + cos(y) + 1.7320508075688772*sin(x)*sin(y)))))));

	return cond13-gammax;
}


fptr fn_ptr_selector(int fn_no)
{

	double (*fn)(double,double,double*) = NULL;
	switch(fn_no)
	{
		case 1 : fn = function1;
			     break;
		case 2 : fn = function2;
			     break;
		case 3 : fn = function3;
			     break;
		case 4 : fn = function4;
			     break;
		case 5 : fn = function5;
			     break;
		case 6 : fn = function6;
			     break;
		case 7 : fn = function7;
			     break;
		case 8 : fn = function8;
			     break;
		case 9 : fn = function9;
			     break;
		case 10 : fn = function10;
			     break;
		case 11 : fn = function11;
			     break;
		case 12 : fn = function12;
			     break;
		case 13 : fn = function13;
			     break;
		case 14 : fn = function14;
			     break;
		case 15 : fn = function15;
			     break;
		case 16 : fn = function16;
			     break;
		default : cout<<"error in functs switch"<<endl;break;

	}
	
	return fn;
}
