function [minY,minX] = function(fun,)

eps = 10^-3;

syms x;
y = x^5 - 1.75*x^4 - 3.75*x^3 + 5.3125*x^2 + 3.6875*x -2.6250; 

xP = input('Input the initial guess:  ');   

it = 0;
while( abs( double(subs(diff(y),x,xP)) )> eps)
    
    xP = xP - double((subs(diff(y),x,xP)/subs(diff(y,2),x,xP)));
    it = it + 1;
    
end

it
minY = double(subs(y,x,xP))
minX = xP

xV = [0.25:0.001:2.25];

plot(xV,subs(y,x,xV));
hold on
plot(minX,minY,'or')
