function [minY,minX] = Brute_force(fun,a,b)

x = linspace(a,b,100);
y = fun(x);

[minY, xM] = min(y);
minX = x(xM);

% figure
% plot(x,y);
% hold on
% plot(minX,minY,'*r')
% hold off


