clear all;close all;clc;
xx = [4 5 6 7 8 9 10];
yy = [2.008 1.475 1.079 0.780 0.559 0.398 0.283];
plot(xx,yy,'r-*');
xlabel('Depth of quadtree'); 
ylabel('RMS Value of Hyperbola function');  
title('Graph of Depth of tree VS RMS value');
hold on
xx = [4 5 6 7 8 9 10];
yy = [2.418 1.741 1.246 0.883 0.624 0.440 0.310];
plot(xx,yy,'g-o'); 
hold on
grid on; 
xx = [4 5 6 7 8 9 10];
yy = [0.876 0.632 0.45 0.32 0.226 0.159 0.112];
plot(xx,yy,'b-+'); 
legend('Rectangle','Triangle','Circle');
