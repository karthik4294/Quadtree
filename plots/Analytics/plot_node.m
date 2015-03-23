clear all;close all;clc;
xx = [0 1 2 3 4 5 6 7 8 9 10];
yy = [1 4 16 64 148 304 592 1156 2272 4492 8920];
plot(xx,yy,'r-*');
xlabel('Depth of quadtree'); 
ylabel('Number of Nodes');  
title('Graph of Depth of tree VS No: of Nodes');
hold on
xx = [0 1 2 3 4 5 6 7 8 9 10];
yy = [1 4 16 46 100 202 400 802 1612 3250 6520];
plot(xx,yy,'g-o'); 
hold on
grid on; 
xx = [0 1 2 3 4 5 6 7 8 9 ];
yy = [36 144 228 408 768 1488 2940 5844 11688 23484];
plot(xx,yy,'b-+'); 
legend('Rectangle','Triangle','Circle');
