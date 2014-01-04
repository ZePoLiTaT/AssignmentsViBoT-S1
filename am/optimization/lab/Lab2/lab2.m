clear; clc; close all;

MIN = -1;
MAX = 1;

x = linspace(-1,5,150);
y = linspace(-1,5,150);

%f3d = @( x, y ) x.^2 + y.^2;
f3d = @( x, y ) x.^2 + (x-y).^2;

[dimx, dimy] = meshgrid(x,y);
z = f3d(dimx, dimy);

figure;
subplot(1,2,1); plot3(dimx, dimy, z);
subplot(1,2,2); surf(z);

%p0 = [4.5,3]';
p0 = [2.25,4.5]';

figure;
contour(dimx, dimy, z, 50);
hold on;

tic
%arbitrary_line_search(f3d, p0);
steepest_descent(f3d, p0);
toc

%powell(f3d, p0);
