clear all;close all;clc;
xx = [0 1 2 3 4 5 6 7 8 9 10 11 12 13];
yy = [0 0 0 0 0 0 0 0 0.01 0.01 0.05 0.1 0.47 1];
plot(xx,yy,'r-*');
xlabel('Depth of quadtree'); 
ylabel('Number of Nodes');  
title('Graph of Depth of tree VS No: of Nodes');
hold on
xx = [0 1 2 3 4 5 6 7 8 9 10 11 12 13];
yy = [0 0 0 0 0 0 0 0 0 0.01 0.03 0.08 0.09 0.94];
plot(xx,yy,'g-o'); 
hold on
grid on; 
xx = [0 1 2 3 4 5 6 7 8 9 10 11 12 13];
yy = [0 0 0 0 0 0 0.01 0.02 0.04 0.1 0.12 0.25 0.44 0.95];
plot(xx,yy,'b-+'); 
legend('Rectangle','Triangle','Circle');
