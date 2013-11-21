clear; clc; close all;
 

MIN = -1;
MAX = 1;

x = linspace(-1,1,50);
y = linspace(-1,1,50);

[dimx, dimy] = meshgrid(x,y);
z = f_3d(dimx, dimy);

figure;
subplot(1,3,2); contour(dimx, dimy, z);
subplot(1,3,3); surf(z);
subplot(1,3,1); plot3(dimx, dimy, z);

%% TODO: Esto va en una funcion
rot90 = [0 -1; 1 0];

p0 = [0.5,0.5]';%;rand(1,1)*(MAX-MIN) - MIN;
t0 = rand(1,1);
d = [1,1]'; %rand(1,2);

for i=1:4
    %Just to see the 2d cut in 3d space
    %figure;
    f = @(t) f_td(t, d, p0);
    %plot3(x,y,f(x));

    %Find the minimum in the line of the parametric f(t,d)
    [minx, miny] = Golden_search(f, -1, 1)

    %Change the direction to be orthogonal
    d = rot90*d;
    p0 = [minx, miny]';
end